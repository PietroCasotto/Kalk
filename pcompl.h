#ifndef PCOMPL_H
#define PCOMPL_H

#include "operando.h"
#include "scalare.h"
#include <math.h>
#include "eccezioni.h"

class pcompl : public operando
{
private:
    double reale, immaginaria;
public:
    pcompl(const double & =0, const double & =0);                           // costruttore a 0, 1 o 2 parametri
    pcompl(const pcompl &);                                                 // costruttore di copia
    virtual void print(std::ostream&)const;                                 // funzione accessoria per la stampa
    void set_reale(const double &);                                         // funzione per assegnare la parte reale
    void set_imm(const double &);                                           // funzione per assegnare la parte immaginaria
    double get_reale() const;                                               // funzione per accedere alla parte reale
    double get_immaginaria() const;                                         // funzione per accedere alla parte immaginaria
    virtual pcompl* operator*(operando const *);                            // operatore di moltiplicazione ereditato dalla classe base
    virtual pcompl* operator+(operando const *);                            // operatore di somma ereditato dalla classe base
    virtual pcompl* operator-(operando const *);                            // operatore di sottrazione ereditato dalla classe base
    virtual pcompl* coniugato();                                            // funzione che calcola il coniugato di un numero complesso
    virtual scalare modulo() const;                                         // funzione che calcola il modulo di un numero complesso
    virtual pcompl* potenza();                                              // funzione che calcola il quadrato di un numero complesso
    virtual std::string toString() const;                                   // funzione che converte l'oggetto in una stringa per poterla stampare a video
    friend std::ostream& operator<<(std::ostream& os, const pcompl& obj);   // dichiarazione di amicizia dell'operatore di output
    friend std::istream& operator>>(std::istream& is, pcompl& obj );        // dichiarazione di amicizia dell'operatore di input
};

#endif // PCOMPL_H
