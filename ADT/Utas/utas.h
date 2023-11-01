#ifndef UTAS_H
#define UTAS_H
#include "../LinkedList/listlinier.h"
#include "../DateTime/datetime.h"
#include "../ListDin/listdin.h"
#include "../EntryMachine/entrymachine.h"
#include "../../boolean.h"
//UTAS linked list
//TWEET LINKED LIST di struct nya ada pointer menuju linked list utas
Address newNodeLinked(UTAS val);

/* Definisi Node : */
typedef int ElType;
typedef struct node* Address;
typedef struct {
    ElType indeks;
    Entry text;
    DATETIME time;
} UTAS;

typedef struct node {
    UTAS infoutas;
    Address next;
} LINKEDUTAS;

#define INDEKS(p) (p).indeks
#define TEXT(p) (p).text
#define TIME(p) (p).time

#define INFOUTAS(p) (p)->infoutas
#define NEXT(p) (p)->next

typedef Address LINKEDUTAS;

#define IDX_UNDEF (-1)
#define FIRSTUTAS(p) (p)

void createUtas(List* l){
    FIRSTUTAS(*l) = NULL;
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void readUtas(List l){
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(List l){
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(List* l ,ElType id_utas, ElType idx){
    
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(List* l ,ElType id_utas, ElType idx){
    
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */

#endif