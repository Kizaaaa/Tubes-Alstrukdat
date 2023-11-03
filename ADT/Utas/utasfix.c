#include <stdio.h>
#include <stdlib.h>
#include "../Utas/utasfix.h"
//bungkusnya listdin KICAUAN, ele listdin adalah link list, INFO link list adalah KICAU, NEXT di KICAU menunjuk ke UTAS. 

Address newNode(ElType val){
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
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

void createUtas(Kicau *U, ElType idx, Entry teks, DATETIME time)
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
    // if (CHECKVALIDTWEET(text))
    // {

    //     TEXTUTAS(INFOUTAS(l)) = text;     //ini gabakal error kalau masukan TEXT() adalah tipe UTAS
    //     CLOSEENTRY();
    // }
    // else
    // {
    //     // proses jika tweet tidak valid
    // }

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

//mengambil UTAS pada indeks tertentu
UTAS getElmtUtas(LINKEDUTAS l,int idx){
    Address p;
    p = FIRSTUTAS(l);
    int i=0;
    while (i<=idx){
        i++;
        p = NEXT(p);
    }
    return(INFOUTAS(p));
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
    // Address p;
    Address p = l;
    int i = 0;
    p = FIRSTUTAS(l);
    while (p!=NULL){
        printf("    | INDEX = %d\n",i);
        printf("    | "); printEntry(AUTHOR(Twt)); printf("\n");
        printf("    | "); TulisDATETIME(TIME(p)); printf("\n");
        printf("    | "), printEntry(TEXTUTAS(p)); printf("\n");
        printf("\n");
        i++;
        p = NEXT(p);
    }
    
}
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */


//SAMBUNG_UTAS

//getting the max indeks, indeks start from 1!
int getLastIdxUtas(LINKEDUTAS l){
    int res=1;
    Address p;
    p = FIRSTUTAS(l);
    while (p!=NULL)
    {
        res++;
        p = NEXT(p);
    }
    return res;
}

void sambungUtas(LINKEDUTAS *l,ElType idx){
    if(idx>getLastIdxUtas(l)){
        printf("Index terlalu tinggi!\n");
    }
    else{
        
    }
}

void insertFirstUtas(LINKEDUTAS *l, UTAS val){
    Address p;
    Address pointerlinked;
    pointerlinked = FIRSTUTAS(*l);
    p = newNodeLinked(val);
    //penambahan di awal
    if (p!=NULL){
        NEXT(p) = FIRSTUTAS(*l); 
        FIRSTUTAS(*l) = p;
    }
    //menambah 1 semua indeks UTAS hingga UTAS terakhir karena terjadi insert di awal
    while (p!=NULL){
        INDEKS(INFOUTAS(p))+=1;
        p = NEXT(p);
    }
    
}

//Menyambung utas pada indeks tertentu.
//UTAS val sudah diisi dengan komponen yg diinginkan
void insertUtasAt(LINKEDUTAS *l, ElType idx, UTAS val)
{   //aku liat dulu entrymachine 2 param nya
    Address pointerlinked;
    Address p;
    pointerlinked = FIRST(*l);
    //Insert di indeks 1 atau pertama
    if (idx==1){
        insertFirstUtas(l,val);
    }
    //insert di indeks Eltype idx pilihan
    else{
        p = newNodeLinked(val);
        if (p!=NULL){
            pointerlinked=FIRST(*l);
            int count=0;
            while (count<idx){
                count++;
                pointerlinked = NEXT(pointerlinked);
            }
            NEXT(p) = NEXT(pointerlinked);
            NEXT(pointerlinked)=p;
        }
        //mengubah indeks UTAS sisanya dengan menambah 1 krn terjadi insert
        while (p!=NULL){
            INDEKS(INFOUTAS(p))+=1;
            p = NEXT(p);
        }
    }
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