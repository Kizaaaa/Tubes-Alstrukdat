#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT/EntryMachine/entrymachine.h"
#include "ADT/Kicau/kicau.h"
#include "ADT/ListProfil/listprofil.h"
#include "ADT/Graf/graf.h"
#include "ADT/ListDinLLTweet/listdintweet.h"
#include "ADT/ListDin/listdin.h"
#include "ADT/DSU/dsu.h"

void SimpanPengguna(Graf Pertemanan, ListStatik ListProfil);

void SimpanKicauan(ListDinT KicauGlobal);

void SimpanBalasan(ListDinT KicauGlobal);

void SimpanDraf(ListStatik ListProfil);

void SimpanUtas(ListDinT KicauGlobal, ListDin UtasGlobal);

void SimpanBatch(Graf Pertemanan, ListStatik ListProfil, ListDinT KicauGlobal, ListDin UtasGlobal);

#endif