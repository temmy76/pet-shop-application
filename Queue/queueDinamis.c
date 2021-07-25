/* Program: queue.h
 * Deskripsi: Spesifikasi ADT Queue menggunakan Linked List
 * Update : Temmy Mahesa Ridwan
 * Tanggal Update : 7 Mei 2021
 */

#include "queueDinamis.h"

/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
 * Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
 * P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
 * Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ AlokasiQ(infoqueue X){
	addrNQ p;
	
	p = (addrNQ)malloc(sizeof(NodeQueue));
	if(p != nil){
		Info(p) = X;
		p->next = nil;
		return p;
	}else {
		return nil;
	}
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
 * I.S.: P terdefinisi.
 * F.S.: P dikembalikan ke sistem.
 */
void DealokasiQ(addrNQ *P){
	free(*P);
}

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) = Nil 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q){
	Front(*Q) = nil;
	Rear(*Q) = nil;
}

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan true, jika Queue Kosong yaitu Front(Q) = Nil dan Rear (Q) = Nil
   Sebaliknya false
*/
boolean IsQueueEmpty(Queue Q){
	// if(Front(Q) == nil && Rear(Q) == nil){
	// 	return true;
	// } else {
	// 	return false;
	// }

	int jmlantri = NBElmt(Q);
	if(jmlantri == 0){
		return true;
	}else{
		return false;
	}
}

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */  
/* F.S. info yang diambil = nilai elemen Front pd I.S. */ 
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q mungkin kosong */ 
void deQueue(Queue *Q){
	addrNQ p, prev;
	
	
	if(Front(*Q)->next == nil){ 
		//fix here
		p = Front(*Q);
		Front(*Q) = Front(*Q)->next;
		p->next = nil;
	}else{
		p = Front(*Q);
		Front(*Q) = Front(*Q)->next;
		DealokasiQ(&p);  
	}
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */ 
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear yang lama mengaitkan pointernya ke node yang baru */ 
void enQueue(Queue *Q, infoqueue data){
	addrNQ p, last;
	
	p = AlokasiQ(data);
	if(Rear(*Q) == nil){
		Front(*Q) = Rear(*Q) = p;
	}else{
		// last = Front(*Q);
		// while(last->next != nil){
		// 	Rear(*Q) = last;
		// 	last = last->next;
		// }
		Rear(*Q)->next = p;
		Rear(*Q) = p;
	}
}

/* 
	Mengirimkan banyaknya elemen queue jika Q berisi atrian atau 
   	mengirimkan 0 jika Q kosong 
*/ 
int NBElmt(Queue Q){
	addrNQ P;
	int jml = 0;
	P = Front(Q);
	while (P != nil)
	{
		jml++;
		P = P->next;
	}
	return jml;
}


/*
	Menampilkan semua node Queue yang sudah di buat 
	IS : Queue sudah dibuat
	FS : Apabila queue kosong akan menampilkan "Antrian Kosong",
		 Apabila tidak kosong akan menampilkan semua node yang sudah dibuat
*/
void printInfoQueue(Queue Q){
	addrNQ p;

	p = Front(Q);
	if(p == nil){
		printf("Antrian Kosong \n");
	}else {
		while(p->next != nil){
			printf("[ %d ] - ", Info(p));
			p = p->next;
		}
		printf("[ %d ] - \n", Info(p));
	}
}

void gotoxy(int x, int y) {
    /* Kursor untuk menunjuk pada titik (x,y) tertentu */

      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*
 * Author : Temmy Mahesa  Ridwan
 * menambah data pelanggan serta mengurutkan Data Pelanggan berdasarkan jumlah nilaiPenyakit 
 * apabila nilaiPenyakit pelanggan nya lebih besar dari pada pelanggan yang duluan datang 
 * maka pelanggan dengan nilaiPenyakit terbesar didahulukan terkecuali pelanngan pertama pada antrian
 * IS : Antian mungkin kosong
 * FS : Antrian sudah disort dengan ketentuan apabila nilaiPenyakit nya lebih besar 
 *      maka pelanggan tersebut didahulukan, terkecuali pelanggan paling pertama
 */  
void enQueuePrior(Queue *Q, infoqueue data){
	addrNQ p;
	p = AlokasiQ(data);
	// printf("test ");
	if(Front(*Q) == nil){ // check apa bila kosong
		enQueue(Q, data);
		// printf("kosong\n");
	}else if(Front(*Q)->next == nil){ // check apabila queue cuma satu
		 enQueue(Q, data);
		//  printf("data cuma 1\n");
	}else{
		addrNQ curr, prev, temp;
		curr = Q->Front->next;
		if (curr->info.penyakit.nilaiSakit < data.penyakit.nilaiSakit) {
			p->next = curr;
			Q->Front->next = p;
			curr = p;
		} else {
			addrNQ current = curr;
			while ((current->next != NULL) && (current->next->info.penyakit.nilaiSakit > data.penyakit.nilaiSakit)) {
				current = current->next;
			}

			p->next = current->next;
			current->next = p;
		}
		// printf("data banyak terakhir\n");

		addrNQ last = Front(*Q);
		while(last != nil){
			last = last->next;
		}
		Rear(*Q) = last;
		
	}
}

/* Author : Temmy Mahesa Ridwan
 * Menghitung Estimasi waktu tunggu pada antrian pelanggan
 * I.S.: Waktu Tunggu pelanggan belum di ketahui 
 * F.S.: Mengembalikan nilai integer waktuTunggu 
 */
int hitungEstimasiTunggu(Queue Q, addrNQ data){
  	if(data == Q.Front){
    	return 0;
    }else{
      	addrNQ curr, prev;
      	curr = Q.Front;
      	while(curr != data){
        	prev = curr;
          	curr = curr->next;
        }
      	curr->info.waktuTunggu = prev->info.waktuSelesai - curr->info.waktuKedatangan;
      	return curr->info.waktuTunggu;
    }
}
/* Author : Temmy Mahesa Ridwan
 * Menghitung Estimasi waktuSelesai pada saat pelayanan
 * I.S.: Waktu Selesai Pelayanan belum di ketahui 
 * F.S.: Mengembalikan nilai integer waktuSelesai
 */
int hitungEstimasiSelesai(Queue Q, addrNQ data){
  	if(data == Q.Front){
    	data->info.waktuSelesai = data->info.waktuKedatangan + hitungLamaPenyakit(data->info.penyakit);
        return data->info.waktuSelesai;
	}else{
      	addrNQ curr, prev;
      	curr = Q.Front;
      	while(curr != data){
          	prev =  curr;
          	curr = curr->next;
        }
      	data->info.waktuSelesai = data->info.waktuKedatangan + hitungLamaPenyakit(data->info.penyakit);
        return data->info.waktuSelesai;
    }
}


