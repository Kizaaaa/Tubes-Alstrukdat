#ifndef KICAU_H
#define KICAU_H

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../EntryMachine/entrymachine.h"
#include "../DateTime/datetime.h"
#include "../Utas/utas.h"

typedef struct kicau
{
    int Id;
    int Like;
    Entry Author;
    Entry Text;
    UTAS Next;
    DATETIME Waktu;
} Kicau;

/* ********** SELEKTOR ********** */
#define ID(k) (k).Id
#define LIKE(k) (k).Like
#define AUTHOR(k) (k).Author
#define TEXT(k) (k).Text
#define NEXT(k) (k).Next
#define WAKTU(k) (k).Waktu

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Tweet */
void CreateTweet(Kicau *k, int id, Entry author, Entry text);

void DisplayTweet(Kicau k);
#endif