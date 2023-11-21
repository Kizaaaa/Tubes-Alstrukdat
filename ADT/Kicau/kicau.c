#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"

void DisplayKicau(Kicau k)
{
    printf("| ID = %lld\n", ID(k));
    printf("| ");
    printEntry(AUTHOR(k));
    printf("\n");
    printf("| ");
    TulisDATETIME(WAKTU(k));
    printf("\n");
    printf("| ");
    printEntry(TEXT(k));
    printf("\n");
    printf("| Disukai = %lld\n", LIKE(k));
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