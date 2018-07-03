#include "eccezioni.h"

ecc_math::ecc_math(std::string a):tipo(a)
{}

std::string ecc_math::get_msg()const{
    return tipo;
}
