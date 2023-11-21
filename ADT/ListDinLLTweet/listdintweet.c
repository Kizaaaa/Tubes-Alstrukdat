/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdintweet.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF_LDT -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
/*typedef int ElTypeLDT; /* type elemen list */
// typedef int IdxType;
// typedef struct
// {
//     ElTypeLDT *buffer; /* memori tempat penyimpan elemen (container) */
//     int nEff;       /* >=0, banyaknya elemen efektif */
//     int capacityT;   /* ukuran elemen */
// } ListDinT;
/* Indeks yang digunakan [0..capacityT-1] */
/* Jika l adalah : ListDinT, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinT */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacityT */

/* ********** SELEKTOR ********** */
#define NEFFT(l) (l).nEffT
#define BUFFERT(l) (l).bufferT
#define ELMTT(l, i) (l).bufferT[i]
#define CAPACITYT(l) (l).capacityT

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinT(ListDinT *l, int capacityT)
{
    BUFFERT(*l) = (ElTypeLDT *)malloc(capacityT * sizeof(ElTypeLDT));
    CAPACITYT(*l) = capacityT;
    NEFFT(*l) = 0;
}
/* I.S. l sembarang, capacityT > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacityT */

void dealocateListDinT(ListDinT *l)
{
    free(BUFFERT(*l));
    CAPACITYT(*l) = 0;
    NEFFT(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYT(l)=0; NEFFT(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ListDinTLength(ListDinT l)
{
    return NEFFT(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDinT(ListDinT l)
{
    return (IdxType)IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxListDinT(ListDinT l)
{
    return (IdxType)NEFFT(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinT(ListDinT l, IdxType i)
{
    if (i < CAPACITYT(l) && i >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListDinT(ListDinT l, IdxType i)
{
    if (i >= 0 && i <= NEFFT(l) - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFFT(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinT(ListDinT l)
{
    if (NEFFT(l) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDinT(ListDinT l)
{
    if (NEFFT(l) == CAPACITYT(l))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinT(ListDinT *l, ElTypeLDT val)
{
    ELMTT(*l, getLastIdxListDinT(*l) + 1) = val;
    NEFFT(*l)
    ++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinT(ListDinT *l, ElTypeLDT *val)
{
    *val = ELMTT(*l, getLastIdxListDinT(*l));
    NEFFT(*l)
    --;
    // printList(*l);
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinT(ListDinT *l, int num)
{
    ElTypeLDT *ptr;
    ptr = (ElTypeLDT *)calloc(CAPACITYT(*l), sizeof(ElTypeLDT));
    ElTypeLDT *temp = ptr;
    CAPACITYT(*l) = CAPACITYT(*l) + num;
    ptr = realloc(ptr, CAPACITYT(*l) * sizeof(ElTypeLDT));
}
/* Proses : Menambahkan capacityT l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinT(ListDinT *l, int num)
{
    ElTypeLDT *ptr;
    ptr = (ElTypeLDT *)calloc(CAPACITYT(*l), sizeof(ElTypeLDT));
    ElTypeLDT *temp = ptr;
    CAPACITYT(*l) = CAPACITYT(*l) - num;
    ptr = realloc(ptr, CAPACITYT(*l) * sizeof(ElTypeLDT));
}
/* Proses : Mengurangi capacityT sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacityT > num, dan nEff < capacityT - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinT(ListDinT *l)
{
    CAPACITYT(*l) = NEFFT(*l);
}
/* Proses : Mengubah capacityT sehingga capacityT = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacityT = nEff */

void CreateKicau(ListDinT *l, Entry author){
    if(isFullListDinT(*l)){
        expandListDinT(&*l,10);
    }
    Kicau k;
    IDBALASAN(k) = 0;
    ID(k) = NEFFT(*l) + 1;
    LIKE(k) = 0;
    AUTHOR(k) = author;
    UTASAN(k) = NULL;
    AddressBT t = NULL;
    ISUTAS(k) = false;
    BALASAN(k) = t;

    printf("Masukkan kicauan:\n");
    STARTENTRY();
    if(!CHECKVALIDTWEET(cleansedEntry(currentEntry))){
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } else {
        TEXT(k) = cleansedEntry(currentEntry);
        printf("\nSelamat! kicauan telah diterbitkan!\nDetil kicauan:\n");

        WAKTU(k) = GetLocalTime();
        DisplayKicau(k);
        // BALASAN(k) = NewTree(k);
        ELMTT(*l,NEFFT(*l)) = k;
        NEFFT(*l)++;
    }
}

void Kicauan(Graf G, ListDinT KicauGlobal, ListStatik ListProfil, int CurrentUser){
    if(NEFFT(KicauGlobal) == 0){
        printf("Belum ada kicauan saat ini.\n");
    } else {
        for(int i=NEFFT(KicauGlobal)-1;i>=0;i--){
            Entry NamaAuthor = AUTHOR(ELMTT(KicauGlobal,i));
            if(isBerteman(G,CurrentUser,indexNama(ListProfil,NamaAuthor))){
                DisplayKicau(ELMTT(KicauGlobal,i));
                printf("\n");
            }
        }
    }
}

void SukaKicau(Graf G, ListDinT *KicauGlobal, ListStatik ListProfil, int CurrentUser, long long int IDLike){
    if(IDLike < 0 || IDLike > NEFFT(*KicauGlobal)){
        printf("Tidak ditemukan kicauan dengan ID = %lld\n",IDLike);
    } else {
        IDLike--;
        Entry NamaAuthor = AUTHOR(ELMTT(*KicauGlobal,IDLike));
        int IDAuthor = indexNama(ListProfil,NamaAuthor);
        if(Jenis(ELMTLS(ListProfil,IDAuthor)) == 1 && !isBerteman(G,CurrentUser,IDAuthor)){
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        } else {
            printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
            LIKE(ELMTT(*KicauGlobal,IDLike))++;
            DisplayKicau(ELMTT(*KicauGlobal,IDLike));
        }
    }
}

void UbahKicau(ListDinT *KicauGlobal, ListStatik ListProfil, int CurrentUser, long long int IDUbah){
    if(IDUbah < 1 || IDUbah > NEFFT(*KicauGlobal)){
        printf("Tidak ditemukan kicauan dengan ID = %lld\n",IDUbah);
    } else {
        IDUbah--;
        Entry NamaAuthor = AUTHOR(ELMTT(*KicauGlobal,IDUbah));
        if(!isSame(NamaAuthor,Nama(ELMTLS(ListProfil,CurrentUser)))){
            printf("Kicauan dengan ID = %lld bukan milikmu!",IDUbah + 1);
        } else {
            printf("Masukkan kicauan baru:\n");
            STARTENTRY();
            if(!CHECKVALIDTWEET(cleansedEntry(currentEntry))){
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
            } else {
                TEXT(ELMTT(*KicauGlobal,IDUbah)) = cleansedEntry(currentEntry);
                printf("\nSelamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
                DisplayKicau(ELMTT(*KicauGlobal,IDUbah));
            }
        }
    }
}

void Balas(Graf G, ListDinT *KicauGlobal, ListStatik ListProfil, int CurrentUser, long long int IDKicau, long long int IDBalas){
    if(IDKicau < 1 || IDKicau > NEFFT(*KicauGlobal)){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    } else {
        Kicau k = ELMTT(*KicauGlobal,IDKicau-1);
        if(IDBalas > IDBALASAN(k)){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        } else {
            Entry authorowner;
            BinTree bi = BALASAN(k);
            if(IDBalas == -1){
                authorowner = Nama(ELMTLS(ListProfil,CurrentUser));
            } else {
                authorowner = AUTHORB(ROOT(searchTree(BALASAN(k),IDBalas)));
            }
            int idAuthorOwner = indexNama(ListProfil,authorowner);
            if(!isBerteman(G,CurrentUser,indexNama(ListProfil,authorowner)) && Jenis(ELMTLS(ListProfil,idAuthorOwner))){
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
            } else {
                BalasanB b;
                IDB(b) = IDBALASAN(k) + 1;
                IDBALASAN(k) = IDB(b);
                AUTHORB(b) = Nama(ELMTLS(ListProfil,CurrentUser));

                printf("Masukkan balasan:\n");
                STARTENTRY();
                if(!CHECKVALIDTWEET(cleansedEntry(currentEntry))){
                    printf("Balasan tidak boleh hanya berisi spasi!\n");
                } else {
                    TEXTB(b) = cleansedEntry(currentEntry);
                    printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");
                    WAKTUB(b) = GetLocalTime();

                    printf("| ID = %d\n",IDB(b));
                    printf("| "); printEntry(AUTHORB(b)); printf("\n");
                    printf("| "); TulisDATETIME(WAKTUB(b)); printf("\n");
                    printf("| "); printEntry(TEXTB(b)); printf("\n\n");

                    if(isTreeEmpty(BALASAN(k))){
                        BALASAN(ELMTT(*KicauGlobal,IDKicau-1)) = newTreeNode(b);
                    } else if(IDBalas == -1){
                        BinTree binitial = bi;
                        addRight(&bi,b);
                        BALASAN(ELMTT(*KicauGlobal,IDKicau-1)) = binitial;
                    } else {
                        BinTree binitial = bi;
                        addRight(&LEFT(searchTree(BALASAN(k),IDBalas)),b);
                        BALASAN(ELMTT(*KicauGlobal,IDKicau-1)) = binitial;
                    }
                    IDBALASAN(ELMTT(*KicauGlobal,IDKicau-1)) = IDBALASAN(ELMTT(*KicauGlobal,IDKicau-1)) + 1;
                }
            }
        }
    }
}

void CoutSpace(int depth){
    for(int i=0;i<3*depth;i++){
        printf(" ");
    }
}

void PrintBalasan(Graf G, ListStatik ListProfil, int CurrentUser, BinTree p, int depth){
    if(!isTreeEmpty(p)){
        Entry AuthorKicau = AUTHORB(ROOT(p));
        int IdAuthorKicau = indexNama(ListProfil,AuthorKicau);

        if(!isBerteman(G,CurrentUser,IdAuthorKicau) && Jenis(ELMTLS(ListProfil,IdAuthorKicau))){
            CoutSpace(depth); printf("| ID = %d\n",IDB(ROOT(p)));
            CoutSpace(depth); printf("| PRIVAT\n");
            CoutSpace(depth); printf("| PRIVAT\n");
            CoutSpace(depth); printf("| PRIVAT\n\n");
        } else {
            CoutSpace(depth); printf("| ID = %d\n",IDB(ROOT(p)));
            CoutSpace(depth); printf("| "); printEntry(AUTHORB(ROOT(p))); printf("\n");
            CoutSpace(depth); printf("| "); TulisDATETIME(WAKTUB(ROOT(p))); printf("\n");
            CoutSpace(depth); printf("| "); printEntry(TEXTB(ROOT(p))); printf("\n\n");
        }
        PrintBalasan(G, ListProfil, CurrentUser,LEFT(p),depth+1);
        PrintBalasan(G, ListProfil, CurrentUser,RIGHT(p),depth);
    }
}

void Balasan(Graf G, ListDinT *KicauGlobal, ListStatik ListProfil, int CurrentUser, long long int IDKicau){
    Entry AuthorKicau = AUTHOR(ELMTT(*KicauGlobal,IDKicau-1));
    int IdAuthorKicau = indexNama(ListProfil,AuthorKicau);
    if(IDKicau < 1 || IDKicau > NEFFT(*KicauGlobal)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    } else if(isTreeEmpty(BALASAN(ELMTT(*KicauGlobal,IDKicau-1)))){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
    } else if(!isBerteman(G,CurrentUser,IdAuthorKicau) && Jenis(ELMTLS(ListProfil,IdAuthorKicau))){
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
    } else {
        PrintBalasan(G, ListProfil, CurrentUser, BALASAN(ELMTT(*KicauGlobal,IDKicau-1)),0);
    }
}

void HapusBalasan(Graf G, ListDinT *KicauGlobal, ListStatik ListProfil, int CurrentUser, long long int IDKicau, long long int IDHapus){
    if(IDKicau < 1 || IDKicau > NEFFT(*KicauGlobal)){
        printf("Kicauan dengan ID = %d tidak ditemukan!\n",IDKicau);
    } else {
        Kicau k = ELMTT(*KicauGlobal,IDKicau-1);
        if(IDHapus > IDBALASAN(k)){
            printf("Balasan tidak ditemukan\n");
        } else {
            BinTree bi = BALASAN(k),t;
            t = searchTree(bi,IDHapus);
            if(!isSame(AUTHORB(ROOT(t)),Nama(ELMTLS(ListProfil,CurrentUser)))){
                printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            } else {
                printf("Balasan berhasil dihapus\n");
                if(isOneElmt(BALASAN(k))){
                    t = BALASAN(k);
                    BALASAN(k) = NULL;
                    free(t);
                } else {
                    RIGHT(PARENT(t)) = RIGHT(t);
                    dealloc(LEFT(t));
                    deallocTreeNode(t);
                    BALASAN(k) = bi;
                }
            }
        }
    }
}

void BuatDraf(ListDinT *KicauGlobal, Stack *S, Entry Author){
    printf("Masukkan draf:\n");
    STARTENTRY();
    Entry CurrentDraf = cleansedEntry(currentEntry);
    if(!CHECKVALIDTWEET(CurrentDraf)){
        printf("Draf tidak boleh hanya berisi spasi!\n");
    } else {
        printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        if(isSame(currentEntry,StringToEntry("HAPUS",5))){
            printf("\nDraf telah berhasil dihapus!\n");
        } else if(isSame(currentEntry,StringToEntry("SIMPAN",6))){
            push(&*S,CurrentDraf);
            printf("Draf telah berhasil disimpan!\n");
        } else if(isSame(currentEntry,StringToEntry("TERBIT",7))){ 
            if(isFullListDinT(*KicauGlobal)){
                expandListDinT(&*KicauGlobal,10);
            }
            Kicau k;
            IDBALASAN(k) = 0;
            ID(k) = NEFFT(*KicauGlobal) + 1;
            LIKE(k) = 0;
            AUTHOR(k) = Author;
            UTASAN(k) = NULL;
            BALASAN(k) = NULL;
            TEXT(k) = CurrentDraf;
            WAKTU(k) = GetLocalTime();

            printf("Selamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
            DisplayKicau(k);

            ELMTT(*KicauGlobal,NEFFT(*KicauGlobal)) = k;
            NEFFT(*KicauGlobal)++;
        }
    }
}

void LihatDraf(ListDinT *KicauGlobal, Stack *S, Entry Author){
    Eltypes dummy;
    if(isEmptyS(*S)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else {
        printf("Ini draf terakhir anda:\n");
        printf("| "); TulisDATETIME(WAKTUS(TOP(*S))); printf("\n");
        printf("| "); printEntry(TEXTS(TOP(*S))); printf("\n\n");
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        if(isSame(currentEntry,StringToEntry("HAPUS",5))){
            Eltypes dummy;
            pop(&*S,&dummy);
            printf("\nDraf telah berhasil dihapus!\n");
        } else if(isSame(currentEntry,StringToEntry("UBAH",4))){
            printf("Masukkan draf yang baru:\n");
            STARTENTRY();
            TEXTS(TOP(*S)) = cleansedEntry(currentEntry);
            WAKTUS(TOP(*S)) = GetLocalTime();
            if(!CHECKVALIDTWEET(TEXTS(TOP(*S)))){
                printf("Draf tidak boleh hanya berisi spasi!\n");
            } else {
                printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
                STARTENTRY();
                currentEntry = cleansedEntry(currentEntry);
                if(isSame(currentEntry,StringToEntry("HAPUS",5))){
                    pop(&*S,&dummy);
                } else if(isSame(currentEntry,StringToEntry("SIMPAN",6))){
                    printf("Draf telah berhasil disimpan!\n");
                } else if(isSame(currentEntry,StringToEntry("TERBIT",6))){
                    if(isFullListDinT(*KicauGlobal)){
                        expandListDinT(&*KicauGlobal,10);
                    }
                    Kicau k;
                    IDBALASAN(k) = 0;
                    ID(k) = NEFFT(*KicauGlobal) + 1;
                    LIKE(k) = 0;
                    AUTHOR(k) = Author;
                    UTASAN(k) = NULL;
                    BALASAN(k) = NULL;
                    TEXT(k) = TEXTS(TOP(*S));
                    WAKTU(k) = GetLocalTime();

                    printf("Selamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
                    DisplayKicau(k);

                    pop(&*S,&dummy);
                    ELMTT(*KicauGlobal,NEFFT(*KicauGlobal)) = k;
                    NEFFT(*KicauGlobal)++;
                }
            }
        } else if(isSame(currentEntry,StringToEntry("TERBIT",6))){ // Terbit
            if(isFullListDinT(*KicauGlobal)){
                expandListDinT(&*KicauGlobal,10);
            }
            Kicau k;
            IDBALASAN(k) = 0;
            ID(k) = NEFFT(*KicauGlobal) + 1;
            LIKE(k) = 0;
            AUTHOR(k) = Author;
            UTASAN(k) = NULL;
            BALASAN(k) = NULL;
            TEXT(k) = TEXTS(TOP(*S));
            WAKTU(k) = GetLocalTime();

            printf("Selamat! Draf kicauan telah diterbitkan!\nDetil kicauan:\n");
            DisplayKicau(k);

            ELMTT(*KicauGlobal,NEFFT(*KicauGlobal)) = k;
            NEFFT(*KicauGlobal)++;
        }
    }
}

void Utas(ListDinT *KicauGlobal, ListDin *UtasGlobal, Entry CurrentUser, long long int *IDUtas, long long int IDCreate){
    if(IDCreate < 1 || IDCreate > NEFFT(*KicauGlobal)){
        printf("Kicauan tidak ditemukan\n");
    } else if(!isSame(AUTHOR(ELMTT(*KicauGlobal,IDCreate-1)), CurrentUser)){
        printf("Kicau ini bukan milik anda!\n");
    } else if(ISUTAS(ELMTT(*KicauGlobal,IDCreate-1))){
        printf("Kicau ini telah menjadi utas\n");
    } else {
        ELMTLDI(*UtasGlobal,*IDUtas-1) = IDCreate-1;
        NEFFLDI(*UtasGlobal) = NEFFLDI(*UtasGlobal) + 1;
        ISUTAS(ELMTT(*KicauGlobal,IDCreate-1)) = true;
        *IDUtas = *IDUtas +1;
        readUtas(&UTASAN(ELMTT(*KicauGlobal,IDCreate-1)));
    }
}

void SambungUtas(ListDinT *KicauGlobal, ListDin UtasGlobal, Entry CurrentUser, long long int IDUtas, long long int Index){
    if(IDUtas < 1 || IDUtas > NEFFLDI(UtasGlobal)){
        printf("Utas tidak ditemukan!\n");
    } else if(!isSame(CurrentUser,AUTHOR(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1))))){
        printf("Anda tidak bisa menyambung utas ini!\n");
    } else {
        sambungUtas(&UTASAN(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1))),Index);
    }
}

void HapusUtas(ListDinT *KicauGlobal, ListDin UtasGlobal, Entry CurrentUser, long long int IDUtas, long long int Index){
    if(IDUtas < 1 || IDUtas > NEFFLDI(UtasGlobal)){
        printf("Utas tidak ditemukan!\n");
    } else if(!isSame(CurrentUser,AUTHOR(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1))))){
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
    } else if(Index == 0){
        printf("Anda tidak bisa menghapus kicauan utama!\n");
    } else {
        deleteUtasAt(&UTASAN(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1))),Index);
    }
}

void CetakUtas(Graf G, ListDinT *KicauGlobal, ListStatik ListProfil, ListDin UtasGlobal, int CurrentUser, long long int IDUtas){
    if(IDUtas < 1 || IDUtas > NEFFLDI(UtasGlobal)){
        printf("Utas tidak ditemukan!\n");
    } else if(Jenis(ELMTLS(ListProfil,indexNama(ListProfil,AUTHOR(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1)))))) && !isBerteman(G,CurrentUser,indexNama(ListProfil,AUTHOR(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1)))))){
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
    } else {
        displayLinkedUtas(ELMTT(*KicauGlobal,ELMTLDI(UtasGlobal,IDUtas-1)));
    }
}
