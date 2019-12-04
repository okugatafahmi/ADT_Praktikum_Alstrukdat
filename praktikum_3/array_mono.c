/*	Nama	: Okugata Fahmi Nurul Y. F.
 * 	NIM			: 13518031
 * 	Tanggal		: 9/9/2019
 * 	Topik		: ADT Array
 * 	Desktripsi	: Melakukan operasi array
 */
 
#include <stdio.h>
#include "array.h"

int main(){
	 /*	KAMUS	*/
	 TabInt t,asc,des;
	 IdxType i;
	 
	 /*	ALGORITMA	*/
	 // input
	 BacaIsi(&t);
	 
	 i=IdxMin;
	 while ((Elmt(t,i)==Elmt(t,IdxMin)) && (i<Neff(t))) {
		i++;
	 }
	 if (Elmt(t,i)==Elmt(t,IdxMin)){
		printf("Array monotonik statik\n");
	 }
	 else{
		asc=t;
		des=t;
		MaxSortDesc(&des);
		InsSortAsc(&asc);
	 
		if (IsEQ(t,asc)){
			printf("Array monotonik tidak mengecil\n");
		}
		else if (IsEQ(t,des)){
			printf("Array monotonik tidak membesar\n");
		}
		else{
			printf("Array tidak monotonik\n");
		}
	}
	 return 0;
}
