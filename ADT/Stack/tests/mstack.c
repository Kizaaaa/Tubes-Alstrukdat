#include <stdio.h>
#include "../stack.h"

void DisplayStack(Stack S)
{
    printf("==============\n");
    while (ADDR_TOP(S) != NULL)
    {
        printEntry(TEXTS(INFOS(ADDR_TOP(S))));
        // TulisDATETIME(WAKTUS(INFOS(ADDR_TOP(S))));
        ADDR_TOP(S) = NEXTS(ADDR_TOP(S));
        printf("\n");
        // printf("GAP\n");
    }
    printf("==============\n");
}

int main()
{
    printf("============================== DRIVER STACK ===============================\n");
    printf("=== Seluruh new line yang terdapat di awal ENTRY masukan akan diabaikan ===\n");
    Stack S;
    CreateStack(&S);
    Entry entryA;
    Eltypes tempET;

    printf("1. Pop\n2. Push\n3. End\nMasukkan pilihan (1/2/3): ");
    STARTENTRY();
    while (!isSame(cleansedEntry(currentEntry), StringToEntry("3", 1)))
    {
        if (isSame(cleansedEntry(currentEntry), StringToEntry("2", 1)))
        {
            printf("Silakan masukkan ENTRY:\n");
            STARTENTRY();
            printf("Hasil Stack:\n");
            entryA = cleansedEntry(currentEntry);
            push(&S, entryA);
            DisplayStack(S);
            printf("\n");
        }
        else if (isSame(cleansedEntry(currentEntry), StringToEntry("1", 1)))
        {
            if (lengthS(S) == 0)
            {
                printf("Nothing to pop\n");
            }
            else
            {
                pop(&S, &tempET);
                DisplayStack(S);
                printf("\n");
            }
        }
        else
        {
            printf("Input tidak valid\n");
        }
        printf("1. Pop\n2. Push\n3. End\nMasukkan pilihan (1/2/3): ");
        STARTENTRY();
    }

    return 0;
}