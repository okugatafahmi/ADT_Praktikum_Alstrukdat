/*  Nama        : Okugata Fahmi Nurul Y. F.
    NIM         : 13518031
    Tanggal     : 15/9/2019
    Topik       : ADT Array Dinamis
    Deskripsi   : Operasi pada array dinamis
*/

#include "arraydin.h"
#include <stdio.h>
#include "boolean.h"

void pilih(int op,TabInt *t){
	/*	KAMUS	*/
	int num;
	boolean cetak;
	
	/* ALGORIMTA	*/
	cetak=true;
	switch(op){
		case 1:
		scanf("%d",&num);
		if (IsFull(*t)){
			printf("array sudah penuh\n");
			cetak=false;
		}
		else{
			AddAsLastEl(t,num);
		}
		break;
		
		case 2:
		scanf("%d",&num);
		GrowTab(t,num);
		break;
		
		case 3:
		scanf("%d",&num);
		if ((MaxEl(*t)-num)<0){
			printf("array terlalu kecil\n");
			cetak=false;
		}
		else{
			ShrinkTab(t,num);
		}
		break;
		
		case 4:
		CompactTab(t);
		break;
	}
	
	if (cetak){
		printf("%d ",MaxEl(*t));
		TulisIsiTab(*t);
		printf("\n");
	}
}

int main(){
	/*	KAMUS	*/
	TabInt t;
	int maxel,n,i,q,op;

	/*	ALGORITMA	*/
	scanf("%d",&maxel);
	MakeEmpty(&t,maxel);
	BacaIsi(&t);
	
	//input q
	scanf("%d",&q);
	for (i=0;i<q;i++){
		scanf("%d",&op);
		pilih(op,&t);
	}
	return 0;
}
