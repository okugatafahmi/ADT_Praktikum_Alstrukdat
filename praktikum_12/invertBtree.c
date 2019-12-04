/* Nama     : Okugata Fahmi N. Y. F.
   NIM      : 13518031
   Tanggal  : 14/11/2019
   Topik    : ADT Binary Tree
*/

#include "bintree.h"

void InvertBtree(BinTree *P){
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
	/* Kamus Lokal */
	addrNode temp;
	
	/* Algoritma */
	if (!IsTreeEmpty(*P)){
		temp = Left(*P);
		Left(*P) = Right(*P);
		Right(*P) = temp;
		InvertBtree(&Left(*P));
		InvertBtree(&Right(*P));
	}
}
