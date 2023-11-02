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
        INFOUTAS(p) = val;  //sial ini gmn anjir tipe p harusnya UTAS
        NEXT(p) = NULL;
    }
    return p;
}

// Address newNodeLinked(ElType indeks, Entry teks, DATETIME time)
// {
//     Address p;
//     p = (Address)malloc(sizeof(LINKEDUTAS));

//     if (p != NULL)
//     {
//         INDEKS(p) = indeks;
//         TEXTUTAS(p) = teks;
//         TIME(p) = time;
//         NEXT(p) = NULL;
//     }
//     return p;
// }

void createUtas(UTAS *U, ElType idx, Entry teks, DATETIME time)
/* I.S sembarang */
/* F.S Terbentuk utas dengan komponen yang terdefinisi*/
{
    INDEKS(*U) = idx;
    TEXTUTAS(*U) = teks;
    TIME(*U) = time;
}

void createLinkedUtas(LINKEDUTAS *l, Kicau Twt)
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */
{
    FIRSTUTAS(*l) = NULL;
}

void readUtas(LINKEDUTAS l){
    boolean stop=false;
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    printf("Masukkan kicauan:\n");
    // Entry A;
    Entry text;
    STARTENTRY();
    text = currentEntry;

    //msh bingung cara baca input
    if (CHECKVALIDTWEET(text))
    {

        TEXTUTAS(l) = text;     //ini gabakal error kalau masukan TEXT() adalah tipe UTAS
        CLOSEENTRY();
    }
    else
    {
        // proses jika tweet tidak valid
    }

    while(!stop){   //will not stop until user says "TIDAK" for continuing taking threads
        printf("Apakah Anda ingin melanjutkan kicauan ini? (YA/TIDAK)\n");
        Entry yn;
        STARTENTRY();
        yn = currentEntry;
        if(isSame(yn,StringToEntry("YA",2))){
            printf("Masukkan kicauan:\n");
            //INPUT MASUKAN USER TEKS
            // createUtas();??? INDEKSNYA JG GMN
            //insert

        }
        else if (isSame(yn,StringToEntry("TIDAK",5))){
            printf("Utas selesai!\n");
            stop = true;
        }
    }
}

/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */
UTAS takeUtas(LINKEDUTAS l, Address p){ //Mengembalikan elemen UTAS di LINKEDLIST yang ditunjuk oleh alamat p
    UTAS u;
    // createUtas(&u);
    return INFOUTAS(p);
}

void displayUtas(UTAS u,Kicau Twt){ //Display hanya 1 UTAS
    printf("    | INDEX = %d\n",INDEKS(u));
    printf("    | "); printEntry(AUTHOR(Twt)); printf("\n");
    printf("    | "); TulisDATETIME(WAKTU(Twt)); printf("\n");
    printf("    | "), printEntry(TEXTUTAS(u)); printf("\n");
    printf("\n");
}

void displayLinkedUtas(LINKEDUTAS l, Kicau Twt){ //Display SELURUH LINKEDUTAS, asumsi pada main sudah diambilkan Linkedutas dengan id_utas masukan
    //print kicauan utama dulu
    printf("| ID = %d\n",ID(Twt));
    printf("| "); printEntry(AUTHOR(Twt)); printf("\n");
    printf("| "); TulisDATETIME(WAKTU(Twt)); printf("\n");
    printf("| "), printEntry(TEXT(Twt)); printf("\n");
    printf("\n");

    //coba print semua utas
    Address p=l;
    // p = FIRSTUTAS(l);
    while (p!=NULL){
        printf("    | INDEX = %d\n",INDEKS(p));
        printf("    | "); printEntry(AUTHOR(Twt)); printf("\n");
        printf("    | "); TulisDATETIME(WAKTU(p)); printf("\n");
        printf("    | "), printEntry(TEXT(p)); printf("\n");
        printf("\n");
        p = NEXT(p);
    }
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */

void insertUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS val)
{   //aku liat dulu entrymachine 2 param nya
    Address pointerlinked;
    Address new;
    new = newNodeLinked(val);
    pointerlinked = FIRST(*l);
    
    
    // while (NEXT(pointerlinked)!=NULL){
    //     /* code */
    // }
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

void deleteUtas(LINKEDUTAS *l, ElType idx, ElType id_utas, UTAS *val)
{
    Address pointerlinked;
    pointerlinked = FIRST(*l);
    while (NEXT(pointerlinked)!=NULL)
    {
        /* code */
    }
    

    free(pointerlinked);
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */