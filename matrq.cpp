#include "matrq.h"

// costruttore a 0 o 1 parametro
matrq::matrq(const int & righe):
    matrice(righe, righe){}

// costruttore
matrq::matrq(const int & righe, std::vector<double> v):
    matrice(righe, righe, v)
{}

// costruttore di copia
matrq::matrq(const matrice & m):
    matrice(m.getC(), m.getC())
{
    for (int i=0; i<m.getC()*m.getR(); ++i){
        getDati()[i]=m.getDati()[i];
    }
}

// funzione che calcola la trasposta di una matrice
matrq* matrq::trasposta(){
    matrq *tmp=new matrq(this->getR());
    for(int i=0; i<this->getR(); ++i){
        for(int j=0; j<this->getR(); ++j){
            (tmp->getDati())[i+j*this->getR()]=(this->getDati())[j+i*this->getR()];
        }
    }
    delete this;
    return tmp;

}

// funzione che calcola il determinante di una matrice
scalare matrq::determinante() const{
    int n=getC();
    double L[n*n], A[n*n], det=1;
    for(int i=0; i<n*n; ++i){
        A[i]=getDati()[i];
    }
    for (int i=0; i<n*n; i++){
        L[i]=0;
    }
    for (int i=0; i<getC(); i++){
        L[i+n*i]=1;
    }
    for(int k=0; k<(n-1); k++){
        for(int i=k+1;i<n; i++){
            if (A[k+n*k]==0){
                throw ecc_math("divisione per zero");
            }
            L[i+n*k]=A[i+n*k]/A[k+n*k];
            for(int j=k; j<n; j++){
                A[i+n*j]=A[i+n*j]-L[i+n*k]*A[k+n*j];
            }
        }
    }
    for(int i=0; i<n; i++){
        det=det*A[i+n*i];
    }
    return det;
}

// funzione che calcola l'a trasposta'inversa di una matrice
matrq* matrq::inversa(){
    int n = getC(), dim=getR()*getC();
    double A[dim], B[dim], p, y;
    std::vector<double> m_tmp;
    for(int i=0;i<dim;++i){
        A[i]=getDati()[i];
    }
    scalare d=determinante();
    if(d.equals(0)){
        throw ecc_math("operazione non possibile");
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j){
                B[i*n+j]=1;
            }
            else{
                B[i*n+j]=0;
            }
        }
    }

    for(int k=0; k<n; ++k){
        p=A[k*n+k];
        for(int j=0;j<n;++j){
            A[k*n+j]=A[k*n+j]/p;
            B[k*n+j]=B[k*n+j]/p;
            }
        for(int i=0;i<n; ++i){
            if(i!=k){
                y=A[i*n+k];
                for(int j=0; j<n;++j){
                    A[i*n+j]=A[i*n+j]-A[k*n+j]*y;
                    if(A[i*n+j]<(1e-009) && A[i*n+j]>(-1e-009)){
                        A[i*n+j]=0;
                    }
                    B[i*n+j]=B[i*n+j]-B[k*n+j]*y;
                    if(B[i*n+j]<(1e-009) && B[i*n+j]>(-1e-009)){
                        B[i*n+j]=0;
                    }
                }
            }
        }
    }
    for(int i=0; i<dim; ++i){
        m_tmp.push_back(B[i]);
    }

    return new matrq(n, m_tmp);
}
