#include "ListUser.h"

/* ********** KONSTRUKTOR ********** */
void CreateUser(User *u, Entry nama, Entry sandi){
   (*u).username = nama;
   (*u).password = sandi;
}
/* Konstruktor : create List kosong  */
void CreateListUser(ListUser *l){
    NEFF(*l) = 0;
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listUserLength(ListUser l){
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListUser(ListUser l){
    return NEFF(l) == 0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListUser(ListUser l){
    return NEFF(l) == CAPACITY;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListUser(ListUser *l);
/* I.S. l sembarang */
/* F.S. List l terdefinisi */

void printListUser(ListUser l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfUsername(ListUser l, Entry nama){
    if (isEmptyListUser(l))
    {
       return IDX_UNDEF; 
    } 
    else
    {
        int idx = 0;
        while (idx < listUserLength(l) && !isSame(l.contents[idx].username, nama))
        {
            idx++;
        }

        if (isSame(l.contents[idx].username, nama))
        {
            return idx;
        } else {
            return IDX_UNDEF;
        }    
    }   
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

boolean isUsernameTaken(ListUser l, Entry val){
    if (isEmptyListUser(l))
    {
        return false;
    } else {
        boolean found = false;
        int ctr = 0;

        while (ctr < listUserLength(l) && !found)
        {
            if (isSame(((l).contents[(ctr)]).username , val))
            {
                found = true;
            }   
            ctr++; 
        }
        return found;
    }
    
}

boolean isPasswordValid(ListUser l, Entry nama, Entry sandi){
    int index;
    index = indexOfUsername(l,nama);
    return (isSame(((l).contents[(index)]).password , sandi));
}

/* ********** MENAMBAH ELEMEN ********** */

/* *** Menambahkan elemen terakhir *** */
void addUser(ListUser *l, User val){
    if (isEmptyListUser(*l))
    {
        ELMT(*l, IDX_MIN) = val;
        NEFF(*l) = 1;
    }
    else
    {
        if (!isFullListUser(*l))
        {
            ELMT(*l, listUserLength(*l)) = val;
        }
        NEFF(*l)++;
    }
    
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void removeUser(ListUser *l, ElType *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */