/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "configcharmachine.h"
#include <stdio.h>

char currentConfChar;

static FILE *pitaconf;
static int retvalconf;

void STARTCC()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pitaconf posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : currentConfChar adalah karakter pertama pada pitaconf. Jika currentConfChar != MARK maka EOP akan padam (false).
              Jika currentConfChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    pitaconf = stdin;
    ADVCC();
}

void ADVCC()
{
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela =
              currentConfChar, currentConfChar != MARK
       F.S. : currentConfChar adalah karakter berikutnya dari currentConfChar yang lama,
              currentConfChar mungkin = MARK.
                    Jika  currentConfChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retvalconf = fscanf(pitaconf, "%c", &currentConfChar);
}