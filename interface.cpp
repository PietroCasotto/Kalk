#include "interface.h"


// funzione definita per risolvere un problema di input-output sulla macchina virtuale perchè quel sistema
// accetta valori di tipo double con il punto come separatore tra parte intera e decimale, mentre la funnzione
// toString() dei double li converte con la virgola al posto del punto e dava problemi durante l'esecuzione
std::string interface::ReplaceAll(std::string &str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

// costruttore
interface::interface(QWidget *parent) :
    QWidget(parent){
    resize(400,300);
    l_input = new QPlainTextEdit();
    layout = new QGridLayout(this);
    ce = new QPushButton( "CE", this);
    connect(ce, SIGNAL(clicked()), this, SLOT(cancella()));
    p_comp = new QPushButton( "+ i", this);
    connect(p_comp, SIGNAL(clicked()), this, SLOT(add_pcomp()));
    m_comp = new QPushButton( "- i", this);
    connect(m_comp, SIGNAL(clicked()), this, SLOT(add_mcomp()));
    modulo = new QPushButton( "modulo", this);
    connect(modulo, SIGNAL(clicked()), parent, SLOT(c_modulo()));
    potenza = new QPushButton( "potenza", this);
    connect(potenza, SIGNAL(clicked()), parent, SLOT(c_potenza()));
    trasposta = new QPushButton( "trasposta", this);
    connect(trasposta, SIGNAL(clicked()), parent, SLOT(trasposta()));
    determ = new QPushButton( "det(X)", this);
    connect(determ, SIGNAL(clicked()), parent, SLOT(determinante()));
    inve = new QPushButton( "inv(X)", this);
    connect(inve, SIGNAL(clicked()), parent, SLOT(inversa()));
    coniugato = new QPushButton( "coniugato", this);
    connect(coniugato, SIGNAL(clicked()), parent, SLOT(coniuga()));
    d7 = new QPushButton( "7", this);
    connect(d7, SIGNAL(clicked()), this, SLOT(add_7()));
    d8 = new QPushButton( "8", this);
    connect(d8, SIGNAL(clicked()), this, SLOT(add_8()));
    d9 = new QPushButton( "9", this);
    connect(d9, SIGNAL(clicked()), this, SLOT(add_9()));
    molt = new QPushButton( "x", this);
    connect(molt, SIGNAL(clicked()), this, SLOT(moltiplicazione()));
    d4 = new QPushButton( "4", this);
    connect(d4, SIGNAL(clicked()), this, SLOT(add_4()));
    d5 = new QPushButton( "5", this);
    connect(d5, SIGNAL(clicked()), this, SLOT(add_5()));
    d6 = new QPushButton( "6", this);
    connect(d6, SIGNAL(clicked()), this, SLOT(add_6()));
    sot = new QPushButton( "-", this);
    connect(sot, SIGNAL(clicked()), this, SLOT(sottrazione()));
    d1 = new QPushButton( "1", this);
    connect(d1, SIGNAL(clicked()), this, SLOT(add_1()));    
    d2 = new QPushButton( "2", this);
    connect(d2, SIGNAL(clicked()), this, SLOT(add_2()));    
    d3 = new QPushButton( "3", this);
    connect(d3, SIGNAL(clicked()), this, SLOT(add_3()));    
    som = new QPushButton( "+", this);
    connect(som, SIGNAL(clicked()), this, SLOT(somma()));
    d0 = new QPushButton( "0", this);
    connect(d0, SIGNAL(clicked()), this, SLOT(add_0()));    
    punto = new QPushButton( ".", this);
    connect(punto, SIGNAL(clicked()), this, SLOT(add_punt()));    
    pm = new QPushButton( "-(x)", this);
    connect(pm, SIGNAL(clicked()), this, SLOT(sim_meno()));
    solve= new QPushButton("=", this);
    connect(solve, SIGNAL(clicked()), parent, SLOT(memorizza()));
    n_l = new QPushButton( "nuova linea", this);
    connect(n_l, SIGNAL(clicked()), this, SLOT(add_lin()));
    spazio = new QPushButton( "spazio", this);
    connect(spazio, SIGNAL(clicked()), this, SLOT(add_spa()));    
    matr = new QPushButton( "matrice", this);
    connect(matr, SIGNAL(clicked()), this, SLOT(add_mat()));    
    comp = new QPushButton( "complesso", this);
    connect(comp, SIGNAL(clicked()), this, SLOT(add_comp()));    
    connect(parent, SIGNAL(display_changed(std::string)), this, SLOT(aggiorna(std::string)));

    setLayout(layout);
    layout->addWidget(l_input   ,0,0,3,4);
    layout->addWidget(ce        ,3,3,1,1);
    layout->addWidget(p_comp    ,4,0,1,1);
    layout->addWidget(m_comp    ,4,1,1,1);
    layout->addWidget(modulo    ,4,2,1,1);
    layout->addWidget(potenza   ,4,3,1,1);
    layout->addWidget(trasposta ,5,0,1,1);
    layout->addWidget(determ    ,5,1,1,1);
    layout->addWidget(inve      ,5,2,1,1);
    layout->addWidget(coniugato ,5,3,1,1);
    layout->addWidget(d7        ,6,0,1,1);
    layout->addWidget(d8        ,6,1,1,1);
    layout->addWidget(d9        ,6,2,1,1);
    layout->addWidget(molt      ,6,3,1,1);
    layout->addWidget(d4        ,7,0,1,1);
    layout->addWidget(d5        ,7,1,1,1);
    layout->addWidget(d6        ,7,2,1,1);
    layout->addWidget(sot       ,7,3,1,1);
    layout->addWidget(d1        ,8,0,1,1);
    layout->addWidget(d2        ,8,1,1,1);
    layout->addWidget(d3        ,8,2,1,1);
    layout->addWidget(som       ,8,3,1,1);
    layout->addWidget(d0        ,9,0,1,1);
    layout->addWidget(punto     ,9,1,1,1);
    layout->addWidget(pm        ,9,2,1,1);
    layout->addWidget(solve     ,9,3,1,1);
    layout->addWidget(n_l       ,10,0,1,1);
    layout->addWidget(spazio    ,10,1,1,1);
    layout->addWidget(matr      ,10,2,1,1);
    layout->addWidget(comp      ,10,3,1,1);
}

// distruttore
interface::~interface(){
    delete layout;
    delete l_input;
    delete ce;
    delete p_comp;
    delete m_comp;
    delete modulo;
    delete potenza;
    delete trasposta;
    delete determ;
    delete inve;
    delete coniugato;
    delete d7;
    delete d8;
    delete d9;
    delete molt;
    delete d4;
    delete d5;
    delete d6;
    delete sot;
    delete d1;
    delete d2;
    delete d3;
    delete som;
    delete d0;
    delete punto;
    delete pm;
    delete solve;
    delete n_l;
    delete spazio;
    delete matr;
    delete comp;
}

// funzione per estrarre il testo inserito nell'input
std::string interface::getOperation() const{
    return l_input->toPlainText().toStdString();
}

// funzione per svuotare il campo com
void interface::clearComp(){
    com=false;
}

// funzione che contrlla il campo com
bool interface::has_comp() const{
    return com;
}

// slot che svuota l'input
void interface::cancella(){
    l_input->setPlainText("" );
    clearComp();
    pos=0;
}

// slot che inserisce il valore +i
void interface::add_pcomp(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc==')')&&(!has_comp())){
        a.insert(--(--a.end()), ' ');
        a.insert(--(--a.end()), '+');
        a.insert(--(--a.end()), 'i');
        a.insert(--(--a.end()), ' ');
        com=true;
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore -i
void interface::add_mcomp(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc==')')&&(!has_comp())){
        a.insert(--(--a.end()), ' ');
        a.insert(--(--a.end()), '-');
        a.insert(--(--a.end()), 'i');
        a.insert(--(--a.end()), ' ');
        com=true;
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 7
void interface::add_7(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '7');
    }
    else{
        a.append("7");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 8
void interface::add_8(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '8');
    }
    else{
        a.append("8");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 9
void interface::add_9(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '9');
    }
    else{
        a.append("9");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il simbolo della moltiplicazione
void interface::moltiplicazione(){
    a=l_input->toPlainText().toStdString();
        a.append(" ");
        a.append("*");
        a.append(" ");
        com=false;
        pos=a.size();
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 4
void interface::add_4(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '4');
    }
    else{
        a.append("4");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 5
void interface::add_5(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '5');
    }
    else{
        a.append("5");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 6
void interface::add_6(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '6');
    }
    else{
        a.append("6");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il simbolo della sottrazione
void interface::sottrazione(){
    a=l_input->toPlainText().toStdString();
        a.append(" ");
        a.append("-");
        a.append(" ");
        com=false;
        pos=a.size();
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 1
void interface::add_1(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '1');
    }
    else{
        a.append("1");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 2
void interface::add_2(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '2');
    }
    else{
        a.append("2");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 3
void interface::add_3(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '3');
    }
    else{
        a.append("3");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il simbolo della somma
void interface::somma(){
    a=l_input->toPlainText().toStdString();
        a.append(" ");
        a.append("+");
        a.append(" ");
        com=false;
        pos=a.size();
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il valore 0
void interface::add_0(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '0');
    }
    else{
        a.append("0");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il punto
void interface::add_punt(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '.');
    }
    else{
        a.append(".");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce il simbolo -
void interface::sim_meno(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), '-');
    }
    else{
        a.insert(pos, "-");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce una nuova linea nella matrice
void interface::add_lin(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), ' ');
        a.insert(--(--a.end()), '$');
        a.insert(--(--a.end()), ' ');
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce lo spazio
void interface::add_spa(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc=='}')||(lc==')')){
        a.insert(--(--a.end()), ' ');
    }
    else{
        a.append(" ");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce i simboli della matrice
void interface::add_mat(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc!='}')&&(lc!=')')){
        a.insert(a.end(), ' ');
        a.insert(a.end(), '}');
        a.insert(pos, " ");
        a.insert(pos, "{");
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce i simboli del complesso
void interface::add_comp(){
    a=l_input->toPlainText().toStdString();
    char lc=a.back();
    if ((lc!='}')&&(lc!=')')){
        a.insert(pos, " " );
        a.insert(pos, "(");
        a.insert(a.end(), ' ');
        a.insert(a.end(), ')');
    }
    l_input->setPlainText(QString::fromStdString(a));
}

// slot che inserisce nell'input il contenuto della stringa var
void interface::aggiorna(std::string var ){
    var=ReplaceAll(var, ",", ".");
    l_input->setPlainText(QString::fromStdString(var));
}

