#include <stdio.h>
#include "../listprofil.h"

int main()
{
    printf("=========================== DRIVER LISTPROFIL ===========================\n");

    printf("DRIVER LIST PROFIL (List Statik dan Queue)\n");
    ListStatik l;
    Queue q;
    Profil p;
    CreateListStatik(&l);
    printf("\nMenambah user\n");
    Daftar(&l);
    p = ELMTLS(l, 0);
    PrintProfil(p);
    printf("\nPenggunaan Queue untuk permintaan pertemanan\n");
    printf("\nTambah permintaan pertemanan\n");
    CreateQueue(&q);
    Elmtqueue elq;
    for (int i = 0; i < 3; i++)
    {
        Entry tes;
        STARTENTRY();
        tes = cleansedEntry(currentEntry);
        CLOSEENTRY();
        Prio(elq) = 3 - i;
        Info(elq) = tes;
        Enqueue(&q, elq);
    }
    printf("Panjang queue permintaan pertemanan = %d\n", lengthQueue(q));
    PrintQueue(q);
    printf("Setelah terima atau tolak permintaan teman\n");
    Dequeue(&q);
    PrintQueue(q);
    return 0;
}