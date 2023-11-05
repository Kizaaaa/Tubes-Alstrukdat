/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#include "stackdraf.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyD(StackD *S)
{
    TopD(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyD(StackD S)
{
    return TopD(S) == Nil;
}
/* Mengirim true jika StackD kosong: lihat definisi di atas */
boolean IsFullD(StackD S)
{
    return TopD(S) == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackD ************ */
void PushD(StackD *S, infotype X)
{
    if (IsEmptyD(*S))
    {
        TopD(*S) = 0;
        InfoTopD(*S) = X;
    }
    else
    {
        TopD(*S)++;
        InfoTopD(*S) = X;
    }
}
/* Menambahkan X sebagai elemen StackD S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackD ************ */
void PopD(StackD *S, infotype *X)
{
    *X = InfoTopD(*S);
    TopD(*S)--;
}
/* Menghapus X dari StackD S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
