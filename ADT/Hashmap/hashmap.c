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
    for (int i = 0; i < NEFFT(*L); i++)
    {
        if (TAGAR(ELMTT(*L, i)).Length != 0)
        {
            AddressHash new = newNodeHash(ELMTT(*L, i));
            int Cidx = generateHash(TAGAR(ELMTT(*L, i)));
            while (HEHASHELMT(*M, Cidx) != NULL)
            {
                Cidx++;
            }
            THEHASHELMT(*M, Cidx) = new;
        }
    }

    AddressHash cur = THEHASHELMT(*M, generateHash(tg));
    while (cur != NULL)
    {
        DisplayKicau(HASHVALUE(NHINFO(cur)));
        cur = NHNEXT(cur);
    }
}

int main()
{
    STARTENTRY();
    printf("%d\n", generateHash(cleansedEntry(currentEntry)));
}