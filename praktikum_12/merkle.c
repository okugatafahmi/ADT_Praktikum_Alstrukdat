/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 14/11/2019
   Topik    : ADT Binary Tree
*/

#include "bintree.h"
#include <math.h>
#include <stdio.h>

/* Kamus Global */
List l;
int level,nNode;

infotype ListId(List L, int id){
	if (id==1){
		return Info(L);
	}
	else{
		return ListId(Tail(L),id-1);
	}
}

void BuildMerkleTree(BinTree *P, int level_now, int id){
	if (level_now==level){
		*P = AlokNode(ListId(l,nNode-id+1));
	}
	else{
		*P = AlokNode(0);
		BuildMerkleTree(&Left(*P),level_now+1,id<<1);
		BuildMerkleTree(&Right(*P),level_now+1,(id<<1)+1);
		Akar(*P) = Akar(Left(*P)) + Akar(Right(*P));
	}
}

int main(){
	/* Kamus */
	int n,i,x;
	BinTree p;
	
	/* Algoritma */
	scanf("%d",&n);
	if (n==0){
		printf("Jumlah masukan tidak sesuai\n");
		return 0;
	}
	level = (int) log2(n)+1;
	if ((int) pow(2,(level-1)) != n){
		printf("Jumlah masukan tidak sesuai\n");
	}
	else{
		l = Nil;
		for (i=0; i<n; i++){
			scanf("%d",&x);
			l = Konso(x,l);
		}
		p = Nil;
		nNode = (int) pow(2,level)-1;
		BuildMerkleTree(&p,1,1);
		PrintTree(p,2);
	}
	return 0;
}
