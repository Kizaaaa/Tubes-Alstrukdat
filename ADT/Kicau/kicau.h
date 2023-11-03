#ifndef KICAU_H
#define KICAU_H

#include "../../boolean.h"
#include "../EntryMachine/entrymachine.h"
#include "../DateTime/datetime.h"
#include "../Utas/utas.h"

typedef struct kicau
{
    int Id;
    int Like;
    Entry Author;
    Entry Text;
    LINKEDUTAS Utasan;
    // LINKEDUTAS Next;
    DATETIME Waktu;
} Kicau;

/* ********** SELEKTOR ********** */
#define ID(k) (k).Id
#define LIKE(k) (k).Like
#define AUTHOR(k) (k).Author
#define TEXT(k) (k).Text
#define UTASAN(k) (k).Utasan
#define WAKTU(k) (k).Waktu

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Tweet */
void CreateKicau(Kicau *k, int id, Entry author);

void EditKicau(Kicau *k);

void DisplayKicau(Kicau k);

void LikeKicau(Kicau *k);

void displayUtas(UTAS u, Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SATU UTAS */

void displayLinkedUtas(LINKEDUTAS l, Kicau Twt);
/* I.S sembarang */
/* F.S Menampilkan SELURUH LinkedUtas termasuk Kicauan Utama */

#endif