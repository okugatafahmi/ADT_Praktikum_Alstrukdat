/*  Nama    : Okugata Fahmi Nurul Y. F.
    NIM     : 13518031
    Tanggal : 29/9/2019
    Topik   : ADT Queue
*/

/* File : queue.c */
/* Implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    /* Kamus Lokal */
    
    /* Algoritma */
    return ( (Head(Q)==Nil) && (Tail(Q)==Nil));
}

boolean IsFull (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    /* Kamus Lokal */
    
    /* Algoritma */
    return ( ((Tail(Q)%MaxEl(Q))+1) == Head(Q));
}

int NBElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    /* Kamus Lokal */
    
    /* Algoritma */
    if (IsEmpty(Q)) return 0;
    if (Head(Q)<=Tail(Q)){
        return (Tail(Q)-Head(Q)+1);
    }
    else{
        return (MaxEl(Q)-(Head(Q)-Tail(Q)-1));
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* Kamus Lokal */
    
    /* Algoritma */
    Q->T = (infotype*) malloc((Max+1)*sizeof(infotype));
    if (Q->T == NULL){
        MaxEl(*Q) = 0;
    }
    else{
        MaxEl(*Q) = Max;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* Kamus Lokal */
    
    /* Algoritma */
    free(Q->T);
    MaxEl(*Q)=0;
}


/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    /* Kamus Lokal */
    
    /* Algoritma */
    if (IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        Q->T[1] = X;
    }
    else{
        Tail(*Q) = (Tail(*Q)%MaxEl(*Q))+1;
        Q->T[Tail(*Q)] = X;
    }
}

void Del (Queue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    /* Kamus Lokal */
    
    /* Algoritma */
    *X = InfoHead(*Q);
    Head(*Q) = ((Head(*Q)%MaxEl(*Q))+1);
}