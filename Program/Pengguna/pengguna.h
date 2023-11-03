#include <stdio.h>
#include "../EntryMachine/charmachine.h"
#include "../EntryMachine/entrymachine.h"
#include "ListUser.h"

void daftar(ListUser *l);
/*  I.S. Prekondisi : Belum login dan ListUser terdefinisi*/
/*  F.S. Akun baru ditambahkan */

void masuk(ListUser *l);
/*  I.S. Prekondisi : Belum login dan sudah mendaftar*/
/*  F.S. Akun baru ditambahkan */


void keluar();
/*  I.S. sudah login*/
/*  F.S. berhasil keluar akun*/ 