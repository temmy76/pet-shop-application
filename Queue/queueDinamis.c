/* Program: queue.h
 * Deskripsi: Spesifikasi ADT Queue menggunakan Linked List
 * Update : Temmy Mahesa Ridwan
 * Tanggal Update : 7 Mei 2021
 */

#include "queueDinamis.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
bool IsQueueEmpty(Queue Q){
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


void InsertPelanggan(Queue *Q){
	int banyak,i ;
	infoqueue X;
	infotype Z;
	List penyakit;
	system("cls");
	printf("[==========================]\n");
	printf("[--  Tambah Pendaftaran  --]\n");
	printf("[==========================]\n\n");
    printf("[=] Nama 	: "); scanf("%s", X.nama); fflush(stdin);
    printf("[=] Jam Kedatangan 	: "); scanf("%d" , &X.waktuKedatangan); fflush(stdin);
    printf("[=] Jumlah Penyakit	: "); scanf("%d",&banyak); fflush(stdin);
	CreateList(&X.penyakit.namaPenyakit);
    for(i = 0; i < banyak; i++){
    	printf("[=] Nama Penyakit 	: "); scanf("%s", Z.nama); fflush(stdin);
		InsertLast(&X.penyakit.namaPenyakit , Z);
	}

	enQueuePrior(Q, X);
}

void ProsesPelanggan(Queue Q){
  	system("cls");
	printf("[==========================]\n");
	printf("[----  Proses Antrian  ----]\n");
	printf("[==========================]\n\n");

    printf("[=] Nama 		: \n"); 
    printf("[=] Jam Kedatangan 	: \n");
    printf("[=] Jumlah Penyakit	: \n");
    printf("[=] Penyakit		: \n");
    printf("[=] Kategori Penyakit	: \n");
    printf("[=] Estimasi Proses	: \n");
    printf("[=] Estimasi Selesai	: \n");
    
    printf("Apakah akan telah diobati ? [Y/N]");
    getch();
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

void daftarPelanggan(Queue Q){
	addrNQ p;
	p = Q.Front;
	checkPenyakit(p->info.penyakit);
	address temp = p->info.penyakit.namaPenyakit.First;
	int i = 1;
	system("cls");
	printf("[==========================]\n");
	printf("[----  Lihat  Antrian  ----]\n");
	printf("[==========================]\n\n");


	if(p == nil){
		printf("Tidak ada Antrian \n");
	}else{
			printf("[--------------------------]\n");
			printf("[       Antrian Utama      ]\n");
			printf("[--------------------------]\n\n");
		while(p != nil){
			printf("[Antrian ke %d]\n", i);
			printf("[=] Nama 		: %s \n", p->info.nama);
			printf("[=] Jam Kedatangan 	: %d\n", p->info.waktuKedatangan);
			printf("[=] Jumlah Penyakit	: %d\n", HitungElement(p->info.penyakit.namaPenyakit));
			printf("[=] Penyakit		: ");
			while(temp != NULL){
				printf(" %s (%s), ", temp->info.nama, temp->info.kategori);
				temp = temp->next;
			}
			printf("\n[=] Estimasi Tunggu	: %d\n", hitungEstimasiTunggu(Q, p));
			printf("[=] Estimasi Selesai	: %d\n\n", hitungEstimasiSelesai(Q, p));
			i++;
			p = p->next;
		}
	}
	getch();
}

/* Author : Nuno Alwi Azimah
 * Menghitung waktu lama penyakit untuk memproses grooming
 * I.S.: Lama proses untuk kucing tidak diketahui
 * F.S.: Mengembalikan nilai lama proses grooming
 *
 * -- pseudo code --
 * kamus
 *
 * algorima
 * return S.nilaisakti * 15
 */
int hitungLamaPenyakit(sakit S){
	return S.nilaiSakit * 15;
}

/* Author : Nuno Alwi Azimah
 * Mengecek kategori dari setiap penyakit
 * I.S.: Kategori penyakit masih kosong
 * F.S.: Kategori dari setiap penyakit diketahui
 *
 * -- pseudo code --
 * kamus
 * list : address
 *
 * algorima
 * adress = S.namaPenyakit->head
 * while(list != Nil) then
 *   if(list.info->nama = "gatal" OR list.info->nama = "jamuran" OR list.info->nama = "mencret") then list.info->kategori <- "Ringan"
 *   else if(list.info->nama = "diabetes" OR list.info->nama = "rabies" OR list.info->nama = "cacing hati") then list.info->kategori <- "Sedang"
 *   else if(list.info->nama = "kanker" OR list.info->nama = "fiv" OR list.info->nama = "infeksi pernapasan") then list.info->kategori <- "Berat"
 *   else then list.info->kategori <- "Baru"
 *   {end if}
 *   
 *   list <- list->next
 * {end while}
 */
void checkPenyakit(sakit S){
  	address list = S.namaPenyakit.First;

	
    while(list != Nil){
		toUpperStr(list->info.nama);
        if(strcmp(list->info.nama,"GATAL") == 0 || strcmp(list->info.nama,"JAMURAN") == 0 || strcmp(list->info.nama,"MENCRET") == 0 ) strcpy(list->info.kategori, "Ringan");
        else if(strcmp(list->info.nama,"DIABETES") == 0 || strcmp(list->info.nama,"RABIES") == 0 || strcmp(list->info.nama,"CACING HATI") == 0) strcpy(list->info.kategori, "Sedang");
        else if(strcmp(list->info.nama,"KANKER") == 0 || strcmp(list->info.nama,"FIV") == 0 || strcmp(list->info.nama,"INFEKSI PERNAFASAN") == 0) strcpy(list->info.kategori, "Berat");
        else strcpy(list->info.kategori, "Baru");
        list = list->next;
    }
}

/* Author : Nuno Alwi Azimah
 * Menghitung poin dari list penyakit
 * I.S.: nilai sakit kosong
 * F.S.: Mengembalikan nilai poin nilai penyakit
 *
 * -- pseudo code --
 * kamus
 * list : address
 *
 * algorima
 * adress = S.namaPenyakit->head
 * while(list != Nil) then
 *   if(list.info->nama = "gatal" OR list.info->nama = "jamuran" OR list.info->nama = "mencret") then S.nilaisakit = S.nilaisakit + 1
 *   else if(list.info->nama = "diabetes" OR list.info->nama = "rabies" OR list.info->nama = "cacing hati") then S.nilaisakit = S.nilaisakit + 3
 *   else if(list.info->nama = "kanker" OR list.info->nama = "fiv" OR list.info->nama = "infeksi pernapasan") then S.nilaisakit = S.nilaisakit + 5
 *   else then S.nilaisakit = S.nilaisakit + 0
 *   {end if}
 *   
 *   list <- list->next
 * {end while}
 * return S.nilaisakit
 */
int hitungPoinPenyakit(sakit S){
	address list = S.namaPenyakit.First;

	toUpperStr(list->info.nama);
    while(list != Nil){
        if(strcmp(list->info.nama,"GATAL") == 0 || strcmp(list->info.nama,"JAMURAN") == 0 || strcmp(list->info.nama,"MENCRET") == 0 ) S.nilaiSakit += 1;
        else if(strcmp(list->info.nama,"DIABETES") == 0 || strcmp(list->info.nama,"RABIES") == 0 || strcmp(list->info.nama,"CACING HATI") == 0) S.nilaiSakit += 3;
        else if(strcmp(list->info.nama,"KANKER") == 0 || strcmp(list->info.nama,"FIV") == 0 || strcmp(list->info.nama,"INFEKSI PERNAFASAN") == 0) S.nilaiSakit += 5;
        else S.nilaiSakit += 0;

        list = list->next;
    }
  	return S.nilaiSakit;
}

/* Author : Nuno Alwi Azimah
 * Memperlihatkan tabel penyakit dengan poin sakit
 * I.S.: tidak ada tabel
 * F.S.: Mengetahui poin-poin dari setiap penyakit
 *
 * -- pseudo code --
 * kamus
 *
 * algorima
 * output ("kategori || nama || poin")
 */
void lihatTabelPenyakit(){
    system("cls");
	printf("[===========================================]\n");
	printf("[------------  Tabel  Penyakit  ------------]\n");
	printf("[===========================================]\n\n");
	printf("||=========================================||\n");
  	printf("|| Kategori ||        Nama        || Point ||\n");
  	printf("||  Ringan  || Gatal              ||   1   ||\n");
    printf("||  Ringan  || Jamuran            ||   1   ||\n");
    printf("||  Ringan  || Mencret            ||   1   ||\n");
    printf("||  Sedang  || Diabetes           ||   3   ||\n");
    printf("||  Sedang  || Rabies             ||   3   ||\n");
    printf("||  Sedang  || Cacing Hati        ||   3   ||\n");
    printf("||  Berat   || Kanker             ||   5   ||\n");
    printf("||  Berat   || FIV                ||   5   ||\n");
    printf("||  Berat   || Infeksi Pernafasan ||   5   ||\n");
  	printf("||=========================================||\n");
}

/* Author : Nuno Alwi Azimah
 * Memperlihatkan menu dari aplikasi
 * I.S.: layar kosong
 * F.S.: Mengetahui fitur-fitur aplikasi
 *
 * -- pseudo code --
 * kamus
 *
 * algorima
 *
 */
void menu(){
	system("cls");
    printf("===========================\n");
    printf("Welcome To UDUSDDH Pet Shop\n");
    printf("===========================\n\n");
    printf("Option Pet Shop : \n");
    printf("1. Lihat Tabel Penyakit\n");
    printf("2. Tambah Pendaftar\n");
    printf("3. Lihat Pendaftar\n");
    printf("4. Proses Pendaftar\n");
    printf("5. Exit Program\n\n");
}

void toUpperStr(char str[]){
    int i;
    for(i = 0; str[i]!='\0'; i++){
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }
}
