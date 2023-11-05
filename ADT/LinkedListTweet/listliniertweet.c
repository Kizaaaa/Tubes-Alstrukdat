/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

// #ifndef listlinier_H
// #define listlinier_H

#include "boolean.h"
#include "../LinkedList/listlinier.h"
#include "listliniertweet.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// /* Definisi Node : */
// typedef int ElType;
// typedef struct node* Address;
// typedef struct node {
//     ElType INFOT;
//     Address NEXTT;
// } Node;

// #define INFO(p) (p)->info
// #define NEXTT(p) (p)->NEXTT

Address newNodeTT(ElType val)
{
    Address p;
    p = (Address)malloc(sizeof(NodeT));
    if (p != NULL)
    {
        INFOT(p) = val;
        NEXTT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFOT(p), NEXTT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXTT(Last)=NULL */

// typedef Address List;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListT(List *l)
{
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyT(List l)
{
    if (FIRST(l) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmtT(List l, int idx)
{
    Address p;
    int i = 0;
    p = FIRST(l);
    while (i < idx)
    {
        i++;
        p = NEXTT(p);
    }
    return (INFOT(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtT(List *l, int idx, ElType val)
{
    Address p;
    int i = 0;
    p = FIRST(*l);
    while (i < idx)
    {
        i++;
        p = NEXTT(p);
        // if (i==idx){
        //     INFOT(p) = val;
        //     break;
        // }
    }
    INFOT(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfT(List l, ElType val)
{
    Address p;
    int res = IDX_UNDEF;
    boolean found = false;
    int idx = 0;
    p = FIRST(l);
    while ((p != NULL) && (found == false))
    {
        if (INFOT(p).Id == val.Id)
        {
            found = true;
        }
        p = NEXTT(p);
        idx++;
    }
    if (found)
    {
        return idx - 1;
    }
    else
    {
        return res;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/

int lengthT(List l)
{
    int len = 0;
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        len++;
        p = NEXTT(p);
    }
    return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** PENAMBAHAN ELEMEN ***/
void insertFirstTT(List *l, ElType val)
{
    Address p;
    p = newNodeTT(val);
    if (p != NULL)
    {
        NEXTT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastTT(List *l, ElType val)
{
    Address p;
    Address idx;
    p = newNodeT(val);
    if (isEmpty(*l))
    {
        insertFirstTT(l, val);
    }
    else
    {
        if (p != NULL)
        {
            idx = FIRST(*l);
            while (NEXTT(idx) != NULL)
            {
                idx = NEXTT(idx);
            }

            NEXTT(idx) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtT(List *l, ElType val, int idx)
{
    Address p;
    Address idx2;
    if (idx == 0)
    {
        insertFirstT(l, val);
    }
    else
    {
        p = newNodeT(val);
        if (p != NULL)
        {
            idx2 = FIRST(*l);
            int count = 0;
            while (count < idx - 1)
            {
                count++;
                idx2 = NEXTT(idx2);
            }
            NEXTT(p) = NEXTT(idx2);
            NEXTT(idx2) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstT(List *l, ElType *val)
{
    Address p;
    p = FIRST(*l);
    *val = INFOT(p);
    FIRST(*l) = NEXTT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai INFOT disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastT(List *l, ElType *val)
{
    Address p;
    Address idx;
    p = FIRST(*l);
    idx = NULL;
    // find idx that'll be the last idx after deleting
    while (NEXTT(p) != NULL)
    {
        idx = p;
        p = NEXTT(p);
    }
    if (length(*l) == 1)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXTT(idx) = NULL;
    }
    *val = INFOT(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai INFOT disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtT(List *l, int idx, ElType *val)
{
    Address p;
    Address idx2;
    p = FIRST(*l);
    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        int count = 0;
        idx2 = FIRST(*l);
        while (count != idx - 1)
        {
            count++;
            idx2 = NEXTT(idx2);
        }
        p = NEXTT(idx2);
        *val = INFOT(p);
        NEXTT(idx2) = NEXTT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListT(List l)
{
    Address p;
    p = FIRST(l);
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while (p != NULL)
        {
            if (NEXTT(p) == NULL)
            {
                printf("%d", INFOT(p));
            }
            else
            {
                printf("%d,", INFOT(p));
            }
            p = NEXTT(p);
        }
        // printf("%d",INFOT(p));
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

/****************** PROSES TERHADAP LIST ******************/
List concatT(List l1, List l2)
{
    List l3;
    Address p, q;
    int val;
    CreateList(&l3);
    p = FIRST(l1);
    q = FIRST(l2);
    while (p != NULL)
    {
        insertLastTT(&l3, INFOT(p));
        p = NEXTT(p);
    }
    while (q != NULL)
    {
        insertLastTT(&l3, INFOT(q));
        q = NEXTT(q);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

// LATIHAN PRAK
void splitListT(List *l1, List *l2, List l)
{
    /* I.S. l mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
    /* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
    /* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
    // example: [1,2,3,4,5,6,7] --> l1:[1,2,3] l2:[4,5,6,7]
    CreateList(l1);
    CreateList(l2);
    Address p;
    int ctr = 0;
    int lenl1 = length(l) / 2;
    p = FIRST(l);
    if (!isEmpty(l))
    {
        while (p != NULL)
        {
            while (ctr != lenl1)
            {
                insertLastT(l1, INFOT(p));
                p = NEXTT(p);
                ctr++;
                // displayList(*l1);
            }
            printf("done\n");
            while (p != NULL)
            {
                insertLastT(l2, INFOT(p));
                p = NEXTT(p);
                // displayList(*l2);
            }
        }
    }
}

List copyListT(List l)
{
    List l1;
    CreateList(&l1);
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        insertLastT(&l1, INFOT(p));
        p = NEXTT(p);
    }

    return l1;
}

List inverseListT(List l)
{
    List l1;
    CreateList(&l1);
    Address p;
    p = FIRST(l);
    while ((p != NULL))
    {
        insertFirstT(&l1, INFOT(p));
        p = NEXTT(p);
    }

    return l1;
}
