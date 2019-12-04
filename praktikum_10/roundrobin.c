/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 31/10/2019
   Topik    : Roundrobin dengan listsirkuler
*/

#include "listsirkuler.h"
#include <stdio.h>
#include "boolean.h"


void DeleteRR (List *L, infotype TQ){
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */	
	if (!IsEmpty(*L)){
		DelLast(L,&P);
		Next(P) = Nil;
		if (Info(P)<=TQ){
			printf("%d\n",Info(P));
			Dealokasi(P);
		}
		else{
			printf("%d\n",TQ);
			Info(P)-=TQ;
			InsertFirst(L,P);
		}
	}
	else{
		printf("List kosong\n");
	}
}

float Average (List L){
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
	/* Kamus Lokal */
	address P;
	float sum=0,n=0;
	
	/* Algoritma */	
	while (!IsEmpty(L)){
		DelFirst(&L,&P);
		sum += Info(P);
		n+=1;
		Dealokasi(P);
	}
	return ((float)sum/(float)n);
}

int main(){
		/* Kamus */
		int tq,t;
		char c;
		List l;
		
		/* Algoritma */
		scanf("%d",&tq);
		while(tq<=0){
			scanf("%d",&tq);
		}
		
		CreateEmpty(&l);
		scanf(" %c",&c);
		while (c!='F'){
			if (c=='A'){
				scanf("%d",&t);
				if (t>0) InsVFirst(&l,t);
			}
			else if (c=='D'){
				//PrintInfo(l);
				DeleteRR(&l,tq);
			}
			else{
				printf("Kode salah\n");
			}
			scanf(" %c",&c);
		}
		
		if (IsEmpty(l)){
			printf("Proses selesai\n");
		}
		else{
			//PrintInfo(l);
			printf("%.2f\n",Average(l));
		}
		return 0;
}
