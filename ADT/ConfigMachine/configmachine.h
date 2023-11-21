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

#endif