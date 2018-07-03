#include "scalare.h"

// costruttore a 0 o 1 parametro
scalare::scalare(const double & i):reale(i)
{}

// costruttore di copia
scalare::scalare(const scalare& s):reale(s.get_val()){}

// funzione per accedere al valore
double scalare::get_val() const{
    return reale;
}

// funzione per assegnare il valore
void scalare::set_val(const double & i){
    reale=i;
}

// operatore di moltiplicazione ereditato dalla classe base
operando* scalare::operator*(operando const * i){
    const scalare *a=dynamic_cast<const scalare*>(i);
    if(a!=0){
        reale*=a->get_val();
    }
    else{
        throw ecc_math("operazione non implementata");
    }
    return this;
}

// operatore di somma ereditato dalla classe base
operando* scalare::operator+(operando const * i){
    const scalare *a=dynamic_cast<const scalare*>(i);
    if(a!=0){
        reale+=a->get_val();
    }
    else{
        throw ecc_math("operazione non implementata");
    }
    return this;
}

// operatore di sottrazione ereditato dalla classe base
operando* scalare::operator-(operando const * i){
    const scalare *a=dynamic_cast<const scalare*>(i);
    if(a!=0){
        reale-=a->get_val();
    }
    else{
        throw ecc_math("operazione non implementata");
    }
    return this;
}

// funzione che converte l'oggetto in una stringa per poterla stampare a video
std::string scalare::toString() const{
    return std::to_string(reale);
}

// funzione di uguaglianza con un double
bool scalare::equals(const double & c){
    return reale==c;
}

// funzione accessoria per la stampa
void scalare::print(std::ostream & os) const{
    os<<get_val();
}

// operatore di output
std::ostream& operator<<(std::ostream& os, const scalare& obj){
    obj.print(os);
    return os;
}

// operatore di input
std::istream& operator>>(std::istream& is, scalare& obj){
    std::string ca;
    double real=0;
    is>>real;
    obj.set_val(real);
    return is;
}

