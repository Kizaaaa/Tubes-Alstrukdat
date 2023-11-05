#include "../../boolean.h"
#include "../../ADT/ListDin/listdin.h"
#include "../../ADT/EntryMachine/entrymachine.h"
#include "../../ADT/EntryMachine/charmachine.h"
#include "../../ADT/Kicau/kicau.h"
#include "../../ADT/LinkedListTweet/listliniertweet.h"
#include "../../ADT/ListDinLLTweet/listdintweet.h"
#include "../../ADT/StackDraf/stackdraf.h"

void SaveDraf(StackD *s, Kicau k)
{
    PushD(s, k);
}

void PublishDraf(StackD *s, ListDinT *l)
{
    Kicau n;
    PopD(s, &n);
    insertLastListDinT(l, n);
}

void DeleteDrafView(StackD *s)
{
    Kicau n;
    PopD(s, &n);
}

void InitializeDrafCreate(StackD *s, Entry auth, int aidi, ListDinT *l)
{
    Kicau tempk;
    CreateKicau(&tempk, aidi, auth);
    Entry n, temp;
    STARTENTRY();
    n = cleansedEntry(currentEntry);
    CLOSEENTRY();
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTENTRY();
    temp = cleansedEntry(currentEntry);
    CLOSEENTRY();
    if (isSame(temp, StringToEntry("SIMPAN", 6)))
    {
        TEXT(tempk) = n;
        SaveDraf(s, tempk);
        printf("Draf telah berhasil disimpan!\n");
    }
    else if (isSame(temp, StringToEntry("TERBIT", 6)))
    {
        TEXT(tempk) = n;
        WAKTU(tempk) = GetLocalTime();
        PublishDraf(s, l);
        printf("Selamat! Draf kicauan telah diterbitkan!\n");
        printf("Detil kicauan: \n");
        DisplayKicau(tempk);
    }
    else if (isSame(temp, StringToEntry("HAPUS", 5)))
    {
    }
}

void InitializeDrafView(StackD *s, ListDinT *l)
{
    if (IsEmptyD(*s))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Entry temp;
        printf("Ini draf terakhir anda:\n");
        DisplayKicau(InfoTopD(*s));
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        STARTENTRY();
        temp = cleansedEntry(currentEntry);
        CLOSEENTRY();
        if (isSame(temp, StringToEntry("HAPUS", 5)))
        {
            DeleteDrafView(s);
        }
        else if (isSame(temp, StringToEntry("TERBIT", 5)))
        {
            PublishDraf(s, l);
            printf("Selamat! Draf kicauan telah diterbitkan!\n");
            printf("Detil kicauan: \n");
            DisplayKicau(InfoTopD(*s));
        }
        else if (isSame(temp, StringToEntry("UBAH", 4)))
        {
            printf("Masukkan draf yang baru:\n");
            Entry n;
            STARTENTRY();
            n = cleansedEntry(currentEntry);
            CLOSEENTRY();
            TEXT(InfoTopD(*s)) = n;
        }
        else if (isSame(temp, StringToEntry("SIMPAN", 6)))
        {
            printf("Draf telah berhasil disimpan!\n");
        }
        else if (isSame(temp, StringToEntry("KEMBALI", 6)))
        {
        }
    }
}