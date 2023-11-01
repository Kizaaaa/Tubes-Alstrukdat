#include <stdio.h>
#include <stdlib.h>
#include "kicau.h"

void CreateTweet(Kicau *k, int id, Entry author, Entry text){
    ID(*k) = id;
    LIKE(*k) = 0;
    AUTHOR(*k) = author;
    TEXT(*k) = text;
    NEXT(*k) = NULL;
    WAKTU(*k) = GetLocalTime();
}

void DisplayTweet(Kicau k){
    printf("| ID = %d\n",ID(k));
    TulisDATETIME(WAKTU(k));
    printf("| Disukai = %d\n",LIKE(k));
}