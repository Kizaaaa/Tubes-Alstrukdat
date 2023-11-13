/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElTypeoforLLT adalah integer */

// #ifndef listlinier_H
// #define listlinier_H

#include "listliniertweet.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// /* Definisi Node : */
// typedef int ElTypeoforLLT;
// typedef struct node* AddressforLLT;
// typedef struct node {
//     ElTypeoforLLT INFOT;
//     AddressforLLT NEXTT;
// } Node;

// #define INFO(p) (p)->info
// #define NEXTT(p) (p)->NEXTT

AddressforLLT newNodeT(ElTypeoforLLT bal)
{
    AddressforLLT p;
    p = (AddressforLLT)malloc(sizeof(NodeT));
    if (p != NULL)
    {
        INFOT(p) = bal;
        NEXTT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan AddressforLLT p dapat diacu INFOT(p), NEXTT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXTT(Last)=NULL */

// typedef AddressforLLT List;

// #define IDX_UNDEF_LLT (-1)
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
ElTypeoforLLT getElmtT(List l, int idx)
{
    AddressforLLT p;
    int i = 0;
    p = FIRST(l);
    while (i < idx)
    {
        i++;
        p = NEXTT(p);
    }
    return (INFOT(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..lengthT(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtT(List *l, int idx, ElTypeoforLLT bal)
{
    AddressforLLT p;
    int i = 0;
    p = FIRST(*l);
    while (i < idx)
    {
        i++;
        p = NEXTT(p);
        // if (i==idx){
        //     INFOT(p) = bal;
        //     break;
        // }
    }
    INFOT(p) = bal;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..lengthT(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi bal */

int indexOfT(List l, ElTypeoforLLT bal)
{
    AddressforLLT p;
    int res = IDX_UNDEF_LLT;
    boolean found = false;
    int idx = 0;
    p = FIRST(l);
    while ((p != NULL) && (found == false))
    {
        if (INFOT(p).Id == bal.Id)
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
/* I.S. l, bal terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai bal */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai bal */
/* Mengembalikan IDX_UNDEF_LLT jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/

int lengthT(List l)
{
    int len = 0;
    AddressforLLT p;
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
void insertFirstT(List *l, ElTypeoforLLT bal)
{
    AddressforLLT p;
    p = newNodeT(bal);
    if (p != NULL)
    {
        NEXTT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai bal jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastT(List *l, ElTypeoforLLT bal)
{
    AddressforLLT p;
    AddressforLLT idx;
    p = newNodeT(bal);
    if (isEmptyT(*l))
    {
        insertFirstT(l, bal);
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
/* bernilai bal jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtT(List *l, ElTypeoforLLT bal, int idx)
{
    AddressforLLT p;
    AddressforLLT idx2;
    if (idx == 0)
    {
        insertFirstT(l, bal);
    }
    else
    {
        p = newNodeT(bal);
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
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..lengthT(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai bal jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstT(List *l, ElTypeoforLLT *bal)
{
    AddressforLLT p;
    p = FIRST(*l);
    *bal = INFOT(p);
    FIRST(*l) = NEXTT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai INFOT disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastT(List *l, ElTypeoforLLT *bal)
{
    AddressforLLT p;
    AddressforLLT idx;
    p = FIRST(*l);
    idx = NULL;
    // find idx that'll be the last idx after deleting
    while (NEXTT(p) != NULL)
    {
        idx = p;
        p = NEXTT(p);
    }
    if (lengthT(*l) == 1)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXTT(idx) = NULL;
    }
    *bal = INFOT(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai INFOT disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtT(List *l, int idx, ElTypeoforLLT *bal)
{
    AddressforLLT p;
    AddressforLLT idx2;
    p = FIRST(*l);
    if (idx == 0)
    {
        deleteFirstT(l, bal);
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
        *bal = INFOT(p);
        NEXTT(idx2) = NEXTT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..lengthT(l) */
/* F.S. bal diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListT(List l)
{
    AddressforLLT p;
    p = FIRST(l);
    if (isEmptyT(l))
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

List copyListT(List l)
{
    List l1;
    CreateListT(&l1);
    AddressforLLT p;
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
    CreateListT(&l1);
    AddressforLLT p;
    p = FIRST(l);
    while ((p != NULL))
    {
        insertFirstT(&l1, INFOT(p));
        p = NEXTT(p);
    }

    return l1;
}
