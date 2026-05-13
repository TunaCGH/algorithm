
double coefficient(int e, Polynomial *pL) {
    Polynomial::iterator p;
    for (p = pL->begin(); p != pL->end(); p++) {
        if(p->e == e)
            return p->c; 
    }
    
    return 0;
}
