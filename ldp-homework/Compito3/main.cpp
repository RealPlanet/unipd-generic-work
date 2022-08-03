#include <iostream>
#include <string.h>

#include <Rational.h>
#include <DoubleVector.h>

using namespace std;

char* strdup(const char* originalString);
int countCharacters(const char* string);
char* findx(const char* s, const char* x);
int strcmp(const char* s1, const char* s2);

int main(int argc, char **argv)
{
    // ES 1 Tester : Creo una stringa, la duplico e poi modifico l'originale
    char originalString[] = {"Ciao"}; //Ciao + \0
    char* dupedString = strdup(originalString);
    cout << dupedString << endl;
    cout << originalString << endl;
    //Fine ES 1 Tester
    //ES 2 Tester: Creo una c-style string e una sottostringa
    char xString[] = {"ITALIA"};
    int xStringSize = 6;
    char sString[] = {"VIVA L'ITALIA!"};
    
    char* ptr = findx(sString, xString);
    
    if(ptr)
    {
        for(int i = 0; i < xStringSize; i++)
            cout << *(ptr + i);
        cout << endl;
    }
    else
    {
        cout << "Sub-String non trovata!" << endl;
    }
    //Fine ES 2 Tester
    
    //ES 3 Tester
    char s1String[] = {"ITALIA"};
    char s2String[] = {"ITALIA"};
    char s3String[] = {"FRANCIA"};
    char s4String[] = {"ITALIO"};
    
    cout << "Confronto ITALIA con ITALIA:" << endl;
    cout << strcmp(s1String, s2String) << endl;
    cout << "Confronto ITALIA con FRANCIA:" << endl;
    cout << strcmp(s1String, s3String) << endl;
    cout << "Confronto FRANCIA con ITALIA:" << endl;
    cout << strcmp(s3String, s1String) << endl;
    cout << "Confronto ITALIO con ITALIA:" << endl;
    cout << strcmp(s4String, s2String) << endl;
    cout << "Confronto ITALIA con ITALIO:" << endl;
    cout << strcmp(s2String, s4String) << endl;
    // Fine ES 3 Tester
    // ES 4 Tester
    // Fine ES4 Tester
    return 0;
}

/*
 * 1.   Write   a   function,   char*   strdup(const   char   *),   that   copies   a   C-style   string   into   memory   it allocates on the free store.
 * Do not use any standard library functions. Do not use subscripting(cioè l’operatore []): use the dereference operator * instead
 */
char* strdup(const char* originalString)
{
    int charNumber = countCharacters(originalString); //La funzione non riceve una lunghezza come parametro quindi dobbiamo calcolarla sul momento!
    char* dupString = new char[charNumber + 1]{}; //Aggiungo 1 al numero di caratteri per poter copiare il null terminator (\0)
    for(int i = 0; i < charNumber; i++)
    {
        *(dupString + i) = *(originalString + i); //Copio ogni carattere senza usare []
    }
    
    return dupString;
}

int countCharacters(const char* string) //Conta i caratteri in una string C-style, si ferma quando trova \0 (null terminator)
{
    int count = 0;
    while(*(string + count) != '\0')
    {
        count++;
    }
    return count;
}
/*
 * 2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
 * Do not use any standard library functions.
 * Do not use subscripting: use thedereference operator * instead.
 */
char* findx(const char* s, const char* x)
{
    bool found = false;

    int charlengthS = countCharacters(s);
    int charlengthX = countCharacters(x);

    if(charlengthX > charlengthS) return nullptr;

    int length = charlengthS - charlengthX + 1; //Non mi è possibile trovare la sottostringa negli nei caratteri charlengthS - length della string quindi non li controllo

    for(int i = 0; i < length; i++) //Scorri la stringa s
    {
        if(*(s + i) == *x) //Se il carattere s+i corrisponde al primo carattere di X allora verifica se è una substring
        {
            for(int j = 1; j < charlengthX; j++)
            {
                if( *(s + i + j) == *(x + j) ) //Se i due caratteri corrispondono continua...
                {
                    if(j+1 == charlengthX)//Se siamo arrivati alla fine della string X allora abbiamo trovato la sottostringa
                    {
                        found = true;
                        break;
                    }
                }
                else
                {
                    i+= j - 1; //Salta i caratteri gia controllati
                    break;
                }
            }
            
            if(found) //Abbiamo trovato la substring allora restituiamo il pointer al primo carattere
            {
                return (char*)(s+i); //Restituisci il pointer del primo carattere della sottostringa
            }
        }
    }

    return nullptr;
}

/*
3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style string.
 Let it return a negative number if s1 is lexicographically before s2, zero if s1 equals s2, and a positivenumber if s1 is lexicographically after s2.
 Do not use any standard library functions. Do not usesubscripting: use the dereference operator * instead.
*/
int strcmp(const char* s1, const char* s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
        {
            break;
        }
        
        s1++;
        s2++;
    }
    
    return *s1-*s2;
}
 
