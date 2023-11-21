#include <stdio.h>
#include "../datetime.h"

int main()
{
    TIME T1;
    printf("BACA TIME\n");
    BacaTIME(&T1);

    printf("TULIS TIME\n");
    printf("T1 = ");
    TulisTIME(T1);
    printf("\n");

    printf("TIME TO DETIK\n");
    printf("T1 = %ld detik\n", TIMEToDetik(T1));

    printf("DETIK TO TIME\n");
    printf("T1 = ");
    TulisTIME(DetikToTIME(TIMEToDetik(T1)));
    printf("\n");

    TIME T2;
    BacaTIME(&T2);
    printf("TEQ\n");
    if (TEQ(T1, T2))
    {
        printf("T1 = T2\n");
    }
    else
    {
        printf("T1 != T2\n");
    }

    printf("TNEQ\n");
    if (TNEQ(T1, T2))
    {
        printf("T1 != T2\n");
    }
    else
    {
        printf("T1 = T2\n");
    }

    printf("TLT\n");
    if (TLT(T1, T2))
    {
        printf("T1 < T2\n");
    }
    else
    {
        printf("T1 > T2\n");
    }

    printf("TGT\n");
    if (TGT(T1, T2))
    {
        printf("T1 > T2\n");
    }
    else
    {
        printf("T1 < T2\n");
    }

    printf("NextNDetik\n");
    printf("T1 = ");
    TulisTIME(NextNDetik(T1, 10));

    printf("PrevDetik\n");
    printf("T1 = ");
    TulisTIME(PrevDetik(T1));

    printf("PrevNDetik\n");
    printf("T1 = ");
    TulisTIME(PrevNDetik(T1, 10));
    printf("\n");

    printf("Durasi\n");
    printf("T1-T2 = %ld detik\n", Durasi(T1, T2));

    printf("Local Time\n");
    DATETIME D = GetLocalTime();

    printf("D = ");
    TulisDATETIME(D);

    return 0;
}