#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// classe che gestisce i rapporti tra l'interfaccia e la gerarchia

#include <QMainWindow>
#include <sstream>
#include "interface.h"
#include "operando.h"
#include "matrice.h"
#include "matrq.h"
#include "scalare.h"
#include "pcompl.h"
#include "eccezioni.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    std::stringstream buffer;
    interface *interf;
    operando *mem, *temp;
    bool isQuad(matrice) const;             // funzione che controlla dopo l'input se la matrice è quadrata

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    operando* input();                      // funzione che gestisce l'input e torna un puntatore all'oggetto appena creato

signals:
    void display_changed(std::string);      //segnale emesso che indica quando è da cambiare il contenuto del display

public slots:
    void trasposta();                       // slot che gestisce il calcolo della trasposta di una matrice
    void determinante();                    // slot che gestisce il calcolo del determinante di una matrice
    void inversa();                         // slot che gestisce il calcolo dell'inversa di una matrice
    void coniuga();                         // slot che gestisce il calcolo del coniugato di un complesso
    void c_modulo();                        // slot che gestisce il calcolo del modulo di un complesso
    void c_potenza();                       // slot che gestisce il calcolo della potenza di un complesso
    void memorizza();                       // slot che gestisce il calcolo delle operazioni do somma, sottrazione e prodotto
};

#endif // MAINWINDOW_H
