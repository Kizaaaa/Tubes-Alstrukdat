/* File : utas.h */
/* PENJELASAN */

#ifndef UTAS_H
#define UTAS_H
#include "../LinkedList/listlinier.h"
#include "../DateTime/datetime.h"
// #include "../ListDin/listdin.h"
#include "../EntryMachine/entrymachine.h"
#include "../Kicau/kicau.h"
#include "../../boolean.h"

/* Definisi Node : */
typedef int ElType;
typedef struct
{
    ElType indeks;
    Entry text;
    DATETIME time;
} UTAS;

#define INDEKS(p) (p).indeks
#define TEXT(p) (p).text
#define TIME(p) (p).time

typedef struct node *Address;
typedef struct node
{
    UTAS infoutas;
    Address next;
} LINKEDUTAS;

#define INFOUTAS(p) (p)->infoutas
#define NEXT(p) (p)->next

// UTAS linked list
// TWEET LINKED LIST di struct nya ada pointer menuju linked list utas
Address newNodeLinked(UTAS val);

#define IDX_UNDEF (-1)
#define FIRSTUTAS(p) (p)

void createUtas(LINKEDUTAS *l,Kicau Twt);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void readUtas(LINKEDUTAS l);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(LINKEDUTAS l);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS *val);
/* I.S list l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */

#endif