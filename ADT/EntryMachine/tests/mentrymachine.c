#include <stdio.h>
#include "../entrymachine.h"

int main()
{
    Entry entryA, entryB;

    // StartEntry, PrintEntry, CleansedEntry
    printf("=========================== DRIVER ENTRYMACHINE ===========================\n");
    printf("=== Seluruh new line yang terdapat di awal ENTRY masukan akan diabaikan ===\n");

    printf("(1 / 8) Testing StartEntry dan PrintEntry\n");
    printf("Silakan masukkan ENTRY:\n");
    STARTENTRY();
    printf("Hasil ENTRY:\n");
    entryA = cleansedEntry(currentEntry);
    printEntry(entryA);
    printf("\n");

    printf("(2 / 8) Testing Check Valisdasi Tweet\n");
    printf("Mengeluarkan INVALID jika panjang ENTRY > 280 atau sama dengan 0\n");
    STARTENTRY();
    entryA = cleansedEntry(currentEntry);
    if (CHECKVALIDTWEET(entryA))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    printf("(3 / 8) Testing Check Valisdasi Username dan Password\n");
    printf("Mengeluarkan INVALID jika panjang ENTRY > 20 atau sama dengan 0\n");
    STARTENTRY();
    entryA = cleansedEntry(currentEntry);
    if (CHECKVALIDUNP(entryA))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    printf("(4 / 8) Testing Check Valisdasi Bio\n");
    printf("Mengeluarkan INVALID jika panjang ENTRY > 135 atau sama dengan 0\n");
    STARTENTRY();
    entryA = cleansedEntry(currentEntry);
    if (CHECKVALIDBIO(entryA))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    printf("(5 / 8) Testing Check Valisdasi weton\n");
    printf("Mengeluarkan INVALID jika ENTRY bukan sebuah weton\n");
    STARTENTRY();
    entryA = cleansedEntry(currentEntry);
    if (CHECKWETON(entryA))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    printf("(6 / 8) Testing Check isSame\n");
    printf("Mengeluarkan INVALID jika kedua ENTRY tidak sama\n");
    STARTENTRY();
    entryA = cleansedEntry(currentEntry);
    STARTENTRY();
    entryB = cleansedEntry(currentEntry);
    if (isSame(entryA, entryB))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    printf("(7 / 8) Testing LOWER\n");
    printf("Akan Mengeluarkan hasil entry dengan seluruh karakter dilowercase\n");
    printf("Silakan masukkan ENTRY:\n");
    STARTENTRY();
    printf("Hasil ENTRY:\n");
    entryA = LOWER(cleansedEntry(currentEntry));
    printEntry(entryA);
    printf("\n");

    printf("(8 / 8) Testing UNIFY\n");
    printf("Akan Mengeluarkan hasil entry dengan huruf kapital di awal ENTRY saja\n");
    printf("Silakan masukkan ENTRY:\n");
    STARTENTRY();
    printf("Hasil ENTRY:\n");
    entryA = UnifyWeton(cleansedEntry(currentEntry));
    printEntry(entryA);
    printf("\n");

    return 0;
}