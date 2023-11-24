#include <stdio.h>
#include "../utas.h"

void displaylinkedkw(LINKEDUTAS l)
// Hanya untuk testing tanpa Kicau!!
// Display SELURUH LINKEDUTAS, asumsi pada main sudah diambilkan Linkedutas dengan id_utas masukan
// coba print semua utas
{
    Address p;
    p = FIRSTUTAS(l);
    while (p != NULL)
    {
        printf("    | INDEX = %d", INDEKS(INFOUTAS(p)));
        printf("\n");
        printf("    | ");
        TulisDATETIME(TIME(INFOUTAS(p)));
        printf("\n");
        printf("    | "), printEntry(TEXTUTAS(INFOUTAS(p)));
        printf("\n");
        printf("\n");
        p = NEXT(p);
    }
}

int main()
{
    printf("============================== DRIVER UTAS ===============================\n");

    int type, idx;
    LINKEDUTAS L1;
    createLinkedUtas(&L1);
    readUtas(&L1);
    displaylinkedkw(L1);
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        // Test InsertUtas
        printf("Case 1:\n");
        scanf("%d", &idx);
        sambungUtas(&L1, idx);
        displaylinkedkw(L1);
        break;
    case 2:
        // Test DeleteUtas
        printf("Case 2\n");
        scanf("%d", &idx);
        deleteUtasAt(&L1, idx);
        Address point;
        point = FIRSTUTAS(L1);
        if (point == NULL)
        {
            printf("Utas habis\n");
        }
        else
        {
            displaylinkedkw(L1);
        }
        break;
    }

    return 0;
}
// gcc -o mutas ADT/Utas/tests/mutas.c ADT/Utas/utas.c ADT/DateTime/datetime.c ADT/EntryMachine/entrymachine.c ADT/ListDin/listdin.c ADT/Stack/stack.c ADT/Kicau/kicau.c ADT/DateTime/time.c ADT/EntryMachine/charmachine.c