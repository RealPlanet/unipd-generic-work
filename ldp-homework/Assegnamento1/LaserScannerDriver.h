#include <vector>
#include <iostream>

/*
    Fabio Ruscica
    Data: 02/12/2020
    V. 1
*/

/*
-Invarianti:
    angle_resolution compresa in un intervallo [0.1,1]

    array_ptr == double*[BUFFER_DIM] con tutti i "sotto-array" inizializzati
        Avere tutta la memoria allocata fin da subito può non essere la soluzione più ottimale ma ritengo semplifichi l'implementazione di new_scan e get_scan
        In ogni caso un buffer con risoluzione di 0.1 riempito completamente occupa circa 2MB, ritengo sia ragionevole per un BUFFER.

    BUFFER_DIM >= 0

    num_of_scan >= 0

    currentSize compresa in un intervallo [-1, BUFFER_DIM[
*/

class LaserScannerDriver
{
private:
    double** array_ptr = nullptr;
    double angle_resolution = 0; //Risoluzione angolare in gradi
    const unsigned int BUFFER_DIM = 10; //Dimensione buffer scan 
    unsigned int num_of_scan = 0; //Dimensione degli array di double salvati all'interno del buffer
    //num_of_scan definita come signed solamente per evitare l'avviso del compilatore di confronti tra signed/unsigned, effetivamente
    //non è possibile avere num_of_scan < 0 per via dei controlli precendenti su angle_resolution
    signed int currentSize = -1; //Ultimo array occupato
public:
    explicit LaserScannerDriver(const double _newResolution);
    LaserScannerDriver(const LaserScannerDriver& otherObj); //Costruttore copy
    LaserScannerDriver(LaserScannerDriver&& otherObj); //Costruttore move
    LaserScannerDriver();
    virtual ~LaserScannerDriver();

    double  get_angle_resolution() const { return angle_resolution; };// ritorna la risoluzione angolare dell'oggetto

    bool    has_scan() const { return (currentSize > -1); }; //has_scan fornito per poter svuotare completamente il buffer senza
    // sapere quanti misurazioni sono state fatte

    double  get_distance(const double angleNumber) const;
    void    new_scan(const std::vector<double>& _newScan);
    void    clear_buffer();
    std::vector<double> get_scan();

    //Eccezione generate dalla clase LaserScannerDriver
    class InvalidAngleResolution : public std::exception {};
    class InvalidAngleRequested : public std::exception {};
    class ScanBufferIsEmpty : public std::exception {};

    LaserScannerDriver& operator=(const LaserScannerDriver& otherObj); //Operatore copia
    LaserScannerDriver& operator=(LaserScannerDriver&& otherObj); //Operatore move
};

std::ostream& operator<<(std::ostream& os, const LaserScannerDriver& object);