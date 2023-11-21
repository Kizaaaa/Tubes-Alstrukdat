#ifndef KICAU_H
#define KICAU_H

#include "../../boolean.h"
#include "../Utas/utas.h"
#include "../Graf/graf.h"
#include "../Tree/tree.h"

typedef struct kicau
{
    long long int IdBalasan;
    long long int Id;
    long long int Like;
    Entry Author;
    Entry Text;
    LINKEDUTAS Utasan;
    DATETIME Waktu;
    BinTree Balasan;
} Kicau;

/* ********** SELEKTOR ********** */
#define IDBALASAN(k) (k).IdBalasan
#define ID(k) (k).Id
#define LIKE(k) (k).Like
#define AUTHOR(k) (k).Author
#define TEXT(k) (k).Text
#define UTASAN(k) (k).Utasan
#define WAKTU(k) (k).Waktu
#define BALASAN(k) (k).Balasan

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Tweet */

void DisplayKicau(Kicau k);

void displayUtas(UTAS u, Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SATU UTAS */

void displayLinkedUtas(LINKEDUTAS l, Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SELURUH LinkedUtas termasuk Kicauan Utama */

#endif