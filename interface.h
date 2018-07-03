#ifndef INTERFACE_H
#define INTERFACE_H

//classe che genera l'interfaccia grafica

#include <QGridLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QWidget>
#include <iostream>
#include <QApplication>
#include <string>

class interface : public QWidget
{
    Q_OBJECT
private:
    bool com=false;
    std::string a="";
    std::size_t pos=0;
    QGridLayout *layout;
    QPlainTextEdit *l_input;
    QPushButton *ce;
    QPushButton *p_comp;
    QPushButton *m_comp;
    QPushButton *modulo;
    QPushButton *potenza;
    QPushButton *trasposta;
    QPushButton *determ;
    QPushButton *inve;
    QPushButton *coniugato;
    QPushButton *d7;
    QPushButton *d8;
    QPushButton *d9;
    QPushButton *molt;
    QPushButton *d4;
    QPushButton *d5;
    QPushButton *d6;
    QPushButton *sot;
    QPushButton *d1;
    QPushButton *d2;
    QPushButton *d3;
    QPushButton *som;
    QPushButton *d0;
    QPushButton *punto;
    QPushButton *pm;
    QPushButton *solve;
    QPushButton *n_l;
    QPushButton *spazio;
    QPushButton *matr;
    QPushButton *comp;
    static std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to);

public:
    explicit interface(QWidget *parent = 0);
    ~interface();
    std::string getOperation() const;   // funzione per estrarre il testo inserito nell'input
    void clearComp();                   // funzione per svuotare il campo com
    bool has_comp() const;              // funzione che contrlla il campo com

public slots:
    void cancella();                    // slot che svuota l'input
    void add_pcomp();                   // slot che inserisce il valore +i
    void add_mcomp();                   // slot che inserisce il valore -i
    void add_7();                       // slot che inserisce il valore 7
    void add_8();                       // slot che inserisce il valore 8
    void add_9();                       // slot che inserisce il valore 9
    void moltiplicazione();             // slot che inserisce il simbolo della moltiplicazione
    void add_4();                       // slot che inserisce il valore 4
    void add_5();                       // slot che inserisce il valore 5
    void add_6();                       // slot che inserisce il valore 6
    void sottrazione();                 // slot che inserisce il simbolo della sottrazione
    void add_1();                       // slot che inserisce il valore 1
    void add_2();                       // slot che inserisce il valore 2
    void add_3();                       // slot che inserisce il valore 3
    void somma();                       // slot che inserisce il simbolo della somma
    void add_0();                       // slot che inserisce il valore 0
    void add_punt();                    // slot che inserisce il punto
    void sim_meno();                    // slot che inserisce il simbolo -
    void add_lin();                     // slot che inserisce una nuova linea nella matrice
    void add_spa();                     // slot che inserisce lo spazio
    void add_mat();                     // slot che inserisce i simboli della matrice
    void add_comp();                    // slot che inserisce i simboli del complesso
    void aggiorna(std::string =" ");    // slot che inserisce nell'input il contenuto della stringa var
};

#endif // INTERFACE_H
