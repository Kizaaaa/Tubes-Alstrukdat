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


typedef struct node *Address;
typedef struct node
{
    UTAS infoutas;
    Address next;
} LINKEDUTAS;


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


#define IDX_UNDEF (-1)
#define FIRSTUTAS(p) (p)

typedef Address LINKEDUTAS;

void createUtas(UTAS *U, ElType idx, Entry teks, DATETIME time);
/* I.S sembarang */
/* F.S Terbentuk utas dengan komponen yang terdefinisi*/

void createLinkedUtas(LINKEDUTAS *l, Kicau Twt);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void readUtas(LINKEDUTAS l);
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(UTAS u,Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SATU UTAS */

void displayLinkedUtas(LINKEDUTAS l,Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SELURUH LinkedUtas termasuk Kicauan Utama */

void sambungUtas(LINKEDUTAS *l,ElType idx);

void insertFirstUtas(LINKEDUTAS *l, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di awal */

void insertUtasAt(LINKEDUTAS *l, ElType idx, UTAS val);
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS *val);
/* I.S list l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */

#endif