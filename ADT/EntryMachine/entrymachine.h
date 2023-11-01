/* Definisi Mesin Masukan: Model Akuisisi Versi I */

#ifndef __ENTRYMACHINE_H__
#define __ENTRYMACHINE_H__

#include "../../boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '

typedef struct
{
   char TabEntry[NMax]; /* container penyimpan entry, indeks yang dipakai [0..NMax-1] */
   int Length;
} Entry;

/* State Mesin Entry */
extern boolean EndEntry;
extern Entry currentEntry;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTENTRY();
/* I.S. : currentChar sembarang
   F.S. : currentChar = MARK;
          currentEntry adalah entry yang sudah diakuisisi tanpa melakukan ignore terhadap blank
          diperlukan penggunaan CLOSEENTRY() untuk mengakhiri setiap STARTENTRY()*/

void CLOSEENTRY();
/* Menutup Entry */

void COPYENTRY();
/* Mengakuisisi entry, menyimpan dalam currentEntry
   I.S. : currentChar adalah karakter pertama dari entry
   F.S. : currentEntry berisi entry yang sudah diakuisisi;
          currentChar = MARK;
          sisa entry TIDAK "dipotong" */

/* Utility Mesin Entry */
boolean CHECKVALIDTWEET(Entry n);
/*  Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 280 dan Length != 0 dan tidak bernilai spasi semuanya)
    dan false jika tweet tidak valid */

boolean CHECKVALIDUNP(Entry n);
/*  Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 20 dan Length != 0)
    dan false jika tweet tidak valid */

void printEntry(Entry n);

#endif