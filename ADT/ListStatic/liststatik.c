/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
{
    NEFFLS(*l) = 0;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStatik(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return NEFFLS(l) == 0;
}

/* *** Test List penuh *** */
boolean isFullListStatik(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return NEFFLS(l) == CAPACITY;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOfListStatik(ListStatik l, Entry nama)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    if (isEmptyListStatik(l))
    {
        return IDX_UNDEF;
    }

    else
    {
        int i = 0;
        boolean found = false;
        while (i <= NEFFLS(l)-1 && !found)
        {
            if (isSame(Nama(ELMTLS(l,i)),nama)) 
            {
                found = true;
            }
            else 
            {
                i++;
            }
        }
        if (found)
        {
            return i;
        }
        else
        {
            return IDX_UNDEF;
        }
        
    }
}