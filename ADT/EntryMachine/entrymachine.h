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

Entry StringToEntry(char *input, int size);

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

Entry LOWER(Entry n);

/* Utility Mesin Entry */
boolean CHECKVALIDTWEET(Entry n);
/*  Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 280 dan Length != 0 dan tidak bernilai spasi semuanya)
    dan false jika tweet tidak valid */

boolean CHECKNOMORHP(Entry n);

boolean CHECKWETON(Entry n);

Entry UnifyWeton(Entry n);

boolean CHECKVALIDUNP(Entry n);
/*  Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 20 dan Length != 0)
    dan false jika tweet tidak valid */

boolean CHECKVALIDBIO(Entry n);

Entry PotongEntry(Entry n, int panjang);

void printEntry(Entry n);

boolean isSame(Entry n1, Entry n2);

Entry cleansedEntry(Entry n);

Entry cutBeforeEntry(Entry n, int k);

Entry cutAfterEntry(Entry n, int k);

int firstNum(Entry n);

int firstNumParam(Entry n);
/*  Parameter Entry TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
    e.g.
    BALAS 111 11;
    firstNumParam(currentEntry) akan mengembalikan nilai 111
    SUKA_KICAUAN 69420;
    firstNumParam(currentEntry) akan mengembalikan nilai 69420
    BALAS 86 -1;
    firstNumParam(currentEntry) akan mengembalikan nilai 86
    BALAS 76 -9;
    firstNumParam(currentEntry) akan mengembalikan nilai 76 */

int secondNumParam(Entry n);
/*  Parameter Entry TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
    e.g.
    BALAS 111 11;
    secondNumParam(currentEntry) akan mengembalikan nilai 11
    SUKA_KICAUAN 69420;
    secondNumParam(currentEntry) akan mengembalikan nilai 0
    BALAS 86 -1;
    secondNumParam(currentEntry) akan mengembalikan nilai -1
    BALAS 76 -9;
    secondNumParam(currentEntry) akan mengembalikan nilai -1 */

void STARTFILEWORD(char* dir);

void ADVLINE();

long long int EntryToInt(Entry n);

#endif