/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 17/10/2019
   Topik    : ADT Stack
*/

#include "boolean.h"
#include "stackt.h"
#include <stdio.h>

void inputStack(Stack *s,int ns){
	/* Kamus Lokal */
	int i;
	infotype x;
	
	/* Algoritma */
	for (i=0;i<ns;i++){
		scanf("%d",&x);
		if ( (x==0) && (!IsEmpty(*s)) ) {
			Pop(s,&x);
		}
		else if ( (x!=0) && (!IsFull(*s)) ) {
			Push(s,x);
		}
	}
}
	
int main(){
	/* Kamus */
	Stack a,b;
	int na,nb,i;
	infotype x,y;
	boolean sama;
	
	/* Algoritma */
	CreateEmpty(&a);
	CreateEmpty(&b);
	
	scanf("%d %d",&na,&nb);
	if (na>0) inputStack(&a,na);
	if (nb>0) inputStack(&b,nb);
	
	sama=true;
	while ( (!IsEmpty(a)) && (!IsEmpty(b)) && sama ) {
		Pop(&a,&x);
		Pop(&b,&y);
		if (x!=y){
			//printf("%d %d\n",x,y);
			sama=false;
		}
	}
	
	if (sama && IsEmpty(a) && IsEmpty(b)) {
		printf("Sama\n");
	}
	else{
		printf("Tidak sama\n");
	}
	return 0;
}
