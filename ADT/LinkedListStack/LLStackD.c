#ifndef LLS_H
#define LLS_H

#include "boolean.h"
#include "kicau.h"
#include "listliniertweet.h"
#include "LLStackD.h"
#include <stdlib.h>

/* Definisi Node : */

// typedef NodeT StackNode;
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

void CreateEmptyLLSD(LLStackD *S)
{
    LLSAMT(*S) = 0;
}

boolean IsEmptyLLSD(LLStackD S)
{
    return LLSAMT(S) == NULL;
}

// boolean IsFullLLSD(LLStackD S);

void PushLLSD(LLStackD *S, Kicau X)
{
    if (IsEmptyLLSD(*S))
    {
        AddressforLLT n = newNodeT(X);
        TOPLLS(*S) = n;
        LLSAMT(*S) += 1;
    }
    else
    {
        AddressforLLT n = newNodeT(X);
        NEXTT(n) = TOPLLS(*S);
        TOPLLS(*S) = n;
        LLSAMT(*S) += 1;
    }
}

void PopLLSD(LLStackD *S, Kicau *X)
{
    if (TOPLLS(*S) != NULL)
    {
        *X = INFOT(TOPLLS(*S));
        AddressforLLT temp = TOPLLS(*S);
        TOPLLS(*S) = NEXTT(TOPLLS(*S));
        free(temp);
        LLSAMT(*S)
        --;
    }
}

#endif