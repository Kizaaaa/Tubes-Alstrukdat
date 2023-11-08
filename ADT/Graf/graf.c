#include <stdio.h>
#include "graf.h"

// Membuat Graf
void buatGraf(Graf *G, int simpul)
{
    int i, j;
    Simpul(*G) = simpul;
    for (i = 0; i < MAX_PENGGUNA; i++)
    {
        for (j = 0; j < MAX_PENGGUNA; j++)
        {
            ELMT(*G, i, j) = 0;
        }
    }
}

void tambahTeman(Graf *G, int userIdx_1, int userIdx_2)
{
    ELMT(*G, userIdx_1, userIdx_2) = 1;
    ELMT(*G, userIdx_2, userIdx_1) = 1;
}

void hapusTeman(Graf *G, int userIdx_1, int userIdx_2)
{
    ELMT(*G, userIdx_1, userIdx_2) = 0;
    ELMT(*G, userIdx_2, userIdx_1) = 0;
}

void printTeman(Graf G, Profil userProfil)
{
    int i;
    userIdx = 0 // ???=================== Dapet indeks buat profil yang mau di print temennya
        int jumlah_teman = jumlahTeman(G, userIdx);

    if (jumlah_teman == 0)
    {
        printf("Belum memiliki teman\n");
    }

    else
    {
        printf("Daftar Teman:");
        for (i = 0; i < MAX_PENGGUNA; i++)
        {
            if (ELMT(G, userIdx, i) == 1)
            {
                printf("%d. %s\n", i + 1, Nama(P));
            }
        }
    }
}

boolean isTemanPenuh(Graf G, int userIdx)
{
    for (int i = 0; i < MAX_PENGGUNA; i++)
    {
        if (ELMT(G, userIdx, i) == 0)
        {
            return false;
        }
    }
    return true;
}

boolean isTeman(Graf G, int userIdx_1, int user_Idx_2)
{
    return (ELMT(G, userIdx_1, user_Idx_2) == 1);
}

boolean jumlahTeman(Graf G, int userIdx)
{
    int i, sum = 0;
    for (i = 0; i < MAX_PENGGUNA; i++)
    {
        if (ELMT(G, user_Idx, i) == 1)
        {
            sum++;
        }
    }
    return sum;
}