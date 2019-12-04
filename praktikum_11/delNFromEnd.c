/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 7/11/2019
   Topik    : ADT List Rekursif
*/

#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>

void urutan(List *L,int n,int *i,int *total){
	if (!IsEmpty(*L)){
		int i_sblm=(*i);
		List P = Tail(*L);
		(*i)++;
		(*total)++;
		// printf("%d %d %d\n",i_sblm,*i,*total);
		urutan(&P,n,i,total);
		// printf("%d %d %d\n",i_sblm,*i,*total);
		if ((*total)-i_sblm==n+1){ // elemen sblm yg dihapus
			SetNext((*L),Next(P));
			// Next(*L) = Next(P);
			// printf("%d\n",*i);
			Dealokasi(P);
		}
	}
}

List delNFromEnd(List L, int n){
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
	/* Kamus Lokal */
	int i = 0, total = 0;
	List P;

	/* Algoritma */
	urutan(&L,n,&i,&total);
	if (n==total){
		P = Tail(L);
		Dealokasi(L);
		return P;
	}
	else{
		return L;
	}
}

// int main(){
// 	int n,x;
// 	List l;
// 	scanf("%d",&n);
// 	l = Nil;
// 	for (int i=0;i<n;i++){
// 		scanf("%d",&x);
// 		l = KonsB(l,x);
// 	}

// 	scanf("%d",&n);
// 	l = delNFromEnd(l,n);
// 	PrintList(l);
// }