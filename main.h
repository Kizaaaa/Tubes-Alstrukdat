#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT/EntryMachine/entrymachine.h"
#include "ADT/Kicau/kicau.h"
#include "ADT/Profile/profile.h"
#include "ADT/ListStatic/liststatik.h"

extern boolean isMasuk;
extern long long int IDKicau;
extern ListStatik ListProfil;
extern int CurrentUser;

#endif


/*
gcc -o main main.c ADT/EntryMachine/entrymachine.c ADT/Kicau/kicau.c ADT/Profile/profile.c ADT/ListStatic/liststatik.c
*/