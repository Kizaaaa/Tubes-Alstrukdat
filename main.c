#include <stdio.h>
#include "main.h"

int main()
{
    boolean exit = false;
    boolean isMasuk = false;
    long long int IDUtas = 1;
    int CurrentUser;

    // ADT
    ListStatik ListProfil;
    Graf Pertemanan;
    ListDinT ListTweets;
    ListDin ListUtas;

    CreateListStatik(&ListProfil);
    CreateGraf(&Pertemanan);
    CreateListDinT(&ListTweets,10);
    CreateListDin(&ListUtas,10);

    while (!exit)
    {
        // INISIALISASI();
        printf("\n>> ");
        STARTENTRY();
        Entry input = cleansedEntry(currentEntry);
        printf("\n");

        if (!isMasuk)
        {
            if (isSame(input, StringToEntry("MASUK", 5)))
            {
                Masuk(&ListProfil, &CurrentUser, &isMasuk);
            }
            else if (isSame(input, StringToEntry("DAFTAR", 6)))
            {
                Daftar(&ListProfil);
            }
            else if (isSame(input, StringToEntry("SIMPAN", 6)))
            {
                
            }
            else if (isSame(input, StringToEntry("MUAT", 4)))
            {

            }
            else if (isSame(input, StringToEntry("TUTUP_PROGRAM", 13)))
            {
                exit = true;
            }
            else if (isSame(input, StringToEntry("KELUAR", 6)))
            {
                printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            { // Input tidak valid
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir. Perintah yang tersedia:\n1. MASUK\n2. DAFTAR\n3. SIMPAN\n4. MUAT\n5. TUTUP_PROGRAM\n");
            }
        }
        else
        { // Sudah masuk
            if (isSame(input, StringToEntry("DAFTAR", 6)))
            {
                printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
            }
            else if (isSame(input, StringToEntry("MASUK", 5)))
            {
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
            }
            else if (isSame(input, StringToEntry("GANTI_PROFIL", 12)))
            {
                GantiProfil(&ELMTLS(ListProfil, CurrentUser));
            }
            else if (isSame(input, StringToEntry("UBAH_FOTO_PROFIL", 16)))
            {
                GantiFoto(&ELMTLS(ListProfil, CurrentUser));
            }
            else if (isSame(input, StringToEntry("ATUR_JENIS_AKUN", 15)))
            {
                GantiJenis(&ELMTLS(ListProfil, CurrentUser));
            }
            else if (isSame(cutBeforeEntry(input, 12), StringToEntry("LIHAT_PROFIL", 12)))
            {
                LihatProfil(Pertemanan, ListProfil, CurrentUser, cutAfterEntry(input, 12));
            }
            else if (isSame(input, StringToEntry("DAFTAR_TEMAN", 12)))
            {
                DaftarTeman(Pertemanan, ListProfil, CurrentUser);
            }
            else if (isSame(input, StringToEntry("HAPUS_TEMAN", 11)))
            {
                HapusTeman(&Pertemanan, &ListProfil, CurrentUser);
            }
            else if (isSame(input, StringToEntry("TAMBAH_TEMAN", 12)))
            {
                TambahTeman(&Pertemanan, &ListProfil, CurrentUser);
            }
            else if (isSame(input, StringToEntry("DAFTAR_PERMINTAAN_PERTEMANAN", 28)))
            {
                TerimaTeman(&Pertemanan, ListProfil, CurrentUser);
            }
            else if (isSame(input, StringToEntry("SETUJUI_PERTEMANAN", 18)))
            {
                SetujuiTeman(&Pertemanan, &ListProfil, CurrentUser);
            }
            else if(isSame(input,StringToEntry("KICAU", 5)))
            {
                CreateKicau(&ListTweets,Nama(ELMTLS(ListProfil,CurrentUser)));
            }
            else if(isSame(input,StringToEntry("KICAUAN", 7)))
            {
                Kicauan(Pertemanan,ListTweets,ListProfil,CurrentUser);
            }
            else if(isSame(cutBeforeEntry(input,12),StringToEntry("SUKA_KICAUAN", 12)))
            {
                SukaKicau(Pertemanan,&ListTweets,ListProfil,CurrentUser,firstNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,12),StringToEntry("UBAH_KICAUAN", 12)))
            {
                UbahKicau(&ListTweets,ListProfil,CurrentUser,firstNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,7),StringToEntry("BALASAN", 7)))
            {
                Balasan(Pertemanan,&ListTweets,ListProfil,CurrentUser,firstNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,5),StringToEntry("BALAS", 5)))
            {
                Balas(Pertemanan,&ListTweets,ListProfil,CurrentUser,firstNumParam(input),secondNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,13),StringToEntry("HAPUS_BALASAN", 13)))
            {
                HapusBalasan(Pertemanan,&ListTweets,ListProfil,CurrentUser,firstNumParam(input),secondNumParam(input));
            }
            else if (isSame(input, StringToEntry("BUAT_DRAF", 9)))
            {
                BuatDraf(&ListTweets,&DRAF(ELMTLS(ListProfil,CurrentUser)),Nama(ELMTLS(ListProfil,CurrentUser)));
            }
            else if (isSame(input, StringToEntry("LIHAT_DRAF", 10)))
            {
                LihatDraf(&ListTweets,&DRAF(ELMTLS(ListProfil,CurrentUser)),Nama(ELMTLS(ListProfil,CurrentUser)));
            }
            else if(isSame(cutBeforeEntry(input,4),StringToEntry("UTAS", 4)))
            {
                Utas(&ListTweets,&ListUtas,Nama(ELMTLS(ListProfil,CurrentUser)),&IDUtas,firstNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,12),StringToEntry("SAMBUNG_UTAS",12)))
            {
                SambungUtas(&ListTweets,ListUtas,Nama(ELMTLS(ListProfil,CurrentUser)),firstNumParam(input),secondNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,10),StringToEntry("HAPUS_UTAS",10)))
            {
                HapusUtas(&ListTweets,ListUtas,Nama(ELMTLS(ListProfil,CurrentUser)),firstNumParam(input),secondNumParam(input));
            }
            else if(isSame(cutBeforeEntry(input,10),StringToEntry("CETAK_UTAS",10)))
            {
                CetakUtas(Pertemanan,&ListTweets,ListProfil,ListUtas,CurrentUser,firstNumParam(input));
            }
            else if (isSame(input, StringToEntry("KELUAR", 6)))
            {
                printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
                isMasuk = false;
            }
            else if (isSame(input, StringToEntry("TUTUP_PROGRAM", 13)))
            {
                exit = true;
            }
        }
    }

    dealocateListDinT(&ListTweets);
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    return 0;
}