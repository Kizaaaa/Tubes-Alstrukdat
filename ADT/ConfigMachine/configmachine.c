#include <stdio.h>
#include "../../boolean.h"
#include "configmachine.h"

boolean EndConfig;
CONFIGG currentConfig;

// int powerDifferentiated(int x, int y)
// // x^y
// {
//     int a = 1;
//     int fin = 1;
//     for (a = 1; a <= y; a++)
//     {
//         fin = fin * x;
//     }
//     return fin;
// }

void CLOSEConfig()
/* Menutup CONFIGG */
{
    EndConfig = true;
}

void COPYConfig()
/* Mengakuisisi Config, menyimpan dalam currentConfig
   I.S. : currentChar adalah karakter pertama dari Config
   F.S. : currentConfig berisi Config yang sudah diakuisisi;
          currentChar = CONFIGMARK;
          sisa Config TIDAK "dipotong" */
{
    // IgnoreBlanks();
    int i = 0;
    while (currentConfChar != CONFIGMARK && i < NMaxCC)
    {
        currentConfig.TabConfig[i] = currentConfChar;
        ADVCC();
        i++;
    }
    currentConfig.Length = i;
}

void IgnoreBlanksCC() // Tetap dibuat, by any chance bisa digunakan
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = CONFIGMARK */
{
    while (currentConfChar == BLANKCC)
    {
        ADVCC();
    }
}

void STARTConfig()
/* I.S. : currentChar sembarang
   F.S. : currentChar = CONFIGMARK;
          currentConfig adalah Config yang sudah diakuisisi tanpa melakukan ignore terhadap blank
          diperlukan penggunaan CLOSEConfig() untuk mengakhiri setiap STARTConfig()*/
{
    STARTCC();
    // IgnoreBlanks();
    if (currentConfChar == CONFIGMARK)
    {
        EndConfig = true;
    }
    else
    {
        EndConfig = false;
        COPYConfig();
    }
}
