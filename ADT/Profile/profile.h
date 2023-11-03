#ifndef PROFILE_H
#define PROFILE_H

#include "../../boolean.h"
#include "../Matrix/matrix.h"
#include "../EntryMachine/entrymachine.h"

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct profil{
    int Jenis; // 0 bertipe privat, 1 bertipe publik
    Entry Bio;
    Entry Nomor;
    Entry Weton;
    Matrix Foto;
} Profil;

/* ********** SELEKTOR ********** */
#define Jenis(P) (P).Jenis
#define Bio(P) (P).Bio
#define Nomor(P) (P).Nomor
#define Weton(P) (P).Weton
#define Foto(P) (P).Foto

/* ********** KONSTRUKTOR ********** */
void CreateProfile(Profil *P, int jenis, Entry bio, Entry nomor, Entry weton, Matrix foto);
/* I.S. P sembarang */
/* F.S. P terdefinisi dengan jenis tertentu */



/* ********** BACA/TULIS ********** */
void TulisProfile(Profil P);
/* I.S. P terdefinisi */
/* F.S. P tercetak di layar dengan format:
    Bio: <Bio>
    Nomor: <Nomor>
    Weton: <Weton>
    Foto: <Foto>
*/

void BacaProfile(Profil *P);
/* I.S. P sembarang */
/* F.S. P terdefinisi dengan membaca dari keyboard */
#endif