/*  Nama        : Okugata Fahmi Nurul Y. F.
    NIM         : 13518031
    Tanggal     : 19/9/2019
    Topik       : ADT Matriks
    Deskripsi   : Realisasi ADT Matriks
*/

#include "matriks.h"
#include <stdio.h>


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M,i,i);
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    /*  KAMUS LOKAL  */
    indeks i,j;

    /*  ALGORITMA   */
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
        for (j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    /*  KAMUS LOKAL  */
    indeks i,j;

    /*  ALGORITMA   */
    MakeMATRIKS(NB,NK,M);
    for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            scanf("%d",&Elmt(*M,i,j));
        }
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /*  KAMUS LOKAL  */
    indeks i,j;

    /*  ALGORITMA   */
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for (j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
            printf("%d ",Elmt(M,i,j));
        }
        printf("%d",Elmt(M,i,GetLastIdxKol(M)));
        if (i<GetLastIdxKol(M)) printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    /*  KAMUS LOKAL  */
    MATRIKS MHsl;
    indeks i,j;

    /*  ALGORITMA   */
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
    for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
        for (j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
            Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return MHsl;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    /*  KAMUS LOKAL  */
    MATRIKS MHsl;
    indeks i,j;

    /*  ALGORITMA   */
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
    for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
        for (j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
            Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return MHsl;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    /*  KAMUS LOKAL  */
    MATRIKS MHsl;
    indeks i,j,k;

    /*  ALGORITMA   */
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MHsl);
    for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
        for (k=GetFirstIdxKol(MHsl);k<=GetLastIdxKol(MHsl);k++){
            Elmt(MHsl,i,k) = 0;
            for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
                Elmt(MHsl,i,k) += (Elmt(M1,i,j) * Elmt(M2,j,k));
            }
        }
    }
    return MHsl;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    /*  KAMUS LOKAL  */
    MATRIKS MHsl;
    indeks i,j;

    /*  ALGORITMA   */
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHsl);
    for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
        for (j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
            Elmt(MHsl,i,j) = X * Elmt(M,i,j);
        }
    }
    return MHsl;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    /*  KAMUS LOKAL  */
    indeks i,j;

    /*  ALGORITMA   */
    for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            Elmt(*M,i,j) *= K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    /*  KAMUS LOKAL  */
    indeks i,j;
    boolean sama;

    /*  ALGORITMA   */
    if ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2))){
        i=GetFirstIdxBrs(M1);
        j=GetFirstIdxKol(M1);
        sama=true;
        while ((i<=GetLastIdxBrs(M1)) && sama){
            while ((j<GetLastIdxKol(M1)) && (Elmt(M1,i,j)==Elmt(M2,i,j))){
                j++;
            }
            sama = (Elmt(M1,i,j)==Elmt(M2,i,j));
            if (sama) i++;
        }
        return sama;
    }
    else return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return (!EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}


/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M)*NKolEff(M));
}


/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    /*  KAMUS LOKAL  */
    indeks i,j;
    boolean sama;

    /*  ALGORITMA   */
    if (IsBujurSangkar(M)){
        i=GetFirstIdxBrs(M);
        j=GetFirstIdxKol(M);
        sama=true;
        while ((i<=GetLastIdxBrs(M)) && sama){
            while ((j<GetLastIdxKol(M)) && (Elmt(M,i,j)==Elmt(M,j,i))){
                j++;
            }
            sama = (Elmt(M,i,j)==Elmt(M,j,i));
            if (sama) i++;
        }
        return sama;
    }
    else return false;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    /*  KAMUS LOKAL  */
    indeks i,j;
    boolean sama;

    /*  ALGORITMA   */
    if (IsBujurSangkar(M)){
        i=GetFirstIdxBrs(M);
        j=GetFirstIdxKol(M);
        sama=true;
        while ((i<=GetLastIdxBrs(M)) && sama){
            while ((j<GetLastIdxKol(M)) && sama){
                sama=(Elmt(M,i,j)==((i==j)?1:0));
                if (sama) j++;
            }
            sama=(Elmt(M,i,j)==((i==j)?1:0));
            if (sama) i++;
        }
        return sama;
    }
    else return false;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /*  KAMUS LOKAL  */
    indeks i,j;
    int cnt;

    /*  ALGORITMA   */
    cnt = 0;
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            if (Elmt(M,i,j)!=0) cnt++;
        }
    }
    return (((float)cnt/(float)NBElmt(M))<=(5.0/100.0));
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return KaliKons(M,(-1));
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    /*  KAMUS LOKAL */  
    indeks i,j,k,r,c;
    float res;
    MATRIKS temp;

    /*  ALGORITMA   */
    if (NBrsEff(M)==1){
        return Elmt(M,1,1);
    }
    else{
        res=0.0;
        MakeMATRIKS((NBrsEff(M)-1),(NKolEff(M)-1),&temp);
        for (k=GetFirstIdxKol(M);k<=GetLastIdxKol(M);k++){
            if (Elmt(M,1,k)!=0){
                r=BrsMin;
                for (i=(GetFirstIdxBrs(M)+1);i<=GetLastIdxBrs(M);i++){
                    c=KolMin;
                    for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
                        if (j!=k){
                            Elmt(temp,r,c) = Elmt(M,i,j);
                            c++;
                        }
                    }
                    r++;
                }
                res += Determinan(temp)*(((1+k)%2==0)?1:-1)*Elmt(M,1,k);
            }
        }
        return res;
    }
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    *M = Inverse1(*M);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    /*  KAMUS LOKAL  */
    indeks i,j;
    ElType temp;
    int tem;

    /*  ALGORITMA   */
    for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for (j=i;j<=GetLastIdxKol(*M);j++){
            temp = Elmt(*M,i,j);
            Elmt(*M,i,j) = Elmt(*M,j,i);
            Elmt(*M,j,i) = temp;
        }
    }
    tem = NBrsEff(*M);
    NBrsEff(*M) = NKolEff(*M);
    NKolEff(*M) = tem;
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    /*  KAMUS LOKAL   */
    float res;
    indeks j;

    /*  ALGORITMA   */
    res=0;
    for (j = KolMin; j<=GetLastIdxKol(M); j++){
        res+=Elmt(M,i,j);
    }
    return (res/NKolEff(M));
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	/*  KAMUS LOKAL   */
    float res;
    indeks i;

    /*  ALGORITMA   */
    res=0;
    for (i = BrsMin; i<=GetLastIdxBrs(M); i++){
        res+=Elmt(M,i,j);
    }
    return (res/NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	/*  KAMUS LOKAL   */
    indeks j;

    /*  ALGORITMA   */
    *max = Elmt(M,i,GetFirstIdxKol(M));
    *min = Elmt(M,i,GetFirstIdxKol(M));
    for (j = KolMin+1; j<=GetLastIdxKol(M); j++){
        if (Elmt(M,i,j) > *max) *max = Elmt(M,i,j);
        if (Elmt(M,i,j) < *min) *min = Elmt(M,i,j);
    }
    
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	/*  KAMUS LOKAL   */
    indeks i;

    /*  ALGORITMA   */
    *max = Elmt(M,GetFirstIdxBrs(M),j);
    *min = Elmt(M,GetFirstIdxBrs(M),j);
    for (i = BrsMin+1; i<=GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) > *max) *max = Elmt(M,i,j);
        if (Elmt(M,i,j) < *min) *min = Elmt(M,i,j);
    }
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	/*  KAMUS LOKAL   */
    indeks j;
    int cnt;

    /*  ALGORITMA   */
    cnt = 0;
    for (j = KolMin; j<=GetLastIdxKol(M); j++){
        if (Elmt(M,i,j) == X) cnt++;
    }
    return cnt;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	/*  KAMUS LOKAL   */
    indeks i;
    int cnt;

    /*  ALGORITMA   */
    cnt = 0;
    for (i = BrsMin; i<=GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j) == X) cnt++;
    }
    return cnt;
}
