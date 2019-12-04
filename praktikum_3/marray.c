/*	Nama		: Okugata Fahmi Nurul Y. F.
 * 	NIM			: 13518031
 * 	Tanggal		: 9/9/2019
 * 	Topik		: ADT Array
 * 	Desktripsi	: Melakukan operasi array
 */
 
#include <stdio.h>
#include "array.h"

int main(){
	 /*	KAMUS	*/
	 TabInt t,temp;
	 IdxType i,idx;
	 ElType x;
	 int cnt;
	 
	 /*	ALGORITMA	*/
	 // input
	 BacaIsi(&t);
	 //output
	 TulisIsiTab(t);
	 printf("\n");
	 
	 scanf("%d",&x);
	 // sort
	 temp=t;
	 InsSortAsc(&t);
	 idx=Search1(t,x);
	 cnt=0;
	 if (idx!=IdxUndef){
		 i=idx;
		 while (Elmt(t,i)==x){
			 i++;
			 cnt++;
		 }
	 }
	 printf("%d\n",cnt);
	 if (idx!=IdxUndef){
		 idx=Search1(temp,x);
		 printf("%d\n",idx);
	 }
	 else{
		 printf("%d tidak ada\n",x);
	 }
	 
	 if (ValMax(t)==x){
		 printf("maksimum\n");
	 }
	 if (ValMin(t)==x){
		 printf("minimum\n");
	 }
	 if (Elmt(t,((IdxMin+Neff(t))/2))==x){
		 printf("median\n");
	 }
	 return 0;
}
