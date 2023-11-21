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

void displayLinkedUtas(Kicau Twt)
{ // Display SELURUH LINKEDUTAS, asumsi pada main sudah diambilkan Linkedutas dengan id_utas masukan
    // print kicauan utama dulu
    DisplayKicau(Twt); printf("\n");

    Address p;
    p = FIRSTUTAS(UTASAN(Twt));
    while (p != NULL)
    {
        printf("    | INDEX = %d\n", INDEKS(INFOUTAS(p)));
        printf("    | ");
        printEntry(AUTHOR(Twt));
        printf("\n");
        printf("    | ");
        TulisDATETIME(TIME(INFOUTAS(p)));
        printf("\n");
        printf("    | "), printEntry(TEXTUTAS(INFOUTAS(p)));
        printf("\n");
        printf("\n");
        p = NEXT(p);
    }
}