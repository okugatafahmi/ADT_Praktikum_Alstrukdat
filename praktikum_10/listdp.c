/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 30/10/2019
   Topik    : ADT Variasi List
*/

/* File : listdp.c */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>


/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return ((First(L)==Nil) && (Last(L)==Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L)=Nil;
    Last(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=(address) malloc(sizeof(ElmtList));
    if (P!=Nil){
        Info(P)=X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    /* Kamus Lokal */
    address P;
    boolean found = false;
    
    /* Algoritma */
    P = First(L);
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
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = Alokasi(X);
    if (IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = Alokasi(X);
    if (IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=First(*L);
    (*X) = Info(P);
    First(*L) = Next(P);

    if (First(*L)!=Nil){
        Prev(First(*L)) = Nil;
    }
    else{
        Last(*L) = Nil;
    }
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=Last(*L);
    (*X) = Info(P);
    Last(*L) = Prev(P);

    if (Last(*L)!=Nil){
        Next(Last(*L)) = Nil;
    }
    else{
        First(*L) = Nil;
    }
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (IsEmpty(*L)){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (Last(*L)==Nil){
        First(*L) = P;
        Last(*L) = P;
    }
    else{
        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
    if (Next(P)!=Nil){
        Prev(Next(P)) = P;
    }
    else{
        Last(*L) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if (Prev(P) != Nil){
        Next(Prev(P)) = P;
    }
    else{
        First(*L) = P;
    }
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    (*P) = First(*L);
    First(*L) = Next(*P);
    if (First(*L)!=Nil){
        Prev(First(*L)) = Nil;
    }
    else{
        Last(*L) = Nil;
    }
    Next(*P)=Nil;
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    (*P) = Last(*L);
    Last(*L) = Prev(*P);
    if (Last(*L)!=Nil){
        Next(Last(*L)) = Nil;
    }
    else{
        First(*L) = Nil;
    }
    Prev(*P)=Nil;
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Search(*L,X);
    if (P!=Nil){
        if (Prev(P)!=Nil){
            Next(Prev(P)) = Next(P);
        }
        else{
            First(*L) = Next(P);
        }
        if (Next(P)!=Nil){
            Prev(Next(P)) = Prev(P);
        }
        else{
            Last(*L) = Prev(P);
        }
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if (Next(Prec)!=Nil){
        Prev(Next(Prec)) = Prec;
        Next(*Pdel) = Nil;
    }
    else{
        Last(*L) = Prec;
    }
    Prev(*Pdel) = Nil;
}

void DelBefore (List *L, address *Pdel, address Succ){
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    (*Pdel) = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(Succ)!=Nil){
        Next(Prev(Succ)) = Succ;
        Prev(*Pdel) = Nil;
    }
    else{
        First(*L) = Succ;
    }
    Next(*Pdel) = Nil;
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    printf("[");
    P = First(L);
    while (P!=Nil){
        printf("%d",Info(P));
        if (Next(P)!=Nil){
            printf(",");
        }
        P=Next(P);
    }
    printf("]");
}

void PrintBackward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    printf("[");
    P = Last(L);
    while (P!=Nil){
        printf("%d",Info(P));
        if (Prev(P)!=Nil){
            printf(",");
        }
        P=Prev(P);
    }
    printf("]");
}