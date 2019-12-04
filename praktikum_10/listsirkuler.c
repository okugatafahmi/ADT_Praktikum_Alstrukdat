/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 30/10/2019
   Topik    : ADT Variasi List
*/

/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listsirkuler.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    /* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P=(address) malloc(sizeof(ElmtList));
    if (P!=Nil){
        Info(P)=X;
        Next(P) = Nil;
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
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    if (IsEmpty(L)){
        return Nil;
    }
    else{
        P=First(L);
        while ((Next(P)!=First(L)) && (Info(P)!=X)) {
            P=Next(P);
        }
        return ((Info(P)==X)? P:Nil);
    }
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
    P=Alokasi(X);
    if (P!=Nil){        
        InsertFirst(L,P);
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
    if (P!=Nil){
        InsertLast(L,P);
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    DelFirst(L,&P);
    (*X) = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
    Dealokasi(P);
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    /* Kamus Lokal */
    address Pt;
    
    /* Algoritma */
    if (IsEmpty(*L)){
        Next(P) = P;
    }
    else{
        Pt = First(*L);
        while (Next(Pt) != First(*L)){
            Pt = Next(Pt);
        }
        Next(Pt) = P;
        Next(P) = First(*L);
    }
    First(*L) = P;
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    /* Kamus Lokal */
    address Pt;
    
    /* Algoritma */
    if (IsEmpty(*L)){
        Next(P) = P;
        First(*L) = P;   
    }
    else{
        Pt = First(*L);
        while (Next(Pt) != First(*L)){
            Pt = Next(Pt);
        }
        Next(Pt) = P;
        Next(P) = First(*L);
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P)=Next(Prec);
    Next(Prec)=P;
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    /* Kamus Lokal */
    address Pt;
    
    /* Algoritma */
    (*P) = First(*L);
    if (Next(First(*L))==First(*L)){
        First(*L) = Nil;
    }
    else {
        Pt = First(*L);
        while (Next(Pt)!=First(*L)){
            Pt = Next(Pt);
        }
        First(*L) = Next(First(*L));
        Next(Pt) = First(*L);
    }
    Next(*P)=Nil;
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
    /* Kamus Lokal */
    address Prec;    
    
    /* Algoritma */
    if (Next(First(*L))==First(*L)){
        (*P) = First(*L);
        First(*L) = Nil;
    }
    else {
        (*P) = First(*L); Prec = Nil;
        while (Next(*P)!=First(*L)){
            Prec = (*P);
            (*P) = Next(*P);
        }
        Next(Prec) = Next(*P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    // if (Next(Prec)==First(*L)){
    //     if (Next(First(*L))==First(*L)){
    //         First(*L) = Nil;    
    //     }
    //     else{
    //         First(*L)=Next(First(*L));
    //         Next(Prec) = First(*L);
    //     }
    // }
    // else{
    //     Next(Prec) = Next(*Pdel);
    // }
}

void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    /* Kamus Lokal */
    address P,Prec;

    /* Algoritma */
    if (!IsEmpty(*L)){
        // Mencari address yang Info(P)==X
        Prec=Nil;
        P=First(*L);
        while ((Next(P)!=First(*L)) && (Info(P)!=X)) {
            Prec = P;
            P=Next(P);
        }

        if (Info(P)==X){
            if (P==First(*L)){ // Ketemunya di depan
                // Mencari last
                Prec = First(*L);
                while (Next(Prec)!=First(*L)){
                    Prec=Next(Prec);
                }
                if (Next(Prec)==Prec){ // Kalau 1 elemen
                    First(*L) = Nil;
                }
                else{
                    First(*L) = Next(First(*L));
                    Next(Prec) =First(*L);
                }
            }
            else{
                Next(Prec) = Next(P);
            }
            Dealokasi(P);
        }
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    if (IsEmpty(L)){
        printf("[]");
    }
    else{
        P = First(L);
        printf("[");
        do {
            printf("%d",Info(P));
            if (Next(P)!=First(L)){
                printf(",");
            }
            P = Next(P);
        } while (P!=First(L));
        printf("]");
    }
}