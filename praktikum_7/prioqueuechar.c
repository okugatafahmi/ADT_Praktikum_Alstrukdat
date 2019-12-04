/*  Nama    : Okugata Fahmi Nurul Y. F.
    NIM     : 13518031
    Tanggal : 3/10/2019
    Topik   : ADT Priority Queue
*/
/* File : prioqueue.c */
/* Implementasi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q)==Nil); //kurang tail
}

boolean IsFull (PrioQueueChar Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return ( ((Tail(Q)%MaxEl(Q))+1) == Head(Q) );
}

int NBElmt (PrioQueueChar Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q)) return 0;
	else{
		if (Head(Q)<=Tail(Q)){
			return (Tail(Q)-Head(Q)+1);
		}
		else{
			return (MaxEl(Q)-(Head(Q)-Tail(Q)-1));
		}
	}
}


/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (infotype*) malloc((Max+1)*sizeof(infotype));
	
	if ((*Q).T == NULL){
        MaxEl(*Q) = 0;
    }
    else{
        MaxEl(*Q) = Max;
    }
}


/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	free((*Q).T);
	MaxEl(*Q) = 0;
}


/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
	/* Kamus Lokal */
    address now,before;
    infotype temp;
    
    /* Algoritma */
    if (IsEmpty(*Q)){
        Head(*Q) = 1;
        Tail(*Q) = 1;
        Q->T[1] = X;
    }
    else{
        Tail(*Q) = (Tail(*Q)%MaxEl(*Q))+1;
        Q->T[Tail(*Q)] = X;
        
        now = Tail(*Q);
        before = ( ((now-2)+MaxEl(*Q))%MaxEl(*Q) ) + 1;
        
        while ( (Prio(Elmt(*Q,now)) < Prio(Elmt(*Q,before)) ) && (now!=Head(*Q)) ){
			temp = Elmt(*Q,now);
			Elmt(*Q,now) = Elmt(*Q,before);
			Elmt(*Q,before) = temp;
			now = before;
			before = ((before+MaxEl(*Q)-2)%MaxEl(*Q) ) + 1;
			//printf("%d\n",now);
		}
    }
}
        
void Del (PrioQueueChar * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	/* Kamus Lokal */
    
    /* Algoritma */
    (*X) = InfoHead(*Q);
    Head(*Q) = ((Head(*Q)%MaxEl(*Q))+1);
}
        

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
	/* Kamus Lokal */
    address i;
    
    /* Algoritma */
    i = Head(Q);
    while (i!=Tail(Q)){
		printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
		i = (i%MaxEl(Q))+1;
	}
	if (i!=Nil) printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
	printf("#\n");
}
