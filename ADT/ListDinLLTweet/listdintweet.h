/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "../../boolean.h"
#include "../Kicau/kicau.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Kicau ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *bufferT; /* memori tempat penyimpan elemen (container) */
    int nEffT;       /* >=0, banyaknya elemen efektif */
    int capacityT;   /* ukuran elemen */
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
void readListDinT(ListDinT *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYT(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITYT(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDinT(ListDinT l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

void copyListDinT(ListDinT lIn, ListDinT *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEffT dan capacityT sama) */
/* Proses : Menyalin isi lIn ke lOut */

void insertLastListDinT(ListDinT *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinT(ListDinT *l, ElType *val);
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

void shrinkList(ListDinT *l, int num);
/* Proses : Mengurangi capacityT sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacityT > num, dan nEffT < capacityT - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDinT *l);
/* Proses : Mengubah capacityT sehingga capacityT = nEffT */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacityT = nEffT */

#endif