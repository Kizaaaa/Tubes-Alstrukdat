#include <stdio.h>
#include <stdlib.h>
#include "../Utas/utas.h"
//bungkusnya listdin KICAUAN, ele listdin adalah link list, INFO link list adalah KICAU, NEXT di KICAU menunjuk ke UTAS. 
Address newNodeLinked(UTAS val)
{
    Address p;
    p = (Address)malloc(sizeof(LINKEDUTAS));

    if (p != NULL)
    {
        INFOUTAS(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void createUtas(LINKEDUTAS *l, Kicau Twt)
{
    /* I.S sembarang */
    /* F.S Terbentuk list kosong l dengan elemen bertipe utas */

    FIRSTUTAS(*l) = NULL;
}

void readUtas(LINKEDUTAS l)
{
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    printf("Masukkan kicauan:\n");
    // Entry A;
    Entry input;
    STARTENTRY();
    input = currentEntry;
    if(isSame(input,StringToEntry("UTAS",4))){

    }
    else{

    }
    // adt var adt entry
    // A = currentEntry;

    // if (CHECKVALIDTWEET(A))
    // {
    //     // proses jika tweet valid
    //     CLOSEENTRY();
    // }
    // else
    // {
    //     // proses jika tweet tidak valid
    // }
    printf("Apakah Anda ingin melanjutkan kicauan ini? (YA/TIDAK)\n");
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void displayUtas(LINKEDUTAS l){
    Address p;

}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS val)
{
    Address pointerlinked;
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS *val)
{
    Address pointerlinked;
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */
