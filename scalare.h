#ifndef SCALARE_H
#define SCALARE_H

#include "operando.h"
#include <iostream>
#include "eccezioni.h"

class scalare : public operando
{
private:
    double reale;
public:
    scalare(const double & =0);                                             // costruttore a 0 o 1 parametro
    scalare(const scalare &);                                               // costruttore di copia
    double get_val() const;                                                 // funzione per accedere al valore
    void set_val(const double &) ;                                          // funzione per assegnare il valore
    virtual operando* operator*(operando const *);                          // operatore di moltiplicazione ereditato dalla classe base
    virtual operando* operator+(operando const *);                          // operatore di somma ereditato dalla classe base
    virtual operando* operator-(operando const *);                          // operatore di sottrazione ereditato dalla classe base
    virtual std::string toString() const;                                   // funzione che converte l'oggetto in una stringa per poterla stampare a video
    bool equals(const double &);                                            // funzione di uguaglianza con un double
    virtual void print(std::ostream&)const ;                                // funzione accessoria per la stampa
    friend std::ostream& operator<<(std::ostream& os, const scalare& obj);  // dichiarazione di amicizia dell'operatore di output
    friend std::istream& operator>>(std::istream& is, scalare& obj);        // dichiarazione di amicizia dell'operatore di input
};

#endif // SCALARE_H
