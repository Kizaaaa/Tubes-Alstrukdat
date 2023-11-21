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

// CONFIGG StringToConfig(char *input, int size)
// {
//     CONFIGG e;
//     e.Length = size;
//     for (int i = 0; i < size; i++)
//     {
//         e.TabConfig[i] = input[i];
//     }
//     return e;
// }

// void IgnoreBlanks() // Tetap dibuat, by any chance bisa digunakan
// /* Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = CONFIGMARK */
// {
//     while (currentChar == BLANK)
//     {
//         ADV();
//     }
// }

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

// CONFIGG LOWER(CONFIGG n)
// {
//     CONFIGG m;
//     m.Length = n.Length;
//     for (int i = 0; i < n.Length; i++)
//     {
//         if (n.TabConfig[i] < 91)
//         {
//             m.TabConfig[i] = n.TabConfig[i] + 32;
//         }
//         else
//         {
//             m.TabConfig[i] = n.TabConfig[i];
//         }
//     }
//     return m;
// }

// boolean CHECKVALIDTWEET(CONFIGG n)
// /*  Melakukan validasi terhadap input tweet
//     Mengembalikan nilai true jika tweet valid (Length <= 280 dan Length != 0 dan tidak bernilai spasi semuanya)
//     dan false jika tweet tidak valid */
// {
//     boolean valid = false;
//     int j = 0;

//     if (n.Length > 280 || n.Length == 0)
//     {
//         return valid;
//     }
//     else
//     {
//         while (j < n.Length)
//         {
//             if (n.TabConfig[j] != 32)
//             {
//                 valid = true;
//                 return valid;
//             }
//             j++;
//         }
//     }
//     return valid;
// }

// boolean CHECKNOMORHP(CONFIGG n)
// {
//     int i = 0;
//     while (i < n.Length)
//     {
//         if (n.TabConfig[i] - '0' < 0 || n.TabConfig[i] - '0' > 9)
//         {
//             return false;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return true;
// }

// boolean CHECKWETON(CONFIGG n)
// {
//     n = LOWER(n);
//     if (isSame(n, StringToConfig("pahing", 6)) || isSame(n, StringToConfig("kliwon", 6)) || isSame(n, StringToConfig("wage", 4)) || isSame(n, StringToConfig("pon", 3)) || isSame(n, StringToConfig("legi", 4)))
//     {
//         return true;
//     }
//     return false;
// }

// CONFIGG UnifyWeton(CONFIGG n)
// {
//     n = LOWER(n);
//     n.TabConfig[0] -= 32;
//     return n;
// }

// boolean CHECKVALIDUNP(CONFIGG n)
// /*  UNP = Username and Password
//     Melakukan validasi terhadap input tweet
//     Mengembalikan nilai true jika tweet valid (Length <= 20 dan Length != 0)
//     dan false jika tweet tidak valid */
// {
//     return (n.Length <= 20 && n.Length != 0);
// }

// boolean CHECKVALIDBIO(CONFIGG n)
// {
//     return (n.Length <= 135 && n.Length != 0);
// }

// CONFIGG PotongConfig(CONFIGG n, int panjang)
// {
//     CONFIGG e;
//     e.Length = panjang;
//     for (int i = 0; i < panjang; i++)
//     {
//         e.TabConfig[i] = n.TabConfig[i];
//     }
//     return e;
// }

// boolean isSame(CONFIGG n1, CONFIGG n2)
// {
//     if (n1.Length != n2.Length)
//     {
//         return false;
//     }
//     else
//     {
//         int j = 0;
//         boolean same = true;
//         while (j < n1.Length)
//         {
//             if (n1.TabConfig[j] != n2.TabConfig[j])
//             {
//                 same = false;
//                 return same;
//             }
//             j++;
//         }
//         return same;
//     }
// }

// void printConfig(CONFIGG n)
// {
//     int i = 0;
//     for (i = 0; i < n.Length; i++)
//     {
//         printf("%c", n.TabConfig[i]);
//     }
// }

// CONFIGG cleansedConfig(CONFIGG n)
// {
//     int j = 0;
//     while (n.TabConfig[j] == 10)
//     {

//         int i = 0;
//         for (i = 0; i < n.Length - 1; i++)
//         {
//             n.TabConfig[i] = n.TabConfig[i + 1];
//         }
//         n.Length -= 1;
//         j++;
//     }
//     return n;
// }

// CONFIGG cutBeforeConfig(CONFIGG n, int k)
// {
//     CONFIGG m;
//     m.Length = k;
//     for (int i = 0; i < k; i++)
//     {
//         m.TabConfig[i] = n.TabConfig[i];
//     }
//     return m;
// }

// CONFIGG cutAfterConfig(CONFIGG n, int k)
// {
//     CONFIGG m;
//     m.Length = n.Length - k - 1;
//     for (int i = 0; i < m.Length; i++)
//     {
//         m.TabConfig[i] = n.TabConfig[k + 1 + i];
//     }
//     return m;
// }

// int firstNumParam(CONFIGG n)
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
// {
//     CONFIGG p;
//     p.Length = 0;
//     int k;
//     int i = 0;
//     int ret = 0;
//     boolean sev = false;
//     while (n.TabConfig[i] != 32)
//     {
//         n = cutAfterConfig(n, 0);
//     }
//     n = cutAfterConfig(n, 0);
//     while (n.TabConfig[i] != 32 && !sev)
//     {
//         p.Length += 1;
//         p.TabConfig[i] = n.TabConfig[i];
//         i++;
//         if (i == n.Length)
//         {
//             sev = true;
//         }
//     }
//     i = 0;
//     while (i < p.Length)
//     {
//         k = p.TabConfig[i] - '0';
//         ret += k * powerDifferentiated(10, p.Length - (i + 1));
//         i++;
//     }
//     return ret;
// }

// int secondNumParam(CONFIGG n)
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
// {
//     CONFIGG p;
//     p.Length = 0;
//     int k;
//     int i = 0;
//     int j = 0;
//     int ret = 0;
//     while (n.TabConfig[i] != 32)
//     {
//         n = cutAfterConfig(n, 0);
//     }
//     n = cutAfterConfig(n, 0);
//     while (n.TabConfig[i] != 32)
//     {
//         i++;
//     }
//     n = cutAfterConfig(n, i);
//     while (j < n.Length)
//     {
//         p.Length += 1;
//         p.TabConfig[j] = n.TabConfig[j];
//         j++;
//     }
//     if (p.TabConfig[0] == 45)
//     {
//         return -1;
//     }
//     else
//     {
//         j = 0;
//         while (j < p.Length)
//         {
//             k = p.TabConfig[j] - '0';
//             ret += k * powerDifferentiated(10, p.Length - (j + 1));
//             j++;
//         }
//         return ret;
//     }
// }

// /* USAGE */
// /*
//     Tweet:
//     STARTConfig();
//     CLOSEConfig();
//     if (CHECKVALIDTWEET(currentConfig))
//     {
//         // proses jika tweet valid
//     }
//     else
//     {
//         // proses jika tweet tidak valid
//     }

//     Username and Password:
//     STARTConfig();
//     CLOSEConfig();
//     if (CHECKVALIDUNP(currentConfig))
//     {
//         // proses jika UnP valid
//     }
//     else
//     {
//         // proses jika UnP tidak valid
//     }
// */

// /*
// gcc -o tes2 ADT/ConfigMachine/Configmachine.c ADT/ConfigMachine/charmachine.c
// */

// // int main(){
// //     STARTConfig();
// //     currentConfig = cleansedConfig(currentConfig);
// //     printConfig(cutBeforeConfig(currentConfig,12));
// //     printf("\n");
// //     printConfig(cutAfterConfig(currentConfig,12));
// //     return 0;
// // }