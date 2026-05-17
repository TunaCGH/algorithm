#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

typedef struct {
    double c; //coefficients
    int e;    //exponents
} ElementType;

typedef vector<ElementType> Polynomial;      //declares the data structure Polynomial

void printPolynomial(Polynomial *pL) {       //prints the Polynomial pL
    if (pL->size() == 0)
        return;

    cout << fixed << setprecision(2);   //sets the decimal precision to 2, e.g.: 5.23
    cout << '(' << (*pL)[0].c << ")x^" << (*pL)[0].e;
        
    for (int i = 1; i < pL->size(); i++)
        cout << setprecision(2) << " + " << '(' << (*pL)[i].c << ")x^" << (*pL)[i].e;
    
    cout << endl;
}

void insert(double c,int e,Polynomial *pL){
    if ((*pL).size() == 0)
    {
        (*pL).insert((*pL).begin(), {c,e});
        return;
    }
    for(int i = 0; i<(*pL).size();i++){
       
        if ((*pL)[i].e == e)
        {
            (*pL)[i].c = c; 
            return;
        }
        else if(e> (*pL)[i].e)
        {   
            (*pL).insert((*pL).begin() +i, {c,e});
            return;
        }
        
    }
    (*pL).push_back({c,e});
    return;
}

void delete_e(int e,Polynomial *pL){
    for(int i = 0; i<(*pL).size();i++)
        if((*pL)[i].e == e)
        {
            (*pL).erase((*pL).begin()+i);
            return;
        }
    cout<<"The exponent does not appear."<<endl;
}


Polynomial differentiate(Polynomial *pL){
    Polynomial newList;
    for (int i = 0; i < pL->size(); i++){
        double current_c = (*pL)[i].e * (*pL)[i].c;
        int current_e = (*pL)[i].e -1;
    
        if(current_c == 0.0)
            continue;
        newList.push_back({current_c, current_e});   
    }
    return newList;
}


double evaluate(double val, Polynomial *pL) {
    double sum =0;
    for (int i = 0; i < pL->size(); i++) {
        sum += (*pL)[i].c * pow(val, (*pL)[i].e);
    }
    
    return sum;
}


double coefficient(int e, Polynomial *pL) {
    
    for (int i = 0; i < pL->size(); i++) {
        if((*pL)[i].e == e)
            return (*pL)[i].c; 
    }
    
    return 0;
}

int main(){

    Polynomial L;
insert(5, 3, &L);
insert(4, 4, &L);
insert(7, 0, &L);
insert(-3, 2, &L);
printPolynomial(&L);
}