/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 24/10/2019
   Topik    : ADT List Linier
*/

#include "listlinier.h"
#include <stdio.h>

int main(){
	/* Kamus */
	int n,q,x,i;
	List l;
	address P,Prec;
	boolean found;
	
	/* Algoritma */
	scanf("%d",&n);
	CreateEmpty(&l);
	for (i=1;i<=n;i++){
		InsVLast(&l,i);
	}
	
	scanf("%d",&q);
	for (i=0;i<q;i++){
		scanf("%d",&x);
		
		P=First(l); Prec=Nil;
		found=false;
		while ((P!=Nil) && (!found)){
			if (Info(P)==x){
				found = true;
			}
			else{
				Prec=P;
				P=Next(P);
			}
		}
		if (!found){
			InsVFirst(&l,x);
			DelVLast(&l,&x);
			printf("miss");
		}
		else{
			if (P!=First(l)){
				Next(Prec)=Next(P);
				Next(P)=First(l);
				First(l)=P;
			}
			printf("hit");
		}
		printf(" ");
		PrintInfo(l);
		printf("\n");
	}
}
