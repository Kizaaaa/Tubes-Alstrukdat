/* File : utas.h */
/* PENJELASAN */

#ifndef UTAS_H
#define UTAS_H

/* Definisi Node : */
typedef int ElType;
// #include "../LinkedList/listlinier.h"
#include "../DateTime/datetime.h"
// #include "../ListDin/listdin.h"
#include "../EntryMachine/entrymachine.h"
#include "../../boolean.h"
typedef struct
{
    ElType indeks;
    Entry text;
    DATETIME time;
} UTAS;


typedef struct nodeLU *Address;
typedef struct nodeLU
{
    UTAS infoutas;
    Address next;
} NodeLU;


#define INDEKS(p) (p).indeks
#define TEXTUTAS(p) (p).text
#define TIME(p) (p).time
// #define INDEKS(p) ((p)->infoutas).indeks
// #define TEXTUTAS(p) ((p)->infoutas).text
// #define TIME(p) ((p)->infoutas).time
#define INFOUTAS(p) (p)->infoutas
#define NEXT(p) (p)->next

// UTAS linked list
// TWEET LINKED LIST di struct nya ada pointer menuju linked list utas


// Address newNodeLinked(ElType indeks, Entry teks, DATETIME time);
Address newNodeLinked(UTAS val);


#define FIRSTUTAS(p) (p)

typedef Address LINKEDUTAS;


void createUtas(UTAS *U, ElType idx, Entry teks, DATETIME time);
/* I.S sembarang */
/* F.S Terbentuk utas dengan komponen yang terdefinisi*/

void createLinkedUtas(LINKEDUTAS *l);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

int getLastIdxUtas(LINKEDUTAS l);
/* I.S list l terdefinisi */
/* F.S Mengirimkan indeks maksimum dalam suatu linkedlist l */

void readUtas(LINKEDUTAS* l);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void sambungUtas(LINKEDUTAS *l, ElType idx);

void insertFirstUtas(LINKEDUTAS *l, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di awal */

void insertLastUtas(LINKEDUTAS *l, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void insertUtasAt(LINKEDUTAS *l, ElType idx, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteFirstUtas(LINKEDUTAS *l);
/* I.S list l tidak kosong */
/* F.S Melakukan penghapusan elemen pertama bertipe UTAS  */

void deleteUtasAt(LINKEDUTAS *l, ElType idx);
/* I.S list l tidak kosong */
/* F.S Melakukan penghapusan elemen pada indeks idx tertentu bertipe UTAS  */

#endif