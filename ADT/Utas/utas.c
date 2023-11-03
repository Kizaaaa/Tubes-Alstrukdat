#include <stdio.h>
#include <stdlib.h>
#include "../Utas/utas.h"
//bungkusnya listdin KICAUAN, ele listdin adalah link list, INFO link list adalah KICAU, NEXT di KICAU menunjuk ke UTAS. 


//ADT UTAS UTAMA
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

void createUtas(UTAS *U, ElType idx, Entry teks, DATETIME time)
/* I.S sembarang */
/* F.S Terbentuk utas dengan komponen yang terdefinisi*/
{
    INDEKS(*U) = idx;
    TEXTUTAS(*U) = teks;
    TIME(*U) = time;
}

void createLinkedUtas(LINKEDUTAS *l)
/* I.S sembarang */
/* F.S Terbentuk list kosong l dengan elemen bertipe utas */
{
    FIRSTUTAS(*l) = NULL;
}

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

//UTAS
//read utas for the first time
void readUtas(LINKEDUTAS* l){
    boolean stop=false;
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    printf("Masukkan kicauan:\n");
    // Entry A;
    Entry text;
    STARTENTRY();
    text = currentEntry;
    UTAS u;
    Address p;
    createUtas(&u,1,text,GetLocalTime());
    insertFirstUtas(l,u);

    CLOSEENTRY();

    while(!stop){   //will not stop until user says "TIDAK" for continuing taking threads
        printf("Apakah Anda ingin melanjutkan kicauan ini? (YA/TIDAK)\n");
        int i=2;
        Entry yn;
        STARTENTRY();
        yn = cleansedEntry(currentEntry);
        CLOSEENTRY();
        if(isSame(yn,StringToEntry("YA",2))){
            printf("Masukkan kicauan:\n");
            STARTENTRY();
            text = cleansedEntry(currentEntry);
            CLOSEENTRY();
            createUtas(&u,i,text,GetLocalTime());
            insertLastUtas(l,u);
        }
        else if (isSame(yn,StringToEntry("TIDAK",5))){
            printf("Utas selesai!\n");
            stop = true;
        }
        i++;
    }
}

// void displayUtas(UTAS u,Kicau Twt){ //Display hanya 1 UTAS
//     printf("    | INDEX = %d\n",INDEKS(u));
//     printf("    | "); printEntry(AUTHOR(Twt)); printf("\n");
//     printf("    | "); TulisDATETIME(WAKTU(Twt)); printf("\n");
//     printf("    | "), printEntry(TEXTUTAS(u)); printf("\n");
//     printf("\n");
// }

// void displayLinkedUtas(LINKEDUTAS l, Kicau Twt){ //Display SELURUH LINKEDUTAS, asumsi pada main sudah diambilkan Linkedutas dengan id_utas masukan
//     //print kicauan utama dulu
//     printf("| ID = %d\n",ID(Twt));
//     printf("| "); printEntry(AUTHOR(Twt)); printf("\n");
//     printf("| "); TulisDATETIME(WAKTU(Twt)); printf("\n");
//     printf("| "), printEntry(TEXT(Twt)); printf("\n");
//     printf("\n");

//     //coba print semua utas
//     // Address p;
//     Address p = l;
//     int i = 0;
//     p = FIRSTUTAS(l);
//     while (p!=NULL){
//         printf("    | INDEX = %d\n",i);
//         printf("    | "); printEntry(AUTHOR(Twt)); printf("\n");
//         printf("    | "); TulisDATETIME(TIME(INFOUTAS(p))); printf("\n");
//         printf("    | "), printEntry(TEXTUTAS(INFOUTAS(p))); printf("\n");
//         printf("\n");
//         i++;
//         p = NEXT(p);
//     }
    
// }
// /* I.S sembarang */
// /* F.S Terbentuk list kosong l dengan elemen bertipe utas */


//SAMBUNG_UTAS

//ID_UTAS asumsi sudah valid
void sambungUtas(LINKEDUTAS *l, ElType idx){
    if(idx>getLastIdxUtas(l)){
        printf("Index terlalu tinggi!\n");
    }
    else{
        UTAS val;
        STARTENTRY();
        Entry text = cleansedEntry(currentEntry);
        CLOSEENTRY();
        createUtas(&val,idx,text,GetLocalTime());
        insertUtasAt(l,idx,val);
    }
}

void insertFirstUtas(LINKEDUTAS *l, UTAS val){
    Address p;
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

void insertLastUtas(LINKEDUTAS *l, UTAS val){
    Address p;
    Address idx;
    p = newNodeLinked(val);
    if (p!=NULL){
        idx = FIRSTUTAS(*l);
        while (NEXT(idx)!=NULL)
        {
            idx = NEXT(idx);
        }
        
        NEXT(idx) = p;
    }
    
}

//Menyambung utas pada indeks tertentu.
//UTAS val sudah diisi dengan komponen yg diinginkan
//SAMBUNG_UTAS 1 1 akan menjadikan utas baru sebagai indeks 1 (insertfirst)
//Indeks idx mulai dari 1
void insertUtasAt(LINKEDUTAS *l, ElType idx, UTAS val){
    Address pointerlinked;
    Address before;
    Address p;
    //Insert di indeks 1 atau pertama
    if (idx==1){
        insertFirstUtas(l,val);
    }
    //insert di indeks Eltype idx pilihan
    else{
        before = FIRSTUTAS(*l);
        pointerlinked = NEXT(FIRSTUTAS(*l));
        p = newNodeLinked(val);
        if (p!=NULL){
            pointerlinked=FIRST(*l);
            int count=1;
            while (count<idx-1){
                count++;
                pointerlinked = NEXT(pointerlinked);
                before = NEXT(before);
            }
            NEXT(p) = pointerlinked;
            NEXT(before)=p;
        }
        //mengubah indeks UTAS sisanya dengan menambah 1 krn terjadi insert
        while (pointerlinked!=NULL){
            INDEKS(INFOUTAS(pointerlinked))+=1;
            pointerlinked = NEXT(pointerlinked);
        }
    }
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

//HAPUS_UTAS
void deleteFirstUtas(LINKEDUTAS *l){
    Address pointerlinked;
    pointerlinked = FIRSTUTAS(*l);
    FIRSTUTAS(*l) = NEXT(pointerlinked);
    free(pointerlinked);
}

void deleteUtasAt(LINKEDUTAS *l, ElType idx)
{
    Address pointerlinked;
    Address before;
    if(idx>getLastIdxUtas(*l)){
        printf("Kicauan sambungan dengan indeks %d tidak ditemukan pada utas!\n",idx);
    }
    else{
        if (idx==1){
            deleteFirstUtas(l);
        }
        else{
            before = FIRSTUTAS(*l);
            pointerlinked = NEXT(FIRSTUTAS(*l));
            int count = 1;
            while (count<idx-1){
                count++;
                pointerlinked = NEXT(pointerlinked);
                before = NEXT(before);
            }
            NEXT(before) = NEXT(pointerlinked);
        }
        printf("Kicauan sambungan berhasil dihapus!\n");
    free(pointerlinked);
    }
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */