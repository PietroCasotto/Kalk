#include "matrice.h"

// costruttore di copia
matrice::matrice(const matrice &o):
    n_riga(o.getR()),
    el_riga(o.getC()),
    dati(new double[o.getR()*o.getC()])
{
    for(int i=0; i<n_riga*el_riga; ++i){
        dati[i]=o[i];
    }
}

// costruttore a 0, 1 o 2 parametri
matrice::matrice(const int & righe, const int & colonne):
    n_riga(righe),
    el_riga(colonne),
    dati(new double[righe*colonne])
{
    for(int i=0; i<n_riga*el_riga; ++i){
        dati[i]=0;
    }
}

// costruttore
matrice::matrice(const int & righe, const int & colonne, std::vector<double> v):
    n_riga(righe),
    el_riga(colonne),
    dati(new double[righe*colonne])
{
    for(int i=0; i<righe*colonne; ++i){
        dati[i]=v[i];
    }
}

// funzione per accedere ai dati della amtrice
double* matrice::getDati()const{
    return dati;
}

// funzione per assegnare i dati partendo da un array
void matrice::setDati( double* d){
    dati=d;
}

// funzione per assegnare i dati partendo da un std::vector
void matrice::setDati(const std::vector<double> &v){
    dati=new double[getR()*getC()];
    for(int i=0; i<getR()*getC(); ++i){
        dati[i]=v[i];
    }

}

// funzione per assegnare il numero di righe
void matrice::setR(const int & d){
    el_riga=d;
}

// funzione per assegnare il numero di colonne
void matrice::setC(const int & d){
    n_riga=d;
}

// funzione per accedere al numero di righe
int matrice::getR() const{
    return el_riga;
}

//funzione per accedere al numero di colonne
int matrice::getC() const{
    return n_riga;
}

// distruttore
matrice::~matrice(){
    delete [] dati;
}

// operatore di moltiplicazione ereditato dalla classe base
matrice* matrice::operator *(operando const *x)try{
    const scalare *a=dynamic_cast<const scalare*>(x);
    const matrice *m=dynamic_cast<const matrice*>(x);
    if(a!=0){
        for(int i=0; i<getR()*getC(); ++i){
            dati[i]*=a->get_val();
        }
    }
    if(m!=0){
        throw ecc_math("operazione non implementata");
    }
    return this;
}
catch (...){
    throw;
}

// operatore di somma ereditato dalla classe base
matrice* matrice::operator +(operando const *sum)try{
    const scalare *a=dynamic_cast<const scalare*>(sum);
    const matrice *m=dynamic_cast<const matrice*>(sum);
    if(a!=0){
        for(int i=0; i<getR()*getC(); ++i){
            dati[i]+=a->get_val();
        }
    }
    if(m!=0){
        if((getR()!=m->getR())||(getC()!=m->getC())) throw ecc_math("operazione non possibile");
        for(int i=0; i<getR()*getC(); ++i){
            dati[i]+=m->getDati()[i];
        }
    }
    return this;
}
catch (...){
    throw;
}

// operatore di sottrazione ereditato dalla classe base
matrice* matrice::operator -(operando const *sum)try{
    const scalare *a=dynamic_cast<const scalare*>(sum);
    const matrice *m=dynamic_cast<const matrice*>(sum);
    if(a!=0){
        for(int i=0; i<getR()*getC(); ++i){
            dati[i]-=a->get_val();
        }
    }
    if(m!=0){
        if((getR()!=m->getR())||(getC()!=m->getC())) throw ecc_math("operazione non possibile");
        for(int i=0; i<getR()*getC(); ++i){
            dati[i]-=m->getDati()[i];
        }
    }
    return this;
}
catch (...){
    throw;
}

// operatore di accesso agli elemnti interni
double matrice::operator[](const int & i){
    return dati[i];
}

// operatore costante di accesso agli elemnti interni
double matrice::operator[](const int & i)const{
    return dati[i];
}

// funzione accessoria per la stampa
void matrice::print(std::ostream & os) const{
    os<<"{";
    for (int j=0; j<getC(); ++j){
        for(int i=0; i<getR(); ++i){
            os<<dati[i+j*el_riga];
            if(i<(getR()-1)){
                os<<" ";
            }
        }
        if(j<(getC()-1)){
            os<<" $ ";
        }
    }
    os<<"}";
}

// funzione che calcola la trasposta di una matrice
matrice* matrice::trasposta(){
    matrice *tmp=new matrice(el_riga, n_riga);
    for(int i=0; i<n_riga; ++i){
        for(int j=0; j<el_riga; ++j){
            (tmp->getDati())[i+j*n_riga]=dati[j+i*el_riga];
        }
    }
    delete this;
    return tmp;

}

// funzione che converte l'oggetto in una stringa per poterla stampare a video
std::string matrice::toString() const {
    std::string buff="";
    buff.append("{");
    buff.append(" ");
    for (int j=0; j<getC(); ++j){
        for(int i=0; i<getR(); ++i){
            buff.append(std::to_string(dati[i+j*el_riga]));
            if(i<(getR()-1)){
                buff.append(" ");
            }
        }
        if(j<(getC()-1)){
            buff.append(" $ ");
        }
    }
    buff.append(" ");
    buff.append("}");
    return buff;
}

// operatore di output
std::ostream& operator<<(std::ostream& os, const matrice& obj){
    obj.print(os);
    return os;
}

//funzione accessoria dell'operatore di input
int prossimo_char(std::istream& is){
    int p=is.peek();
    char f=p;
    while (f==' '){
        is.ignore(1);
        p=is.peek();
        f=p;
    }
    return f;
}

// operatore di input
std::istream& operator>>(std::istream& is, matrice& obj)try{
    int col=0, r=1, p;
    double el=0;
    char f;
    std::vector<double> val;
    is>>f;
    if(f!='{'){
        throw ecc_input();
    }
    is>>el;

    val.push_back(el);
    col++;
    p=prossimo_char(is);
    f=p;
    while ((isdigit(p))||(f=='-')){
        is>>el;
        val.push_back(el);
        col++;
        p=prossimo_char(is);
        f=p;
    }
    while (f!='}'){
        if (f=='$'){
            r++;
            is>>f;
            p=prossimo_char(is);
            f=p;
            for (int i=0; i<col; ++i){
                if ((isdigit(p))||(f='-')){
                    is>>el;
                    val.push_back(el);
                }
                else{
                    throw ecc_input();
                }
            p=prossimo_char(is);
            f=p;
            }
        }
        else{
            throw ecc_input();
        }

    }
    is>>f;

    obj.setR(r);
    obj.setC(col);
    obj.setDati(val);

    return is;
}
catch (ecc_input()){
    throw;
}


