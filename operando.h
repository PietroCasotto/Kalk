#ifndef OPERANDO_H
#define OPERANDO_H

#include <iostream>
#include <string>

class operando
{
public:
    operando();                                                             // costruttore senza parametri
    virtual ~operando();                                                    // distruttore virtuale
    virtual void print(std::ostream&)const =0;                              // funzione accessoria per la stampa
    virtual operando* operator*(operando const *) =0;                       // operatore di moltiplicazione virtuale puro
    virtual operando* operator+(operando const *) =0;                       // operatore di somma virtuale puro
    virtual operando* operator-(operando const *) =0;                       // operatore di sottrazione virtuale puro
    virtual std::string toString() const =0;                                // funzione che converte l'oggetto in una stringa per poterla stampare a video virtuale pura
    friend std::ostream& operator<<(std::ostream& os, const operando& obj); // dichiarazione di amicizia dell'operatore di output


};

#endif // OPERANDO_H
