#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

typedef struct {
    double c; //coefficients
    int e;    //exponents
} ElementType;

typedef list<ElementType> Polynomial;      //declares the data structure Polynomial

void printPolynomial(Polynomial *pL) {       //prints the Polynomial pL
    if (pL->size() == 0)
        return;

    cout << std::fixed << setprecision(2);   //sets the decimal precision to 2, e.g.: 5.23
    
    Polynomial::iterator it = pL->begin();
    cout << '(' << it->c << ")x^" << it->e;
    
    it++;
    for (; it != pL->end(); it++)
        cout << " + (" << it->c << ")x^" << it->e;
    
    cout << endl;
}

void insert(double c,int e,Polynomial *pL){
    Polynomial::iterator p;   
    if (pL->size()==0)
    {
        pL->push_back({c, e});
        return;
    }

    for (p = pL->begin(); p != pL->end(); p++) {
       
        if (p->e == e)
        {
            p->c = c; 
            return;
        }
        else if(e> p->e)
        {   
            pL->insert( p, {c,e});
            return;
        }
    }    
    
    pL->push_back({c,e});
    return;
}
