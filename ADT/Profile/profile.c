#include <stdio.h>
#include <stdlib.h>
#include "profile.h"

/* ********** KONSTRUKTOR ********** */
void CreateProfile(Profil *P, int jenis, Entry bio, Entry nomor, Entry weton, Matrix foto)
{
    /* I.S. P sembarang */
    /* F.S. P terdefinisi dengan jenis tertentu */
    /* Algoritma */
    Jenis(*P) = jenis;
    Bio(*P) = bio;
    Nomor(*P) = nomor;
    Weton(*P) = weton;
    Foto(*P) = foto;
}

/* ********** BACA/TULIS ********** */
void TulisProfile(Profil P)
{
    /* I.S. P terdefinisi */
    /* F.S. P tercetak di layar dengan format:
        Bio: <Bio>
        Nomor: <Nomor>
        Weton: <Weton>
        Foto: <Foto>
    */
    printf("Bio: "); printEntry(Bio(P)); printf("\n");
    printf("Nomor: "); printEntry(Bio(P)); printf("\n");
    printf("Weton: "); printEntry(Bio(P)); printf("\n");
    printf("Foto: "); TulisMATRIKS(Foto(P)); printf("\n");  


   
}

void BacaProfile(Profil *P);
/* I.S. P sembarang */
/* F.S. P terdefinisi dengan membaca dari keyboard */
