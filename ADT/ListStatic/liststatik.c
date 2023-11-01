/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
{
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int liststatikLength(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    return NEFF(l);
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdxListStatikStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdxListStatikStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return listStatikLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListStatik(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (IDX_MIN <= i && i < CAPACITY);
}

boolean isIdxEffListStatik(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return (getFirstIdxListStatik(l) <= i && i <= getLastIdxListStatik(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListStatik(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return listStatikLength(l) == 0;
}

/* *** Test List penuh *** */
boolean isFullListStatikListStatik(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return listStatikLength(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    IdxType n;
    scanf("%d", &n);
    while (!(0 <= n && n <= CAPACITY))
    {
        scanf("%d", &n);
    }
    CreateListStatik(l);
    NEFF(*l) = n;
    for (int i = IDX_MIN; i < n; i++)
    {
        scanf("%d", &ELMT(*l, i));
    }
}
void printListStatik(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int i;
    if (!isEmptyListStatik(l))
    {
        printf("[");
        for (i = getFirstIdxListStatik(l); i <= getLastIdxListStatik(l); i++)
        {
            printf("%d", ELMT(l, i));
            if (i != getLastIdxListStatik(l))
            {
                printf(",");
            }
        }
        printf("]");
    }
    else
    {
        printf("[]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusListStatik(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */
{
    int i;
    ListStatik l3;
    CreateListStatik(&l3);
    NEFF(l3) = listStatikLength(l1);
    for (i = getFirstIdxListStatik(l1); i <= getLastIdxListStatik(l1); i++)
    {
        if (plus)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }

        else
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */
{
    if (listStatikLength(l1) == listStatikLength(l2))
    {
        int i;
        boolean equal = true;
        i = getFirstIdxListStatik(l1);
        while (i <= getLastIdxListStatik(l1) && equal)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                equal = false;
            }
            i++;
        }
        
        return equal;
    }
    else
    {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOfListStatik(ListStatik l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    if (isEmptyListStatik(l))
    {
        return IDX_UNDEF;
    }

    else
    {
        int i;
        boolean found = false;
        i = getFirstIdxListStatik(l);
        while (i <= getLastIdxListStatik(l) && !found)
        {
            if (ELMT(l, i) == val)
            {
                found = true;
            }
            else 
            {
                i++;
            }
        }
        if (found)
        {
            return i;
        }
        else
        {
            return IDX_UNDEF;
        }
        
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesListStatik(ListStatik l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    int i, tempmax, tempmin;
    tempmax = ELMT(l, getFirstIdxListStatik(l));
    tempmin = ELMT(l, getFirstIdxListStatik(l));

    for (i = getFirstIdxListStatik(l) + 1; i <= getLastIdxListStatik(l); i++)
    {
        if (ELMT(l, i) > tempmax)
        {
            tempmax = ELMT(l, i);
        }

        if (ELMT(l, i) < tempmin)
        {
            tempmin = ELMT(l, i);
        }
    }
    *max = tempmax;
    *min = tempmin;
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstListStatik(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
{
    if (isEmptyListStatik(*l))
    {
        ELMT(*l, IDX_MIN) = val;
    }
    else
    {
        if (!isFullListStatik(*l))
        {
            for (int i = getLastIdxListStatik(*l); i >= getFirstIdxListStatik(*l); i--)
            {
                ELMT(*l, i + 1) = ELMT(*l, i);
            }
            ELMT(*l, getFirstIdxListStatik(*l)) = val;
        }
    }
    NEFF(*l)++;
}
void insertListStatikAt(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
{
    if (isEmptyListStatik(*l))
    {
        ELMT(*l, IDX_MIN) = val;
    }
    else
    {
        if (!isFullListStatik(*l))
        {
            for (int i = getLastIdxListStatik(*l); i >= idx; i--)
            {
                ELMT(*l, i + 1) = ELMT(*l, i);
            }
            ELMT(*l, idx) = val;
        }
    }
    NEFF(*l)++;
}
void insertLastListStatik(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    if (isEmptyListStatik(*l))
    {
        ELMT(*l, IDX_MIN) = val;
    }
    else
    {
        if (!isFullListStatik(*l))
        {
            ELMT(*l, getLastIdxListStatik(*l) + 1) = val;
        }
    }
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstListStatik(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, getFirstIdxListStatik(*l));
    for (int i = getFirstIdxListStatik(*l); i < getLastIdxListStatik(*l); i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteListStatikAt(ListStatik *l, ElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, idx);
    for (int i = idx; i < getLastIdxListStatik(*l); i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    NEFF(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLastStatik(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, getLastIdxListStatik(*l));
    NEFF(*l)--;
}

/* ********** SORTING ********** */
void sortListStatik(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int pass, i, temp, imax, imin;
    if (asc)
    {
        for (pass = getFirstIdxListStatik(*l); pass <= getLastIdxListStatik(*l) - 1; pass++)
        {
            imin = pass;
            for (i = pass + 1; i <= getLastIdxListStatik(*l); i++)
            {
                if (ELMT(*l, imin) > ELMT(*l, i))
                {
                    imin = i;
                }
            }
            temp = ELMT(*l, imin);
            ELMT(*l, imin) = ELMT(*l, pass);
            ELMT(*l, pass) = temp;
        }
    }
    else
    {
        for (pass = getFirstIdxListStatik(*l); pass <= getLastIdxListStatik(*l) - 1; pass++)
        {
            imax = pass;
            for (i = pass + 1; i <= getLastIdxListStatik(*l); i++)
            {
                if (ELMT(*l, imax) < ELMT(*l, i))
                {
                    imax = i;
                }
            }
            temp = ELMT(*l, imax);
            ELMT(*l, imax) = ELMT(*l, pass);
            ELMT(*l, pass) = temp;
        }
    }
}