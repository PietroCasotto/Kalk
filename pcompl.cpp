#include "pcompl.h"

// costruttore a 0, 1 o 2 parametri
pcompl::pcompl(const double & r, const double & i):
    reale(r),
    immaginaria(i)
{}

// costruttore di copia
pcompl::pcompl(const pcompl &c):
    reale(c.get_reale()),
    immaginaria(c.get_immaginaria())
{}

//  funzione accessoria per la stampa
void pcompl::print(std::ostream& os) const{
    os<<"( "<<reale;
    if (immaginaria>=0){
        os<<" +i "<<immaginaria<<" )";
    }
    else{
        os<<" -i "<<-1*immaginaria<<" )";
    }
    return;
}

// funzione per assegnare la parte reale
void pcompl::set_reale(const double & r){
    reale=r;
    return;
}

// funzione per assegnare la parte immaginaria
void pcompl::set_imm(const double & i){
    immaginaria=i;
    return;
}

// funzione per accedere alla parte reale
double pcompl::get_reale() const{
    return reale;
}

// funzione per accedere alla parte immaginaria
double pcompl::get_immaginaria() const{
    return immaginaria;
}

// operatore di moltiplicazione ereditato dalla classe base
pcompl* pcompl::operator *(operando const* o){
    const pcompl* im=dynamic_cast<const pcompl*>(o);
    const scalare* sca=dynamic_cast<const scalare*>(o);
    if (im!=0){
        double r1=reale, i1=immaginaria;
        double r2=im->get_reale(), i2=im->get_immaginaria();
        reale=(r1*r2)-(i1*i2);
        immaginaria=(r1*i2)+(i1*r2);
    }
    else if(sca!=0){
        reale=reale*sca->get_val();
        immaginaria=immaginaria*sca->get_val();
    }
    return this;
}

// operatore di somma ereditato dalla classe base
pcompl* pcompl::operator +(operando const* o){
    const pcompl* im=dynamic_cast<const pcompl*>(o);
    const scalare* sca=dynamic_cast<const scalare*>(o);
    if (im!=0){
        reale=reale+im->get_reale();
        immaginaria=immaginaria+im->get_immaginaria();
    }
    else if(sca!=0){
        reale=reale+sca->get_val();
    }
    return this;
}

// operatore di sottrazione ereditato dalla classe base
pcompl* pcompl::operator -(operando const* o){
    const pcompl* im=dynamic_cast<const pcompl*>(o);
    const scalare* sca=dynamic_cast<const scalare*>(o);
    if (im!=0){
        reale=reale-im->get_reale();
        immaginaria=immaginaria-im->get_immaginaria();
    }
    else if(sca!=0){
        reale=reale-sca->get_val();
    }
    return this;
}

// funzione che calcola il coniugato di un numero complesso
pcompl* pcompl::coniugato() {
    immaginaria= immaginaria*(-1);
    return this;
}

// funzione che calcola il modulo di un numero complesso
scalare pcompl::modulo() const{
    double c=reale*reale+immaginaria*immaginaria;
    return sqrt(c) ;
}

// funzione che calcola il quadrato di un numero complesso
pcompl* pcompl::potenza(){
    double n_r=reale, n_i=immaginaria;
    reale=(n_r*n_r)-(n_i*n_i);
    immaginaria=(n_r*n_i)+(n_i*n_r);
    return this;
}

// funzione che converte l'oggetto in una stringa per poterla stampare a video
std::string pcompl::toString() const{
    std::string buff="";
    buff.append("(");
    buff.append(" ");
    buff.append(std::to_string(reale));
    if (immaginaria>=0){
        buff.append(" +i ");
        buff.append(std::to_string(immaginaria));
    }
    else{
        buff.append(" -i ");
        buff.append(std::to_string(-1*immaginaria));
    }
    buff.append(" ");
    buff.append(")");
    return buff;
}

// operatore di output
std::ostream& operator<<(std::ostream& os, const pcompl& obj){
    obj.print(os);
    return os;
}

// operatore di input
std::istream& operator>>(std::istream& is, pcompl& obj)try{
    std::string ca;
    double real=0, imm=0;
    is>>ca;
    if(ca!="("){
        throw ecc_input();
    }
    is>>real;
    is>>ca;
    if(ca=="+i"){
        is>>imm;
    }
    else if(ca=="-i"){
        is>>imm;
        imm=-1*imm;
    }
    is>>ca;
    if (ca==")"){
        obj.set_reale(real);
        obj.set_imm(imm);
    }
    else{
        throw ecc_input();
    }

    return is;
}
catch(ecc_input()){
    throw;
}


