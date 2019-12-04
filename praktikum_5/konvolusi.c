/*  Nama        : Okugata Fahmi Nurul Y. F.
    NIM         : 13518031
    Tanggal     : 19/9/2019
    Topik       : ADT Matriks
    Deskripsi   : Konvolusi Matriks
*/

#include "matriks.h"
#include <stdio.h>

int main(){
	/*	KAMUS	*/
	MATRIKS a,b,c;
	int n,m,k;
	indeks i,j,mid,kiri,kanan,atas,bawah,row,col;
	
	/*	ALGORITMA	*/
	//input
	scanf("%d %d",&n,&m);
	BacaMATRIKS(&a,n,m);
	scanf("%d",&k);
	BacaMATRIKS(&b,k,k);
	
	//operasi
	mid = (NBrsEff(b)+1)/2;
	MakeMATRIKS(NBrsEff(a),NKolEff(a),&c);
	
	for (i=GetFirstIdxBrs(a); i<=GetLastIdxBrs(a); i++){
		for (j=GetFirstIdxKol(a); j<=GetLastIdxKol(a); j++){
			Elmt(c,i,j) = 0;
			
			kiri=mid-(j-GetFirstIdxKol(a));
			kanan = mid+(GetLastIdxKol(a)-j);
			if (kiri<GetFirstIdxKol(b)) kiri=GetFirstIdxKol(b);
			if (kanan>GetLastIdxKol(b)) kanan=GetLastIdxKol(b);
			
			atas=mid-(i-GetFirstIdxBrs(a));
			bawah = mid+(GetLastIdxBrs(a)-i);
			if (atas<GetFirstIdxBrs(b)) atas=GetFirstIdxBrs(b);
			if (bawah>GetLastIdxBrs(b)) bawah=GetLastIdxBrs(b);
			//printf("%d %d %d %d",kiri,kanan,atas,bawah);
			
			for (row=atas; row<=bawah; row++){
				for (col=kiri; col<=kanan; col++){
					Elmt(c,i,j) += (Elmt(b,row,col)*Elmt(a,(i-(mid-row)),(j-(mid-col))));
				}
			}
		}
		//printf("\n");
	}
	
	TulisMATRIKS(c);
}
/*2 3
1 2 3
4 5 6
3
1 2 -3
1 -2 1
-1 1 2*/
    