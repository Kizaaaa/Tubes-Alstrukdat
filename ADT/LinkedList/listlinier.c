/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

// #ifndef listlinier_H
// #define listlinier_H

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define INFO(p) (p)->info
// #define NEXT(p) (p)->next

Address newNode(ElType val)
{
    Address p;
    p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

// typedef Address List;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
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
ElType getElmt(List l, int idx)
{
    Address p;
    int i = 0;
    p = FIRST(l);
    while (i < idx)
    {
        i++;
        p = NEXT(p);
    }
    return (INFO(p));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val)
{
    Address p;
    int i = 0;
    p = FIRST(*l);
    while (i < idx)
    {
        i++;
        p = NEXT(p);
        // if (i==idx){
        //     INFO(p) = val;
        //     break;
        // }
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val)
{
    Address p;
    int res = IDX_UNDEF;
    boolean found = false;
    int idx = 0;
    p = FIRST(l);
    while ((p != NULL) && (found == false))
    {
        if (INFO(p) == val)
        {
            found = true;
        }
        p = NEXT(p);
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

int length(List l)
{
    int len = 0;
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        len++;
        p = NEXT(p);
    }
    return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    Address p;
    p = newNode(val);
    if (p != NULL)
    {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val)
{
    Address p;
    Address idx;
    p = newNode(val);
    if (isEmpty(*l))
    {
        insertFirst(l, val);
    }
    else
    {
        if (p != NULL)
        {
            idx = FIRST(*l);
            while (NEXT(idx) != NULL)
            {
                idx = NEXT(idx);
            }

            NEXT(idx) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx)
{
    Address p;
    Address idx2;
    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            idx2 = FIRST(*l);
            int count = 0;
            while (count < idx - 1)
            {
                count++;
                idx2 = NEXT(idx2);
            }
            NEXT(p) = NEXT(idx2);
            NEXT(idx2) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    Address p;
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val)
{
    Address p;
    Address idx;
    p = FIRST(*l);
    idx = NULL;
    // find idx that'll be the last idx after deleting
    while (NEXT(p) != NULL)
    {
        idx = p;
        p = NEXT(p);
    }
    if (length(*l) == 1)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(idx) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val)
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
            idx2 = NEXT(idx2);
        }
        p = NEXT(idx2);
        *val = INFO(p);
        NEXT(idx2) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
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
            if (NEXT(p) == NULL)
            {
                printf("%d", INFO(p));
            }
            else
            {
                printf("%d,", INFO(p));
            }
            p = NEXT(p);
        }
        // printf("%d",INFO(p));
        printf("]");
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
{
    List l3;
    Address p, q;
    int val;
    CreateList(&l3);
    p = FIRST(l1);
    q = FIRST(l2);
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    while (q != NULL)
    {
        insertLast(&l3, INFO(q));
        q = NEXT(q);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

// LATIHAN PRAK
void splitList(List *l1, List *l2, List l)
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
                insertLast(l1, INFO(p));
                p = NEXT(p);
                ctr++;
                // displayList(*l1);
            }
            printf("done\n");
            while (p != NULL)
            {
                insertLast(l2, INFO(p));
                p = NEXT(p);
                // displayList(*l2);
            }
        }
    }
}

List copyList(List l)
{
    List l1;
    CreateList(&l1);
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        insertLast(&l1, INFO(p));
        p = NEXT(p);
    }

    return l1;
}

List inverseList(List l)
{
    List l1;
    CreateList(&l1);
    Address p;
    p = FIRST(l);
    while ((p != NULL))
    {
        insertFirst(&l1, INFO(p));
        p = NEXT(p);
    }

    return l1;
}

int maxList(List l)
{
    Address p;
    p = FIRST(l);
    int res = INFO(p);
    while (p != NULL)
    {
        if (res < INFO(p))
        {
            res = INFO(p);
        }
        p = NEXT(p);
    }

    return res;
}

int minList(List l)
{
    Address p;
    p = FIRST(l);
    int res = INFO(p);
    while (p != NULL)
    {
        if (res > INFO(p))
        {
            res = INFO(p);
        }
        p = NEXT(p);
    }

    return res;
}

float average(List l)
{
    Address p;
    p = FIRST(l);
    float total = 0;
    while (p != NULL)
    {
        total += INFO(p);
        p = NEXT(p);
    }
    // printf("Total : %f\n",total);
    // printf("Length: %d\n",length(l));
    return (total / length(l));
}

List sortListasc(List l)
{
    List L1;
    CreateList(&L1);
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        if (isEmpty(L1))
        {
            insertFirst(&L1, INFO(p));
            p = NEXT(p);
        }
        else
        {
            insertAt(&L1, INFO(p), idxMin(L1, INFO(p)));
            p = NEXT(p);
        }
    }
    return L1;
}

List sortListdesc(List l)
{
    List L1;
    CreateList(&L1);
    Address p;
    p = FIRST(l);
    while (p != NULL)
    {
        if (isEmpty(L1))
        {
            insertFirst(&L1, INFO(p));
            p = NEXT(p);
        }
        else
        {
            insertAt(&L1, INFO(p), idxMax(L1, INFO(p)));
            p = NEXT(p);
        }
        // displayList(L1);
    }
    return L1;
}

int idxMin(List l, int val)
{
    int idx = 0;
    boolean found = false;
    Address p;
    p = FIRST(l);
    while ((p != NULL) && (found == false))
    {
        if (INFO(p) > val)
        {
            found = true;
        }
        p = NEXT(p);
        idx++;
    }
    if (found)
    {
        return idx - 1;
    }
    else
    {
        return idx;
    }
}

int idxMax(List l, int val)
{
    int idx = 0;
    boolean found = false;
    Address p;
    p = FIRST(l);
    while ((p != NULL) && (found == false))
    {
        if (INFO(p) < val)
        {
            found = true;
        }
        p = NEXT(p);
        idx++;
    }
    if (found)
    {
        return idx - 1;
    }
    else
    {
        return idx;
    }
}
