#include <stdio.h>
#include "../dsu.h"

int main(){
    printf("=========================== DRIVER DISJOINT SET ===========================\n");

    DisjointSet dsu;
    initializeSet(&dsu);
    printf("PARENTD[0] = %d\n", PARENTD(dsu, 0));
    printf("RANK[0] = %d\n", RANK(dsu, 0));
    printf("PARENTD[1] = %d\n", PARENTD(dsu, 1));
    printf("RANK[1] = %d\n", RANK(dsu, 1));
    
    return 0;
}