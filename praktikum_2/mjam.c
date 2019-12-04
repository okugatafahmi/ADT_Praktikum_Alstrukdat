/* Nama		: Okugata Fahmi Nurul Y. F.
 * NIM		: 13518031
 * Tanggal	: 31/08/2019
 * Deskripsi: Membaca n pasang jam kemudian menuliskan durasinya. Setelah itu, keluarkan jam minimum
 * 			  dan maksimum
 */

#include "jam.h"
#include <stdio.h>

int main(){
	// KAMUS
	JAM j1,j2,temp,min,maks; // untuk menampung jam
	int n,i; // n: banyak data telepon, i: untuk iterasi
	
	// ALGORITMA
	scanf("%d",&n);
	
	min=MakeJAM(23,59,59);
	maks=MakeJAM(0,0,0);
	for (i=0;i<n;i++){
		printf("[%d]\n",(i+1));
		BacaJAM(&j1);
		BacaJAM(&j2);
		if (JGT(j1,j2)){
			temp=j1;
			j1=j2;
			j2=temp;
		}
		if (JLT(j1,min)) min=j1;
		if (JGT(j2,maks)) maks=j2;
		printf("%ld\n",Durasi(j1,j2));
	}
	
	// Penulisan Akhir
	TulisJAM(min);
	printf("\n");
	TulisJAM(maks);
	printf("\n");
	return 0;
}
