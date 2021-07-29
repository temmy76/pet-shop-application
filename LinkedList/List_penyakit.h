#ifndef List_penyakit_H
#define List_penyakit_H

// #include "bool.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define Nil  NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

typedef struct {
  char nama[35];
  char kategori[35];
}infotype;
typedef struct tElmtlist *address;
typedef struct  tElmtlist{
	infotype info;
	address next;
}ElmtList;
/* Definisi  List                   */
/* List Kosong  :  First(L) = Nil   */
/* Setiap elemen dengan address P dapat diacu Info(P),Next(P)       */
/* Elemen terakhir  List :jika addressnya Last, maka next(Last)=Nil */

typedef struct {
	address First;
}List;

/* Pembuatan  List Kosong  */
void CreateList(List *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

/* Manajeman  memory  			*/
address Alokasi(infotype  X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void Dealokasi(address *P);
/* I.S  :   P  terdefinisi         	*/
/* F.S  :   P dikembalikan ke  sistem 	*/
/*   	    Melakukan  dealokasi, pengembalian address  P */

void InsertLast(List *L, infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */	
/*	  	Jika alokasi gagal: I.S = F.S			     */


int HitungElement(List L);
/* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */

void PrintInfo(List L);
    
#endif