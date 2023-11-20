/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdintweet.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF_LDT -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
/*typedef int ElTypeLDT; /* type elemen list */
// typedef int IdxType;
// typedef struct
// {
//     ElTypeLDT *buffer; /* memori tempat penyimpan elemen (container) */
//     int nEff;       /* >=0, banyaknya elemen efektif */
//     int capacityT;   /* ukuran elemen */
// } ListDinT;
/* Indeks yang digunakan [0..capacityT-1] */
/* Jika l adalah : ListDinT, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinT */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacityT */

/* ********** SELEKTOR ********** */
#define NEFFT(l) (l).nEffT
#define BUFFERT(l) (l).bufferT
#define ELMTT(l, i) (l).bufferT[i]
#define CAPACITYT(l) (l).capacityT

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinT(ListDinT *l, int capacityT)
{
    BUFFERT(*l) = (ElTypeLDT *)malloc(capacityT * sizeof(ElTypeLDT));
    CAPACITYT(*l) = capacityT;
    NEFFT(*l) = 0;
}
/* I.S. l sembarang, capacityT > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacityT */

void dealocateListDinT(ListDinT *l)
{
    free(BUFFERT(*l));
    CAPACITYT(*l) = 0;
    NEFFT(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYT(l)=0; NEFFT(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinTLength(ListDinT l)
{
    return NEFFT(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDinT(ListDinT l)
{
    return (IdxType)IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxListDinT(ListDinT l)
{
    return (IdxType)NEFFT(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinT(ListDinT l, IdxType i)
{
    if (i < CAPACITYT(l) && i >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListDinT(ListDinT l, IdxType i)
{
    if (i >= 0 && i <= NEFFT(l) - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFFT(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinT(ListDinT l)
{
    if (NEFFT(l) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDinT(ListDinT l)
{
    if (NEFFT(l) == CAPACITYT(l))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinT(ListDinT *l, ElTypeLDT val)
{
    ELMTT(*l, getLastIdxListDinT(*l) + 1) = val;
    NEFFT(*l)
    ++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinT(ListDinT *l, ElTypeLDT *val)
{
    *val = ELMTT(*l, getLastIdxListDinT(*l));
    NEFFT(*l)
    --;
    // printList(*l);
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinT(ListDinT *l, int num)
{
    ElTypeLDT *ptr;
    ptr = (ElTypeLDT *)calloc(CAPACITYT(*l), sizeof(ElTypeLDT));
    ElTypeLDT *temp = ptr;
    CAPACITYT(*l) = CAPACITYT(*l) + num;
    ptr = realloc(ptr, CAPACITYT(*l) * sizeof(ElTypeLDT));
}
/* Proses : Menambahkan capacityT l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinT(ListDinT *l, int num)
{
    ElTypeLDT *ptr;
    ptr = (ElTypeLDT *)calloc(CAPACITYT(*l), sizeof(ElTypeLDT));
    ElTypeLDT *temp = ptr;
    CAPACITYT(*l) = CAPACITYT(*l) - num;
    ptr = realloc(ptr, CAPACITYT(*l) * sizeof(ElTypeLDT));
}
/* Proses : Mengurangi capacityT sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacityT > num, dan nEff < capacityT - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinT(ListDinT *l)
{
    CAPACITYT(*l) = NEFFT(*l);
}
/* Proses : Mengubah capacityT sehingga capacityT = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacityT = nEff */