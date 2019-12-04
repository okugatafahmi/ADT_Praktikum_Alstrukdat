/*  Nama        : Okugata Fahmi Nurul Y. F.
    NIM         : 13518031
    Tanggal     : 28/08/2019
    Deskripsi   : Realisasi fungsi/ prosedur pada jam.h
*/

#include "jam.h"
#include "boolean.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return ((H>=0) && (H<=23) && (M>=0) && (M<=59) && (S>=0) && (S<=59));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    // Kamus Lokal
    JAM res;

    // Algoritma
    Hour(res)=HH;
    Minute(res)=MM;
    Second(res)=SS;
    return res;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    // Kamus Lokal
    int h,m,s;

    // Algoritma
    do{
        scanf("%d %d %d",&h,&m,&s);
        if (!IsJAMValid(h,m,s)){    //jika tidak valid, munculkan pesan kesalahan
            printf("Jam tidak valid\n");
        }
    } while(!IsJAMValid(h,m,s)); 
    *J=MakeJAM(h,m,s);
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}
/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return 1L*(3600*Hour(J)+60*Minute(J)+Second(J));
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    // Kamus Lokal
    int h,m,s;

    // Algoritma
    if (N>=86400){
        N=N%(86400);
    }
    h=N/3600;
    N%=3600;
    m=N/60;
    N%=60;
    s=N;
    return MakeJAM(h,m,s);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return ((Hour(J1)==Hour(J2)) && (Minute(J1)==Minute(J2)) && (Second(J1)==Second(J2)));
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return !JEQ(J1,J2);
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    if (Hour(J1)==Hour(J2)){
        if (Minute(J1) == Minute(J2)){
            return (Second(J1)<Second(J2));
        }
        else{
            return (Minute(J1)<Minute(J2));
        }
    }
    else{
        return (Hour(J1)<Hour(J2));
    }
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
    if (Hour(J1)==Hour(J2)){
        if (Minute(J1) == Minute(J2)){
            return (Second(J1)>Second(J2));
        }
        else{
            return (Minute(J1)>Minute(J2));
        }
    }
    else{
        return (Hour(J1)>Hour(J2));
    }
}

JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    Second(J)++;
    if (Second(J)>59){
        Second(J)%=60;
        Minute(J)++;
        if (Minute(J)>59){
            Minute(J)%=60;
            Hour(J)++;
            if (Hour(J)>23) Hour(J)%=24;
        }
    }
    return J;
}

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    //menambahkan jam
    Hour(J)+=(N/3600);
    N%=3600;
    //menambahkan menit
    Minute(J)+=(N/60);
    N%=60;
    //menambahkan detik
    Second(J)+=N;

    if (Second(J)>59){
        Second(J)%=60;
        Minute(J)++;
    }
    if (Minute(J)>59){
        Minute(J)%=60;
        Hour(J)++;
    }
    if (Hour(J)>23) Hour(J)%=24;
    return J;
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    Second(J)--;
    if (Second(J)<0){
        Second(J)+=60;
        Minute(J)--;
        if (Minute(J)<0){
            Minute(J)+=60;
            Hour(J)--;
            if (Hour(J)<0) Hour(J)+=24;
        }
    }
    return J;
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
    // Kamus Lokal
    long detik=JAMToDetik(J)-N;
    
    // Algoritma
    while (detik<0){
        detik+=(24*3600);
    }
    return DetikToJAM(detik);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    // Kamus Lokal
    long dAw=JAMToDetik(JAw),dAkh=JAMToDetik(JAkh);

    // Algoritma
    if (dAw>dAkh){
        dAkh+=(24*3600);
    }
    return (dAkh-dAw);
}