#include <stdio.h>
#include "main.h"

#define MASUK 

Entry CurrentUser;
boolean isMasuk = false;

int main(){
    boolean exit = false;

    while(!exit){
        STARTENTRY();
        Entry input = cleansedEntry(currentEntry);
        if(isSame(input,StringToEntry("MASUK",5))){
            printf("anjay\n");
        } else if(isSame(input,StringToEntry("TUTUP_PROGRAM",13))){
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
            exit = true;
        }
    }
    
    return 0;
}