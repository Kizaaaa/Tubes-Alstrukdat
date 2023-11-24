#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

void CreateHashMap(HashMap *M)
{
    HMNEFF(*M) = 0;
}

int generateHash(Entry e)
{
    e = LOWER(e);
    long long p = 31, m = 9971;
    long long hash = 0;
    long long p_pow = 1;
    for (int i = 0; i < e.Length; i++)
    {
        hash = (hash + (e.TabEntry[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash;
}

AddressHash newNodeHash(Kicau k)
{
    AddressHash p = (AddressHash)malloc(sizeof(NODEHASH));
    if (p != NULL)
    {
        HASHVALUE(NHINFO(p)) = k;
        HASHKEY(NHINFO(p)) = generateHash(TAGAR(k));
        NHNEXT(p) = NULL;
    }
}

void getndisplayHM(HashMap *M, ListDinT *L, Entry tg)
{
    int counter = 0;
    for (int i = 0; i < NEFFT(*L); i++)
    {
        if (TAGAR(ELMTT(*L, i)).Length != 0)
        {
            AddressHash new = newNodeHash(ELMTT(*L, i));
            int Cidx = generateHash(TAGAR(ELMTT(*L, i)));
            boolean loop = false;
            while (THEHASHELMT(*M, Cidx) != NULL)
            {
                Cidx++;
                loop = true;
                // NHNEXT(THEHASHELMT(*M, Cidx - 1)) = new;
            }
            if (loop)
            {
                NHNEXT(THEHASHELMT(*M, Cidx - 1)) = new;
            }
            THEHASHELMT(*M, Cidx) = new;
        }
    }

    AddressHash cur = THEHASHELMT(*M, generateHash(cleansedEntry(tg)));
    while (cur != NULL)
    {
        counter += 1;
        printf("================\n");
        DisplayKicau(HASHVALUE(NHINFO(cur)));
        cur = NHNEXT(cur);
    }

    if (counter == 0)
    {
        printf("Tidak terdapat kicauan dengan tagar tersebut!\n");
    }
}

int main()
{
    ListDinT L;
    HashMap M;
    Entry author;
    CreateListDinT(&L, 100);
    Kicau a, b, c;
    STARTENTRY();
    author = cleansedEntry(currentEntry);
    CreateKicau(&L, author);
    CreateKicau(&L, author);
    CreateKicau(&L, author);

    STARTENTRY();
    getndisplayHM(&M, &L, cleansedEntry(currentEntry));
}