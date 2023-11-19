#include "../../boolean.h"
#include "../../ADT/EntryMachine/entrymachine.h"
#include "../../ADT/EntryMachine/charmachine.h"
#include "../../ADT/Kicau/kicau.h"
#include "../../ADT/LinkedListTweet/listliniertweet.h"
#include "../../ADT/ListDinLLTweet/listdintweet.h"
// #include "../../ADT/StackDraf/stackdraf.h"
#include "../../ADT/LinkedListStack/LLStackD.h"

void InitializeDrafCreate(LLStackD *s, Entry auth, int aidi, ListDinT *l);

void InitializeDrafView(LLStackD *s, ListDinT *l);

void SaveDraf(LLStackD *s, Kicau k);

void PublishDrafCreate(Kicau n, ListDinT *l);

void PublishDrafView(LLStackD *s, ListDinT *l);

void DeleteDrafCreate(LLStackD *s);

void UbahRec(LLStackD *s, ListDinT *l);

// void InitializeDrafCreate(StackD *s, Entry auth, int aidi, ListDinT *l);

// void InitializeDrafView(StackD *s, ListDinT *l);

// void SaveDraf(StackD *s, Kicau k);

// void PublishDrafCreate(Kicau n, ListDinT *l);

// void PublishDrafView(StackD *s, ListDinT *l);

// void DeleteDrafCreate(StackD *s);

// void UbahRec(StackD *s, ListDinT *l);

// void DeleteDrafView(StackD *s);
