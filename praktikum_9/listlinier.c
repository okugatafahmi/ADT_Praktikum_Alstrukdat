/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 18/10/2019
   Topik    : ADT List Linier
*/

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    /* Kamus Lokal */
    address P;
    P=(address) malloc(sizeof(ElmtList));
    if (P!=Nil){
        Info(P)=X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    /* Kamus Lokal */
    address P;
    boolean found=false;

    /* Algoritma */
    P=First(L);
    while ((P!=Nil) && (!found)){
        if (Info(P)==X){
            found = true;
        }
        else{
            P=Next(P);
        }
    }
    return P;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P=Alokasi(X);
    if (IsEmpty(*L)){
        First(*L)=P;
    }
    else{
        Next(P)=First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* Kamus Lokal */
    address P,Pt,Prec;

    /* Algoritma */
    Pt=Alokasi(X);
    P=First(*L); Prec=Nil;
    while(P!=Nil){
        Prec=P; P=Next(P);
    }
    if (Prec==Nil){
        First(*L)=Pt;
    }
    else{
        Next(Prec)=Pt;
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /* Kamus Lokal */
    address P,Prec;

    /* Algoritma */
    P=First(*L); Prec=Nil;
    if (Next(P)==Nil){
        DelVFirst(L,X);
    }
    else{
        while(Next(P)!=Nil){
            Prec=P; P=Next(P);
        }
        *X = Info(P);
        Next(Prec) = Nil;
        Dealokasi(&P);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    /* Kamus Lokal */
    
    /* Algoritma */
    Next(P)=First(*L);   
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    /* Kamus Lokal */

    /* Algoritma */
    Next(P)=Next(Prec);
    Next(Prec)=P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    /* Kamus Lokal */
    address Pt,Prec;

    /* Algoritma */
    Pt=First(*L); Prec=Nil;
    while(Pt!=Nil){
        Prec=Pt; Pt=Next(Pt);
    }
    if (Prec==Nil){
        First(*L)=P;
    }
    else{
        Next(Prec)=P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    /* Algoritma */
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    /* Kamus Lokal */
    address P,Prec;
    boolean found = false;

    /* Algoritma */
    P=First(*L); Prec=Nil;
    while ((P!=Nil) && (!found)){
        if (Info(P)==X){
            found = true;
        }
        else{
            Prec=P;
            P=Next(P);
        }
    }
    if (found){ //Info(P)=X
        if (Prec==Nil){ //P=First(*L)
            First(*L)=Next(P);
        }
        else{
            Next(Prec)=Next(P);
        }
        Dealokasi(&P);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    /* Kamus Lokal */
    address Prec;

    /* Algoritma */
    *P = First(*L); Prec=Nil;
    while (Next(*P)!=Nil){
        Prec=*P; *P = Next(*P);
    }
    if (Prec==Nil){
    	First(*L)=Nil;
    }
    else{
    	Next(Prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel=Next(Prec);
    Next(Prec)=Next(Next(Prec));
    Next(*Pdel)=Nil;
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    printf("[");
    P=First(L);
    while(P!=Nil){
        printf("%d",Info(P));
        if (Next(P)!=Nil){
            printf(",");
        }
        P=Next(P);
    }
    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /* Kamus Lokal */
    address P;
    int cnt=0;

    /* Algoritma */
    P=First(L);
    while(P!=Nil){
        cnt++; P=Next(P);
    }
    return cnt;
}


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    /* Kamus Lokal */
    address P;
    infotype maks;

    /* Algoritma */
    P=First(L);
    maks=Info(P);
    P=Next(P);
    while(P!=Nil){
        if (Info(P)>maks){
            maks=Info(P);
        }
        P=Next(P);
    }
    return maks;
}


/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    /* Kamus Lokal */
    address P,Prec;

    /* Algoritma */
    P=First(*L1); Prec=Nil;
    while (P!=Nil){
        Prec=P; P=Next(P);
    }
    if (Prec==Nil){
    	First(*L3)=First(*L2);
    }
    else{
    	Next(Prec)=First(*L2);
    	First(*L3)=First(*L1);
    }

    First(*L1)=Nil;
    First(*L2)=Nil;
}
    
