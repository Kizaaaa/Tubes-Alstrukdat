#include <stdio.h>
#include "../listdintweet.h"

int main()
{
    printf("=========================== DRIVER KICAU/LISTDINTWEET ===========================\n");

    Kicau K;
    CreateKicau(&K);
    printf("Isi Kicau:\n");
    PrintKicau(K);
    printf("\n");
    return 0;
}