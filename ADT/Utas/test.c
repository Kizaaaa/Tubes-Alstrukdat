#include <stdio.h>
#include "../Kicau/kicau.h"

#define MASUK 

Entry CurrentUser;
boolean isMasuk = false;

int main(){

    // LINKEDUTAS L1;
    // // Kicau twt;
    // //buat linked utas kosong
    // createLinkedUtas(&L1);
    // readUtas(&L1);

    // while(!exit){
    //     //INISIALISASI();

    //     STARTENTRY();
    //     Entry input = cleansedEntry(currentEntry);

    //     if(!isMasuk){
    //         if(isSame(input,StringToEntry("MASUK",5))){
    //             //MASUK()
    //             isMasuk = true;
    //         } else if(isSame(input,StringToEntry("DAFTAR",6))){
            
    //         } else if(isSame(input,StringToEntry("MUAT",4))){
            
    //         } else if(isSame(input,StringToEntry("TUTUP_PROGRAM",13))){
    //             exit = true;
    //         } else if(isSame(input,StringToEntry("KELUAR",6))){
    //             printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    //         } else { //Input tidak valid

    //         }
    //     } else {
    //         if(isSame(input,StringToEntry("DAFTAR",6))){
    //             printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    //         } else if(isSame(input,StringToEntry("MASUK",5))){
    //             printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
    //         } else if(isSame(input,StringToEntry("GANTI_PROFIL",12))){

    //         } else if(isSame(input,StringToEntry("LIHAT_PROFIL",6))){

    //         } else if(isSame(input,StringToEntry("ATUR_JENIS_AKUN",6))){

    //         } else if(isSame(input,StringToEntry("UBAH_FOTO_PROFIL",16))){

    //         } else if(isSame(input,StringToEntry("DAFTAR_TEMAN",12))){

    //         } else if(isSame(input,StringToEntry("DAFTAR",6))){

    //         }
    //         else if(isSame(input,StringToEntry("TUTUP_PROGRAM",13))){
    //             exit = true;
    //         } 
    //     }


        
    
    
    // printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
    return 0;
}
// gcc -o test test.c utas.c ADT/DateTime/datetime.c ADT/EntryMachine/entrymachine.c ADT/ListDin/listdin.c ADT/ListStatic/liststatik.c ADT/Matrix/matrix.c ADT/Queue/queue.c ADT/Stack/stack.c ADT/Kicau/kicau.c