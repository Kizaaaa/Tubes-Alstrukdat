#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"

void CreateTweet(Kicau *k, int id, Entry author, Entry text){
    ID(*k) = id;
    LIKE(*k) = 0;
    AUTHOR(*k) = author;
    TEXT(*k) = text;
    // NEXT(*k) = NULL;
    WAKTU(*k) = GetLocalTime();
}

void DisplayTweet(Kicau k){
    printf("| ID = %d\n",ID(k));
    printf("| "); printEntry(AUTHOR(k)); printf("\n");
    printf("| "); TulisDATETIME(WAKTU(k)); printf("\n");
    printf("| "); printEntry(TEXT(k)); printf("\n");
    printf("| Disukai = %d\n",LIKE(k));
}