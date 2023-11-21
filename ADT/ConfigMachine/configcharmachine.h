/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CONFIG_CHAR_MACHINE_H__
#define __CONFIG_CHAR_MACHINE_H__

#include "../../boolean.h"

#define CONFIGMARK '\n'
/* State Mesin */
extern char currentConfChar;
extern boolean EOP;

void STARTCC();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentConfChar adalah karakter pertama pada pita
          Jika currentConfChar != MARK maka EOP akan padam (false)
          Jika currentConfChar = MARK maka EOP akan menyala (true) */

void ADVCC();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentConfChar, currentConfChar != MARK
   F.S. : currentConfChar adalah karakter berikutnya dari currentConfChar yang lama,
          currentConfChar mungkin = MARK
          Jika  currentConfChar = MARK maka EOP akan menyala (true) */

#endif