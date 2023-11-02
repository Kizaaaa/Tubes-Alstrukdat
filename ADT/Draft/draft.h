/* File : draft.h */
/* PENJELASAN */

#ifndef DRAFT_H
#define DRAFT_H
#include "../Stack/stack.h"
#include "../DateTime/datetime.h"
#include "../EntryMachine/entrymachine.h"
#include "../Kicau/kicau.h"
#include "../../boolean.h"

typedef struct { 
  Entry T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;

#endif