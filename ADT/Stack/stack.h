/* File: stacklinked.h */

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include "../../boolean.h"
#include "../EntryMachine/entrymachine.h"
#include "../DateTime/datetime.h"
#include <stdlib.h>

/* Deklarasi infotype */
typedef struct eltypes{
    Entry texts;
    DATETIME waktus;
} Eltypes;


/* Stack dengan representasi berkait dengan pointer */
typedef struct nodes* Addresss;
typedef struct nodes {
    Eltypes infos;
    Addresss nexts; 
} Nodes; 

/* Type stack dengan ciri Top: */
typedef struct { 
    Addresss addrTop; /* alamat Top: elemen puncak */
} Stack;

/* Selektor */
#define NEXTS(p) (p)->nexts
#define INFOS(p) (p)->infos
#define TEXTS(p) (p).texts
#define WAKTUS(p) (p).waktus
#define ADDR_TOP(s) (s).addrTop
#define TOP(s) (s).addrTop->infos 

/* Prototype manajemen memori */
Addresss newNode(Entry x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyS(Stack s);
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int lengthS(Stack s);
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStack(Stack *s);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void push(Stack *s, Entry x);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, Eltypes *x);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

#endif