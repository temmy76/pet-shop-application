#include "List_penyakit.h"

/* Pembuatan  List Kosong  */
void CreateList(List *L){
    /* I.S  :  Sembarang    		*/
    /* F.S  :  Terbentuk  List kosong  	*/
    (*L).First = Nil;
}


/* Manajeman  memory  			*/
address Alokasi(infotype  X){
    /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Next(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */
    address p;
    p = (address)malloc(sizeof(ElmtList));
    if(p != Nil){
        p->info = X;
        p->next = Nil;
    }
    return p;
}

void Dealokasi(address *P){
  /* I.S  : P terdefinisi      				*/
  /* F.S  : P dikembalikan ke  sistem 			*/
  /*   	    Melakukan dealokasi, pengembalian address P */
    (*P)->next = Nil;
    free(*P);
}

void InsertLast(List *L, infotype X){
    /* I.S  : L mungkin kosong          */
    /* F.S  : Melakukan alokasi sebuah elemen dan                */
    /*        menambahkan elemen list di akhir; elemen terakhir  */
    /*        yang baru bernilai X jika alokasi berhasil, 	     */	
    /*	  Jika alokasi gagal: I.S = F.S			     */
    address p = Alokasi(X);
    if(p == NULL){
        return;
    }
    if(L->First == NULL){
        L->First= p;
        return;
    }

    address last = L->First;
    while(last != NULL){
        last = last->next;
    }
    last->next = p;
}


int HitungElement(List L){
    address P;
    int jumlah = 0;
    if(L.First == Nil){
        return 0;
    }else{
        P = L.First;
        do{
            jumlah++;
            P = P->next;
        }while(P != Nil);
    }
    return jumlah;
}
/* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */