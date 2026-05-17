#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>
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



// insert elements into list
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

void delete_e(int e, Polynomial *pL) {
    Polynomial::iterator it = pL->begin();
    for (it = pL->begin(); it != pL->end(); it++) {
        if (it->e == e) {
            pL->erase(it);
            return;
        }
    }
    cout << "The exponent does not appear.\n";
}


// calculate the  first derivative
Polynomial differentiate(Polynomial *pL) {
    Polynomial dL;
    Polynomial::iterator p;
    for (p = pL->begin(); p != pL->end(); p++) {
        double current_c = p->e * p->c; 
        int current_e = p->e - 1;       

        if (current_c == 0.0)
            continue;
        dL.push_back({current_c, current_e});   
    }
    
    return dL;
}

//calculate the function when x = specific value
double evaluate(double val, Polynomial *pL) {
    double sum =0;
    Polynomial::iterator p;
    for (p = pL->begin(); p != pL->end(); p++) 
        sum += p->c * pow(val, p->e);

    return sum;
}

// retrieve the cofficient at efficient value position
double coefficient(int e, Polynomial *pL) {
    Polynomial::iterator p;
    for (p = pL->begin(); p != pL->end(); p++) {
        if(p->e == e)
            return p->c; 
    }
    
    return 0;
}

int main(){
    	
    Polynomial L;
    insert(5, 3, &L); insert(5, 4, &L);
    insert(7, 0, &L); insert(-3, 2, &L);
    printPolynomial(&L);
    for (int e = 10; e >= 0; e--)
    printf("The coefficient of x^%d is: %.2f\n", e, coefficient(e, &L));
}