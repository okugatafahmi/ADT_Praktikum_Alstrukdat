/* Nama     : Okugata Fahmi Nurul Y. F.
   NIM      : 13518031
   Tanggal  : 17/10/2019
   Topik    : ADT Stack
*/

#include "boolean.h"
#include "stackt.h"
#include "mesintoken.h"
#include <math.h>
#include <stdio.h>

void Tambah(Stack *s,int x){
	/* Kamus Lokal */
	
	/* Algoritma */
	Push(s,x);
	printf("%d\n",x);
}

int Op(int a,int b,char c){
	switch(c){
		case '+':
		return (a+b);
		
		case '-':
		return (a-b);
		
		case '*':
		return (a*b);
		
		case '/':
		return (a/b);
		
		case '^':
		return pow(a,b);
	}
}

int main(){
	/* Kamus */
	Stack s;
	boolean sudah=false;
	int res,a,b;
	
	/* Algoritma */
	CreateEmpty(&s);
	STARTTOKEN();
	if (!EndToken){
		sudah = true;
		Tambah(&s,CToken.val);
		
		ADVTOKEN();
		while (!EndToken){
			if (CToken.tkn=='b'){
				Tambah(&s,CToken.val);
			}
			else{
				Pop(&s,&b);
				Pop(&s,&a);
				printf("%d %c %d\n",a,CToken.tkn,b);
				res = Op(a,b,CToken.tkn);
				printf("%d\n",res);
				Push(&s,res);
			}
			ADVTOKEN();
		}
	}
	
	if (!sudah){
		printf("Ekspresi kosong\n");
	}
	else{
		printf("Hasil=%d\n",res);
	}
	return 0;
}

