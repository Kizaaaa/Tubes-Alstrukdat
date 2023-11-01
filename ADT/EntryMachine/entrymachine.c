#include <stdio.h>
#include "../../boolean.h"
#include "entrymachine.h"

boolean EndEntry;
Entry currentEntry;

void CLOSEENTRY()
/* Menutup Entry */
{
    EndEntry = true;
}

void COPYENTRY()
/* Mengakuisisi entry, menyimpan dalam currentEntry
   I.S. : currentChar adalah karakter pertama dari entry
   F.S. : currentEntry berisi entry yang sudah diakuisisi;
          currentChar = MARK;
          sisa entry TIDAK "dipotong" */
{
    // IgnoreBlanks();
    int i = 0;
    while (currentChar != MARK && i < NMax)
    {
        currentEntry.TabEntry[i] = currentChar;
        ADV();
        i++;
    }
    currentEntry.Length = i;
}

Entry StringToEntry(char* input, int size){
   Entry e;
   e.Length = size;
   for(int i=0;i<size;i++){
      e.TabEntry[i] = input[i];
   }
   return e;
}

void IgnoreBlanks() // Tetap dibuat, by any chance bisa digunakan
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTENTRY()
/* I.S. : currentChar sembarang
   F.S. : currentChar = MARK;
          currentEntry adalah entry yang sudah diakuisisi tanpa melakukan ignore terhadap blank
          diperlukan penggunaan CLOSEENTRY() untuk mengakhiri setiap STARTENTRY()*/
{
    START();
    // IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndEntry = true;
    }
    else
    {
        EndEntry = false;
        COPYENTRY();
    }
}

boolean CHECKVALIDTWEET(Entry n)
/*  Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 280 dan Length != 0 dan tidak bernilai spasi semuanya)
    dan false jika tweet tidak valid */
{
    boolean valid = false;
    int j = 0;

    if (n.Length > 280 || n.Length == 0)
    {
        return valid;
    }
    else
    {
        while (j < n.Length)
        {
            if (n.TabEntry[j] != 32)
            {
                valid = true;
                return valid;
            }
            j++;
        }
    }
    return valid;
}

boolean CHECKVALIDUNP(Entry n)
/*  UNP = Username and Password
    Melakukan validasi terhadap input tweet
    Mengembalikan nilai true jika tweet valid (Length <= 20 dan Length != 0)
    dan false jika tweet tidak valid */
{
    return (n.Length <= 20 && n.Length != 0);
}

boolean CHECKVALIDBIO(Entry n)
{
    return (n.Length <= 135 && n.Length != 0);
}

boolean isSame(Entry n1, Entry n2)
{
    if (n1.Length != n2.Length)
    {
        return false;
    }
    else
    {
        int j = 0;
        boolean same = true;
        while (j < n1.Length)
        {
            if (n1.TabEntry[j] != n2.TabEntry[j])
            {
                printf("%d", n1.TabEntry[j] != n2.TabEntry[j]);
                same = false;
                return same;
            }
            j++;
        }
        return same;
    }
}

void printEntry(Entry n)
{
    int i = 0;
    for (i = 0; i < n.Length; i++)
    {
        printf("%c", n.TabEntry[i]);
    }
}

Entry cleansedEntry(Entry n)
{
    if (n.TabEntry[0] == 10)
    {
        int i = 0;
        for (i = 0; i < n.Length - 1; i++)
        {
            n.TabEntry[i] = n.TabEntry[i + 1];
        }
        n.Length -= 1;
    }
    return n;
}

/* USAGE */
/*
    Tweet:
    STARTENTRY();
    CLOSEENTRY();
    if (CHECKVALIDTWEET(currentENTRY))
    {
        // proses jika tweet valid
    }
    else
    {
        // proses jika tweet tidak valid
    }

    Username and Password:
    STARTENTRY();
    CLOSEENTRY();
    if (CHECKVALIDUNP(currentENTRY))
    {
        // proses jika UnP valid
    }
    else
    {
        // proses jika UnP tidak valid
    }
*/