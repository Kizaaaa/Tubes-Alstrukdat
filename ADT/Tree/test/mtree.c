#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

int main()
{
    printf("============================== DRIVER TREE ===============================\n");

    BalasanB b1, b2, b3;
    IDB(b1) = 1;
    AUTHORB(b1) = StringToEntry("Kiza", 4);
    TEXTB(b1) = StringToEntry("Balas1", 6);
    WAKTUB(b1) = GetLocalTime();

    BinTree t = newTreeNode(b1), t2;
    IDB(b2) = 2;
    TEXTB(b2) = StringToEntry("Balas2", 6);
    RIGHT(t) = newTreeNode(b2);

    IDB(b3) = 3;
    TEXTB(b3) = StringToEntry("Balas3", 6);
    RIGHT(RIGHT(t)) = newTreeNode(b3);

    printf("Preorder: ");
    printPreorder(t);
    printf("\n");

    printf("Inorder: ");
    printInorder(t);
    printf("\n");

    printf("Postorder: ");
    printPostorder(t);
    printf("\n");

    t2 = searchTree(t, 3);
    if (t2 != NULL)
    {
        printf("Found node with IDBalas = 3\n");
        printf("Text: ");
        printEntry(TEXTB(ROOT(t2)));
        printf("\n");
    }
    else
    {
        printf("Node with IDBalas = 3 not found\n");
    }

    dealloc(t);

    return 0;
}