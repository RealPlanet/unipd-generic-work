#include "LaserScannerDriver.h"
#include "math.h"

/*
    Fabio Ruscica
    Data: 02/12/2020
    V. 1
*/

// Inizio costruttori classe
//Costruttore di default

LaserScannerDriver::LaserScannerDriver() : angle_resolution{ 1 }, num_of_scan{ 181 }
{   // 180 / 1 + 1, risparmio un conto e lo imposto a 180

    // Stesso comportamento del costruttore con parametro, unica differenza è la mancanza dell'eccezione dato che la risoluzione è
    // pre-impostata
    array_ptr = new double* [BUFFER_DIM] {nullptr};

    for (unsigned int i = 0; i < BUFFER_DIM; i++)
    {
        array_ptr[i] = new double[num_of_scan] {0};
    }

    currentSize = -1;
}

//Costruttore con risoluzione
LaserScannerDriver::LaserScannerDriver(const double _newResolution) : angle_resolution{ _newResolution }, num_of_scan{ (unsigned int)(180 / angle_resolution) + 1 }
{
    //Se ho una risoluzione pari a 1 allora salvero 181 valori (da 0 a 180)
    if (_newResolution < 0.1 || _newResolution > 1 ) //La risoluzione d'angolo deve essere [0.1, 1]
    {
        throw InvalidAngleResolution();
    }

    array_ptr = new double*[BUFFER_DIM];

    for (unsigned int i = 0; i < BUFFER_DIM; i++)
    {
        array_ptr[i] = new double[num_of_scan] {0};
        // Nel costruttore di copia inizializzo prima tutti i valori a zero e poi sovrascrivo i dati opportuni
        // dato che lo faccio per la copia preferisco farlo ovunque per mantenere coerenza.
    }
    currentSize = -1;
}

//Costruttore copia
LaserScannerDriver::LaserScannerDriver(const LaserScannerDriver& otherObj) : angle_resolution{ otherObj.angle_resolution }, num_of_scan{ otherObj.num_of_scan }
{
    if (this == &otherObj) //Siamo nel costruttore allora this->array_ptr non è stato allocato
    {   
        array_ptr = new double* [BUFFER_DIM] {nullptr}; // this non è ancora inizializzato, occupo la memoria
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            array_ptr[i] = new double[num_of_scan] {0};
        }

        for (unsigned int i = 0; i < BUFFER_DIM; i++) //Copio ogni misurazione
        {
            for (unsigned int j = 0; j < num_of_scan; j++)
            {
                array_ptr[i][j] = otherObj.array_ptr[i][j];
            }
        }
        currentSize = otherObj.currentSize; //Aggiorno current size
    }
    else //Self assignment, allora inizializzo
    {
        //Self reference porta a del comportamento non definito (es, valori casuali dovuto all inizializzarzione della memoria)
        array_ptr = new double* [BUFFER_DIM] {nullptr};
        angle_resolution = 1;
        currentSize = -1;
        num_of_scan = 181; // 180 / 1 + 1, risparmio un conto e lo imposto a 181 manualmente      
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            array_ptr[i] = new double[num_of_scan] {0};
            // Nel costruttore di copia inizializzo prima tutti i valori a zero e poi sovrascrivo i dati opportuni
            // dato che lo faccio per la copia preferisco farlo ovunque per mantenere coerenza.
        }
    }

}

//Costruttore move
LaserScannerDriver::LaserScannerDriver(LaserScannerDriver&& otherObj) : angle_resolution{ otherObj.angle_resolution }, num_of_scan{ otherObj.num_of_scan }
{
    //VS avvisa che il costruttore potrebbe lanciare un eccezione ma non ne vedo motivo, per via dell'allocazione di memoria per ogni array
    //nel costruttore otherObj.array_ptr è sempre definito (anche il costruttore senza parametri alloca memoria)

    if (this == &otherObj) //Siamo nel costruttore allora this->array_ptr non è stato allocato
    {
        currentSize = otherObj.currentSize;
        array_ptr = otherObj.array_ptr; //Sposta il riferimento sul nuovo oggetto
        otherObj.array_ptr = nullptr;
        otherObj.currentSize = -1;
    }
    else //Self assignment, allora inizializzo
    {
        angle_resolution = 1;
        array_ptr = new double* [BUFFER_DIM] {nullptr};
        currentSize = -1;
        num_of_scan = 181; // 180 / 1 + 1, risparmio un conto e lo imposto a 181 manualmente 
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            array_ptr[i] = new double[num_of_scan] {0};
            // Nel costruttore di copia inizializzo prima tutti i valori a zero e poi sovrascrivo i dati opportuni
            // dato che lo faccio per la copia preferisco farlo ovunque per mantenere coerenza.
        }
    }
    
}
//Fine costruttori classe

/*
    La funzione get_distance che accetta un angolo (double) e ritorna il valore di distanza
    corrispondente a tale angolo (tenendo conto della risoluzione angolare) nella scansione
    più recente acquisita dal sensore – tale scansione non è eliminata dal buffer, e se l’angolo
    richiesto non è disponibile la funzione ritorna il valore di angolo più vicino;
*/

double LaserScannerDriver::get_distance(const double angleNumber) const
{
    if (!has_scan()) //has_scan deve essere utilizzato prima di ogni get per evitare eccezioni
    {
        throw ScanBufferIsEmpty();
    }

    if(angleNumber < 0 || angleNumber > 180)
	{
		throw InvalidAngleRequested();
	}

    unsigned int reqIndex = (unsigned int)std::round(angleNumber/ angle_resolution); //Calcolo l'indice della misurazione che corrisponde all'angolo
   
    if (reqIndex >= num_of_scan)
    {
        /*
            Se angleNumber == 180 e dalla divisione angleNumber/ angle_resolution
            risulta un numero con parte decimale > 0.5 round arrotonda alla "size" dell'array
            quindi riduco di uno l'indice ottenuto
        */
        reqIndex = num_of_scan - 1;
    }

    double reqMeasure = array_ptr[currentSize][reqIndex]; //Accedo direttamente alla misurazione e la restituisco
    return reqMeasure;
}

/*
    La funzione new_scan che accetta un vector<double> contenente i dati forniti dal sensore
    e lo memorizza nel buffer (sovrascrivendo il dato più vecchio se il buffer è pieno) – questa
    funzione esegue anche il controllo di dimensione: se i dati sono in numero minore del
    previsto, completa i dati mancanti a 0, se sono in numero maggiore, li taglia;
 */
void LaserScannerDriver::new_scan(const std::vector<double>& _newScan)
{
    //Viene aggiunto il nuovo scan in fondo alla coda e viene rimosso dalla lista lo scan più vecchio
    if (currentSize == BUFFER_DIM - 1) //Se abbiamo riempito tutto il buffer
    {
        //Rimuovi il meno recente, ovvero quello in posizione 0
        //Algoritmo O(N) ma ritengo sia più semplice da implementare e da modificare anziche implementare un array circolare completo
        delete[] array_ptr[0];//tutti gli elementi di array_ptr sono SEMPRE definiti (vedi costruttore) allora non devo effetuare controlli per delete
        for (unsigned int i = 1; i < BUFFER_DIM; i++) //Sposto ogni elemento dell'array indietro di una posizione
        {
            array_ptr[i-1] = array_ptr[i]; 
        }
        array_ptr[currentSize] = new double[num_of_scan] {0}; //Inizializzo l'ultimo elemento nuovamente per rispettare la regola
    }
    else currentSize++;

    for (unsigned int i = 0; i < _newScan.size() && i < num_of_scan; i++) //For eventualmente tronca valori in eccesso
    {
        array_ptr[currentSize][i] = _newScan[i];
    }

    for (unsigned int i = _newScan.size(); i < num_of_scan; i++)
    {
        array_ptr[currentSize][i] = 0;
    }
}

/*
    La funzione clear_buffer che elimina (senza ritornarle) tutte le letture salvate;
 */
void LaserScannerDriver::clear_buffer()
{
    for (unsigned int i = 0; i < BUFFER_DIM; i++)
    {
        delete[] array_ptr[i]; //Cancello e re inizializzo l'array di double
        array_ptr[i] = new double[num_of_scan] {0};
    }

    currentSize = -1;
}

/*
    La funzione get_scan che fornisce in output (in maniera opportuna) un vector<double>
    contenete la lettura più vecchia del sensore e la rimuove dal buffer;
 */
std::vector<double> LaserScannerDriver::get_scan()
{
    if (currentSize < 0)
    {
        throw ScanBufferIsEmpty();
    }

    std::vector<double> v;
    for (unsigned int i = 0; i < num_of_scan; i++) //Sposta ogni dato di scan dentro ad un vettore
    {
        v.push_back(array_ptr[0][i]);
    }

    delete[] array_ptr[0];//tutti gli elementi di array_ptr sono SEMPRE definiti (vedi costruttore) allora non devo effetuare controlli per delete
    for (unsigned int i = 1; i < currentSize + 1; i++) //Sposto ogni elemento dell'array indietro di una posizione
    {
        array_ptr[i - 1] = array_ptr[i];
    }

    array_ptr[currentSize] = new double[num_of_scan] {0}; //Inizializzo l'ultimo elemento nuovamente per rispettare la regola
    
    currentSize--; //Riduci currentSize

    return v;
}

LaserScannerDriver::~LaserScannerDriver()
{
    if (array_ptr)
    {
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            if (array_ptr[i])
            {
                delete[] array_ptr[i]; //Cancello l'array di double
            }    
        }
        delete[] array_ptr;

    }
    
    currentSize = -1;
    array_ptr = nullptr;
}

/*
    L’overloading dell’operator<< che stampa a schermo l’ultimo dato salvato (ma non lo
    rimuove dal buffer)
 */
std::ostream& operator<<(std::ostream& os, const LaserScannerDriver& object)
{
    unsigned int measureNumber = (unsigned int)(180 / object.get_angle_resolution() ) + 1;
    
    for (unsigned int i = 0; i < measureNumber; i++ )
    {
        double requestedAngle = i * object.get_angle_resolution();
        //os << "Angolo " << requestedAngle << ": " << object.get_distance( requestedAngle ) << "; " << std::endl;
        os << object.get_distance(requestedAngle) << " ";
    }
    os << std::endl << std::endl;
    return os;
}

LaserScannerDriver& LaserScannerDriver::operator=(const LaserScannerDriver& otherObj) //Operatore copy
{
    if (array_ptr == otherObj.array_ptr) return *this; //self assignment check!

    if (angle_resolution != otherObj.angle_resolution)
    {
        angle_resolution = otherObj.angle_resolution;
        num_of_scan = otherObj.num_of_scan;
    }

    currentSize = otherObj.currentSize;

    if (array_ptr) //Se esiste array_ptr inizializa i suoi elementi
    {
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            if (array_ptr[i]) delete[] array_ptr[i]; //Cancello e re inizializzo l'array di double
            array_ptr[i] = new double[num_of_scan] {0};
        }
    }
    else //Altrimenti inizializza il buffer
    {
        array_ptr = new double* [BUFFER_DIM] {nullptr};
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            array_ptr[i] = new double[num_of_scan] {0};
        }
    }
   
    for (unsigned int i = 0; i < BUFFER_DIM; i++) //Copio TUTTO, quando viene creato un nuovo oggetto tutti i puntatori vengono inizializzati a 0
    { //Quindi copiando sovrascrivo anche dati vecchi e non rischio segfault
        for (unsigned int j = 0; j < num_of_scan; j++)
        {
            (array_ptr[i][j]) = (otherObj.array_ptr[i][j]);
        }
    }

    return *this;
}

//Operatore move
LaserScannerDriver& LaserScannerDriver::operator=(LaserScannerDriver&& otherObj)
{
    if (array_ptr == otherObj.array_ptr) return *this; //self assignment check!

    if (angle_resolution != otherObj.angle_resolution)
    {
        angle_resolution = otherObj.angle_resolution;
        num_of_scan = otherObj.num_of_scan;
    }

    if (array_ptr) //Se esiste un buffer, lo cancello per liberare memoria, poi punto a quello nuovo
    {
        for (unsigned int i = 0; i < BUFFER_DIM; i++)
        {
            if(array_ptr[i]) delete[] array_ptr[i]; 
        }
        delete[] array_ptr;
    }

    currentSize = otherObj.currentSize;
    array_ptr = otherObj.array_ptr; //Sposta il riferimento sul nuovo oggetto
    otherObj.array_ptr = nullptr;
    otherObj.currentSize = -1;

    return *this;
}