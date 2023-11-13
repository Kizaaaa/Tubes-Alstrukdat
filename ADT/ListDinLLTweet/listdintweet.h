/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINT_H
#define LISTDINT_H

#include "../../boolean.h"
#include "../LinkedListTweet/listliniertweet.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF_LDT -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef NodeT ElTypeLDT; /* type elemen list */
typedef int IdxType;
typedef struct
{
  ElTypeLDT *bufferT; /* memori tempat penyimpan elemen (container) */
  int nEffT;          /* >=0, banyaknya elemen efektif */
  int capacityT;      /* ukuran elemen */
} ListDinT;
/* Indeks yang digunakan [0..capacityT-1] */
/* Jika l adalah : ListDinT, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinT */
/* Maka cara akses:
   l.nEffT      untuk mengetahui banyaknya elemen
   l.bufferT    untuk mengakses seluruh nilai elemen list
   l.bufferT[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEffT = 0
  Definisi elemen pertama : l.bufferT[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.bufferT[i] dengan i=l.capacityT */

/* ********** SELEKTOR ********** */
#define NEFFT(l) (l).nEffT
#define BUFFERT(l) (l).bufferT
#define ELMTT(l, i) (l).bufferT[i]
#define CAPACITYT(l) (l).capacityT

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinT(ListDinT *l, int capacityT);
/* I.S. l sembarang, capacityT > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacityT */

void dealocateListDinT(ListDinT *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYT(l)=0; NEFFT(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinTLength(ListDinT l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDinT(ListDinT l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxListDinT(ListDinT l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinT(ListDinT l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListDinT(ListDinT l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFFT(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinT(ListDinT l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDinT(ListDinT l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void insertLastListDinT(ListDinT *l, ElTypeLDT val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinT(ListDinT *l, ElTypeLDT *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinT(ListDinT *l, int num);
/* Proses : Menambahkan capacityT l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinT(ListDinT *l, int num);
/* Proses : Mengurangi capacityT sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacityT > num, dan nEffT < capacityT - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinT(ListDinT *l);
/* Proses : Mengubah capacityT sehingga capacityT = nEffT */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacityT = nEffT */

#endif