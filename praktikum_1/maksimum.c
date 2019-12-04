/* Nama 	: Okugata Fahmi Nurul Y. F.
 * NIM		: 13518031
 * Tanggal	: 28 Agustus 2019
 * Deskripsi: mencari maksimum dari 3 buah integer
 */

#include<stdio.h>

int main(){
	//Kamus
	int a,b,c,res;
	
	//Algoritma
	scanf("%d %d %d",&a,&b,&c);
	if (a>b){
		if (a>c){
			res=a;
		}
		else{
			res=c;
		}
	}
	else{
		if (b>c){
			res=b;
		}
		else{
			res=c;
		}
	}
	printf("%d\n",res);
	return 0;
}
