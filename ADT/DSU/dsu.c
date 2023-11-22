#include <stdio.h>
#include "dsu.h"

void initializeSet(DisjointSet *dsu) {
    for (int i = 0; i < MAX_PENGGUNA; ++i) {
        PARENTD(*dsu,i) = i;
        RANK(*dsu,i) = 0;
    }
}

// Find the representative of the set (with path compression)
int findSet(DisjointSet *dsu, int x) {
    if (PARENTD(*dsu,x) != x) {
        PARENTD(*dsu,x) = findSet(dsu, PARENTD(*dsu,x)); // Path compression
    }
    return PARENTD(*dsu,x);
}

// Union two sets (with union by rank)
void unionSets(DisjointSet *dsu, int x, int y) {
    int rootX = findSet(dsu, x);
    int rootY = findSet(dsu, y);
    
    if (rootX != rootY) {
        if (RANK(*dsu,rootX) < RANK(*dsu,rootY)) {
            PARENTD(*dsu,rootX) = rootY;
        } else if (RANK(*dsu,rootX) > RANK(*dsu,rootY)) {
            PARENTD(*dsu,rootY) = rootX;
        } else {
            PARENTD(*dsu,rootY) = rootX;
            RANK(*dsu,rootX)++;
        }
    }
}

// Find friends using disjoint set union
void findFriends(DisjointSet *dsu, Graf G, ListStatik ListProfil, int CurrentUser) {
    printf("Terdapat  orang dalam Kelompok Teman A :\n");

    for (int i = 0; i < MAX_PENGGUNA; ++i) {
        if (Busur(G,CurrentUser,i) == 1) {
            int root1 = findSet(&*dsu, CurrentUser);
            int root2 = findSet(&*dsu, i);

            if (root1 == root2) {
                printEntry(Nama(ELMTLS(ListProfil,i))); printf("\n");
            }
        }
    }

    printf("\n");
}