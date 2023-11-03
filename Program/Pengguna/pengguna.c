/*Program pengguna*/
#include "pengguna.h"

void daftar(ListUser *l){
/*  I.S. Prekondisi : Belum login dan ListUser terdefinisi*/
/*  F.S. Akun baru ditambahkan */
    User u;
    Entry username, password;
    printf("Masukkan nama:\n");
    STARTENTRY();
    username = cleansedEntry(currentEntry);
    CLOSEENTRY();
    while (isUsernameTaken(*l,username) || !CHECKVALIDUNP(username))
    {
        if (isUsernameTaken(*l,username))
        {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
        }
        else
        {
            printf("Wah, sayang sekali namamu lebih dari 20 karakter\n");
        }
        printf("Masukkan nama:\n");
        STARTENTRY();
        username = cleansedEntry(currentEntry);
        CLOSEENTRY();
    }

    printf("Masukkan kata sandi:\n");
    STARTENTRY();
    password = cleansedEntry(currentEntry);
    CLOSEENTRY();
    while (!CHECKVALIDUNP(password))
    {
        printf("Passwordmu terlalu panjang\n");
        STARTENTRY();
        password = cleansedEntry(currentEntry);
        CLOSEENTRY();
    }
    
    CreateUser(&u,username,password);
    addUser(l,u);
    printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");   
}

void masuk(ListUser *l){
/*  I.S. Prekondisi : Belum login dan sudah mendaftar*/
/*  F.S. Akun baru ditambahkan */ 
    Entry username, password;
    printf("Masukkan nama:\n");
    STARTENTRY();
    username = cleansedEntry(currentEntry);
    CLOSEENTRY();
    while (indexOfUsername(*l, username) == IDX_UNDEF)
    {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("Masukkan nama:\n");
        STARTENTRY();
        username = cleansedEntry(currentEntry);
        CLOSEENTRY();
    }
    
    printf("Masukkan kata sandi:\n");
    STARTENTRY();
    password = cleansedEntry(currentEntry);
    CLOSEENTRY();
    while (!isPasswordValid(*l,username,password))
    {
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        printf("Masukkan kata sandi:\n");
        STARTENTRY();
        password = cleansedEntry(currentEntry);
        CLOSEENTRY();
    }
    
    printf("Anda telah berhasil masuk dengan nama pengguna ");
    printEntry(username);
    printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
}

void keluar(){
/*  I.S. sudah login*/
/*  F.S. berhasil keluar akun*/
    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!");
}
