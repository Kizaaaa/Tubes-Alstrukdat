/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOPD adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackDt_H
#define stackDt_H

#include "../../boolean.h"
#include "../Kicau/kicau.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Kicau infotype;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOPD : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotype TD[MaxEl]; /* tabel penyimpan elemen */
  address TOPD;       /* alamat TOPD: elemen puncak */
} StackD;
/* Definisi stack S kosong : S.TOPD = Nil */
/* Elemen yang dipakai menyimpan nilai StackD TD[0]..TD[MaxEl-1] */
/* Jika S adalah StackD maka akses elemen : */
/* S.TD[(S.TOPD)] untuk mengakses elemen TOPD */
/* S.TOPD adalah alamat elemen TOPD */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopD(S) (S).TOPD
#define InfoTopD(S) (S).TD[(S).TOPD]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyD(StackD *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOPD bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyD(StackD S);
/* Mengirim true jika StackD kosong: lihat definisi di atas */
boolean IsFullD(StackD S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackD ************ */
void PushD(StackD *S, infotype X);
/* Menambahkan X sebagai elemen StackD S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOPD yang baru,TOPD bertambah 1 */

/* ************ Menghapus sebuah elemen StackD ************ */
void PopD(StackD *S, infotype *X);
/* Menghapus X dari StackD S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOPD yang lama, TOPD berkurang 1 */

#endif