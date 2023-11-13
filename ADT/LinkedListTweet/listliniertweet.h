/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi AddressforLLT dengan pointer */
/* ElTypeoforLLT adalah integer */

#ifndef listlinierT_H
#define listlinierT_H

#include "../../boolean.h"
#include "../Kicau/kicau.h"
// #include "../LinkedList/listlinier.h"

/* Definisi Node : */
typedef Kicau ElTypeoforLLT;
typedef struct nodeT *AddressforLLT;
typedef struct nodeT
{
    ElTypeoforLLT infoT;
    AddressforLLT nextT;
} NodeT;

#define INFOT(p) (p)->infoT
#define NEXTT(p) (p)->nextT

AddressforLLT newNodeT(ElTypeoforLLT val);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan AddressforLLT p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef AddressforLLT List;

#define IDX_UNDEF_LLT (-1)
#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListT(List *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyT(List l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElTypeoforLLT getElmtT(List l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtT(List *l, int idx, ElTypeoforLLT val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfT(List l, ElTypeoforLLT val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstT(List *l, ElTypeoforLLT val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastT(List *l, ElTypeoforLLT val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtT(List *l, ElTypeoforLLT val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstT(List *l, ElTypeoforLLT *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastT(List *l, ElTypeoforLLT *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtT(List *l, int idx, ElTypeoforLLT *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListT(List l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthT(List l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/

List copyListT(List l);

List inverseListT(List l);

#endif