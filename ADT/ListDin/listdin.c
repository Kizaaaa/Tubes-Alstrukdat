/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdin.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
/*typedef int int; /* type elemen list */
// typedef int int;
// typedef struct
// {
//     int *bufferLDI; /* memori tempat penyimpan elemen (container) */
//     int nEffLDI;       /* >=0, banyaknya elemen efektif */
//     int capacityLDI;   /* ukuran elemen */
// } ListDin;
/* Indeks yang digunakan [0..capacityLDI-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEffLDI      untuk mengetahui banyaknya elemen
   l.bufferLDI    untuk mengakses seluruh nilai elemen list
   l.bufferLDI[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEffLDI = 0
  Definisi elemen pertama : l.bufferLDI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.bufferLDI[i] dengan i=l.capacityLDI */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacityLDI)
{
   BUFFERLDI(*l) = (int *)malloc(capacityLDI * sizeof(int));
   CAPACITYLDI(*l) = capacityLDI;
   NEFFLDI(*l) = 0;
}
/* I.S. l sembarang, capacityLDI > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacityLDI */

void dealocateListDin(ListDin *l)
{
   free(BUFFERLDI(*l));
   CAPACITYLDI(*l) = 0;
   NEFFLDI(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYLDI(l)=0; NEFFLDI(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listdinLength(ListDin l)
{
   return NEFFLDI(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
int getFirstIdxListDin(ListDin l)
{
   return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getLastIdxListDin(ListDin l)
{
   return (int)NEFFLDI(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDin(ListDin l, int i)
{
   if (i < CAPACITYLDI(l) && i >= 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffListDin(ListDin l, int i)
{
   if (i >= 0 && i <= NEFFLDI(l) - 1)
   {
      return true;
   }
   else
   {
      return false;
   }
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFFLDI(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDin(ListDin l)
{
   if (NEFFLDI(l) == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListDin(ListDin l)
{
   if (NEFFLDI(l) == CAPACITYLDI(l))
   {
      return true;
   }
   else
   {
      return false;
   }
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
{
   int N;
   while (true)
   {
      // printf("Masukkan Nilai N: ");
      scanf("%d", &N);
      if ((N >= 0) && (N <= CAPACITYLDI(*l)))
      {
         // CreateListDin(l,N);
         NEFFLDI(*l) = N;
         break;
      }
   }
   int i;
   for (i = 0; i < N; i++)
   {
      // printf("----Nilai ElmtLDI ke-%d: ",i);
      scanf("%d", &ELMTLDI(*l, i));
   }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYLDI(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITYLDI(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDin(ListDin l)
{
   if (NEFFLDI(l) == 0)
   {
      printf("[]");
   }
   else
   {
      int i;
      printf("[");
      for (i = getFirstIdxListDin(l); i < NEFFLDI(l) - 1; i++)
      {
         printf("%d,", ELMTLDI(l, i));
      }
      printf("%d", ELMTLDI(l, NEFFLDI(l) - 1));
      printf("]");
   }
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
   int i;
   ListDin ln;
   CreateListDin(&ln, CAPACITYLDI(l1));
   NEFFLDI(ln) = NEFFLDI(l1);
   if (plus)
   { // dijumlahkan
      for (i = getFirstIdxListDin(l1); i < NEFFLDI(l1); i++)
      {
         ELMTLDI(ln, i) = ELMTLDI(l1, i) + ELMTLDI(l2, i);
      }
   }
   else
   { // dikurangkan
      for (i = getFirstIdxListDin(l1); i < NEFFLDI(l1); i++)
      {
         ELMTLDI(ln, i) = ELMTLDI(l1, i) - ELMTLDI(l2, i);
      }
   }
   // printList(ln);
   return ln;
}
/* Prekondisi : l1 dan l2 memiliki NeffLDI sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListDinEqual(ListDin l1, ListDin l2)
{
   int i;
   if (NEFFLDI(l1) == NEFFLDI(l2))
   {
      if (NEFFLDI(l1) == 0)
      {
         return true;
      }
      for (i = getFirstIdxListDin(l1); i < NEFFLDI(l1); i++)
      {
         if (ELMTLDI(l1, i) != ELMTLDI(l2, i))
         {
            return false;
         }
      }
      return true;
   }
   else
   {
      return false;
   }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEffLDI l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexlistdinOf(ListDin l, int val)
{
   int ans, i;
   ans = -1;
   for (i = getFirstIdxListDin(l); i < NEFFLDI(l); i++)
   {
      if (ELMTLDI(l, i) == val)
      {
         ans = i;
         break;
      }
   }
   // printf("ans: %d\n",ans);
   return ans;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, int *max, int *min)
{
   *max = ELMTLDI(l, getFirstIdxListDin(l));
   *min = ELMTLDI(l, getFirstIdxListDin(l));
   int i;
   for (i = getFirstIdxListDin(l); i < NEFFLDI(l); i++)
   {
      if (*max < ELMTLDI(l, i))
      {
         *max = ELMTLDI(l, i);
      }
      if (*min > ELMTLDI(l, i))
      {
         *min = ELMTLDI(l, i);
      }
   }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut)
{
   CreateListDin(lOut, NEFFLDI(lIn));
   NEFFLDI(*lOut) = NEFFLDI(lIn);
   int i;
   for (i = getFirstIdxListDin(lIn); i < NEFFLDI(lIn); i++)
   {
      ELMTLDI(*lOut, i) = ELMTLDI(lIn, i);
   }
   // printList(*lOut);
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEffLDI dan capacityLDI sama) */
/* Proses : Menyalin isi lIn ke lOut */
int sumListDin(ListDin l)
{
   int total = 0;
   int i;
   for (i = getFirstIdxListDin(l); i < NEFFLDI(l); i++)
   {
      total = total + ELMTLDI(l, i);
   }
   // printf("--total: %d",total);
   return total;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, int val)
{
   int count = 0;
   int i;
   if (NEFFLDI(l) == 0)
   {
      return count;
   }
   for (i = getFirstIdxListDin(l); i < NEFFLDI(l); i++)
   {
      if (ELMTLDI(l, i) == val)
      {
         count++;
      }
   }
   // printf("--countval: %d",count);
   return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sortListDin(ListDin *l, boolean asc)
{
   int i;
   if (isEmptyListDin(*l) == false)
   {
      if (asc)
      {
         boolean bool = true;
         while (bool)
         {
            int count_true = -1;
            for (i = 0; i < NEFFLDI(*l) - 1; i++)
            {
               if (ELMTLDI(*l, i) > ELMTLDI(*l, i + 1))
               {
                  int temp = ELMTLDI(*l, i);
                  ELMTLDI(*l, i) = ELMTLDI(*l, i + 1);
                  ELMTLDI(*l, i + 1) = temp;
               }
               else
               {
                  count_true++;
               }
            }
            if (ELMTLDI(*l, NEFFLDI(*l) - 2) > ELMTLDI(*l, NEFFLDI(*l) - 1))
            {
               int temp = ELMTLDI(*l, i);
               ELMTLDI(*l, i) = ELMTLDI(*l, i + 1);
               ELMTLDI(*l, i + 1) = temp;
            }
            else
            {
               count_true++;
            }
            if (count_true == NEFFLDI(*l) - 1)
            {
               break;
            }
         }
      }
      else
      {
         while (true)
         {
            int count_true = -1;
            for (i = 0; i < NEFFLDI(*l) - 1; i++)
            {
               if (ELMTLDI(*l, i) < ELMTLDI(*l, i + 1))
               {
                  int temp = ELMTLDI(*l, i);
                  ELMTLDI(*l, i) = ELMTLDI(*l, i + 1);
                  ELMTLDI(*l, i + 1) = temp;
               }
               else
               {
                  count_true++;
               }
            }
            if (ELMTLDI(*l, NEFFLDI(*l) - 2) < ELMTLDI(*l, NEFFLDI(*l) - 1))
            {
               int temp = ELMTLDI(*l, i);
               ELMTLDI(*l, i) = ELMTLDI(*l, i + 1);
               ELMTLDI(*l, i + 1) = temp;
            }
            else
            {
               count_true++;
            }
            if (count_true == NEFFLDI(*l) - 1)
            {
               break;
            }
         }
      }
   }
   // printList(*l);
}

/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin *l, int val)
{
   ELMTLDI(*l, getLastIdxListDin(*l) + 1) = val;
   NEFFLDI(*l)
   ++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDin(ListDin *l, int *val)
{
   *val = ELMTLDI(*l, getLastIdxListDin(*l));
   NEFFLDI(*l)
   --;
   // printList(*l);
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num)
{
   int *ptr;
   ptr = (int *)calloc(CAPACITYLDI(*l), sizeof(int));
   int *temp = ptr;
   CAPACITYLDI(*l) = CAPACITYLDI(*l) + num;
   ptr = realloc(ptr, CAPACITYLDI(*l) * sizeof(int));
}
/* Proses : Menambahkan capacityLDI l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num)
{
   int *ptr;
   ptr = (int *)calloc(CAPACITYLDI(*l), sizeof(int));
   int *temp = ptr;
   CAPACITYLDI(*l) = CAPACITYLDI(*l) - num;
   ptr = realloc(ptr, CAPACITYLDI(*l) * sizeof(int));
}
/* Proses : Mengurangi capacityLDI sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacityLDI > num, dan nEffLDI < capacityLDI - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l)
{
   CAPACITYLDI(*l) = NEFFLDI(*l);
}
/* Proses : Mengubah capacityLDI sehingga capacityLDI = nEffLDI */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacityLDI = nEffLDI */
