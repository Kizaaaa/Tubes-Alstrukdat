#include <stdio.h>
#include <stdlib.h>
#include "profile.h"

/* ********** KONSTRUKTOR ********** */
void CreateProfile(Profil *P, Entry nama, Entry password, int jenis, Entry bio, Entry nomor, Entry weton, Matrix *foto)
{
    /* I.S. P sembarang */
    /* F.S. P terdefinisi dengan jenis tertentu */

    Jenis(*P) = jenis;
    Nama(*P) = nama;
    Password(*P) = password;
    Bio(*P) = bio;
    Nomor(*P) = nomor;
    Weton(*P) = weton;
    CreateFoto(foto);
}

void CreateFoto(Matrix *foto)
{
    /* I.S. P terdefinisi */
    /* F.S. P terdefinisi dengan foto baru */
    IdxType i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            ELMT(*foto, i, j) = ' ';
        }
    }
}

/* ********** BACA/TULIS ********** */
void LihatProfile(Profil P, Entry nama)
{
    /* I.S. P terdefinisi */
    /* F.S. P tercetak di layar dengan format:
        Nama: <Nama>
        Bio Akun : <Bio>
        No HP: <Nomor>
        Weton: <Weton>
        Foto profil akun <nama>
    */
    printf("Nama: %s\n", Nama(P));
    printf("Bio Akun: %s\n", Bio(P));
    printf("No HP: %s\n", Nomor(P));
    printf("Weton: %s\n", Weton(P));

    printf("Foto profil akun %s\n", nama);
    PrintFoto(Foto(P));
}

/* ********** MENGEMBALIKAN FOTO DAN PROFIL ********** */
Profil GetProfile(Profil P)
{
    /* Mengembalikan profil P */
    return P;
}

Matrix GetFoto(Matrix foto)
{
    /* Mengembalikan foto profil P */
    return foto;
}

/* ********** MENGUBAH FOTO DAN PROFILE ********** */
void GantiBioNomorWeton(Profil *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P terdefinisi dengan bio, nomor, dan weton baru */
    printf("Masukan Bio Akun: ");
    STARTENTRY();
    Bio(*P) = cleansedEntry(currentEntry); // MAKSIMAL 135 KARAKTER
    CLOSEENTRY();

    printf("Masukan No HP: ");
    STARTENTRY();
    Nomor(*P) = cleansedEntry(currentEntry); // HARUS DALAM ANGKA
    CLOSEENTRY();

    printf("Masukan Weton: ");
    STARTENTRY();
    Weton(*P) = cleansedEntry(currentEntry); // HARI HARUS ADA DI LIST WETON: Pahing, Kliwon, Wage, Pon, dan Legi (case insensitive)
    CLOSEENTRY();
}

void GantiFoto(Profil *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P terdefinisi dengan foto baru */
    printf("Masukan foto profil\n");
    IdxType i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%c", &ELMT(Foto(*P), i, j)); //INI HARUS PAKAI CHARMACHINE
        }
    }
}

/* ********** ATUR JENIS AKUN (PRIVAT/UMUM) ********** */
void SetJenis(Profil *P, int jenis)
{
    /* I.S. P terdefinisi */
    /* F.S. P terdefinisi dengan jenis baru
            0 bertipe privat, 1 bertipe publik
    */
    Jenis(*P) = jenis;
}

/* ********** FOTO ********** */
void PrintFoto(Profil *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P Cetak foto baru 5x5  */
    IdxType i, j;
    char c;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            c = ELMT(Foto(*P), i, j + 1);
            if (c == 'R')
            {
                print_red(c);
            }
            if (c == 'G')
            {
                print_green(c);
            }
            if (c == 'B')
            {
                print_blue(c);
            }
        }
        printf("\n");
    }
}