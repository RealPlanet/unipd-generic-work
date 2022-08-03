// Laboratorio3Programmazione.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <doubleVector.h>
#include <string>
#include <vector>

using namespace std;

/*
1.Create a program that:
    1.Allocates an array of 10 ints in the free store;
    2.Writes out of bound;
    3.Please check that the memory access out of bound causes the program to terminate.Does this always happen? Why?
    A: Spesso si andrà ad accedere ad un indirizzo del processo che ritornera un valore qualsiasi, avvolte con indirizzi abbastanza grandi può
        capitare che si tenti di accedere a memoria al di fuori del processo quindi il sistema operativo termina l'esecuzione
*/

int main()
{
    //Drill:
    //vector<int>* my_pointer = new vector<int>{0,1,2,3,4,5,6,7,8,9};
    //vector<int> my_vector =  {0,1,2,3,4,5,6,7,8,9};
    
    doubleVector my_v(10);
    my_v.safe_set(10.1, 1);
    
    cout << my_v[0] << endl;
    my_v[0] = 10;
    cout << my_v[0] << endl;
    
    for(int i = 0; i < 10; i++)
    {
        cout << my_v[i] << endl;
    }
    
}

/*
 * 1.What is a dereference operator and why do we need one?
 * Un dereference operator(*) ci permette di accedere ad indirizzi per ottenere il dato contenuto in essi.
 * 
 * 2.What is an address? How are memory addresses manipulated in C++?
 * Un indirizzo è una sequenze esadecimale che ci permette di accedere ad un dato contenuto in una posizione specifica nella memoria, in c++ è possibile manipolarli
 * attraverso i pointer(*) e le reference (&)
 * 
 * 3.What   information   about   a   pointed-to   object   does   a   pointer   have?   What   useful information does it lack?
 * I pointer contengono una quantità di informazioni limitata che riguarda solo al "tipo" del dato (int,double, ecc..)
 * 
 * 
 * 4.What can a pointer point to?
 * 
 * Un pointer punta ad una parte della memoria, esiste un pointer per ogni tipo definito, per esempio int o double
 * un pointer void* può puntare a una qualsiasi informazione ma si perde ogni abilità di manipolare il dato senza fare un cast(molto pericoloso).
 * 
 * 5.When do we need a pointer (instead of a reference or a named object)?
 * Un pointer ci permette di gestire la memoria più facilmente rispetto a reference o oggetti attraverso la gestione della memoria dinamica.
 * 
 * 6.What is a destructor? When do we want one?
 * Un distruttore è una funzione di una classe che viene chiamata automaticamente quando un oggetto deve essere cancellato, ne utilizziamo uno per liberare
 * la memoria che andiamo ad occupare con vari pointer creati con "new"
 * 
*/