#ifndef PROFIL_H
#define PROFIL_H

#include "../../boolean.h"
#include "../../main.h"
#include "../EntryMachine/entrymachine.h"
#include "../../Program/Pcolor/pcolor.h"
#include "../ListStatic/liststatik.h"

/* Ukuran maksimum baris dan kolom Matrix foto */
#define ROW_CAP 10
#define COL_CAP 10

typedef int IdxType; /* Index baris, kolom */
typedef struct
{
    char mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixChar;

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
} Profil;

/* ********** SELEKTOR ********** */
#define Jenis(P) (P).Jenis
#define Nama(P) (P).Nama
#define Password(P) (P).Password
#define Bio(P) (P).Bio
#define Nomor(P) (P).Nomor
#define Weton(P) (P).Weton
#define Foto(P) (P).Foto



/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

void Masuk();

/* ********** KONSTRUKTOR ********** */
void Daftar(Profil *P);
/* I.S. P sembarang */
/* F.S. P terdefinisi dengan jenis tertentu */

MatrixChar FotoDefault();
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan foto baru */

/* ********** BACA/TULIS ********** */
void LihatProfile(Profil P, Entry nama);
/* I.S. P terdefinisi */
/* F.S. P tercetak di layar dengan format:
    Nama: <Nama>
    Bio Akun : <Bio>
    No HP: <Nomor>
    Weton: <Weton>
    Foto profil akun <nama>
*/

/* ********** MENGUBAH FOTO DAN PROFILE ********** */
void GantiBioNomorWeton(Profil *P);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan bio, nomor, dan weton baru */

void GantiFoto(Profil *P);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan foto baru */

/* ********** ATUR JENIS AKUN (PRIVAT/UMUM) ********** */
void SetJenis(Profil *P, int jenis);
/* I.S. P terdefinisi */
/* F.S. P terdefinisi dengan jenis baru
        0 bertipe privat, 1 bertipe publik
*/

/* ********** FOTO ********** */
void PrintFoto(Profil P);
/* I.S. Foto terdefinisi */
/* F.S. P tercetak di layar dengan format (5x5):
    Representasi foto profil (PColor: R = merah)
    *****
    *****
    *****
    *****
    *****
 */

#endif