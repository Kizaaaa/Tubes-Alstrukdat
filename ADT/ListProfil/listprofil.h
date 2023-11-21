#ifndef LISTPROFIL_H
#define LISTPROFIL_H

#include "../../boolean.h"
#include "../EntryMachine/entrymachine.h"
#include "../../Program/Pcolor/pcolor.h"
#include "../Stack/stack.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
/* Ukuran maksimum baris dan kolom Matrix foto */
#define ROW_CAP 10
#define COL_CAP 10

typedef struct
{
    char mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixChar;

typedef struct
{
    int Prio;   /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas adalah tertinggi) */
    Entry Info; /* elemen karakter */
} Elmtqueue;

typedef struct
{
    Elmtqueue Element[CAPACITY];
    int IdxHead;
    int IdxTail;
} Queue;

/* *** Definisi TYPE Profil *** */
typedef struct Profil
{
    int Jenis; // 0 bertipe privat, 1 bertipe publik
    Entry Nama;
    Entry Password;
    Entry Bio;
    Entry Nomor;
    Entry Weton;
    MatrixChar Foto;
    int JumlahTeman;
    Queue PermintaanPertemanan;
    Stack Draf;
} Profil;

/* Definisi elemen dan koleksi objek */
typedef struct
{
    Profil contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int nEff;                  /* >=0, banyaknya elemen efektif */
} ListStatik;

/* ********** SELEKTOR ********** */
#define Jenis(P) (P).Jenis
#define Nama(P) (P).Nama
#define Password(P) (P).Password
#define Bio(P) (P).Bio
#define Nomor(P) (P).Nomor
#define Weton(P) (P).Weton
#define Foto(P) (P).Foto
#define JumlahTeman(P) (P).JumlahTeman
#define PermintaanPertemanan(P) (P).PermintaanPertemanan
#define DRAF(P) (P).Draf

#define Info(E) (E).Info
#define Prio(E) (E).Prio
#define ELMTQ(Q, i) (Q).Element[i]
#define IDXHEAD(Q) (Q).IdxHead
#define IDXTAIL(Q) (Q).IdxTail
#define HEAD(Q) (Q).Element[(Q).IdxHead]
#define TAIL(Q) (Q).Element[(Q).IdxTail]
#define NEFFLS(l) (l).nEff
#define ELMTLS(l, i) (l).contents[(i)]
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

void Masuk(ListStatik *ListProfil, int *CurrentUser, boolean *isMasuk);

/* ********** KONSTRUKTOR ********** */
void Daftar(ListStatik *ListProfil);
/* I.S. P sembarang */
/* F.S. P terdefinisi dengan jenis tertentu */

MatrixChar FotoDefault();
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan foto baru */

/* ********** BACA/TULIS ********** */
void PrintProfil(Profil P);
/* I.S. P terdefinisi */
/* F.S. P tercetak di layar dengan format:
    Nama: <Nama>
    Bio Akun : <Bio>
    No HP: <Nomor>
    Weton: <Weton>
    Foto profil akun <nama>
*/

/* ********** MENGUBAH FOTO DAN PROFILE ********** */
void GantiProfil(Profil *P);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan bio, nomor, dan weton baru */

void GantiFoto(Profil *P);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan foto baru */

/* ********** ATUR JENIS AKUN (PRIVAT/UMUM) ********** */
void GantiJenis(Profil *P);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan jenis baru
        0 bertipe privat, 1 bertipe publik
*/

/* ********** FOTO ********** */
void PrintFoto(MatrixChar m);
/* I.S. Foto terdefinisi */
/* F.S. P tercetak di layar dengan format (5x5):
    Representasi foto profil (PColor: R = merah)
    *****
    *****
    *****
    *****
    *****
 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStatik(ListStatik l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListStatik(ListStatik l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexNama(ListStatik l, Entry val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

void CreateQueue(Queue *Q);

boolean isEmptyQueue(Queue Q);

int lengthQueue(Queue Q);

boolean IsIn(Queue Q, Entry nama);

void Enqueue(Queue *Q, Elmtqueue Val);

void Dequeue(Queue *Q);

void PrintQueue(Queue Q);

#endif