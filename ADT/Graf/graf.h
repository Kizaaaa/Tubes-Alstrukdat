#ifndef GRAF_H
#define GRAF_H

#include "../../boolean.h"
#include "../../ADT/ListProfil/listprofil.h"

#define MAX_PENGGUNA 20

typedef struct
{
    int simpul;
    int matriks[MAX_PENGGUNA][MAX_PENGGUNA];
} Graf;

#define Simpul(G) (G).simpul
#define ELMT(G, i, j) (G).matriks[i][j]

/* *** Konstruktor membentuk Graf *** */
void buatGraf(Graf *G, vType v, eType e);
//  menghasilkan sebuah graph G=(V,E),

void tambahTeman(Graf *G, int userIdx_1, int userIdx_2);
// Menambahkan teman antara pengguna dengan indeks userIdx_1 dan userIdx_2

void hapusTeman(Graf *G, int userIdx_1, int userIdx_2);
// Menghapus pertemanan antara pengguna dengan indeks userIdx_1 dan userIdx_2

void printTeman(Graf G, User user_Idx, int userIdx);
// Menampilkan pertemanan

boolean isTemanPenuh(Graf G, int userIdx);
// Mengecek apakah pengguna dengan indeks userIdx masih dapat memiliki teman tambahan

boolean isTeman(Graf G, int userIdx_1, int user_Idx_2);
// Mengecek apakah pengguna dengan indeks userIdx_1 dan userIdx_2 memiliki hubungan pertemanan

boolean jumlahTeman(Graf G, int userIdx);
// Menghitung jumlah teman dari pengguna dengan indeks userIdx

#endif