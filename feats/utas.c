#include "../LinkedList/listlinier.h"
#include "../DateTime/datetime.h"
#include "../ListDin/listdin.h"
#include "../EntryMachine/entrymachine.h"
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


Address newNode(ElType val){
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void createUtas(List* l){
    FIRST(*l) = NULL;
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void readUtas(List l){
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(List l){
    Address p;
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(List* l , ElType idx, UTAS val){
    Address p;
    Address idx2;
    if (idx==0){
        insertFirst(l,val);
    }
    else{
        p = newNode(val);
        if (p!=NULL){
            idx2=FIRST(*l);
            int count=0;
            while (count<idx-1){
                count++;
                idx2 = NEXT(idx2);
            }
            NEXT(p) = NEXT(idx2);
            NEXT(idx2)=p;
        }
    }
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(List* l ,ElType id_utas, UTAS* val){
    Address p;
    Address idx2;
    p = FIRST(*l);
    if (id_utas==0){
        deleteFirst(l,val);
    }
    else{
        int count=0;
        idx2 = FIRST(*l);
        while (count!=id_utas-1){
            count++;
            idx2 = NEXT(idx2);
        }
        p = NEXT(idx2);
        *val = INFO(p);
        NEXT(idx2) = NEXT(p);
        free(p);
        
    }
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */
