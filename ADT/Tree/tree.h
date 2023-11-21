/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#ifndef TREE_H
#define TREE_H
#include "../../boolean.h"
#include "../EntryMachine/entrymachine.h"
#include "../DateTime/datetime.h"

/* Selektor */
#define PARENT(p) (p)->parent
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right
#define IDB(b) (b).IdB
#define AUTHORB(b) (b).AuthorB
#define TEXTB(b) (b).TextB
#define WAKTUB(b) (b).WaktuB

typedef struct balasan
{
    long long int IdB;
    Entry AuthorB;
    Entry TextB;
    DATETIME WaktuB;
} BalasanB;

typedef struct treeNode* AddressBT;
typedef struct treeNode { 
    AddressBT parent;
    BalasanB info;
    AddressBT left;
    AddressBT right;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef AddressBT BinTree;

BinTree NewTree (BalasanB root, BinTree left_tree, BinTree right_tree);
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (BalasanB root, BinTree left_tree, BinTree right_tree, BinTree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

AddressBT newTreeNode(BalasanB val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (AddressBT p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */

void dealloc(BinTree p);

void addRight(BinTree *p, BalasanB b);

void addChild(BinTree *p, BalasanB b);

BinTree searchTree(BinTree p, long long int IDBalas);

#endif