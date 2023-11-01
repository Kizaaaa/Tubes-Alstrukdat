#include "../LinkedList/listlinier.h"
#include "../DateTime/datetime.h"
#include "../ListDin/listdin.h"
#include "../EntryMachine/entrymachine.h"
#include "../Kicau/kicau.h"
#include "../../boolean.h"

#include <stdio.h>
#include <stdlib.h>
//UTAS linked list
//TWEET LINKED LIST di struct nya ada pointer menuju linked list utas


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


Address newNodeLinked(UTAS val){
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFOUTAS(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

typedef Address LINKEDUTAS;

#define IDX_UNDEF (-1)
#define FIRSTUTAS(p) (p)

void createUtas(LINKEDUTAS* l){
    FIRSTUTAS(*l) = NULL;
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void readUtas(LINKEDUTAS l){
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    printf("Masukkan kicauan:\n");
    Entry A;
    STARTENTRY();
    //adt var adt entry
    A = currentEntry;
    
    if (CHECKVALIDTWEET(A))
    {
        // proses jika tweet valid
        CLOSEENTRY();   
    }
    else
    {
        // proses jika tweet tidak valid
    }
    printf("Apakah Anda ingin melanjutkan kicauan ini? (YA/TIDAK)\n");
    STARTENTRY();

    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(LINKEDUTAS l){
    Address p;
    
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(LINKEDUTAS* l, ElType idx, ElType id_utas, UTAS val){
    Address pointerlinked;

}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(LINKEDUTAS* l, ElType idx, ElType id_utas, UTAS* val){
    Address pointerlinked;
    
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */
