#ifndef DSU_H
#define DSU_H

#include "../../boolean.h"
#include "../Graf/graf.h"
#include "../ListProfil/listprofil.h"

typedef struct {
    int parentd[MAX_PENGGUNA];
    int rank[MAX_PENGGUNA];
} DisjointSet;

#define PARENTD(d,i) (d).parentd[i]
#define RANK(d,i) (d).rank[i]

void initializeSet(DisjointSet *dsu);

void findFriends(DisjointSet *dsu, Graf G, ListStatik ListProfil, int CurrentUser);

#endif