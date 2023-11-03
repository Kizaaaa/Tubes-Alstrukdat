/* Program harus melakukan inisialisasi dengan melakukan load dari file konfigurasi ketika awal menjalan program. */

/*
.______    __    __  .______      .______    __  .______
|   _  \  |  |  |  | |   _  \     |   _  \  |  | |   _  \
|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |
|   _  <  |  |  |  | |      /     |   _  <  |  | |      /
|  |_)  | |  `--'  | |  |\  \----.|  |_)  | |  | |  |\  \----.
|______/   \______/  | _| `._____||______/  |__| | _| `._____|
Selamat datang di BurBir.
Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.

Silahkan masukan folder konfigurasi untuk dimuat: config-1;

File konfigurasi berhasil dimuat! Selamat berkicau!

>>
*/

#include <stdio.h>
#include <stdlib.h>
#include "inisialisasi.h"

void inisialisasi(Entry *namaFile)
{
    /* Melakukan inisialisasi dengan melakukan load dari file konfigurasi ketika awal menjalan program */
    /*
    .______    __    __  .______      .______    __  .______
    |   _  \  |  |  |  | |   _  \     |   _  \  |  | |   _  \
    |  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |
    |   _  <  |  |  |  | |      /     |   _  <  |  | |      /
    |  |_)  | |  `--'  | |  |\  \----.|  |_)  | |  | |  |\  \----.
    |______/   \______/  | _| `._____||______/  |__| | _| `._____|
    Selamat datang di BurBir.
    Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.

    Silahkan masukan folder konfigurasi untuk dimuat: <input config-1>;

    File konfigurasi berhasil dimuat! Selamat berkicau!

    >>
    */
    printf(".______    __    __  .______      .______    __  .______\n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");

    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    // INI HARUS PAKAI ENTRYMACHINE
    STARTENTRY();
    Entry namaFile = cleansedEntry(*namaFile);
    CLOSEENTRY();
    // scanf("%s", namaFile);
    printf("\n");

    // KAMUS LOKAL
    FILE *file;
    char *namaFile;

    // ALGORITMA
    file = fopen(namaFile, "r");
    if (file == NULL)
    {
        printf("File konfigurasi gagal dimuat! Silahkan coba lagi.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    }
    fclose(file);
}