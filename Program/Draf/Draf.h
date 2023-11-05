#include "../../boolean.h"
#include "../../ADT/ListDin/listdin.h"
#include "../../ADT/EntryMachine/entrymachine.h"
#include "../../ADT/EntryMachine/charmachine.h"
#include "../../ADT/Kicau/kicau.h"
#include "../../ADT/LinkedListTweet/listliniertweet.h"
#include "../../ADT/ListDinLLTweet/listdintweet.h"
#include "../../ADT/StackDraf/stackdraf.h"

void InitializeDrafCreate(StackD *s, Entry auth, int aidi, ListDinT *l);

void InitializeDrafView(StackD *s, ListDinT *l);

void SaveDraf(StackD *s, Kicau k);

void PublishDraf(StackD *s, ListDinT *l);

void DeleteDrafCreate(StackD *s);

// void DeleteDrafView(StackD *s);
