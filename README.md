# Kalk
Piccola calcolatrice sulle matrici, matrici quadrate e numeri complessi sviluppata in C++ con libreire Qt per l'interfaccia grafica

Questa piccola calcolatrice è stata sviluppata come progetto di un corso di Programmazione ad Oggetti per l'università, quindi non è perfetta e non punta ad esserlo. Lo scopo del progetto era creare, appunto, una calcolatrice che efettuava calcoli su tipi di dati definiti da noi, io ho implementato le matrici, matrici quadrate e complessi in forma algebrica (modificata per comodità di implementazione)

Per ogni tipo di dato sono state implementate le operazioni di somma, moltiplicazione e sottrazione con uno scalare e con elementi dello stesso tipo. Unica eccezione è la moltiplicazione di due matrici, che non è stata (ancora) implementata.
Le operazioni sono state implementate solo nel verso Operando->Scalare e non viceversa, ma la questione è in fase di sviluppo.
Inoltre per le matrici è stata inserita l'operazione di trasposta, per le matrici quadrate anche il determinante e l'inversa.
Per i complessi è stato inserito il coniugato, il modulo e l'elevamento a potenza.

La gerarchia viene riportata anche in Java con una classe di test, dove vengono mostrate tutte le operazioni possibili.

PS: Se qualcuno vuole/può aiutarmi a fare l'interfaccia grafica simile a quella già realizzata in C++ anche per Java mi farebbe un favore


Manuale utente della GUI:

Il programma si apre direttamente sull'unica schermata della calcolatrice. Qui sono presenti dei QPushButton che aggiungono il carattere alla fine del testo presente nell'apposito spazio oppure inseriscono la sintassi necessaria nel posto corretto.
Eventualmente i dati si possono scrivere direttamente da tastiera, ricordando di inserire sempre uno spazio tra due simboli diversi. 
Le matrici iniziano sempre con "{" seguita da uno spazio e finiscono con "}" preceduta da uno spazio, i valori di ogni elemento sono separati da uno spazio e le righe sono separate dal carattere "$" sempre preceduto e seguito da uno spazio. 
I numeri complessi iniziano con "(" seguita da uno spazio, come separazione tra la parte reale e quella immaginaria ci sono le stringhe "+i" oppure "-i" a segnalare il segno della parte immaginaria, e infine termina sempre col carattere ")" preceduto da uno spazio.
Le operazioni con un solo operando non hanno rispettivo grafico, quindi bisogna usare i tasti predisposti, mentre la somma, la sottrazione e il prodotto usano i simboli standard, rispettivamente "+", "-" e "*", preceduti e seguiti da uno spazio.
Le operazioni di somma, sottrazione e prodotto per uno scalare sono state definite in un unico verso, ovvero prima del simbolo dell'operazione c'è un operando e dopo uno scalare, non il contrario. 

Istruzioni per la compilazione:

Il progetto contiene alcune parti di codice funzionanti solo se la versione di C++ utilizzata é superiore alla 11 quindi nel file .pro deve comparire la seguente stringa per la configurazione:

CONFIG += c++11

e anche la seguente stringa, perché per l'interfaccia grafica utilizza widget della libreria Qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
