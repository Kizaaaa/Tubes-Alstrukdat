#include <stdio.h>
#include "../../boolean.h"
#include "entrymachine.h"

boolean EndEntry;
Entry currentEntry;

int powerDifferentiated(int x, int y)
// x^y
{
    int a = 1;
    int fin = 1;
    for (a = 1; a <= y; a++)
    {
        fin = fin * x;
    }
    return fin;
}

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

Entry StringToEntry(char *input, int size)
{
    Entry e;
    e.Length = size;
    for (int i = 0; i < size; i++)
    {
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

Entry LOWER(Entry n){
    Entry m;
    m.Length = n.Length;
    for(int i=0;i<n.Length;i++){
        if(n.TabEntry[i] < 91){
            m.TabEntry[i] = n.TabEntry[i] + 32;
        } else {
            m.TabEntry[i] = n.TabEntry[i];
        }
    }
    return m;
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

boolean CHECKNOMORHP(Entry n){
    int i = 0;
    while(i < n.Length){
        if(n.TabEntry[i] - '0' < 0 || n.TabEntry[i] - '0' > 9){
            return false;
        } else {
            i++;
        }
    }
    return true;
}

boolean CHECKWETON(Entry n){
    n = LOWER(n);
    if(isSame(n,StringToEntry("pahing",6)) || isSame(n,StringToEntry("kliwon",6)) || isSame(n,StringToEntry("wage",4)) || isSame(n,StringToEntry("pon",3)) || isSame(n,StringToEntry("legi",4))){
        return true;
    }
    return false;
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

Entry PotongEntry(Entry n, int panjang){
    Entry e;
    e.Length = panjang;
    for(int i=0;i<panjang;i++){
        e.TabEntry[i] = n.TabEntry[i];
    }
    return e;
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
    int j = 0;
    while (n.TabEntry[j] == 10)
    {

        int i = 0;
        for (i = 0; i < n.Length - 1; i++)
        {
            n.TabEntry[i] = n.TabEntry[i + 1];
        }
        n.Length -= 1;
        j++;
    }
    return n;
}

Entry cutBeforeEntry(Entry n, int k)
{
    Entry m;
    m.Length = k;
    for (int i = 0; i < k; i++)
    {
        m.TabEntry[i] = n.TabEntry[i];
    }
    return m;
}

Entry cutAfterEntry(Entry n, int k)
{
    Entry m;
    m.Length = n.Length - k;
    for (int i = 0; i < m.Length; i++)
    {
        m.TabEntry[i] = n.TabEntry[k + 1 + i];
    }
    return m;
}

int firstNumParam(Entry n)
/*  Parameter Entry TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
    e.g.
    BALAS 111 11;
    firstNumParam(currentEntry) akan mengembalikan nilai 111
    SUKA_KICAUAN 69420;
    firstNumParam(currentEntry) akan mengembalikan nilai 69420
    BALAS 86 -1;
    firstNumParam(currentEntry) akan mengembalikan nilai 86
    BALAS 76 -9;
    firstNumParam(currentEntry) akan mengembalikan nilai 76 */
{
    Entry p;
    p.Length = 0;
    int k;
    int i = 0;
    int ret = 0;
    boolean sev = false;
    while (n.TabEntry[i] != 32)
    {
        n = cutAfterEntry(n, 0);
    }
    n = cutAfterEntry(n, 0);
    while (n.TabEntry[i] != 32 && !sev)
    {
        p.Length += 1;
        p.TabEntry[i] = n.TabEntry[i];
        i++;
        if (i == n.Length)
        {
            sev = true;
        }
    }
    i = 0;
    while (i < p.Length)
    {
        k = p.TabEntry[i] - '0';
        ret += k * powerDifferentiated(10, p.Length - (i + 1));
        i++;
    }
    return ret;
}

int secondNumParam(Entry n)
/*  Parameter Entry TIDAK PERLU dipotong menggunakan cutAfter atau cutBefore
    e.g.
    BALAS 111 11;
    secondNumParam(currentEntry) akan mengembalikan nilai 11
    SUKA_KICAUAN 69420;
    secondNumParam(currentEntry) akan mengembalikan nilai 0
    BALAS 86 -1;
    secondNumParam(currentEntry) akan mengembalikan nilai -1
    BALAS 76 -9;
    secondNumParam(currentEntry) akan mengembalikan nilai -1 */
{
    Entry p;
    p.Length = 0;
    int k;
    int i = 0;
    int j = 0;
    int ret = 0;
    while (n.TabEntry[i] != 32)
    {
        n = cutAfterEntry(n, 0);
    }
    n = cutAfterEntry(n, 0);
    while (n.TabEntry[i] != 32)
    {
        i++;
    }
    n = cutAfterEntry(n, i);
    while (j < n.Length)
    {
        p.Length += 1;
        p.TabEntry[j] = n.TabEntry[j];
        j++;
    }
    if (p.TabEntry[0] == 45)
    {
        return -1;
    }
    else
    {
        j = 0;
        while (j < p.Length)
        {
            k = p.TabEntry[j] - '0';
            ret += k * powerDifferentiated(10, p.Length - (j + 1));
            j++;
        }
        return ret;
    }
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

/*
gcc -o tes2 ADT/EntryMachine/entrymachine.c ADT/EntryMachine/charmachine.c
*/

// int main(){
//     STARTENTRY();
//     currentEntry = StringToEntry("",0);
//     STARTENTRY();
//     currentEntry = cleansedEntry(currentEntry);
//     printf("%d",currentEntry.Length);
//     return 0;
// }