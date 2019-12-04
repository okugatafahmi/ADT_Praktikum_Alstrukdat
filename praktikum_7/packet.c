/*  Nama    : Okugata Fahmi Nurul Y. F.
    NIM     : 13518031
    Tanggal : 3/10/2019
    Topik   : ADT Priority Queue
    Deskripsi: Penggunaan priority queue
*/

#include "prioqueuechar.h"
#include <stdio.h>

int main(){
	/* Kamus Lokal */
    PrioQueueChar q;
    infotype x;
    int n,i,j,detikMin,num,detikMaks;
    
    /* Algoritma */
    scanf("%d",&n);
    
    CreateEmpty(&q,n);
    detikMin = 1;
    num = 1;
    for (i=0; i<n; i++){
		scanf("%d %c",&Prio(x),&Info(x));
		Add(&q,x);
		
		//printf("%d %d\n",detikMin,detikMaks);
		if (Prio(x)==detikMin){
			for (j = Head(q); Prio(Elmt(q,j))==num; j=(j%MaxEl(q))+1){
				Del(&q,&x);
				printf("%d %c\n",(i+1),Info(Elmt(q,j)));
				num+=1;
			}
			detikMin = num;
		}
	}
	
	return 0;
}
