#include <stdio.h>
#include "graf.h"

void LihatProfil(Graf G, ListStatik ListProfil, int CurrentUser, Entry namaTeman){
    if(indexNama(ListProfil,namaTeman) == IDX_UNDEF){
        printf("Akun tidak ditemukan!\n");
    } else {
        int indexTeman = indexNama(ListProfil,namaTeman);
        if(Jenis(ELMTLS(ListProfil,indexTeman)) == 0 || CurrentUser == indexTeman){ // Akun Publik
            PrintProfil(ELMTLS(ListProfil,indexTeman));
        } else { // Akun Privat
            if(isBerteman(G,CurrentUser,indexTeman)){
                PrintProfil(ELMTLS(ListProfil,indexTeman));
            } else {
                printf("Wah, akun "); printEntry(Nama(ELMTLS(ListProfil,indexTeman)));
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil "); printEntry(Nama(ELMTLS(ListProfil,indexTeman)));
                printf("!\n");
            }
        }
    }
}

void CreateGraf(Graf *G)
{
    for(int i=0;i<MAX_PENGGUNA;i++){
        Simpul(*G,i) = 0;
        for(int j=0;j<MAX_PENGGUNA;j++){
            if(i == j){
                Busur(*G,i,j) = 1;
            } else {
                Busur(*G,i,j) = 0;
            }
        }
    }
}

void TambahTeman(Graf *G, ListStatik *ListProfil, int CurrentUser){
    if(!isEmptyQueue(PermintaanPertemanan(ELMTLS(*ListProfil,CurrentUser)))){
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    } else {
        printf("Masukkan nama pengguna:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);

        if(indexNama(*ListProfil,currentEntry) == IDX_UNDEF){
            printf("Pengguna bernama "); printEntry(currentEntry); printf(" tidak ditemukan.\n");
        } else{
            int indexteman = indexNama(*ListProfil, currentEntry);
            Entry namaTeman = currentEntry;
            if(CurrentUser == indexteman){
                printf("Anda tidak dapat mengirim permintaan pertemanan ke diri sendiri...\n");
            } else if(isBerteman(*G,CurrentUser,indexteman)){
                printf("Anda sudah berteman dengan "); printEntry(currentEntry); printf(".\n");
            } else {
                if(IsIn(PermintaanPertemanan(ELMTLS(*ListProfil,indexteman)),Nama(ELMTLS(*ListProfil,CurrentUser)))){
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada "); printEntry(namaTeman); printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
                } else {
                    printf("Permintaan pertemanan kepada "); printEntry(currentEntry); printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
                    Elmtqueue e;
                    Info(e) = Nama(ELMTLS(*ListProfil,CurrentUser));
                    Prio(e) = JumlahTeman(ELMTLS(*ListProfil,CurrentUser));
                    Enqueue(&PermintaanPertemanan(ELMTLS(*ListProfil,indexteman)), e);
                }
            }
        }
    }
}

void HapusTeman(Graf *G, ListStatik *ListProfil, int CurrentUser){
    if(NEFFLS(*ListProfil) == 1){
        printf("Tidak dapat menghapus teman...\nHanya ada anda sendiri...\nDi dunia ini...\n");
    } else if(JumlahTeman(ELMTLS(*ListProfil,CurrentUser)) == 0){
        printf("Anda belum mempunyai teman.\n");
    } else {
        printf("Masukkan nama pengguna:\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(indexNama(*ListProfil, currentEntry) == IDX_UNDEF){ // Nama tidak ditemukan
            printf("Pengguna tidak ditemukan!\n");
            printf("Masukkan nama pengguna:\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        int indexteman = indexNama(*ListProfil, currentEntry);
        Entry namaTeman = currentEntry;
        if(CurrentUser == indexteman){
            printf("Anda tidak dapat menghapus diri sendiri...\n");
        } if(!isBerteman(*G, CurrentUser,indexteman)){
            printEntry(namaTeman); printf(" bukan teman anda.\n");
        } else {
            printf("Apakah anda yakin ingin menghapus "); printEntry(currentEntry); printf(" dari daftar teman anda?(YA/TIDAK)\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
            while(!isSame(currentEntry,StringToEntry("YA",2)) && !isSame(currentEntry,StringToEntry("TIDAK",5))){
                printf("Input tidak valid. (YA/TIDAK)\n");
                STARTENTRY();
                currentEntry = cleansedEntry(currentEntry);
            }
            if(isSame(currentEntry,StringToEntry("YA",2))){
                printEntry(namaTeman); printf(" berhasil dihapus dari daftar teman Anda.\n");
                Busur(*G,CurrentUser,indexteman) = 0;
                Busur(*G,indexteman,CurrentUser) = 0;
            JumlahTeman(ELMTLS(*ListProfil,CurrentUser))--;
            JumlahTeman(ELMTLS(*ListProfil,indexteman))--;
            } else {
                printf("Penghapusan teman dibatalkan.\n");
            }
        }
    }
}

void DaftarTeman(Graf G, ListStatik ListProfil, int CurrentUser)
{
    if(JumlahTeman(ELMTLS(ListProfil,CurrentUser)) == 0){
        printEntry(Nama(ELMTLS(ListProfil,CurrentUser))); printf(" Belum memiliki teman\n");
    } else {
        printEntry(Nama(ELMTLS(ListProfil,CurrentUser))); printf(" memiliki %d teman\n", JumlahTeman(ELMTLS(ListProfil,CurrentUser)));
        printf("Daftar Teman "); printEntry(Nama(ELMTLS(ListProfil,CurrentUser))); printf("\n");
        for(int i=0;i<MAX_PENGGUNA;i++){
            if((Busur(G, CurrentUser, i) == 1) && (!isSame(Nama(ELMTLS(ListProfil,i)), Nama(ELMTLS(ListProfil,CurrentUser))))){
                printf("| "); printEntry(Nama(ELMTLS(ListProfil,i))); printf("\n");
            }
        }
    }
}

void TerimaTeman(Graf *G, ListStatik ListProfil, int CurrentUser){
    if(isEmptyQueue(PermintaanPertemanan(ELMTLS(ListProfil,CurrentUser)))){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else {
        PrintQueue(PermintaanPertemanan(ELMTLS(ListProfil,CurrentUser)));
    }
}

void SetujuiTeman(Graf *G, ListStatik *ListProfil, int CurrentUser){
    if(isEmptyQueue(PermintaanPertemanan(ELMTLS(*ListProfil,CurrentUser)))){
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else {
        Entry teman = Info(HEAD(PermintaanPertemanan(ELMTLS(*ListProfil,CurrentUser))));
        int jumlahTeman = Prio(HEAD(PermintaanPertemanan(ELMTLS(*ListProfil,CurrentUser))));

        printf("Permintaan pertemanan teratas dari "); printEntry(teman);
        printf("\n\n| "); printEntry(teman);
        printf("\n| Jumlah teman: %d\n\n", jumlahTeman);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)\n");
        STARTENTRY();
        currentEntry = cleansedEntry(currentEntry);
        while(!isSame(currentEntry,StringToEntry("YA",2)) && !isSame(currentEntry,StringToEntry("TIDAK",5))){
            printf("Input tidak valid. (YA/TIDAK)\n");
            STARTENTRY();
            currentEntry = cleansedEntry(currentEntry);
        }
        if(isSame(currentEntry,StringToEntry("YA",2))){
            int indexTeman = indexNama(*ListProfil,teman);
            Busur(*G,CurrentUser,indexTeman) = 1;
            Busur(*G,indexTeman,CurrentUser) = 1;
            JumlahTeman(ELMTLS(*ListProfil,CurrentUser))++;
            JumlahTeman(ELMTLS(*ListProfil,indexTeman))++;
            printf("Permintaan pertemanan dari "); printEntry(teman);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan "); printEntry(teman); printf(".\n\n");
        } else {
            printf("Permintaan pertemanan dari "); printEntry(teman); printf(" telah ditolak.\n");
        }
        Dequeue(&PermintaanPertemanan(ELMTLS(*ListProfil,CurrentUser)));
    }
}

boolean isBerteman(Graf G, int User1, int User2){
    return Busur(G, User1, User2);
}