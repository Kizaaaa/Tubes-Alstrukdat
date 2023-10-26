#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "time.h"
#include "datetime.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
{
    /* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
    /* Prekondisi: 1 <= M <= 12*/
    /* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
    /* Aturan Leap Year: */
    /* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. */
    /* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
    /* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
    /* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

    if (M == 2)
    {
        if (Y % 400 == 0)
        {
            return 29;
        }
        else if (Y % 100 == 0)
        {
            return 28;
        }
        else if (Y % 4 == 0)
        {
            return 29;
        }
        return 28;
    }
    else if (M == 4 || M == 6 || M == 9 || M == 11)
    {
        return 30;
    }
    return 31;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    /* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

    return (D >= 1 && D <= GetMaxDay(M, Y) && M >= 1 && M <= 12 && Y >= 1900 && Y <= 2030 && IsTIMEValid(h, m, s));
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    /* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

    TIME T;
    CreateTime(&T, hh, mm, ss);

    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
{
    /* I.S. : D tidak terdefinisi */
    /* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
    /* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
    /* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
        diulangi hingga didapatkan DATETIME yang valid. */
    /* Contoh:
        32 13 2023 12 34 56
        DATETIME tidak valid
        31 12 2023 12 34 56
        --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

    /*KAMUS*/
    int DD, MM, YYYY, hh, mm, ss;

    /*ALGORITMA*/
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);

    while (!IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &hh, &mm, &ss);
    }
    CreateDATETIME(D, DD, MM, YYYY, hh, mm, ss);
}

void TulisDATETIME(DATETIME D)
{
    /* I.S. : D sembarang */
    /* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
    /* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

    /*ALGORITMA*/
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1=D2, false jika tidak */
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1 tidak sama dengan D2 */
    return (!DEQ(D1, D2));
}

boolean DLT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1<D2, false jika tidak */

    if (Year(D1) < Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) < Month(D2))
        {
            return true;
        }
        else if (Month(D1) == Month(D2))
        {
            if (Day(D1) < Day(D2))
            {
                return true;
            }
            else if (Day(D1) == Day(D2))
            {
                return TLT(Time(D1), Time(D2));
            }
            return false;
        }
        return false;
    }
    return false;
}

boolean DGT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1>D2, false jika tidak */
    return (!DLT(D1, D2) && DNEQ(D1, D2));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik ditambah N */

    /*KAMUS*/
    DATETIME D1;
    TIME T;
    long sisa;

    /*ALGORITMA*/
    while (TIMEToDetik(Time(D)) + N > 86400) // Lebih dari 1 hari
    {
        if (Day(D) < GetMaxDay(Month(D), Year(D))) // Jika tanggal hari tsb. < Jumlah hari dalam suatu bulan dan tahun
        {
            Day(D) += 1; // Menambah hari, namun mengurangi detik yang setara dengan 1 hari
            N -= 86400;
        }
        else if (Month(D) < 12) // Sama seperti kasus sebelumnya, tapi ditujukan untuk konversi bulan
        {
            Month(D) += 1;
            Day(D) = 1;
            N -= 86400;
        }
        else // Sama seperti kasus sebelumnya, tapi ditujukan untuk konversi tahun
        {
            Year(D) += 1;
            Month(D) = 1;
            Day(D) = 1;
            N -= 86400;
        }
    }

    sisa = TIMEToDetik(Time(D)) + N;
    T = DetikToTIME(sisa);
    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(T), Minute(T), Second(T));

    return (D1);
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik dikurang N */

    /*KAMUS*/
    DATETIME D1;
    TIME T;
    long sisa = TIMEToDetik(Time(D)) - N;

    /*ALGORITMA*/
    while (sisa < 0)
    {
        if (Day(D) > 1)
        {
            Day(D) -= 1;
            sisa += 86400;
        }
        else if (Month(D) > 1)
        {
            Month(D) -= 1;
            Day(D) = GetMaxDay(Month(D), Year(D));
            sisa += 86400;
        }
        else
        {
            Year(D) -= 1;
            Month(D) = 12;
            Day(D) = 31;
            sisa += 86400;
        }
    }

    T = DetikToTIME(sisa);
    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(T), Minute(T), Second(T));

    return (D1);
}

/**** Kelompok Operator Aritmetika terhadap DATETIME ****/
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    /* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
    /* Prekondisi: DAkh > DAw */

    /*KAMUS*/
    long durasi = TIMEToDetik(Time(DAkh)) - TIMEToDetik(Time(DAw));
    Time(DAkh) = Time(DAw);

    /*ALGORITMA*/
    while (!DEQ(DAw, DAkh))
    {
        DAw = DATETIMENextNDetik(DAw, 86400);
        durasi += 86400;
    }

    return durasi;
}
