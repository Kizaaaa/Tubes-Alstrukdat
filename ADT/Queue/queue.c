/* File : queue.h */
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */

// #ifndef QUEUE_H
// #define QUEUE_H
#include <stdio.h>
#include "queue.h"

// #define IDX_UNDEF -1
// #define CAPACITY 100

/* Definisi elemen dan address */
// typedef int ElType;
// typedef struct {
// 	ElType buffer[CAPACITY]; 
// 	int idxHead;
// 	int idxTail;
// } Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).buffer[(q).idxHead]
// #define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q){
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q){
    if ((IDX_TAIL(q) == IDX_UNDEF)&&(IDX_HEAD(q)==IDX_UNDEF)){
        // printf("--trueee\n");
        return true;
    }
    else{
        // printf("--falsee\n");
        return false;
    }
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q){
    // return ((IDX_HEAD(q)==0) && (IDX_TAIL(q)==CAPACITY-1));
    boolean ans=false;
    if (((IDX_TAIL(q)==CAPACITY-1)&&(IDX_HEAD(q)==0))||(IDX_HEAD(q)==IDX_TAIL(q)+1)){
        ans = true;
    }
    return ans;
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthQueue(Queue q){
    int len = 0;
    int i;
    if (isEmptyQueue(q)){
        return 0;
    }
    // else{
    //     return (IDX_TAIL(q)-IDX_HEAD(q)+1);
    // }

    else{ //IDXHEAD>IDXTAIL
        len = (((IDX_TAIL(q) - IDX_HEAD(q) +CAPACITY) % CAPACITY) + 1);
    }
    return len;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    if(isEmptyQueue(*q)){
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else{
        if (IDX_TAIL(*q)==CAPACITY-1){
            IDX_TAIL(*q)=0;
        }
        else{
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q)=val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (lengthQueue(*q)==1){
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else{
        if (IDX_HEAD(*q)==CAPACITY-1){
            IDX_HEAD(*q)=0;
        }
        else{
            IDX_HEAD(*q)++;
        }
    }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q){
    int val=0;
    if (isEmptyQueue(q)){
        printf("[]\n");
    }
    else if (lengthQueue(q)==1){
        printf("[");
        printf("%d",q.buffer[IDX_TAIL(q)]);
        printf("]\n");
    }
    else if (IDX_TAIL(q)<IDX_HEAD(q)){
        int i=0;
        printf("[");
        for (i=IDX_HEAD(q);i<=CAPACITY-1;i++){
            printf("%d,",q.buffer[i]);
        }
        for (i=0;i<IDX_TAIL(q);i++){
            // printf("\nINDEKS: %d\n",i);
            printf("%d,",q.buffer[i]);
        }
        printf("%d",q.buffer[IDX_TAIL(q)]);
        printf("]\n");
    }
    else if (IDX_HEAD(q)<IDX_TAIL(q)){
        int i=0;
        printf("[");
        for (i=IDX_HEAD(q);i<IDX_TAIL(q);i++){
            printf("%d,",q.buffer[i]);
        }
        printf("%d",q.buffer[IDX_TAIL(q)]);
        printf("]\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

Queue reverseQueue(Queue q){
    Queue Q1;
    Queue hasil;
    CreateQueue(&Q1);
    CreateQueue(&hasil);
    Q1=q;
    int i,j,val;
    int len = lengthQueue(q);
    int pjg = lengthQueue(q);
    for (i=0;i<pjg;i++){
        j=0;
        while(j<len){
            dequeue(&q,&val);
            j++;
        }
        enqueue(&hasil,val);
        printf("\n");
        len--;
        q=Q1;
    }
    // displayQueue(hasil);
    return (hasil);
}
