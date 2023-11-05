#ifndef GRAF_H
#define GRAF_H

#include "../../boolean.h"
#include "../../ADT/Matrix/matrix.h"

typedef int vType;
typedef int eType;
typedef struct 
{
    Matrix m;
} Graf;

// #define 


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Graf *** */
void CreateGraf(Graf *G, vType v, eType e);
//  menghasilkan sebuah graph G=(V,E), 
// V tidak kosong, E bisa kosong }


boolean IsEmpty(Graf G);
// Test apakah G adalah Graph kosong

boolean Adjacent(Graf G, vType v1, vType v2);
// tes apakah v1 dan v2 bertetangga

boolean Incident(Graf G, vType v, eType e);
//  tes apakah v berhubungan dengan e

void Neighbors(Graf G, vType v);
// daftar seluruh simpul yang bertetangga dengan v

void AddV(Graf *G, vType v);
// menambahkan simpul v pada G

void DeleteV(Graf *G, vType v);
// menghapus simpul v dari G, berikut semua busur incident v

void AddE(Graf *G, vType v1, vType v2);
// menambahkan busur (v1,v2) pada G

void DeleteE(Graf *G, vType v1, vType v2);
// menghapus busur (v1,v2) dari G















#endif