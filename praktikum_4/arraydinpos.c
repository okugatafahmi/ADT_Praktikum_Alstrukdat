/*  Nama        : Okugata Fahmi Nurul Y. F.
    NIM         : 13518031
    Tanggal     : 15/9/2019
    Topik       : ADT Array Dinamis
    Deskripsi   : Realisasi pada array dinamis secara implisit
*/

/* MODUL TABEL INTEGER */
/* Berisi realisasi pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#include "arraydinpos.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
    /* KAMUS LOKAL	*/
    IdxType i;
    
    /*	ALGORITMA	*/
    TI(*T) = (ElType *) malloc((maxel+1)*sizeof(ElType));
    MaxEl(*T) = maxel;
    for (i=0;i<=MaxEl(*T);i++){
		Elmt(*T,i) = ValUndef;
	}
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    MaxEl(*T)=0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/* KAMUS LOKAL	*/
    IdxType i;
    int cnt;
    
    /*	ALGORITMA	*/
    i=IdxMin;
    cnt = 0;
    while ((i<MaxEl(T)) && (Elmt(T,i)!=ValUndef)){
		cnt++;
		i++;
	}
	if (Elmt(T,i)!=ValUndef) cnt++;
	return cnt;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	/* KAMUS LOKAL	*/
    IdxType i;
    
    /*	ALGORITMA	*/
    i=GetFirstIdx(T);
    while ((i<MaxEl(T)) && (Elmt(T,i)!=ValUndef)){
		i++;
	}
	
	return ((Elmt(T,i)==ValUndef) ? (i-1):i);
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((i>=GetFirstIdx(T)) && (i<=(MaxEl(T)-GetFirstIdx(T)+1)) );
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (Elmt(T,IdxMin)==ValUndef);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (GetLastIdx(T)==MaxEl(T));
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    /*  KAMUS LOKAL   */
    int n;
    IdxType i;
    
    /*  ALGORITMA   */
    do{
        scanf("%d",&n);
    } while ((n<0) || (n>MaxEl(*T)) );
    
    if (n>0){
        for (i=IdxMin;i<=n;i++){
            scanf("%d",&Elmt(*T,i));
        }
    }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /*  ALGORITMA   */
    printf("[");
    if (!IsEmpty(T)){
        i=GetFirstIdx(T);
        printf("%d",Elmt(T,i));
        
        i++;
        IdxLast = GetLastIdx(T);
        while (i<=IdxLast){
            printf(",%d",Elmt(T,i));
            i++;
        }
    }
    printf("]");
}



/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    /*  KAMUS LOKAL */
    IdxType i,j,IdxLast;
    TabInt res;

    /* ALGORITMA    */
    MakeEmpty(&res,MaxEl(T1));
    i=GetFirstIdx(T1);
    j=GetFirstIdx(T2);
    IdxLast=GetLastIdx(T1);
    while (i<=IdxLast){
        Elmt(res,i) = Elmt(T1,i) + (((plus)? 1:-1)*Elmt(T2,j));
        i++;
        j++;
    }
    return res;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    /*  KAMUS LOKAL */
    IdxType i,j,IdxLast;

    /* ALGORITMA    */
    if (NbElmt(T1)==NbElmt(T2)){
        i=GetFirstIdx(T1);
        j=GetFirstIdx(T2);
        IdxLast = GetLastIdx(T1);
        while ((i<IdxLast) && (Elmt(T1,i)==Elmt(T2,j))){
            i++;
            j++;
        }
        return (Elmt(T1,i)==Elmt(T2,j));
    }
    else{
        return false;
    }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /* ALGORITMA    */
    if (IsEmpty(T)){
		return IdxUndef;
	}
	else{
		i=GetFirstIdx(T);
		IdxLast = GetLastIdx(T);
		while ((i<IdxLast) && (Elmt(T,i)!=X)){
			i++;
		}
		return ((Elmt(T,i)==X)? i:IdxUndef);
	}
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{    
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /* ALGORITMA    */
    if (IsEmpty(T)){
		return false;
	}
	else{
		i=GetFirstIdx(T);
		IdxLast = GetLastIdx(T);
		while ((i<IdxLast) && (Elmt(T,i)!=X)){
			i++;
		}
		return (Elmt(T,i)==X);
	}
}


/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /* ALGORITMA    */
    i= GetFirstIdx(T);
    *Max = Elmt(T,i);
    *Min = Elmt(T,i);
    i++;
    IdxLast = GetLastIdx(T);
    while (i<=IdxLast){
        if (Elmt(T,i)>*Max) *Max=Elmt(T,i);
        if (Elmt(T,i)<*Min) *Min=Elmt(T,i);
        i++;
    }
}
        

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /* ALGORITMA    */
    MakeEmpty(Tout,MaxEl(Tin));

	i=GetFirstIdx(Tin);
	IdxLast = GetLastIdx(Tin);
    while (i<=IdxLast){
        Elmt(*Tout,i) = Elmt(Tin,i);
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;
    ElType res;

    /* ALGORITMA    */
    if (IsEmpty(T)){
		return 0;
	}
	else{
		res=0;
		i=GetFirstIdx(T);
		IdxLast = GetLastIdx(T);
		while (i<=IdxLast){
			res+=Elmt(T,i);
			i++;
		}
		return res;
	}
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	/*  KAMUS LOKAL */
    IdxType i,IdxLast;
    int cnt;

    /* ALGORITMA    */
    if (IsEmpty(T)){
		return 0;
	}
	else{
		cnt=0;
		i=GetFirstIdx(T);
		IdxLast = GetLastIdx(T);
		while (i<=IdxLast){
			if (Elmt(T,i)==X) cnt+=1;
			i++;
		}
		return cnt;
	}
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    /*  KAMUS LOKAL */
    IdxType i,IdxLast;

    /* ALGORITMA    */
    if (!IsEmpty(T)){
        i=GetFirstIdx(T);
        IdxLast=GetLastIdx(T);
        while ((i<IdxLast) && (Elmt(T,i)%2==0)){
            i++;
        }
        return (Elmt(T,i)%2==0);
    }
    else
    {
        return false;
    }
    
}


/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    /*  KAMUS LOKAL */
    IdxType i,j,IdxLast;
    ElType temp;
    boolean swapped;

    /* ALGORITMA    */
    i=GetFirstIdx(*T);
    IdxLast=GetLastIdx(*T);
    swapped=true;
    while ((i<IdxLast) && swapped){
        swapped=false;
        for (j=GetFirstIdx(*T);j<(IdxLast-i+1);j++){
            if ( ((asc)? (Elmt(*T,j)>Elmt(*T,(j+1))) : (Elmt(*T,j)<Elmt(*T,(j+1))) ) ){
                temp = Elmt(*T,j);
                Elmt(*T,j) = Elmt(*T,(j+1));
                Elmt(*T,(j+1)) = temp;
                swapped = true;
            }
        }
        i++;
    }
}
   

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    /*	KAMUS	*/
    IdxType i;
    
    /*	ALGORITMA	*/
    if (IsEmpty(*T)){
		Elmt(*T,IdxMin)=X;
	}
	else{
		i=GetLastIdx(*T);
		Elmt(*T,(i+1))=X;
	}    
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    /*	KAMUS	*/
    IdxType i;
    
    /*	ALGORITMA	*/
    i=GetLastIdx(*T);
    *X=Elmt(*T,i);
    Elmt(*T,i) = ValUndef;
}


/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    /*	KAMUS	*/
    IdxType i;
    
    /*	ALGORITMA	*/
    TI(*T) = (ElType *) realloc(TI(*T),(MaxEl(*T)+num+1)*sizeof(ElType));
    i=MaxEl(*T)+1;
    MaxEl(*T)+= num;
    
    while (i<=MaxEl(*T)){
		Elmt(*T,i)=ValUndef;
		i++;
	}
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    TI(*T) = (ElType *) realloc(TI(*T),(MaxEl(*T)-num+1)*sizeof(ElType));
    MaxEl(*T)-= num;
}


void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    /*  KAMUS LOKAL */
    IdxType n;

    /*  ALGORITMA   */
    n = MaxEl(*T)-GetLastIdx(*T);
    if (n>0) ShrinkTab(T,n);
}
