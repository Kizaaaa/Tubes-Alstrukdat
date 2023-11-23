#ifndef HASHMAP_H
#define HASHMAP_H

#include "../../boolean.h"
#include "../Kicau/kicau.h"
#include "../Utas/utas.h"
#include "../ListDinLLTweet/listdintweet.h"
#include "../EntryMachine/entrymachine.h"

typedef struct
{
    int hashKey;
    Kicau hashValue;
} Hash;

#define HASHKEY(H) (H).hashKey
#define HASHVALUE(H) (H).hashValue

typedef struct nodeHash *AddressHash;

typedef struct nodeHash
{
    Hash infoNH;
    AddressHash nextNH;
} NODEHASH;

#define NHINFO(NH) (NH)->infoNH
#define NHNEXT(NH) (NH)->nextNH

#define HMCAP 9971
typedef struct
{
    AddressHash hashmapContents[HMCAP];
    int hashnEff;
} HashMap;

#define THEHASH(HM) (HM).hashmapContents
#define THEHASHELMT(HM, i) (HM).hashmapContents[i]
#define HMNEFF(HM) (HM).hashnEff

void CreateHashMap(HashMap *M);

void getndisplayHM(HashMap *M, ListDinT *L, Entry tg);

AddressHash newNodeHash(Kicau k);

int generateHash(Entry e);

#endif
