#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include <string>

// eccezione lanciabile dalle operazioni sui dati
class ecc_math{
private:
    std::string tipo;
public:
    ecc_math(std::string);
    std::string get_msg() const;
};

//eccezione lanciabile dagli operatori di input
class ecc_input{};

#endif // ECCEZIONI_H
