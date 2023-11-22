#include "save.h"

void entrytofile(FILE *f, Entry n){
    for(int i=0;i<n.Length;i++){
        fprintf(f,"%c",n.TabEntry[i]);
    }
}

void datetimetofile(FILE *f, DATETIME D){
    fprintf(f,"%d/%d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

void SimpanPengguna(Graf Pertemanan, ListStatik ListProfil){
    FILE *f = fopen("pengguna.config","w");
    int n = NEFFLS(ListProfil),i,j,k;
    int req[400][3],reqeff=0;

    fprintf(f,"%d\n",n);
    for(i=0;i<n;i++){
        Profil p = ELMTLS(ListProfil,i);
        entrytofile(f,Nama(p)); fprintf(f,"\n");
        entrytofile(f,Password(p)); fprintf(f,"\n");
        entrytofile(f,Bio(p)); fprintf(f,"\n");
        entrytofile(f,Nomor(p)); fprintf(f,"\n");
        entrytofile(f,Weton(p)); fprintf(f,"\n");
        (Jenis(p)) ? fprintf(f,"Privat\n") : fprintf(f,"Publik\n");
        for(j=0;j<5;j++){
            for(k=0;k<10;k++){
                fprintf(f,"%c ",ELMT(Foto(p),j,k));
            }
            fprintf(f,"\n");
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
            fprintf(f,"%d ", Busur(Pertemanan,i,j));
        }
        fprintf(f,"\n");
    }

    fprintf(f,"%d\n",reqeff);
    for(i=0;i<reqeff;i++){
        fprintf(f,"%d %d %d\n",req[i][0],req[i][1],req[i][2]);
    }
    fclose(f);
}

void SimpanKicauan(ListDinT KicauGlobal){
    FILE *f = fopen("kicau.config","w");
    long long int n = NEFFT(KicauGlobal),i;
    fprintf(f,"%lld\n",n);
    for(i=0;i<n;i++){
        Kicau k = ELMTT(KicauGlobal,i);
        fprintf(f,"%lld\n",ID(k));
        entrytofile(f,TEXT(k)); fprintf(f,"\n");
        fprintf(f,"%lld\n",LIKE(k));
        entrytofile(f,AUTHOR(k)); fprintf(f,"\n");
        datetimetofile(f,WAKTU(k)); fprintf(f,"\n");
    }
    fclose(f);
}

long long int TrueParent(BinTree p){
    while(PARENT(p) != NULL && RIGHT(PARENT(p)) == p){
        p = PARENT(p);
    }
    if(PARENT(p) == NULL){
        return -1;
    } else {
        return IDB(ROOT(PARENT(p)));
    }
}

void PrintAllBalasan(FILE *f, BinTree p){
    if(!isTreeEmpty(p)){
        fprintf(f,"%lld %lld\n",TrueParent(p),IDB(ROOT(p)));
        entrytofile(f,TEXTB(ROOT(p))); fprintf(f,"\n");
        entrytofile(f,AUTHORB(ROOT(p))); fprintf(f,"\n");
        datetimetofile(f,WAKTUB(ROOT(p))); fprintf(f,"\n");
        PrintAllBalasan(f,RIGHT(p));
        PrintAllBalasan(f,LEFT(p));
    }
}

void SimpanBalasan(ListDinT KicauGlobal){
    FILE *f = fopen("balasan.config","w");
    long long int n = NEFFT(KicauGlobal),i;
    long long int balasan[10000], balasaneff = 0;
    for(i=0;i<n;i++){
        if(BALASAN(ELMTT(KicauGlobal,i)) != NULL){
            balasan[balasaneff] = i;
            balasaneff++;
        }
    }
    fprintf(f,"%lld\n",balasaneff);
    for(i=0;i<balasaneff;i++){
        BinTree t = BALASAN(ELMTT(KicauGlobal,balasan[i]));
        fprintf(f,"%lld\n%d\n",balasan[i]+1,BanyakNode(t));
        PrintAllBalasan(f,t);
    }
    fclose(f);
}

void SimpanDraf(ListStatik ListProfil){
    FILE *f = fopen("draf.config","w");
    int i,drafeff=0,listdraf[20];
    for(i=0;i<NEFFLS(ListProfil);i++){
        if(!isEmptyS(DRAF(ELMTLS(ListProfil,i)))){
            listdraf[drafeff] = i;
            drafeff++;
        }
    }
    fprintf(f,"%d\n",drafeff);
    for(i=0;i<drafeff;i++){
        Profil p = ELMTLS(ListProfil,listdraf[i]);
        entrytofile(f,Nama(p)); fprintf(f," %d\n",lengthS(DRAF(p)));
        while(!isEmptyS(DRAF(p))){
            entrytofile(f,TEXTS(TOP(DRAF(p)))); fprintf(f,"\n");
            datetimetofile(f,WAKTUS(TOP(DRAF(p)))); fprintf(f,"\n");
            ADDR_TOP(DRAF(p)) = NEXTS(ADDR_TOP(DRAF(p)));
        }
    }
    fclose(f);
}

void SimpanUtas(ListDinT KicauGlobal, ListDin UtasGlobal){
    FILE *f = fopen("utas.config","w");
    long long int i;
    fprintf(f,"%d\n",NEFFLDI(UtasGlobal));
    for(i=0;i<NEFFLDI(UtasGlobal);i++){
        fprintf(f,"%d\n%d\n",ELMTLDI(UtasGlobal,i)+1,getLastIdxUtas(UTASAN(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i)))));
        Address p;
        p = FIRSTUTAS(UTASAN(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i))));
        while (p != NULL){
            entrytofile(f,TEXTUTAS(INFOUTAS(p))); fprintf(f,"\n");
            entrytofile(f,AUTHOR(ELMTT(KicauGlobal,ELMTLDI(UtasGlobal,i)))); fprintf(f,"\n");
            datetimetofile(f,TIME(INFOUTAS(p))); fprintf(f,"\n");
            p = NEXT(p);
        }
    }
    fclose(f);
}

void SimpanBatch(Graf Pertemanan, ListStatik ListProfil, ListDinT KicauGlobal, ListDin UtasGlobal){
    SimpanPengguna(Pertemanan,ListProfil);
    SimpanKicauan(KicauGlobal);
    SimpanBalasan(KicauGlobal);
    SimpanDraf(ListProfil);
    SimpanUtas(KicauGlobal,UtasGlobal);
}
