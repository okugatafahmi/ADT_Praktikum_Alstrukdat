/* Nama 	: Okugata Fahmi Nurul Y. F.
 * NIM		: 13518031
 * Tanggal	: 28 Agustus 2019
 * Deskripsi: Mengkonversi suhu
 */

#include<stdio.h>

int main(){
	//Kamus
	float t,res;
	char kode;	
	
	//Algoritma
	scanf("%f %c",&t,&kode);
	if (kode=='R'){
		res=(float)4/(float)5*t;
	}
	else if (kode=='F'){
		res=((float)9/(float)5*t)+32;
	}
	else {//kode=='K'
		res=t+273.15;
	}
	printf("%0.2f\n",res);
	return 0;
}
