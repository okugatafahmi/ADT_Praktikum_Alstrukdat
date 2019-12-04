/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 7/11/2019
   Topik    : ADT List Rekursif
*/

/* File: listrek.c */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi list : */
/* List kosong : L = Nil */

/* Deklarasi  nama untuk variabel kerja */ 
/*    L : List */
/*    P : address   */
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=(address) malloc(sizeof(ElmtList));

    if (P!=Nil){
        Info(P)=X;
        Next(P)=Nil;
    }
    return P;
}

void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}


/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    return (L==Nil);
}

int IsOneElmt(List L){
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    if (IsEmpty(L)){
        return 0;
    }
    else{
        return (Next(L)==Nil);
    }
}


/* *** Selektor *** */
infotype FirstElmt (List L){
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    return (Info(L));
}

List Tail(List L){
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    return (Next(L));
}


/* *** Konstruktor *** */
List Konso(infotype e, List L){
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    P=Alokasi(e);
    if (P!=Nil){
        Next(P) = L;
        return P;
    }
    else{
        return L;
    }
}

List KonsB(List L, infotype e){
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    if (L==Nil){
        P=Alokasi(e);
        return P;
    }
    else{
        Next(L) = KonsB(Tail(L),e);
        return L;
    }
}


/* *** Operasi Lain *** */
List Copy (List L){
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
    /* Kamus Lokal */
    address P;

    /* Algoritma */
    if (IsEmpty(L)){
        return Nil;
    }
    else{
        return Konso(FirstElmt(L),Copy(Tail(L)));
    }
}

void MCopy (List Lin, List *Lout){
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
    (*Lout) = Copy(Lin);
}

List Concat (List L1, List L2){
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
    if (L1==Nil){
        return Copy(L2);
    }
    else{
        List L3 = Alokasi(Info(L1));
        if (L3!=Nil){
            Next(L3)=Concat(Next(L1),L2);
            return L3;
        }
        
    }
}

void MConcat (List L1, List L2, List *LHsl){
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    (*LHsl) = Concat(L1,L2);
}

void PrintList (List L){
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
    if (L!=Nil){
        printf("%d\n",Info(L));
        if (Next(L)!=Nil){
            PrintList(Tail(L));
        }
    }
}

int NbElmtList (List L){
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
    if (L==Nil){
        return 0;
    }
    else{
        return (1+NbElmtList(Tail(L)));
    }
}

boolean Search (List L, infotype X){
/* Mengirim true jika X adalah anggota list, false jika tidak */
    if (L==Nil){
        return false;
    }
    else if (Info(L)==X){
        return true;
    }
    else{
        return Search(Tail(L),X);
    }
}


/* ** Fungsi/ Prosedur tambahan praktikum ** */
/* ** Pencarian nilai ekstrim ** */
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L){
/* Mengirimkan nilai info(P) yang maksimum */
	/* Kamus Lokal */
	infotype res;
	
	/* Algoritma */
	if (IsOneElmt(L)){
		return Info(L);
	}
	else{
		res = MaxList(Tail(L));
		return ((res>=Info(L))? res:Info(L));
	}
}

infotype MinList (List L){
/* Mengirimkan nilai info(P) yang minimum */
/* Kamus Lokal */
	infotype res;
	
	/* Algoritma */
	if (IsOneElmt(L)){
		return Info(L);
	}
	else{
		res = MinList(Tail(L));
		return ((res<=Info(L))? res:Info(L));
	}
}

infotype SumList (List L){
/* Mengirimkan total jumlah elemen List L */
	/* Kamus Lokal */
	
	/* Algoritma */
	if (IsOneElmt(L)){
		return Info(L);
	}
	else{
		return (Info(L)+SumList(Tail(L)));
	}
}

float AverageList (List L){
/* Mengirimkan nilai rata-rata elemen list L */
	/* Kamus Lokal */
	infotype sum;
	int n;
	
	/* Algoritma */
	sum = SumList(L);
	n = NbElmtList(L);
	return ((float) sum/(float) n);
}


/* ** Operasi-Operasi Lain ** */
List InverseList (List L){
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
	/* Kamus Lokal */
	address P,Pt;
	
	/* Algoritma */
	if (!IsEmpty(L)){
		if (IsOneElmt(L)){
			return L;
		}
		else{
			return KonsB(InverseList(Tail(L)),Info(L));
		}
	}
	else{
		return Nil;
	}
}


void SplitPosNeg (List L, List *L1, List *L2){
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	
	if (IsEmpty(L)){
		(*L1) = Nil;
		(*L2) = Nil;
	}
	else{
		SplitPosNeg(Tail(L),L1,L2);
		
		P = Alokasi(Info(L));
		if (Info(P)>=0){
			Next(P) = (*L1);
			(*L1) = P;
		}
		else{
			Next(P) = (*L2);
			(*L2) = P;
		}
	}
}

void SplitOnX (List L, infotype X, List *L1, List *L2){
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	
	if (IsEmpty(L)){
		(*L1) = Nil;
		(*L2) = Nil;
	}
	else{
		SplitOnX(Tail(L),X,L1,L2);
		
		P = Alokasi(Info(L));
		if (Info(P)<X){
			Next(P) = (*L1);
			(*L1) = P;
		}
		else{
			Next(P) = (*L2);
			(*L2) = P;
		}
	}
}

int ListCompare (List L1, List L2){
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
	if ( (IsEmpty(L1)) && (IsEmpty(L2)) ){
		return 0;
	}
	else if (IsEmpty(L1)){
		return -1;
	}
	else if (IsEmpty(L2)){
		return 1;
	}
	else if (Info(L1)==Info(L2)){
		return ListCompare(Tail(L1),Tail(L2));
	}
	else{
		return ((Info(L1)<Info(L2))? -1:1);
	}
}

boolean IsAllExist (List L1, List L2){
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
	if (IsEmpty(L1) || IsEmpty(L2)){
		return false;
	}
	else if (IsOneElmt(L1)){
		return Search(L2, Info(L1));
	}
	else if (Search(L2,Info(L1))){
		return IsAllExist(Tail(L1), L2);
	}
	else{
		return false;
	}
}
