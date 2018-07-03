#include "mainwindow.h"


// funzione che controlla dopo l'input se la matrice è quadrata
bool MainWindow::isQuad(matrice m) const{
    return m.getC()==m.getR();
}

// costruttore
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    interf(new interface(this)),
    mem(0),
    temp(0)
{
    resize(400,300);
}

// distruttore
MainWindow::~MainWindow()
{
    delete interf;
    delete mem;
    delete temp;
}


// funzione che gestisce l'input e torna un puntatore all'oggetto appena creato
operando* MainWindow::input()try{
    pcompl comp;
    matrice mat=(0);
    int c=buffer.peek();
    double d;
    char f=c;
    while (f==' '){
        buffer.ignore(1);
        c=buffer.peek();
        f=c;
    }
    if (f=='{'){
        buffer>>mat;
        if (isQuad(mat)){
            return new matrq(mat);
        }
        return new matrice(mat);
    }
    else if(f=='('){
        buffer>>comp;
        return new pcompl(comp);
    }
    else{
        if(isdigit(c)){
            buffer>>d;
            return new scalare(d);
        }
        else{
            return new scalare();
        }

    }

    return new scalare();
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
    return new scalare();
}

// slot che gestisce il calcolo della trasposta di una matrice
void MainWindow::trasposta()try{
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    mem=input();
    matrice *p=dynamic_cast<matrice*>(mem);
    if (p!=0){
        mem=p->trasposta();
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.str("");
    buffer.clear();
    buffer.flush();
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}

// slot che gestisce il calcolo  del determinante di una matrice
void MainWindow::determinante()try{
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    matrq *p=dynamic_cast<matrq*>(mem);
    if (p!=0){
        scalare t=p->determinante();
        delete mem;
        mem=new scalare(t);
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.clear();
    buffer.str("");
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}
catch (ecc_math e){
    emit display_changed(e.get_msg());
}

// slot che gestisce il calcolo dell'inversa di una matrice
void MainWindow::inversa()try {
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    matrq *p=dynamic_cast<matrq*>(mem);
    if (p!=0){
        mem=p->inversa();
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.clear();
    buffer.str("");
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}
catch (ecc_math e){
    emit display_changed(e.get_msg());
}

// slot che gestisce il calcolo del coniugato di un complesso
void MainWindow::coniuga()try{
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    pcompl*c=dynamic_cast<pcompl*>(mem);
    if(c!=0){
        mem=c->coniugato();
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.clear();
    buffer.str("");
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}

// slot che gestisce il calcolo del modulo di un complesso
void MainWindow::c_modulo()try{
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    pcompl *c=dynamic_cast<pcompl*>(mem);
    if (c!=0){
        scalare t=c->modulo();
        delete mem;
        mem=new scalare(t);
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.clear();
    buffer.str("");
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}

// slot che gestisce il calcolo della potenza di un complesso
void MainWindow::c_potenza()try{
    buffer<<interf->getOperation();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    pcompl*c=dynamic_cast<pcompl*>(mem);
    if(c!=0){
        mem=c->potenza();
        emit display_changed(mem->toString());
    }
    else{
        emit display_changed("operazione non possibile");
    }
    buffer.str("");
    buffer.clear();
}
catch(ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}

// slot che gestisce il calcolo delle operazioni do somma, sottrazione e prodotto
void MainWindow::memorizza() try{
    char o;
    int p;
    buffer<<interf->getOperation();

    buffer.clear();
    delete mem;
    delete temp;
    temp=0;
    mem=input();
    p=buffer.peek();
    o=p;
    while ((o==' ')&&(!buffer.eof())){
        buffer.ignore(1);
        p=buffer.peek();
        o=p;
    }
    if (!buffer.eof()){
        buffer>>o;
        temp=input();
        if(o=='+'){
            *mem+temp;
        }
        else if (o=='-'){
            *mem-temp;
        }
        else if (o=='*'){
            *mem*temp;
        }
        else{
            emit display_changed("operazione non possibile");
        }
    }
    buffer.str("");
    buffer.clear();

    emit display_changed(mem->toString());
}
catch (ecc_input){
    mem=0;
    temp=0;
    emit display_changed("errore sui dati in input");
}
catch (ecc_math e){
    emit display_changed(e.get_msg());
}
