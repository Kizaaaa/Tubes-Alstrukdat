#include "save.h"

void SimpanPengguna(Graf Pertemanan, ListStatik ListProfil){
    int n = NEFFLS(ListProfil),i,j,k;
    int req[400][3],reqeff=0;

    printf("%d\n",n);
    for(i=0;i<n;i++){
        Profil p = ELMTLS(ListProfil,i);
        printEntry(Nama(p)); printf("\n");
        printEntry(Password(p)); printf("\n");
        printEntry(Bio(p)); printf("\n");
        printEntry(Nomor(p)); printf("\n");
        printEntry(Weton(p)); printf("\n");
        (Jenis(p)) ? printf("Privat\n") : printf("Publik\n");
        for(j=0;j<5;j++){
            for(k=0;k<10;k++){
                printf("%c ",ELMT(Foto(p),j,k));
            }
            printf("\n");
        }

        while(!isEmptyQueue(PermintaanPertemanan(p))){
            req[reqeff][0] = indexNama(ListProfil,Info(HEAD(PermintaanPertemanan(p))));
            req[reqeff][1] = i;
            req[reqeff][2] = Prio(HEAD(PermintaanPertemanan(p)));
            Dequeue(&PermintaanPertemanan(p));
            reqeff++;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", Busur(Pertemanan,i,j));
        }
        printf("\n");
    }

    printf("%d\n",reqeff);
    for(i=0;i<reqeff;i++){
        printf("%d %d %d\n",req[i][0],req[i][1],req[i][2]);
    }
}

void SimpanKicauan(ListDinT KicauGlobal){
    long long int n = NEFFT(KicauGlobal),i;
    printf("%lld\n",n);
    for(i=0;i<n;i++){
        Kicau k = ELMTT(KicauGlobal,i);
        printf("%lld\n",ID(k));
        printEntry(TEXT(k)); printf("\n");
        printf("%lld\n",LIKE(k));
        printEntry(AUTHOR(k)); printf("\n");
        TulisDATETIME(WAKTU(k)); printf("\n");
    }
}

void SimpanBalasan(ListDinT KicauGlobal){
    long long int n = NEFFT(KicauGlobal),i;
    long long int balasan[10000], balasaneff = 0;
    for(i=0;i<n;i++){
        if(BALASAN(ELMTT(KicauGlobal,i)) != NULL){
            balasan[balasaneff] = i;
            balasaneff++;
        }
    }
    printf("%lld\n",balasaneff);
    for(i=0;i<balasaneff;i++){
        BinTree t = BALASAN(ELMTT(KicauGlobal,balasan[i]));
        printf("%lld\n%d\n",balasan[i]+1,BanyakNode(t));
        PrintAllBalasan(t);
    }
}

void SimpanDraf(ListStatik ListProfil){
    int i,drafeff=0,listdraf[20];
    for(i=0;i<NEFFLS(ListProfil);i++){
        if(!isEmptyS(DRAF(ELMTLS(ListProfil,i)))){
            listdraf[drafeff] = i;
            drafeff++;
        }
    }
    printf("%d\n",drafeff);
    for(i=0;i<drafeff;i++){
        Profil p = ELMTLS(ListProfil,listdraf[i]);
        printEntry(Nama(p)); printf(" %d\n",lengthS(DRAF(p)));
        while(!isEmptyS(DRAF(p))){
            printEntry(TEXTS(TOP(DRAF(p)))); printf("\n");
            TulisDATETIME(WAKTUS(TOP(DRAF(p)))); printf("\n");
            ADDR_TOP(DRAF(p)) = NEXTS(ADDR_TOP(DRAF(p)));
        }
    }
}

void SimpanUtas(ListDinT KicauGlobal, ListDin UtasGlobal){
    long long int i;
    printf("%d\n",NEFFLDI(UtasGlobal));
    for(i=0;i<NEFFLDI(UtasGlobal);i++){
        printf("%d\n%d\n",ELMTLDI(UtasGlobal,i)+1,getLastIdxUtas(UTASAN(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i)))));
        Address p;
        p = FIRSTUTAS(UTASAN(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i))));
        while (p != NULL){
            printEntry(TEXTUTAS(INFOUTAS(p))); printf("\n");
            printEntry(AUTHOR(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i)))); printf("\n");
            TulisDATETIME(TIME(INFOUTAS(p))); printf("\n");
            p = NEXT(p);
        }
    }
}

void SimpanBatch(Graf Pertemanan, ListStatik ListProfil, ListDinT KicauGlobal, ListDin UtasGlobal){
    SimpanPengguna(Pertemanan,ListProfil);
    SimpanKicauan(KicauGlobal);
    SimpanBalasan(KicauGlobal);
    SimpanDraf(ListProfil);
    SimpanUtas(KicauGlobal,UtasGlobal);
}
