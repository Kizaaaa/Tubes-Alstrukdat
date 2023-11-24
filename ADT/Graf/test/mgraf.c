#include <stdio.h>
#include "../graf.h"

int main()
{
    printf("=========================== DRIVER GRAF ===========================\n");

    Graf G;
    CreateGraf(&G);
    printf("Simpul 0: %d\n", Simpul(G, 0));
    printf("Busur 0-0: %d\n", Busur(G, 0, 0));
    printf("Busur 0-1: %d\n", Busur(G, 0, 1));
    printf("Busur 1-0: %d\n", Busur(G, 1, 0));
    printf("Busur 1-1: %d\n", Busur(G, 1, 1));

    TambahTeman(&G, 0, 1);
    printf("Busur 0-1: %d\n", Busur(G, 0, 1));
    printf("Busur 1-0: %d\n", Busur(G, 1, 0));
    
    HapusTeman(&G, 0, 1);
    printf("Busur 0-1: %d\n", Busur(G, 0, 1));
    printf("Busur 1-0: %d\n", Busur(G, 1, 0));

    return 0;
}