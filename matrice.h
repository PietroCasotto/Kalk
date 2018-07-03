#ifndef MATRICE_H
#define MATRICE_H

#include "operando.h"
#include <iostream>
#include <vector>
#include "scalare.h"
#include "eccezioni.h"
#include <vector>

class matrice: public operando{
private:
    int n_riga;
    int el_riga;
    double *dati;
public:
    matrice(const matrice & );                                              // costruttore di copia
    matrice(const int & =0,const int & =0);                                 // costruttore a 0, 1 o 2 parametri
    matrice(const int &, const int & , std::vector<double>);                // costruttore
    double* getDati() const;                                                // funzione per accedere ai dati della amtrice
    void setDati(double*);                                                  // funzione per assegnare i dati partendo da un array
    void setDati(const std::vector<double> &);                              // funzione per assegnare i dati partendo da un std::vector
    void setR(const int &);                                                 // funzione per assegnare il numero di righe
    void setC(const int &);                                                 // funzione per assegnare il numero di colonne
    int getR() const;                                                       // funzione per accedere al numero di righe
    int getC() const;                                                       // funzione per accedere al numero di colonne
    virtual ~matrice() ;                                                    // distruttore
    virtual matrice* operator*(operando const *);                           // operatore di moltiplicazione ereditato dalla classe base
    virtual matrice* operator+(operando const *);                           // operatore di somma ereditato dalla classe base
    virtual matrice* operator-(operando const *);                           // operatore di sottrazione ereditato dalla classe base
    virtual double operator[](const int &);                                 // operatore di accesso agli elemnti interni
    virtual double operator[](const int &) const;                           // operatore costante di accesso agli elemnti interni
    virtual void print(std::ostream&)const;                                 // funzione accessoria per la stampa
    virtual matrice* trasposta();                                           // funzione che calcola la trasposta  di una matrice
    virtual std::string toString() const;                                   // funzione che converte l'oggetto in una stringa per poterla stampare a video
    friend std::ostream& operator<<(std::ostream& os, const matrice& obj);  // dichiarazione di amicizia dell'operatore di output
    friend std::istream &operator>>(std::istream& is, matrice& obj );       // dichiarazione di amicizia dell'operatore di input
};

#endif // MATRICE_H
