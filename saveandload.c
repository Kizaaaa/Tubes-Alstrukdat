#include "saveandload.h"

void entrytofile(FILE *f, Entry n)
{
    for (int i = 0; i < n.Length; i++)
    {
        fprintf(f, "%c", n.TabEntry[i]);
    }
}

void datetimetofile(FILE *f, DATETIME D)
{
    fprintf(f, "%02d/%02d/%04d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

DATETIME entryToDateTime(Entry n){
    DATETIME d;
    Day(d) = EntryToInt(cutBeforeEntry(n,2));
    n = cutAfterEntry(n,2);
    Month(d) = EntryToInt(cutBeforeEntry(n,2));
    n = cutAfterEntry(n,2);
    Year(d) = EntryToInt(cutBeforeEntry(n,4));
    n = cutAfterEntry(n,4);
    Hour(Time(d)) = EntryToInt(cutBeforeEntry(n,2));
    n = cutAfterEntry(n,2);
    Minute(Time(d)) = EntryToInt(cutBeforeEntry(n,2));
    n = cutAfterEntry(n,2);
    Second(Time(d)) = EntryToInt(cutBeforeEntry(n,2));
    n = cutAfterEntry(n,2);
    return d;
}

void SimpanPengguna(char *Path, Graf Pertemanan, ListStatik ListProfil)
{
    char path[300];
    char *folder = Path;
    char *pengguna = "/pengguna.config";
    long long int i = 0;

    while (*folder)
    {
        path[i] = *folder;
        folder++;
    }
    while (*pengguna)
    {
        *folder = *pengguna;
        pengguna++;
        folder++;
    }
    *folder = '\0';

    FILE *f = fopen(Path, "w");
    int n = NEFFLS(ListProfil), j, k;
    int req[400][3], reqeff = 0;

    fprintf(f, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        Profil p = ELMTLS(ListProfil, i);
        entrytofile(f, Nama(p));
        fprintf(f, "\n");
        entrytofile(f, Password(p));
        fprintf(f, "\n");
        entrytofile(f, Bio(p));
        fprintf(f, "\n");
        entrytofile(f, Nomor(p));
        fprintf(f, "\n");
        entrytofile(f, Weton(p));
        fprintf(f, "\n");
        (Jenis(p)) ? fprintf(f, "Privat\n") : fprintf(f, "Publik\n");
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 10; k++)
            {
                fprintf(f, "%c ", ELMT(Foto(p), j, k));
            }
            fprintf(f, "\n");
        }

        while (!isEmptyQueue(PermintaanPertemanan(p)))
        {
            req[reqeff][0] = indexNama(ListProfil, Info(HEAD(PermintaanPertemanan(p))));
            req[reqeff][1] = i;
            req[reqeff][2] = Prio(HEAD(PermintaanPertemanan(p)));
            Dequeue(&PermintaanPertemanan(p));
            reqeff++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(f, "%d ", Busur(Pertemanan, i, j));
        }
        fprintf(f, "\n");
    }

    fprintf(f, "%d\n", reqeff);
    for (i = 0; i < reqeff; i++)
    {
        fprintf(f, "%d %d %d\n", req[i][0], req[i][1], req[i][2]);
    }
    fclose(f);
}

void SimpanKicauan(char *Path, ListDinT KicauGlobal)
{
    char path[300];
    char *folder = Path;
    char *kicau = "/kicau.config";
    long long int i = 0;

    while (*folder)
    {
        path[i] = *folder;
        folder++;
    }
    while (*kicau)
    {
        *folder = *kicau;
        kicau++;
        folder++;
    }
    *folder = '\0';

    FILE *f = fopen(Path, "w");
    long long int n = NEFFT(KicauGlobal);
    fprintf(f, "%lld\n", n);
    for (i = 0; i < n; i++)
    {
        Kicau k = ELMTT(KicauGlobal, i);
        fprintf(f, "%lld\n", ID(k));
        entrytofile(f, TEXT(k));
        fprintf(f, "\n");
        entrytofile(f, TAGAR(k));
        fprintf(f, "\n");
        fprintf(f, "%lld\n", LIKE(k));
        entrytofile(f, AUTHOR(k));
        fprintf(f, "\n");
        datetimetofile(f, WAKTU(k));
        fprintf(f, "\n");
    }
    fclose(f);
}

long long int TrueParent(BinTree p)
{
    while (PARENT(p) != NULL && RIGHT(PARENT(p)) == p)
    {
        p = PARENT(p);
    }
    if (PARENT(p) == NULL)
    {
        return -1;
    }
    else
    {
        return IDB(ROOT(PARENT(p)));
    }
}

void PrintAllBalasan(FILE *f, BinTree p)
{
    if (!isTreeEmpty(p))
    {
        fprintf(f, "%lld %lld\n", TrueParent(p), IDB(ROOT(p)));
        entrytofile(f, TEXTB(ROOT(p)));
        fprintf(f, "\n");
        entrytofile(f, AUTHORB(ROOT(p)));
        fprintf(f, "\n");
        datetimetofile(f, WAKTUB(ROOT(p)));
        fprintf(f, "\n");
        PrintAllBalasan(f, RIGHT(p));
        PrintAllBalasan(f, LEFT(p));
    }
}

void SimpanBalasan(char *Path, ListDinT KicauGlobal)
{
    char path[300];
    char *folder = Path;
    char *balas = "/balasan.config";
    long long int i = 0;

    while (*folder)
    {
        path[i] = *folder;
        folder++;
    }
    while (*balas)
    {
        *folder = *balas;
        balas++;
        folder++;
    }
    *folder = '\0';

    FILE *f = fopen(Path, "w");
    long long int n = NEFFT(KicauGlobal);
    long long int balasan[10000], balasaneff = 0;
    for (i = 0; i < n; i++)
    {
        if (BALASAN(ELMTT(KicauGlobal, i)) != NULL)
        {
            balasan[balasaneff] = i;
            balasaneff++;
        }
    }
    fprintf(f, "%lld\n", balasaneff);
    for (i = 0; i < balasaneff; i++)
    {
        BinTree t = BALASAN(ELMTT(KicauGlobal, balasan[i]));
        fprintf(f, "%lld\n%d\n", balasan[i] + 1, BanyakNode(t));
        PrintAllBalasan(f, t);
    }
    fclose(f);
}

void SimpanDraf(char *Path, ListStatik ListProfil)
{
    char path[300];
    char *folder = Path;
    char *draf = "/draf.config";
    long long int i = 0;

    while (*folder)
    {
        path[i] = *folder;
        folder++;
    }
    while (*draf)
    {
        *folder = *draf;
        draf++;
        folder++;
    }
    *folder = '\0';

    FILE *f = fopen(Path, "w");
    int drafeff = 0, listdraf[20];
    for (i = 0; i < NEFFLS(ListProfil); i++)
    {
        if (!isEmptyS(DRAF(ELMTLS(ListProfil, i))))
        {
            listdraf[drafeff] = i;
            drafeff++;
        }
    }
    fprintf(f, "%d\n", drafeff);
    for (i = 0; i < drafeff; i++)
    {
        Profil p = ELMTLS(ListProfil, listdraf[i]);
        entrytofile(f, Nama(p));
        fprintf(f, " %d\n", lengthS(DRAF(p)));
        while (!isEmptyS(DRAF(p)))
        {
            entrytofile(f, TEXTS(TOP(DRAF(p))));
            fprintf(f, "\n");
            datetimetofile(f, WAKTUS(TOP(DRAF(p))));
            fprintf(f, "\n");
            ADDR_TOP(DRAF(p)) = NEXTS(ADDR_TOP(DRAF(p)));
        }
    }
    fclose(f);
}

void SimpanUtas(char *Path, ListDinT KicauGlobal, ListDin UtasGlobal)
{
    char path[300];
    char *folder = Path;
    char *utas = "/utas.config";
    long long int i = 0;

    while (*folder)
    {
        path[i] = *folder;
        folder++;
    }
    while (*utas)
    {
        *folder = *utas;
        utas++;
        folder++;
    }
    *folder = '\0';

    FILE *f = fopen(Path, "w");
    fprintf(f, "%d\n", NEFFLDI(UtasGlobal));
    for (i = 0; i < NEFFLDI(UtasGlobal); i++)
    {
        fprintf(f, "%d\n%d\n", ELMTLDI(UtasGlobal, i) + 1, getLastIdxUtas(UTASAN(ELMTT(KicauGlobal, ELMTLDI(UtasGlobal, i)))));
        Address p;
        p = FIRSTUTAS(UTASAN(ELMTT(KicauGlobal, ELMTLDI(UtasGlobal, i))));
        while (p != NULL)
        {
            entrytofile(f, TEXTUTAS(INFOUTAS(p)));
            fprintf(f, "\n");
            entrytofile(f, AUTHOR(ELMTT(KicauGlobal, ELMTLDI(UtasGlobal, i))));
            fprintf(f, "\n");
            datetimetofile(f, TIME(INFOUTAS(p)));
            fprintf(f, "\n");
            p = NEXT(p);
        }
    }
    fclose(f);
}

void SimpanBatch(Graf Pertemanan, ListStatik ListProfil, ListDinT KicauGlobal, ListDin UtasGlobal)
{
    printf("Masukkan nama folder penyimpanan:\n");
    STARTENTRY();
    currentEntry = cleansedEntry(currentEntry);

    char path[265] = "Config/";
    char *folder = path;

    while (*folder)
    {
        folder++;
    }
    for (int i = 0; i < currentEntry.Length; i++)
    {
        *folder = currentEntry.TabEntry[i];
        folder++;
    }
    *folder = '\0';

    struct stat info;
    if (stat(path, &info) != 0)
    {
    }
    if (S_ISDIR(info.st_mode))
    {
        printf("Anda akan melakukan penyimpanan di ");
        printEntry(currentEntry);
        printf(".\n\n");
        printf("Mohon tunggu...\n");

        SimpanPengguna(path, Pertemanan, ListProfil);
        *folder = '\0';
        printf("1...\n");
        SimpanKicauan(path, KicauGlobal);
        *folder = '\0';
        SimpanBalasan(path, KicauGlobal);
        *folder = '\0';
        printf("2...\n");
        SimpanDraf(path, ListProfil);
        *folder = '\0';
        SimpanUtas(path, KicauGlobal, UtasGlobal);
        *folder = '\0';
        printf("3...\n\n");

        printf("Penyimpanan telah berhasil dilakukan!\n");
    }
    else
    {
        printf("Belum terdapat folder ");
        printEntry(currentEntry);
        printf(". Akan dilakukan pembuatan folder ");
        printEntry(currentEntry);
        printf(" terlebih dahulu.\n\n");

        printf("Mohon tunggu...\n1...\n2...\n3...\n\n");
        int status = mkdir(path, 0777);

        if (status == 0)
        {
            printEntry(currentEntry);
            printf(" sudah berhasil dibuat.\n\n");
            printf("Anda akan melakukan penyimpanan di ");
            printEntry(currentEntry);
            printf(".\n\n");
            printf("Mohon tunggu...\n");

            SimpanPengguna(path, Pertemanan, ListProfil);
            *folder = '\0';
            printf("1...\n");
            SimpanKicauan(path, KicauGlobal);
            *folder = '\0';
            SimpanBalasan(path, KicauGlobal);
            *folder = '\0';
            printf("2...\n");
            SimpanDraf(path, ListProfil);
            *folder = '\0';
            SimpanUtas(path, KicauGlobal, UtasGlobal);
            *folder = '\0';
            printf("3...\n\n");

            printf("Penyimpanan telah berhasil dilakukan!\n");
        }
        else
        {
            perror("Error creating directory\n");
        }
    }
}

void MuatPengguna(char* Path, Graf *Pertemanan, ListStatik *ListProfil){
    char path[365];
    long long int i = 0;
    currentEntry = StringToEntry("/pengguna.config",16);

    while (*Path != '\r')
    {
        path[i] = *Path;
        Path++;
        i++;
    }
    char *folder = path;
    while(*folder){
        folder++;
    }
    for (i = 0; i < currentEntry.Length; i++)
    {
        *folder = currentEntry.TabEntry[i];
        folder++;
    }
    *folder = '\0';
    STARTFILEWORD(path);
    NEFFLS(*ListProfil) = EntryToInt(currentEntry);
    ADVLINE();
    for(int i=0;i<NEFFLS(*ListProfil);i++){
        Profil p;
        Nama(p) = currentEntry; ADVLINE();
        Password(p) = currentEntry; ADVLINE();
        Bio(p) = currentEntry; ADVLINE();
        Nomor(p) = currentEntry; ADVLINE();
        Weton(p) = currentEntry; ADVLINE();
        CreateQueue(&PermintaanPertemanan(p));
        CreateStack(&DRAF(p));
        if(isSame(currentEntry,StringToEntry("Publik",6))){
            Jenis(p) = 0;
        } else {
            Jenis(p) = 1;
        }
        ADVLINE();
        for(int j=0;j<5;j++){
            for(int k=0;k<10;k++){
                ELMT(Foto(p),j,k) = currentEntry.TabEntry[2*k];
            }
            ADVLINE();
        }
        ELMTLS(*ListProfil,i) = p;
    }

    int x;
    for(int i=0;i<NEFFLS(*ListProfil);i++){
        x = 0;
        for(int j=0;j<NEFFLS(*ListProfil);j++){
            Busur(*Pertemanan,i,j) = currentEntry.TabEntry[2*j] - '0';
            if(Busur(*Pertemanan,i,j) == 1){
                x++;
            }
        }
        JumlahTeman(ELMTLS(*ListProfil,i)) = x-1;
        ADVLINE();
    }

    int n = EntryToInt(currentEntry),meminta,diminta,banyakteman;
    ADVLINE();
    for(int i=0;i<n;i++){
        meminta = firstNum(currentEntry);
        diminta = firstNumParam(currentEntry);
        banyakteman = secondNumParam(currentEntry);
        Elmtqueue eq;
        Info(eq) = Nama(ELMTLS(*ListProfil,meminta));
        Prio(eq) = banyakteman;
        Enqueue(&PermintaanPertemanan(ELMTLS(*ListProfil,diminta)),eq);
        ADVLINE();
    }
}

void MuatKicauan(char* Path, ListDinT *KicauGlobal){
    char path[365];
    long long int i = 0;
    currentEntry = StringToEntry("/kicau.config",13);

    while (*Path != '\r')
    {
        path[i] = *Path;
        Path++;
        i++;
    }
    char *folder = path;
    while(*folder){
        folder++;
    }
    for (i = 0; i < currentEntry.Length; i++)
    {
        *folder = currentEntry.TabEntry[i];
        folder++;
    }
    *folder = '\0';
    STARTFILEWORD(path);
    NEFFT(*KicauGlobal) = EntryToInt(currentEntry); ADVLINE();
    long long int n = NEFFT(*KicauGlobal);
    expandListDinT(KicauGlobal,n);
    for(i=0;i<n;i++){
        Kicau k;
        ID(k) = EntryToInt(currentEntry); ADVLINE();
        TEXT(k) = currentEntry; ADVLINE();
        TAGAR(k) = currentEntry; ADVLINE();
        LIKE(k) = EntryToInt(currentEntry); ADVLINE();
        AUTHOR(k) = currentEntry; ADVLINE();
        WAKTU(k) = entryToDateTime(currentEntry); ADVLINE();
        UTASAN(k) = NULL;
        BALASAN(k) = NULL;
        IDBALASAN(k) = 0;
        ISUTAS(k) = false;
        ELMTT(*KicauGlobal,i) = k;
    }
}

void MuatBalasan(char* Path, ListDinT *KicauGlobal){
    char path[365];
    long long int i = 0;
    currentEntry = StringToEntry("/balasan.config",15);

    while (*Path != '\r')
    {
        path[i] = *Path;
        Path++;
        i++;
    }
    char *folder = path;
    while(*folder){
        folder++;
    }
    for (i = 0; i < currentEntry.Length; i++)
    {
        *folder = currentEntry.TabEntry[i];
        folder++;
    }
    *folder = '\0';
    // printf("%s",path);
    STARTFILEWORD(path);
    long long int n = EntryToInt(currentEntry),IDKicauan,t,IDParent,IDBalas;
    // printf("banyak kicauan yang memiliki balasan :"); printEntry(currentEntry); printf("\n");
    ADVLINE();
    while(n--){
        // printf("ID kicauan :"); printEntry(currentEntry); printf("\n");
        IDKicauan = EntryToInt(currentEntry); ADVLINE();
        // printf("Memiliki "); printEntry(currentEntry); printf(" Balasan\n");
        t = EntryToInt(currentEntry); ADVLINE();
        Kicau k = ELMTT(*KicauGlobal,IDKicauan);
        IDBALASAN(k) = t;
        while(t--){
            BinTree bt = BALASAN(k),bs;
            if(currentEntry.TabEntry[0] == '-'){
                IDParent = -1;
            } else {
                IDParent = firstNum(currentEntry);
            }
            IDBalas = firstNumParam(currentEntry);
            // printf("Balasan dengan ID ke %d memiliki parent balasan ID ke %d\n", IDBalas, IDParent);
            ADVLINE();
            BalasanB b;
            TEXTB(b) = currentEntry; ADVLINE();
            AUTHORB(b) = currentEntry; ADVLINE();
            WAKTUB(b) = entryToDateTime(currentEntry); ADVLINE();
            IDB(b) = IDBalas;
            // printf("| ID = %lld\n", IDB(b));
            // printf("| "); printEntry(AUTHORB(b)); printf("\n");
            // printf("| "); TulisDATETIME(WAKTUB(b)); printf("\n");
            // printf("| "); printEntry(TEXTB(b)); printf("\n\n");

            if(isTreeEmpty(bt)){
                bt = newTreeNode(b);
                BALASAN(ELMTT(*KicauGlobal,IDKicauan)) = bt;
            } else if(IDParent == -1){
                addRight(&bt,b);
                BALASAN(ELMTT(*KicauGlobal,IDKicauan)) = bt;
            } else {
                bs = bt;
                bs = searchTree(bs,IDParent);
                addChild(&bs,b);
                BALASAN(ELMTT(*KicauGlobal,IDKicauan)) = bt;
            }
        }
    }
}

void MuatDraf(char* Path, ListStatik *ListProfil){
    char path[365];
    long long int i = 0;
    currentEntry = StringToEntry("/draf.config",12);

    while (*Path != '\r')
    {
        path[i] = *Path;
        Path++;
        i++;
    }
    char *folder = path;
    while(*folder){
        folder++;
    }
    for (i = 0; i < currentEntry.Length; i++)
    {
        *folder = currentEntry.TabEntry[i];
        folder++;
    }
    *folder = '\0';
    printf("%s",path);
    STARTFILEWORD(path);
    long long int n = EntryToInt(currentEntry);
    ADVLINE();
    while(n--){

    }
}

void MuatUtas(char* path, ListDinT *KicauGlobal, ListDin *UtasGlobal){

}

void MuatBatch(Graf *Pertemanan, ListStatik *ListProfil, ListDinT *KicauGlobal, ListDin *UtasGlobal)
{
    printf("Masukkan nama folder yang hendak dimuat:\n");
    STARTENTRY();
    currentEntry = cleansedEntry(currentEntry);

    char path[265] = "Config/";
    for (int i = 0; i < currentEntry.Length; i++)
    {
        path[i+7] = currentEntry.TabEntry[i];
    }

    struct stat info;
    if (stat(path, &info) != 0)
    {
        printf("Tidak ada folder yang dimaksud!\n");
    }
    else
    {
        printf("Anda akan melakukan pemuatan dari folder ");
        printEntry(currentEntry);
        printf(".\n");
        MuatPengguna(path,Pertemanan,ListProfil);
        MuatKicauan(path,KicauGlobal);
        MuatBalasan(path,KicauGlobal);
        MuatDraf(path,ListProfil);
    }
}
