#include <stdio.h>
#include <stdlib.h>
#include "../Utas/utas.h"
// bungkusnya listdin KICAUAN, ele listdin adalah link list, INFO link list adalah KICAU, NEXT di KICAU menunjuk ke UTAS.

// TEMPORARY FUNCTIONS
void displayUtasKW(UTAS u)
{ // Display hanya 1 UTAS
    printf("    | INDEX = %d\n", INDEKS(u));
    printf("    | ");
    TulisDATETIME(TIME(u));
    printf("\n");
    printf("    | "), printEntry(TEXTUTAS(u));
    printf("\n");
    printf("\n");
}

// ADT UTAS UTAMA
Address newNodeLinked(UTAS val)
{
    Address p;
    p = (Address)malloc(sizeof(NodeLU));

    if (p != NULL)
    {
        INFOUTAS(p) = val;
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

// getting the max indeks, indeks start from 1!
int getLastIdxUtas(LINKEDUTAS l)
{
    int res = 0;
    Address p;
    p = FIRSTUTAS(l);
    while (p != NULL)
    {
        res++;
        p = NEXT(p);
    }
    return res;
}

// UTAS
// read utas for the first time
void readUtas(LINKEDUTAS *l)
{
    boolean stop = false;
    boolean valid = false;
    printf("Utas berhasil dibuat!\n");
    printf("\n");
    Entry text;
    while (!valid)
    {
        printf("Masukkan kicauan:\n");
        STARTENTRY();
        text = cleansedEntry(currentEntry);
        CLOSEENTRY();
        valid = CHECKVALIDTWEET(text);
        if (!valid)
        {
            printf("Masukanmu tidak valid, pastikan masukan tidak mengandung spasi saja atau kosong\n");
            printf("\n");
        }
    }
    UTAS u;
    Address p;
    createUtas(&u, 1, text, GetLocalTime());
    insertFirstUtas(&*l, u);
    p = FIRSTUTAS(*l);
    // INDEKS(INFOUTAS(p)) = 1;
    int i = 1;
    while (!stop)
    { // will not stop until user says "TIDAK" for continuing taking threads
        valid = false;
        printf("Apakah Anda ingin melanjutkan kicauan ini? (YA/TIDAK)\n");
        UTAS x;
        Entry yn;
        STARTENTRY();
        yn = cleansedEntry(currentEntry);
        CLOSEENTRY();
        if (isSame(yn, StringToEntry("YA", 2)))
        {
            while (!valid)
            {
                printf("Masukkan kicauan:\n");
                STARTENTRY();
                text = cleansedEntry(currentEntry);
                CLOSEENTRY();
                valid = CHECKVALIDTWEET(text);
                if (!valid)
                {
                    printf("Masukanmu tidak valid, pastikan masukan tidak mengandung spasi saja atau kosong\n");
                    printf("\n");
                }
            }
            i = i + 1;
            createUtas(&x, i, text, GetLocalTime());
            insertLastUtas(&*l, x);
        }
        else if (isSame(yn, StringToEntry("TIDAK", 5)))
        {
            printf("Utas selesai!\n");
            stop = true;
        }
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

// SAMBUNG_UTAS

// ID_UTAS asumsi sudah valid
void sambungUtas(LINKEDUTAS *l, ElType idx)
{
    if (idx > getLastIdxUtas(*l))
    {
        printf("Index terlalu tinggi!\n");
    }
    else
    {
        UTAS val;
        Entry text;
        boolean valid = false;
        while (!valid)
        {
            printf("Masukkan kicauan:\n");
            STARTENTRY();
            text = cleansedEntry(currentEntry);
            CLOSEENTRY();
            valid = CHECKVALIDTWEET(text);
            if (!valid)
            {
                printf("*Masukanmu tidak valid, pastikan masukan tidak mengandung spasi saja atau kosong\n");
                printf("\n");
            }
        }
        createUtas(&val, idx, text, GetLocalTime());
        insertUtasAt(l, idx, val);
    }
}

void insertFirstUtas(LINKEDUTAS *l, UTAS val)
{
    Address p;
    p = newNodeLinked(val);
    // penambahan di awal
    if (p != NULL)
    {
        NEXT(p) = FIRSTUTAS(*l);
        FIRSTUTAS(*l) = p;
    }
    // menambah 1 semua indeks UTAS hingga UTAS terakhir karena terjadi insert di awal
    p = NEXT(p);
    while (p != NULL)
    {
        INDEKS(INFOUTAS(p)) += 1;
        p = NEXT(p);
    }
}

void insertLastUtas(LINKEDUTAS *l, UTAS val)
{
    Address p;
    Address idx;
    p = newNodeLinked(val);
    if (p != NULL)
    {
        idx = FIRSTUTAS(*l);
        while (NEXT(idx) != NULL)
        {
            idx = NEXT(idx);
        }

        NEXT(idx) = p;
    }
}

// Menyambung utas pada indeks tertentu.
// UTAS val sudah diisi dengan komponen yg diinginkan
// SAMBUNG_UTAS 1 1 akan menjadikan utas baru sebagai indeks 1 (insertfirst)
// Indeks idx mulai dari 1
void insertUtasAt(LINKEDUTAS *l, ElType idx, UTAS val)
{
    Address pointerlinked;
    Address temp;
    Address before;
    Address p;
    // Insert di indeks 1 atau pertama
    if (idx == 1)
    {
        insertFirstUtas(l, val);
    }
    // insert di indeks Eltype idx pilihan
    else
    {
        before = FIRSTUTAS(*l);
        pointerlinked = NEXT(FIRSTUTAS(*l));
        p = newNodeLinked(val);
        if (p != NULL)
        {
            pointerlinked = FIRSTUTAS(*l);
            int count = 1;
            while (count < idx - 1)
            {
                count++;
                pointerlinked = NEXT(pointerlinked);
                before = NEXT(before);
            }
            NEXT(p) = NEXT(pointerlinked);
            NEXT(before) = p;
        }
        // mengubah indeks UTAS sisanya dengan menambah 1 krn terjadi insert
        temp = NEXT(pointerlinked);
        INDEKS(INFOUTAS(temp)) -= 1;

        while (temp != NULL)
        {
            // printf("    ||"),printEntry(TEXTUTAS(INFOUTAS(pointerlinked)));printf("\n");
            INDEKS(INFOUTAS(temp)) += 1;
            temp = NEXT(temp);
        }
    }
}
/* I.S l mungkin kosong (bukan sebuah utas) */
/* F.S Melakukan alokasi sebuah elemen tipe bentukan UTAS dan menambahkan elemen list di akhir */

// HAPUS_UTAS
void deleteFirstUtas(LINKEDUTAS *l)
{
    Address pointerlinked;
    Address loopingidx;
    pointerlinked = FIRSTUTAS(*l);
    FIRSTUTAS(*l) = NEXT(pointerlinked);
    loopingidx = NEXT(pointerlinked);
    while (loopingidx != NULL)
    {
        INDEKS(INFOUTAS(loopingidx)) -= 1;
        loopingidx = NEXT(loopingidx);
    }
    free(pointerlinked);
}

void deleteUtasAt(LINKEDUTAS *l, ElType idx)
{
    Address pointerlinked;
    Address before;
    if (idx > getLastIdxUtas(*l))
    {
        printf("Kicauan sambungan dengan indeks %d tidak ditemukan pada utas!\n", idx);
    }
    else
    {
        if (idx == 1)
        {
            deleteFirstUtas(l);
        }
        else
        {
            before = FIRSTUTAS(*l);
            pointerlinked = NEXT(FIRSTUTAS(*l));
            int count = 1;
            while (count < idx - 1)
            {
                count++;
                pointerlinked = NEXT(pointerlinked);
                before = NEXT(before);
            }
            NEXT(before) = NEXT(pointerlinked);
            Address loopingidx;
            loopingidx = NEXT(pointerlinked);
            while (loopingidx != NULL)
            {
                INDEKS(INFOUTAS(loopingidx)) -= 1;
                loopingidx = NEXT(loopingidx);
            }
            free(pointerlinked);
        }
        printf("Kicauan sambungan berhasil dihapus!\n");
    }
}
/* I.S List l tidak kosong */
/* F.S Melakukan penghapusan elemen bertipe UTAS  */