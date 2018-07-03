#ifndef QMATR_H
#define QMATR_H

#include "matrice.h"
#include "scalare.h"
#include "eccezioni.h"
#include <vector>

class matrq : public matrice
{
public:
    matrq(const int & =0);                      // costruttore a 0 o 1 parametro
    matrq(const int &, std::vector<double>);    // costruttore
    matrq(const matrice &);                     // costruttore di copia
    virtual matrq* trasposta();                 // funzione che calcola la trasposta di una matrice
    scalare determinante() const;               // funzione che calcola il determinante di una matrice
    matrq* inversa();                           // funzione che calcola l'a trasposta'inversa di una matrice
};

#endif // QMATR_H
