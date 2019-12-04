/*  Nama        : Okugata Fahmi Nurul Y. F. */
/*  NIM         : 13518031                  */
/*  Tanggal     : 4/9/2019                  */
/*  Deskripsi   : Realisasi array.h */

/* MODUL TABEL INTEGER */
/* Berisi realisasi pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "array.h"
#include <stdio.h>

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff((*T))=0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T);
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmt(T)==0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T)==IdxMax);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    // KAMUS LOKAL
    int n;
    IdxType i;

    // ALGORITMA
    do{
        scanf("%d",&n);
    } while(!((n>=0) && (n<=MaxNbEl(*T))));

    if (n>0){
        Neff(*T)=n;
        for (i=IdxMin;i<=n;i++){
            scanf("%d",&Elmt((*T),i));
        }
    }
    else{
        MakeEmpty(T);
    }
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    /* KAMUS LOKAL */
    ElType el;

    /*   ALGORITMA   */
    MakeEmpty(T);
    do{
        scanf("%d",&el);
        if (el!=-9999){
            Neff(*T)++;
            Elmt(*T,(Neff(*T)))=el;
        }
    } while((el!=-9999) && (Neff(*T)<IdxMax));
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T)){
        for (i=IdxMin;i<=Neff(T);i++){
            printf("[%d]%d\n",i,Elmt(T,i));
        }
    }
    else{
        printf("Tabel kosong\n");
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    printf("[");
    if (Neff(T)){
        for (i=IdxMin;i<Neff(T);i++){
            printf("%d,",Elmt(T,i));
        }
        printf("%d",Elmt(T,Neff(T)));
    }
    printf("]");
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    for (i=IdxMin;i<=Neff(T1);i++){
        Elmt(T1,i)+=Elmt(T2,i);
    }
    return T1;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    for (i=IdxMin;i<=Neff(T1);i++){
        Elmt(T1,i)-=Elmt(T2,i);
    }
    return T1;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    for (i=IdxMin;i<=Neff(T1);i++){
        Elmt(T1,i)*=Elmt(T2,i);
    }
    return T1;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    for (i=IdxMin;i<=Neff(Tin);i++){
        Elmt(Tin,i)*=c;
    }
    return Tin;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T1)==Neff(T2)){
        i=IdxMin;
        while ((i<Neff(T1)) && (Elmt(T1,i)==Elmt(T2,i))){
            i++;
        }
        return (Elmt(T1,i)==Elmt(T2,i));
    }
    else
    {
        return false;
    }
    
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    i=IdxMin;
    while ((i<Neff(T1)) && (Elmt(T1,i)==Elmt(T2,i)) ){
        i++;
    }

    if (Elmt(T1,i)==Elmt(T2,i)){
        return (Neff(T1)<Neff(T2));
    }
    else {
        return (Elmt(T1,i)<Elmt(T2,i));
    }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T)){
        i=IdxMin;
        while ((i<Neff(T)) && (Elmt(T,i)!=X)){
            i++;
        }
        return ((Elmt(T,i)==X)? i:IdxUndef );
    }
    else
    {
        return IdxUndef;
    }
    
    
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    /* KAMUS LOKAL  */
    boolean Found;
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T)){
        Found=false;
        i=IdxMin;
        while ((i<=Neff(T)) && (!Found)){
            if (Elmt(T,i)==X){
                Found=true;
            }
            else{
                i++;
            }
        }
        return ((Found)? i:IdxUndef);
    }
    else{
        return IdxUndef;
    }
   
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    /* KAMUS LOKAL  */
    boolean Found;
    IdxType i;

    /*  ALGORITMA   */
    Found=false;
    if (Neff(T)){
        i=IdxMin;
        while ((i<=Neff(T)) && (!Found)){
            if (Elmt(T,i)==X){
                Found=true;
            }
            else{
                i++;
            }
        }
    }
    return Found;
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
    /* KAMUS LOKAL  */
    IdxType i;

    /*  ALGORITMA   */
    i=Neff(T);
    Elmt(T,(IdxMin-1))=X;
    while (Elmt(T,i)!=X){
        i--;
    }
    return (i>0);
}


/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    /*  KAMUS LOKAL */
    IdxType i;
    ElType maks;

    /*  ALGORITMA   */
    maks=Elmt(T,IdxMin);
    i=IdxMin+1;
    while (i<=Neff(T)){
        if (Elmt(T,i)>maks){
            maks=Elmt(T,i);
        }
        i++;
    }
    return maks;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    /*  KAMUS LOKAL */
    IdxType i;
    ElType mini;

    /*  ALGORITMA   */
    mini=Elmt(T,IdxMin);
    i=IdxMin+1;
    while (i<=Neff(T)){
        if (Elmt(T,i)<mini){
            mini=Elmt(T,i);
        }
        i++;
    }
    return mini;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    /*  KAMUS LOKAL */
    IdxType i,idx;

    /*  ALGORITMA   */
    idx=IdxMin;
    i=IdxMin+1;
    while (i<=Neff(T)){
        if (Elmt(T,i)>Elmt(T,idx)){
            idx=i;
        }
        i++;
    }
    return idx;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    /*  KAMUS LOKAL */
    IdxType i,idx;

    /*  ALGORITMA   */
    idx=IdxMin;
    i=IdxMin+1;
    while (i<=Neff(T)){
        if (Elmt(T,i)<Elmt(T,idx)){
            idx=i;
        }
        i++;
    }
    return idx;
}


/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    Neff((*Tout))=Neff(Tin);
    for (i=IdxMin;i<=Neff(Tin);i++){
        Elmt((*Tout),i)=Elmt(Tin,i);
    }
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    /*  KAMUS LOKAL */
    IdxType i,idx;
    TabInt temp;

    /*  ALGORITMA   */
    if (Neff(T)){
        for (i=IdxMin;i<=Neff(T);i++){
            Elmt(temp,i)=Elmt(T,(Neff(T)-i+1));
        }
        Neff(temp)=Neff(T);
        return temp;
    }
    else{
        return T;
    }
}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T)){
        i=IdxMin;
        while ((i<((Neff(T)+IdxMin)/2)) && (Elmt(T,i)==Elmt(T,(Neff(T)-i+1))) ){
            i++;
        }
        return (Elmt(T,i)==Elmt(T,(Neff(T)-i+1)));
    }
    else{
        return true;
    }
}


/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    /*  KAMUS LOKAL */
    IdxType i,j,idx;
    ElType temp;

    /*  ALGORITMA   */
    for (i=IdxMin;i<Neff(*T);i++){
        idx=i;
        for (j=i;j<=Neff(*T);j++){
            if (Elmt(*T,j)>Elmt(*T,idx)){
                idx=j;
            }
        }
        if (idx!=i){
            temp=Elmt(*T,idx);
            Elmt(*T,idx)=Elmt(*T,i);
            Elmt(*T,i)=temp;
        }
    }
}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    /*  KAMUS LOKAL */
    IdxType i,j;
    ElType temp;

    /*  ALGORITMA   */
    for (i=IdxMin+1;i<=Neff(*T);i++){
        temp=Elmt((*T),i);
        j=i-1;
        while ((j>=IdxMin) && (Elmt(*T,j)>temp)){
            Elmt(*T,(j+1))=Elmt(*T,j);
            j--;
        }
        Elmt(*T,(j+1))=temp;
    }
}


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    /*  ALGORITMA   */
    Neff(*T)++;
    Elmt(*T,Neff(*T))=X;
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    /*  KAMUS LOKAL */
    IdxType idx;

    /*  ALGORITMA   */
    Neff(*T)++;
    idx=Neff(*T);
    while (idx>i){
        Elmt(*T,idx)=Elmt(*T,(idx-1));
        idx--;
    }
    Elmt(*T,idx)=X;
}


/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    /*  ALGORITMA   */
    *X = Elmt(*T,Neff(*T));
    Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    /*  KAMUS LOKAL */
    IdxType idx;

    /*  ALGORITMA   */
    *X = Elmt(*T,i);
    for (idx=i;idx<Neff(*T);idx++){
        Elmt(*T,idx)=Elmt(*T,(idx+1));
    }
    Neff(*T)--;
}


/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    i=Neff(*T);
    Elmt(*T,(IdxMin-1))=X;
    while (Elmt(*T,i)!=X){
        i--;
    }
    if (i==(IdxMin-1)){
        Neff(*T)++;
        Elmt(*T,Neff(*T))=X;
    }
    else{
        printf("nilai sudah ada\n");
    }
}


/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    /*  KAMUS LOKAL */
    IdxType i;

    /*  ALGORITMA   */
    if (Neff(T)){
        i=IdxMin;
        while ((Elmt(T,i)<X) && (i<Neff(T))){
            i++;
        }
        return ((Elmt(T,i)==X)? i:IdxUndef);
    }
    else{
        return IdxUndef;
    }
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return (Elmt(T,Neff(T)));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return (Elmt(T,IdxMin));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    /*  KAMUS LOKAL */
    IdxType i;    

    /*  ALGORITMA   */
    if ((!IsEmpty(*T)) && (!IsFull(*T))){
        i=IdxMin;
        while ((i<=Neff(*T)) && (Elmt(*T,i)<X)){
            i++;
        }
        if (i<=Neff(*T)){
            AddEli(T,X,i);
        }
        else{
            AddAsLastEl(T,X);
        }
    }
    else if (IsEmpty(*T)){
        Neff(*T)++;
        Elmt(*T,IdxMin)=X;
    }
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    /*  KAMUS LOKAL */
    IdxType i;    

    /*  ALGORITMA   */
    i=IdxMin;
    while ((i<Neff(*T)) && (Elmt(*T,i)!=X)){
        i++;
    }
    if (Elmt(*T,i)==X){
        ((i==GetLastIdx(*T))? DelLastEl(T,&X):DelEli(T,i,&X));
    }
}