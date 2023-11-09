#ifndef GRAF_H
#define GRAF_H

#include "../../boolean.h"
#include "../ListProfil/listprofil.h"

#define MAX_PENGGUNA 20

typedef struct {
    int Simpul[MAX_PENGGUNA];
    int Busur[MAX_PENGGUNA][MAX_PENGGUNA];
} Graf;

#define Simpul(G,i) (G).Simpul[(i)]
#define Busur(G, i, j) (G).Busur[(i)][(j)]

void LihatProfil(Graf G, ListStatik ListProfil, int CurrentUser, Entry namaTeman);

/* *** Konstruktor membentuk Graf *** */
void CreateGraf(Graf *G);
//  menghasilkan sebuah graph G=(V,E),

void TambahTeman(Graf *G, ListStatik *ListProfil, int CurrentUser);
// Menambahkan teman antara pengguna dengan indeks userIdx_1 dan userIdx_2

void HapusTeman(Graf *G, ListStatik *ListProfil, int CurrentUser);
// Menghapus pertemanan antara pengguna dengan indeks userIdx_1 dan userIdx_2

void DaftarTeman(Graf G, ListStatik ListProfil, int CurrentUser);
// Menampilkan pertemanan

void TerimaTeman(Graf *G, ListStatik ListProfil, int CurrentUser);

void SetujuiTeman(Graf *G, ListStatik *ListProfil, int CurrentUser);

boolean isBerteman(Graf G, int User1, int User2);
// Mengecek apakah pengguna dengan indeks userIdx_1 dan userIdx_2 memiliki hubungan pertemanan

#endif