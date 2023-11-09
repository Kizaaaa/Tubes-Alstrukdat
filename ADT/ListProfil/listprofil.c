#include <stdio.h>
#include <stdlib.h>
#include "listprofil.h"

void Masuk(ListStatik *ListProfil, int *CurrentUser, boolean *isMasuk){
    if(isEmptyListStatik(*ListProfil)){
        printf("Belum ada pengguna yang didaftarkan!\n");
    } else {
        printf("Masukkan nama:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        printf("\n");
        while(indexNama(*ListProfil,currentEntry) == IDX_UNDEF){
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            printf("Masukkan nama:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
            printf("\n");
        }

        *CurrentUser = indexNama(*ListProfil,currentEntry);

        printf("Masukkan kata sandi:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        printf("\n");
        while(!isSame(currentEntry,Password(ELMTLS(*ListProfil,*CurrentUser)))){
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            printf("Masukkan kata sandi:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
            printf("\n");
        }

        printf("Anda telah berhasil masuk dengan nama pengguna ");
        printEntry(Nama(ELMTLS(*ListProfil,*CurrentUser)));
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
        *isMasuk = true;
    }
}

void Daftar(ListStatik *ListProfil){
    /* I.S. P sembarang */
    /* F.S. P terdefinisi dengan jenis tertentu */
    if(isFullListStatik(*ListProfil)){
        printf("Jumlah pengguna sudah maksimum, tidak dapat mendaftarkan akun lagi\n");
    } else {
        Jenis(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = 0; //Akun Publik
        JumlahTeman(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = 0; //Jumlah Teman
        Entry blank = StringToEntry("",0);
        Bio(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = blank;
        Nomor(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = blank;
        Weton(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = blank;
        Queue q; CreateQueue(&q);
        PermintaanPertemanan(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = q;

        printf("Masukkan nama:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        printf("\n");
        while(!CHECKVALIDUNP(currentEntry) || indexNama(*ListProfil,currentEntry) != IDX_UNDEF){
            if(currentEntry.Length == 0){
                printf("Nama tidak boleh kosong!\n\n");
            } else if(currentEntry.Length > 20){
                printf("Nama tidak boleh lebih dari 20 karakter!\n\n");
            } else if(indexNama(*ListProfil,currentEntry) != IDX_UNDEF) { //Nama pengguna sudah diambil
                printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
            }

            printf("Masukkan nama:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
            printf("\n");
        }
        Nama(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = currentEntry;

        printf("Masukkan kata sandi:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        printf("\n");
        while(!CHECKVALIDUNP(currentEntry)){
            if(currentEntry.Length == 0){
                printf("Kata sandi tidak boleh kosong!\n\n");
            } else {
                printf("Kata sandi tidak boleh lebih dari 20 karakter!\n\n");
            }

            printf("Masukkan kata sandi:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
            printf("\n");
        }
        Password(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = currentEntry;

        Foto(ELMTLS(*ListProfil,NEFFLS(*ListProfil))) = FotoDefault();
        NEFFLS(*ListProfil)++;
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }
}

MatrixChar FotoDefault(){
    int i, j;
    MatrixChar m;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 10; j++){
            if(j%2){
                ELMT(m,i,j) = '*';
            } else {
                ELMT(m,i,j) = 'R';
            }
        }
    }

    return m;
}

void PrintProfil(Profil P){
    /* I.S. P terdefinisi */
    /* F.S. P tercetak di layar dengan format:
        Nama: <Nama>
        Bio Akun : <Bio>
        No HP: <Nomor>
        Weton: <Weton>
        Foto profil akun <nama>
    */
    printf("| Nama: "); printEntry(Nama(P)); printf("\n");
    printf("| Bio Akun: "); printEntry(Bio(P)); printf("\n");
    printf("| No HP: "); printEntry(Nomor(P)); printf("\n");
    printf("| Weton: "); printEntry(Weton(P)); printf("\n\n");

    printf("Foto profil akun "); printEntry(Nama(P)); printf("\n");
    PrintFoto(Foto(P));
}

/* ********** MENGUBAH FOTO DAN PROFILE ********** */
void GantiProfil(Profil *P){
    printf("| Nama: "); printEntry(Nama(*P)); printf("\n");
    printf("| Bio Akun: "); printEntry(Bio(*P)); printf("\n");
    printf("| No HP: "); printEntry(Nomor(*P)); printf("\n");
    printf("| Weton: "); printEntry(Weton(*P)); printf("\n\n");

    printf("Masukkan Bio Akun:\n");
    STARTENTRY();
    if(currentEntry.Length > 135){
        Bio(*P) = PotongEntry(cleansedEntry(currentEntry),135);// MAKSIMAL 135 KARAKTER
    } else {
        Bio(*P) = cleansedEntry(currentEntry);
    }
    

    printf("Masukkan No HP:\n");
    STARTENTRY();
    currentEntry = cleansedEntry(currentEntry); // HARUS DALAM ANGKA
    while(!CHECKNOMORHP(currentEntry) && !isSame(currentEntry,StringToEntry("",0))){
        printf("No HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan No HP:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
    }
    Nomor(*P) = currentEntry;

    printf("Masukkan Weton:\n");
    STARTENTRY();
    currentEntry = cleansedEntry(currentEntry); // HARI HARUS ADA DI LIST WETON: Pahing, Kliwon, Wage, Pon, dan Legi (case insensitive)
    while(!CHECKWETON(currentEntry) && !isSame(currentEntry,StringToEntry("",0))){
        printf("Weton anda tidak valid.\n\n");
        printf("Masukkan Weton:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
    }
    Weton(*P) = UnifyWeton(currentEntry);

    printf("Profil Anda sudah berhasil diperbarui!\n\n");
}

void GantiFoto(Profil *P){
    printf("Foto profil Anda saat ini adalah\n");
    PrintFoto(Foto(*P));

    printf("\nMasukkan foto profil yang baru\n");

    MatrixChar m;
    ROW_EFF(m) = 5; COL_EFF(m) = 10;
    int i=0,j=0;
    STARTENTRY();
    boolean color= true;
    for(int k=0;k<currentEntry.Length;k++){
        if(currentEntry.TabEntry[k] != 10 && currentEntry.TabEntry[k] != 32){
            ELMT(m,i,j) = currentEntry.TabEntry[k];
            j++;
            if(j==10){
                i++;
                j = 0;
            }
        }
    }
    Foto(*P) = m;

    printf("Foto profil anda sudah berhasil diganti!\n");
}

/* ********** ATUR JENIS AKUN (PRIVAT/UMUM) ********** */
void GantiJenis(Profil *P){
    if(Jenis(*P)){
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK)\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!isSame(currentEntry,StringToEntry("YA",2)) && !isSame(currentEntry,StringToEntry("TIDAK",5))){
            printf("Input tidak valid. (YA/TIDAK)\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        if(isSame(currentEntry,StringToEntry("YA",2))){
            printf("Akun anda sudah diubah menjadi akun Publik.\n");
            Jenis(*P) = 0;
        }
    } else {
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK)\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!isSame(currentEntry,StringToEntry("YA",2)) && !isSame(currentEntry,StringToEntry("TIDAK",5))){
            printf("Input tidak valid. (YA/TIDAK)\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        if(isSame(currentEntry,StringToEntry("YA",2))){
            printf("Akun anda sudah diubah menjadi akun Privat.\n");
            Jenis(*P) = 1;
        }
    }
}

/* ********** FOTO ********** */
void PrintFoto(MatrixChar m)
{
    /* I.S. P terdefinisi */
    /* F.S. P Cetak foto baru 5x5  */
    int i, j;
    char c1,c2;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 10; j+=2){
            c1 = ELMT(m, i, j + 1);
            c2 = ELMT(m, i, j);
            if(c2 == 'R'){
                print_red(c1);
            }
            if(c2 == 'G'){
                print_green(c1);
            }
            if (c2 == 'B'){
                print_blue(c1);
            }
        }
        printf("\n");
    }
}

void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
{
    NEFFLS(*l) = 0;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStatik(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return NEFFLS(l) == 0;
}

/* *** Test List penuh *** */
boolean isFullListStatik(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return NEFFLS(l) == CAPACITY;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexNama(ListStatik l, Entry nama)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    if (isEmptyListStatik(l)){
        return IDX_UNDEF;
    } else {
        int i = 0;
        boolean found = false;
        while (i < NEFFLS(l) && !found){
            if (isSame(Nama(ELMTLS(l,i)),nama)) {
                found = true;
            } else {
                i++;
            }
        }
        if(found){
            return i;
        } else {
            return IDX_UNDEF;
        }
        
    }
}

void CreateQueue(Queue *Q){
    IDXHEAD(*Q) = IDX_UNDEF;
    IDXTAIL(*Q) = IDX_UNDEF;
}

boolean isEmptyQueue(Queue Q){
    return IDXHEAD(Q) == IDX_UNDEF && IDXTAIL(Q) == IDX_UNDEF;
}

int lengthQueue(Queue Q){
    if(IDXHEAD(Q) == IDX_UNDEF){
        return 0;
    } else if(IDXHEAD(Q) <= IDXTAIL(Q)){
        return IDXTAIL(Q) - IDXHEAD(Q) + 1;
    } else {
        return CAPACITY + IDXTAIL(Q) - IDXHEAD(Q) + 1;
    }
}

boolean IsIn(Queue Q, Entry nama){
    while(IDXHEAD(Q) != IDXTAIL(Q)){
        if(isSame(Info(HEAD(Q)),nama)){
            return true;
        }
        IDXHEAD(Q) = (IDXHEAD(Q) + 1) % CAPACITY;
    }
    if(isSame(Info(HEAD(Q)),nama)){
        return true;
    }
    return false;
}

void Enqueue(Queue *Q, Elmtqueue Val){
    if(isEmptyQueue(*Q)){
        IDXHEAD(*Q) = 0;
        IDXTAIL(*Q) = 0;
        ELMTQ(*Q,0) = Val;
    } else {
        int idxheadawal = IDXHEAD(*Q);
        while(Prio(Val) < Prio(HEAD(*Q)) && IDXHEAD(*Q) != IDXTAIL(*Q)){
            IDXHEAD(*Q) = (IDXHEAD(*Q) + 1) % CAPACITY;
        }
        if(IDXHEAD(*Q) == IDXTAIL(*Q) && Prio(Val) < Prio(HEAD(*Q))){
            IDXTAIL(*Q) = (IDXTAIL(*Q) + 1) % CAPACITY;
            TAIL(*Q) = Val;
        } else {
            IDXTAIL(*Q) = (IDXTAIL(*Q) + 1) % CAPACITY;
            int idxtailawal = IDXTAIL(*Q);
            while(IDXTAIL(*Q) != IDXHEAD(*Q)){
                TAIL(*Q) = ELMTQ(*Q,(IDXTAIL(*Q) - 1 + CAPACITY) % CAPACITY);
                IDXTAIL(*Q) = (IDXTAIL(*Q) - 1 + CAPACITY) % CAPACITY;
            }
            TAIL(*Q) = Val;
            IDXTAIL(*Q) = idxtailawal;
        }
        IDXHEAD(*Q) = idxheadawal;
    }
}

void Dequeue(Queue *Q){
    if(lengthQueue(*Q) == 1){
        IDXHEAD(*Q) = IDX_UNDEF;
        IDXTAIL(*Q) = IDX_UNDEF;
    } else {
        IDXHEAD(*Q) = (IDXHEAD(*Q) + 1) % CAPACITY;
    }
}

void PrintQueue(Queue Q){
    if(isEmptyQueue(Q)){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else {
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n",lengthQueue(Q));
        while(IDXHEAD(Q) != IDXTAIL(Q)){
            printf("\n| "); printEntry(Info(HEAD(Q)));
            printf("\n| Jumlah teman: %d\n", Prio(HEAD(Q)));
            IDXHEAD(Q) = (IDXHEAD(Q) + 1) % CAPACITY;
        }
        printf("\n| "); printEntry(Info(HEAD(Q)));
        printf("\n| Jumlah teman: %d\n\n", Prio(HEAD(Q)));
    }
}

// int main(){
//     Queue q;
//     CreateQueue(&q);
//     Elmtqueue e;
//     Prio(e) = 1;
//     Info(e) = StringToEntry("Kiza",4);
//     Enqueue(&q,e);
//     Prio(e) = 8;
//     Info(e) = StringToEntry("Risa",4);
//     Enqueue(&q,e);
//     Prio(e) = 9;
//     Info(e) = StringToEntry("Nnael",5);
//     Enqueue(&q,e);
//     PrintQueue(q);
//     return 0;
// }
/*
gcc -o tes3 ADT/ListProfil/listprofil.c ADT/EntryMachine/entrymachine.c ADT/EntryMachine/charmachine.c Program/Pcolor/pcolor.c
*/