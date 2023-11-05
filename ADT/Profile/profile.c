#include <stdio.h>
#include <stdlib.h>
#include "profile.h"

void Masuk(){
    if(isEmptyListStatik(ListProfil)){
        printf("Belum ada pengguna yang didaftarkan!\n");
    } else {
        printf("Masukkan nama:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(indexOfListStatik(ListProfil,currentEntry) == IDX_UNDEF){
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            printf("Masukkan nama:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }

        CurrentUser = indexOfListStatik(ListProfil,currentEntry);

        printf("Masukkan kata sandi:");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!isSame(currentEntry,Password(ELMTLS(ListProfil,CurrentUser)))){
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            printf("Masukkan kata sandi:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }

        printf("Anda telah berhasil masuk dengan nama pengguna ");
        printEntry(Nama(ELMTLS(ListProfil,CurrentUser)));
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
    }
}

/* ********** KONSTRUKTOR ********** */
void Daftar(Profil *P){
    /* I.S. P sembarang */
    /* F.S. P terdefinisi dengan jenis tertentu */
    if(isFullListStatik(ListProfil)){
        printf("Jumlah pengguna sudah maksimum, tidak dapat mendaftarkan akun lagi\n");
    } else {
        Jenis(*P) = 0; //Akun Publik
        Entry blank = StringToEntry("",0);
        Bio(*P) = blank;
        Nomor(*P) = blank;
        Weton(*P) = blank;
        printf("Masukkan nama:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!CHECKVALIDUNP(currentEntry) && indexOfListStatik(ListProfil,currentEntry) != IDX_UNDEF){
            if(currentEntry.Length == 0){
                printf("Nama tidak boleh kosong!\n");
            } else if(currentEntry.Length > 20){
                printf("Nama tidak boleh lebih dari 20 karakter!\n");
            } else { //Nama pengguna sudah diambil
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            }

            printf("Masukkan nama:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        Nama(*P) = currentEntry;

        printf("Masukkan kata sandi:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!CHECKVALIDUNP(currentEntry)){
            if(currentEntry.Length == 0){
                printf("Kata sandi tidak boleh kosong!\n");
            } else {
                printf("Kata sandi tidak boleh lebih dari 20 karakter!\n");
            }

            printf("Masukkan kata sandi:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        Password(*P) = currentEntry;

        Foto(*P) = FotoDefault();
        NEFFLS(ListProfil)++;
    }
}

MatrixChar FotoDefault()
{
    /* I.S. P terdefinisi */
    /* F.S. P terdefinisi dengan foto baru */
    IdxType i, j;
    MatrixChar m;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 10; j++){
            if(j%2){
                ELMT(m,i,j) = '*';
            } else {
                ELMT(m,i,j) = 'R';
            }
        }
    }

    return m;
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
    printf("| Nama: "); printEntry(Nama(P)); printf("\n");
    printf("| Bio Akun: "); printEntry(Bio(P)); printf("\n");
    printf("| No HP: "); printEntry(Nomor(P)); printf("\n");
    printf("| Weton: "); printEntry(Weton(P)); printf("\n\n");

    printf("Foto profil akun %s\n", nama);
    PrintFoto(P);
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
void PrintFoto(Profil P)
{
    /* I.S. P terdefinisi */
    /* F.S. P Cetak foto baru 5x5  */
    IdxType i, j;
    char c;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j+=2)
        {
            c = ELMT(Foto(P), i, j + 1);
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