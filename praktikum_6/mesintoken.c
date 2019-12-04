/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 29/9/2019
   Topik    : ADT Mesintoken
*/


/* File: mesintoken.c */
/* Implementasi Mesin Token: Model Akuisisi Versi I */

#include "mesintoken.h"


/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
  /* Kamus Lokal */


  /* Algoritma */
  while ((CC==BLANK) && (CC!=MARK)){
    ADV();
  }
}

void STARTTOKEN(){
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
  /* Kamus Lokal */
  

  /* Algoritma */
  START();
  IgnoreBlank();
  if (CC==MARK){
    EndToken = true;
  }
  else{
    EndToken = false;
    SalinToken();
  }
}

void ADVTOKEN(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  /* Kamus Lokal */
  

  /* Algoritma */
  IgnoreBlank();
  if (CC==MARK){
    EndToken = true;
  }
  else{
    SalinToken();
  }
  IgnoreBlank();
}


void SalinToken(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	/* Kamus Lokal */
	int res=0;
	char op;

	/* Algoritma */
	while ((CC!= MARK) && (CC!= BLANK)){
		if ((CC>='0') && (CC<='9')){
			res = res*10 + ((int) (CC-'0'));
		}
		else if ((CC!=MARK) || (CC!=BLANK)){
			res = -1;
			op = CC;
		}
		ADV();
    }
    IgnoreBlank();
    if (res==-1){
		CToken.tkn = op;
		CToken.val = -1;
	}
	else{
		CToken.tkn = 'b';
		CToken.val = res;
	}
}
