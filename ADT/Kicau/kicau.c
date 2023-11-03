#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"

void CreateKicau(Kicau *k, int id, Entry author){
    ID(*k) = id;
    LIKE(*k) = 0;
    AUTHOR(*k) = author;
    WAKTU(*k) = GetLocalTime();

    printf("Masukkan kicauan:\n");
    STARTENTRY();
    if(!CHECKVALIDTWEET(cleansedEntry(currentEntry))){
        printf("Kicauan tidak boleh hanya berisi spasi!");
        STARTENTRY();
    }
    TEXT(*k) = cleansedEntry(currentEntry);
    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    DisplayKicau(*k);
}

void EditKicau(Kicau *k){
    
}

void DisplayKicau(Kicau k){
    printf("| ID = %d\n",ID(k));
    printf("| "); printEntry(AUTHOR(k)); printf("\n");
    printf("| "); TulisDATETIME(WAKTU(k)); printf("\n");
    printf("| "); printEntry(TEXT(k)); printf("\n");
    printf("| Disukai = %d\n",LIKE(k));
}

void LikeKicau(Kicau *k){
    LIKE(*k)++;
}