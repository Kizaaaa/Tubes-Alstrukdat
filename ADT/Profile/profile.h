#ifndef PROFILE_H
#define PROFILE_H

#include "../../boolean.h"
#include "../Matrix/matrix.h"
#include "../EntryMachine/entrymachine.h"

/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct{
    int Jenis; // 0 bertipe privat, 1 bertipe publik
    Entry Bio;
    Entry Nomor;
    Entry Weton;
    Matrix Foto;
} Profil;

#endif