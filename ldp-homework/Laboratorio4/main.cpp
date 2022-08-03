#include <iostream>
#include <cstring>

using namespace std;

struct Link
{
public:
    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr): value{v}, prev{p}, succ{s} {}
    std::string value;
    Link* prev;
    Link* succ;
};

Link* find(Link* p, const std::string& s)
{
    while(p)
    {
        if(p->value == s) return p;
        p = p->succ;
    }
    
    return nullptr;
}

Link* add(Link* p, Link* n) //Inserisci N dopo P
{
    if(!n) return p;
    if(!p) return n;
    
    n->succ = p->succ;
    if(p->succ)p->succ->prev = n; //Aggiorna il precedente del nodo che si trovava dopo P (Ora si trova dopo N) se e solo se
    //ll nodo esiste effetivamente (Per esempio se si è in coda o si aggiunge un nodo ad una lista con un solo elemento)
    n->prev = p;
    p->succ = n;
    
    return n;
} 

Link* erase(Link* p)
{
    if(!p) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* insert(Link* p, Link* n) //Inserisci N prima P
{
    if(!n) return p;
    if(!p) return n;
    n->succ= p;
    if(p->prev) p->prev->succ= n;
    n->prev= p->prev;
    p->prev= n;
    return n;
}

void push_back(Link* p, Link* n) //Aggiungi N in coda a P
{
    if(!p)
    {
        return;
    }
    
    while(p->succ) //Scorro la lista fino all'ultimo nodo
    {
        p = p->succ;
    }
    
    p->succ = n;
    n->prev = p;
}

Link* pop_back(Link*& p) //Rimuovo un nodo in coda (N) a P
{
    Link* n = p;
    
    if( n->succ )
    {
        while(n->succ) //Scorro la lista fino all'ultimo nodo
        {
            n = n->succ;
        }
        
        if(n->prev)
        {
            n->prev->succ = nullptr; //Se esiste un precedente allora cancella il riferimento al successivo
            n->prev = nullptr;
        }
        //Necessito di un if perchè la testa non ha un precedente
    }
    else if( !n->prev )
    {
        p = nullptr;
    }
    
    return n;
}

/*
 * 
 * 
 * 
*/

bool is_palindrome(const string& s)
{
    int lchar = 0;
    int rchar = s.length()-1;
    
    while(lchar < rchar)
    {
        if(s[lchar] != s[rchar]) return false;
        
        rchar--;
        lchar++;
    }
    
    return true;
}

bool is_palindrome(const char s[], int length)
{
    
    for(int i = 0, j = length-1; i < j; i++)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        
        j--;
        i++;
    }
    return true;
}

bool is_palindrome(const char* first, const char* last)
{
    while(first < last)
    {
        if(*first != *last)
        {
            return false;
        }
        first++;
        last--;
    }
    return true;
}

int main(int argc, char **argv)
{
    Link* list = new Link("1");    
    push_back(list, new Link("2"));
    push_back(list, new Link("3"));
    push_back(list, new Link("4"));
    push_back(list, new Link("5"));
    push_back(list, new Link("6"));
    
    while(list)
    {
        Link* n = pop_back(list);
        cout<< n->value << endl;
        delete n;
    }
    
    return 0;
}