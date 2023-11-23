#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include <stdlib.h>
#include "sys/stat.h"
#include "boolean.h"
#include "ADT/EntryMachine/entrymachine.h"
#include "ADT/Kicau/kicau.h"
#include "ADT/ListProfil/listprofil.h"
#include "ADT/Graf/graf.h"
#include "ADT/ListDinLLTweet/listdintweet.h"
#include "ADT/ListDin/listdin.h"
// #include "ADT/DSU/dsu.h"

void SimpanBatch(Graf Pertemanan, ListStatik ListProfil, ListDinT KicauGlobal, ListDin UtasGlobal);

void MuatBatch(Graf *Pertemanan, ListStatik *ListProfil, ListDinT *KicauGlobal, ListDin *UtasGlobal, long long int *IDUtas);

#endif