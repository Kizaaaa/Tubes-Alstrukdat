#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"

void CreateKicau(Kicau *k, int id, Entry author)
{
    ID(*k) = id;
    LIKE(*k) = 0;
    AUTHOR(*k) = author;
    UTASAN(*k) = NULL;
    WAKTU(*k) = GetLocalTime();

    printf("Masukkan kicauan:\n");
    STARTENTRY();
    if (!CHECKVALIDTWEET(cleansedEntry(currentEntry)))
    {
        printf("Kicauan tidak boleh hanya berisi spasi!");
        STARTENTRY();
    }
    TEXT(*k) = cleansedEntry(currentEntry);
    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    DisplayKicau(*k);
}

void EditKicau(Kicau *k)
{
}

void DisplayKicau(Kicau k)
{
    printf("| ID = %d\n", ID(k));
    printf("| ");
    printEntry(AUTHOR(k));
    printf("\n");
    printf("| ");
    TulisDATETIME(WAKTU(k));
    printf("\n");
    printf("| ");
    printEntry(TEXT(k));
    printf("\n");
    printf("| Disukai = %d\n", LIKE(k));
}

void LikeKicau(Kicau *k)
{
    LIKE(*k)
    ++;
}

void displayUtas(UTAS u, Kicau Twt)
{ // Display hanya 1 UTAS
    printf("    | INDEX = %d\n", INDEKS(u));
    printf("    | ");
    printEntry(AUTHOR(Twt));
    printf("\n");
    printf("    | ");
    TulisDATETIME(WAKTU(Twt));
    printf("\n");
    printf("    | "), printEntry(TEXTUTAS(u));
    printf("\n");
    printf("\n");
}

void displayLinkedUtas(LINKEDUTAS l, Kicau Twt)
{ // Display SELURUH LINKEDUTAS, asumsi pada main sudah diambilkan Linkedutas dengan id_utas masukan
    // print kicauan utama dulu
    printf("| ID = %d\n", ID(Twt));
    printf("| ");
    printEntry(AUTHOR(Twt));
    printf("\n");
    printf("| ");
    TulisDATETIME(WAKTU(Twt));
    printf("\n");
    printf("| "), printEntry(TEXT(Twt));
    printf("\n");
    printf("\n");

    // coba print semua utas
    //  Address p;
    Address p;
    int i = 0;
    p = FIRSTUTAS(l);
    while (p != NULL)
    {
        printf("    | INDEX = %d\n", i);
        printf("    | ");
        printEntry(AUTHOR(Twt));
        printf("\n");
        printf("    | ");
        TulisDATETIME(TIME(INFOUTAS(p)));
        printf("\n");
        printf("    | "), printEntry(TEXTUTAS(INFOUTAS(p)));
        printf("\n");
        printf("\n");
        i++;
        p = NEXT(p);
    }
}