/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 29/9/2019
   Topik    : ADT Mesinkata
*/


#include "mesinkata.h"
#include <stdio.h>

void Salin(Kata* dest, Kata src){
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
	/* Kamus Lokal*/
	int i;

	/* Algroitma */
	for (i=1; i<=src.Length; i++){
		dest->TabKata[i] = src.TabKata[i];
	}
	dest->Length = src.Length;
}

int HitungSamaKata(Kata a,Kata b){
	/* Kamus Lokal*/
	int i,j,cnt=0;

	/* Algroitma */
	
	if (a.Length <= b.Length){
		for (i=1; i<=b.Length; i++){
			if (a.TabKata[1]==b.TabKata[i]){
				j=1;
				while ((a.TabKata[j]==b.TabKata[i+j-1]) && (j<a.Length) && ((i+j-1)<b.Length)){
					j++;
				}
				if ((j==a.Length) && (a.TabKata[j]==b.TabKata[i+j-1])){
					cnt++;
				}
			}
		}
	}
	return cnt;
}

/*void CetakKata(Kata a){
	for (int i=1; i<=a.Length; i++){
		printf("%c", a.TabKata[i]);
	}
	printf("\n");
}*/


int main(){
	/* Kamus */
	int cnt=0;
	Kata pattern;

	/* Algroitma */
	STARTKATA();
	if (!EndKata){
		Salin(&pattern, CKata);
		//CetakKata(pattern);
		while (CC!=MARK){
			ADVKATA();
			//CetakKata(CKata);
			if (!EndKata) cnt += HitungSamaKata(pattern,CKata);
		}
	}
	
	printf("%d\n",cnt);
	return 0;
}
