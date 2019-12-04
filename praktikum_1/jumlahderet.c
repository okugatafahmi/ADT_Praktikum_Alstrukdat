/* Nama 	: Okugata Fahmi Nurul Y. F.
 * NIM		: 13518031
 * Tanggal	: 28 Agustus 2019
 * Deskripsi: Menjumlahkan bilangan dari 1 sampai n
 */

#include<stdio.h>

int main(){
	//Kamus
	int i,n,res;
	
	//Algoritma
	scanf("%d",&n);
	res=0;
	for (i=1;i<=n;i++){
		res+=i;
	}
	printf("%d\n",res);
	return 0;
}
