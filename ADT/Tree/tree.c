#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(BalasanB root, BinTree left_tree, BinTree right_tree){
    BinTree t = newTreeNode(root);
    LEFT(t) = left_tree;
    RIGHT(t) = right_tree;
    return t;
}

void CreateTree(BalasanB root, BinTree left_tree, BinTree right_tree, BinTree *p){
    BinTree t = newTreeNode(root);
    LEFT(t) = left_tree;
    RIGHT(t) = right_tree;
    *p = t;
}

AddressBT newTreeNode(BalasanB val){
    AddressBT p = (AddressBT)malloc(sizeof(TreeNode));
    PARENT(p) = NULL;
    ROOT(p) = val;
    LEFT(p) = NULL;
    RIGHT(p) = NULL;
    return p;
}

void deallocTreeNode(AddressBT p){
    free(p);
}

boolean isTreeEmpty(BinTree p){
    return p == NULL;
}

boolean isOneElmt(BinTree p){
    return !isTreeEmpty(p) && (LEFT(p) == NULL && RIGHT(p) == NULL);
}

boolean isUnerLeft(BinTree p){
    return !isTreeEmpty(p) && (LEFT(p) != NULL && RIGHT(p) == NULL);
}

boolean isUnerRight(BinTree p){
    return !isTreeEmpty(p) && (LEFT(p) == NULL && RIGHT(p) != NULL);
}

boolean isBinary(BinTree p){
    return !isTreeEmpty(p) && (LEFT(p) != NULL && RIGHT(p) != NULL);
}

void dealloc(BinTree p){
    if(isOneElmt(p)){
        deallocTreeNode(p);
    } else {
        if(LEFT(p) != NULL){
            dealloc(LEFT(p));
        }
        if(RIGHT(p) != NULL){
            dealloc(RIGHT(p));
        }
        deallocTreeNode(p);
    }
}

void addRight(BinTree *p, BalasanB b)
{
    if(isTreeEmpty(*p)){
        *p = newTreeNode(b);
    } else {
        while(RIGHT(*p) != NULL){
            *p = RIGHT(*p);
        }
        RIGHT(*p) = newTreeNode(b);
        PARENT(RIGHT(*p)) = *p;
    }
}

void addChild(BinTree *p, BalasanB b){
    if(LEFT(*p) == NULL){
        LEFT(*p) = newTreeNode(b);
        PARENT(LEFT(*p)) = *p;
    } else {
        addRight(&LEFT(*p),b);
    }
}

BinTree searchTree(BinTree p, long long int IDBalas){
    if(p == NULL || IDB(ROOT(p)) == IDBalas){
        return p;
    }
    BinTree LeftResult = searchTree(LEFT(p), IDBalas);
    BinTree RightResult = searchTree(RIGHT(p), IDBalas);
    if(LeftResult == NULL){
        return RightResult;
    } else {
        return LeftResult;
    }
}

int BanyakNode(BinTree p){
    if(isOneElmt(p)){
        return 1;
    } else if(isUnerLeft(p)){
        return 1 + BanyakNode(LEFT(p));
    } else if(isUnerRight(p)){
        return 1 + BanyakNode(RIGHT(p));
    } else {
        return 1 + BanyakNode(LEFT(p)) + BanyakNode(RIGHT(p));
    }
}



// int main(){
//     BalasanB b;
//     IDB(b) = 1;
//     AUTHORB(b) = StringToEntry("Kiza",4);
//     TEXTB(b) = StringToEntry("Balas1",6);
//     WAKTUB(b) = GetLocalTime();

//     BinTree t = newTreeNode(b),t2;
//     PARENT(t) = NULL;
//     IDB(b) = 2;
//     TEXTB(b) = StringToEntry("Balas2",6);
//     RIGHT(t) = newTreeNode(b);
//     PARENT(RIGHT(t)) = t;

//     IDB(b) = 3;
//     TEXTB(b) = StringToEntry("Balas3",6);
//     RIGHT(RIGHT(t)) = newTreeNode(b);
//     PARENT(RIGHT(RIGHT(t))) = RIGHT(t);

//     printf("%lld",TrueParent(RIGHT(RIGHT(t))));
//     return 0;
// }
/*
gcc -o tree ADT/Tree/tree.c ADT/DateTime/datetime.c ADT/DateTime/time.c ADT/EntryMachine/entrymachine.c ADT/EntryMachine/charmachine.c
*/