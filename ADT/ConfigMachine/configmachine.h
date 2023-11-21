/* Definisi Mesin Masukan: Model Akuisisi Versi I */

#ifndef __CONFIGMACHINE_H__
#define __CONFIGMACHINE_H__

#include "../../boolean.h"
#include "configcharmachine.h"

#define NMaxCC 280
#define BLANKCC ' '

typedef struct
{
    char TabConfig[NMaxCC]; /* container penyimpan Config, indeks yang dipakai [0..NMaxCC-1] */
    int Length;
} CONFIGG;

/* State Mesin CONFIGG */
extern boolean EndConfig;
extern CONFIGG currentConfig;

CONFIGG StringToConfig(char *input, int size);

void IgnoreBlanksCC();
/* Mengabaikan satu atau beberapa BLANKCC
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANKCC atau currentChar = MARK */

void STARTConfig();
/* I.S. : currentChar sembarang
   F.S. : currentChar = MARK;
          currentConfig adalah Config yang sudah diakuisisi tanpa melakukan ignore terhadap blank
          diperlukan penggunaan CLOSEConfig() untuk mengakhiri setiap STARTConfig()*/

void CLOSEConfig();
/* Menutup CONFIGG */

void COPYConfig();
/* Mengakuisisi Config, menyimpan dalam currentConfig
   I.S. : currentChar adalah karakter pertama dari Config
   F.S. : currentConfig berisi Config yang sudah diakuisisi;
          currentChar = MARK;
          sisa Config TIDAK "dipotong" */

// CONFIGG LOWER(CONFIGG n);

// /* Utility Mesin CONFIGG */
// boolean CHECKVALIDTWEET(CONFIGG n);
// /*  Melakukan validasi terhadap input tweet
//     Mengembalikan nilai true jika tweet valid (Length <= 280 dan Length != 0 dan tidak bernilai spasi semuanya)
//     dan false jika tweet tidak valid */

// boolean CHECKNOMORHP(CONFIGG n);

// boolean CHECKWETON(CONFIGG n);

// CONFIGG UnifyWeton(CONFIGG n);

// boolean CHECKVALIDUNP(CONFIGG n);
// /*  Melakukan validasi terhadap input tweet
//     Mengembalikan nilai true jika tweet valid (Length <= 20 dan Length != 0)
//     dan false jika tweet tidak valid */

// boolean CHECKVALIDBIO(CONFIGG n);

// CONFIGG PotongConfig(CONFIGG n, int panjang);

// void printConfig(CONFIGG n);

// boolean isSame(CONFIGG n1, CONFIGG n2);

// CONFIGG cleansedConfig(CONFIGG n);

// CONFIGG cutBeforeConfig(CONFIGG n, int k);

// CONFIGG cutAfterConfig(CONFIGG n, int k);

// int firstNumParam(CONFIGG n);
// /*  Parameter CONFIGG TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
//     e.g.
//     BALAS 111 11;
//     firstNumParam(currentConfig) akan mengembalikan nilai 111
//     SUKA_KICAUAN 69420;
//     firstNumParam(currentConfig) akan mengembalikan nilai 69420
//     BALAS 86 -1;
//     firstNumParam(currentConfig) akan mengembalikan nilai 86
//     BALAS 76 -9;
//     firstNumParam(currentConfig) akan mengembalikan nilai 76 */

// int secondNumParam(CONFIGG n);
// /*  Parameter CONFIGG TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
//     e.g.
//     BALAS 111 11;
//     secondNumParam(currentConfig) akan mengembalikan nilai 11
//     SUKA_KICAUAN 69420;
//     secondNumParam(currentConfig) akan mengembalikan nilai 0
//     BALAS 86 -1;
//     secondNumParam(currentConfig) akan mengembalikan nilai -1
//     BALAS 76 -9;
//     secondNumParam(currentConfig) akan mengembalikan nilai -1 */

#endif