#ifndef LLS_H
#define LLS_H

#include "../../boolean.h"
#include "../Kicau/kicau.h"
#include "../LinkedListTweet/listliniertweet.h"

/* Definisi Node : */

typedef NodeT StackNode;
// typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOPD : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    AddressforLLT TopLLS;
    int LLSDAmt;
} LLStackD;

#define TOPLLS(d) (d).TopLLS
#define LLSAMT(d) (d).LLSDAmt
#define TOPLLSKIC(d) (d).INFOT(TOPLLS(d))
#define NEXTLLSKIC(d) (d).NEXTT(TOPLLS(d))

void CreateEmptyLLSD(LLStackD *S);

boolean IsEmptyLLSD(LLStackD S);

// boolean IsFullLLSD(LLStackD S);

void PushD(LLStackD *S, StackNode X);

void PopD(LLStackD *S, StackNode *X);

#endif