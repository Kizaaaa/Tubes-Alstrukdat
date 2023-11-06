#include <stdio.h>
#include "main.h"



int main(){
    boolean exit = false;
    boolean isMasuk = false;
    long long int IDKicau = 1;
    ListStatik ListProfil;
    int CurrentUser;
    CreateListStatik(&ListProfil);

    while(!exit){
        //INISIALISASI();
        printf(">> ");
        STARTENTRY();
        Entry input = cleansedEntry(currentEntry);

        if(!isMasuk){
            if(isSame(input,StringToEntry("MASUK",5))){
                Masuk(&ListProfil, &CurrentUser, &isMasuk);
            } else if(isSame(input,StringToEntry("DAFTAR",6))){
                Daftar(&ListProfil);
            } else if(isSame(input,StringToEntry("MUAT",4))){
            
            } else if(isSame(input,StringToEntry("TUTUP_PROGRAM",13))){
                exit = true;
            } else if(isSame(input,StringToEntry("KELUAR",6))){
                printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            } else { //Input tidak valid

            }
        } else { //Sudah masuk
            if(isSame(input,StringToEntry("DAFTAR",6))){
                printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
            } else if(isSame(input,StringToEntry("MASUK",5))){
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
            } else if(isSame(input,StringToEntry("GANTI_PROFIL",12))){
                GantiProfil(&ELMTLS(ListProfil,CurrentUser));
            } else if(isSame(input,StringToEntry("UBAH_FOTO_PROFIL",16))){
                GantiFoto(&ELMTLS(ListProfil,CurrentUser));
            } else if(isSame(input,StringToEntry("ATUR_JENIS_AKUN",15))){
                GantiJenis(&ELMTLS(ListProfil,CurrentUser));
            } else if(isSame(input,StringToEntry("DAFTAR_TEMAN",12))){

            } else if(isSame(input,StringToEntry("KICAU",5))){
                // CreateKicau(kicau, IDKicau, CurrentUser);
            } else if(isSame(input,StringToEntry("UTAS",4))){
                
            } else if(isSame(input,StringToEntry("DAFTAR",6))){

            } else if(isSame(input,StringToEntry("DAFTAR",6))){

            } else if(isSame(input,StringToEntry("KELUAR",6))){
                printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
                isMasuk = false;
            }
            else if(isSame(input,StringToEntry("TUTUP_PROGRAM",13))){
                exit = true;
            } 
        }


        
    }
    
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    return 0;
}