#include "operando.h"

// costruttore senza parametri
operando::operando()
{}

// distruttore virtuale
operando::~operando(){

}

// operatore di output
std::ostream& operator<<(std::ostream& os, const operando& obj){
    obj.print(os);
    return os;
}
