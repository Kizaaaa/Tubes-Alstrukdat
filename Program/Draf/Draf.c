#include "../../boolean.h"
#include "../../ADT/ListDin/listdin.h"
#include "../../ADT/EntryMachine/entrymachine.h"
#include "../../ADT/EntryMachine/charmachine.h"
#include "../../ADT/Kicau/kicau.h"
#include "../../ADT/LinkedListTweet/listliniertweet.h"
#include "../../ADT/ListDinLLTweet/listdintweet.h"
#include "../../ADT/StackDraf/stackdraf.h"

void SimpanDraf(StackD *s, Kicau k)
{
    PushD(s, k);
}

void PublishDraf(StackD *s, ListDinT *l)
{
    Kicau n;
    PopD(s, &n);
    insertLastListDinT(l, n);
}

void DeleteDraf(StackD *s)
{
    Kicau n;
    PopD(s, &n);
}