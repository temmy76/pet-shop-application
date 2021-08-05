/* Program: queue.h
 * Deskripsi: Spesifikasi ADT Queue menggunakan Linked List
 * Update : Temmy Mahesa Ridwan
 * Tanggal Update : 7 Mei 2021
 */

#include "queueDinamis.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
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
		p->info.waktuSelesai = 0;
		p->info.waktuTunggu = 0;
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
void DealokasiQ(addrNQ P){
	
	DealokasiList(P->info.penyakit.namaPenyakit.First);
	P->info.penyakit.namaPenyakit.First = nil;
	free(P);
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
	
	if(Front(*Q) == nil&& Rear(*Q) == nil ){
		printf("Queue is Empty");
	}else {
		p = Front(*Q);
		if(p == Rear(*Q)){
			Front(*Q) = nil;
			Rear(*Q) = nil;
		}else {
			Front(*Q) = p->next;
		}

		p->next = nil;
		DealokasiQ(p);

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
			printf("[ %d ] - ", Info(p).penyakit.nilaiSakit);
			p = p->next;
		}
		printf("[ %d ] - \n", Info(p).penyakit.nilaiSakit);
	}
}

/* Author : Wili Akbar Nugraha
 * Menambahkan pasien ke list antrian
 * IS : Queue Mungkin kosong
 * FS : Menambah pendaftar dan diurutkan sesuai nilai penyakit yang dimiliki kecuali element pertama
 * Modified : Temmy Mahesa Ridwan
*/
void InsertPelanggan(Queue *Q){
	int banyak,i ;
	infoqueue X;
	
	system("cls");
    for (int i = 2; i <27 ; ++i) {
        gotoxy(15,i);printf("||                                                                                     ||\n");
    }
    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,5);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,6);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,7);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(15,10);printf("=========================================================================================\n");
    gotoxy(15,27);printf("=========================================================================================\n");
	gotoxy(36,12);printf("[==========================================]\n");
	gotoxy(36,13);printf("[---          Tambah Pendaftaran        ---]\n");
	gotoxy(36,14);printf("[==========================================]\n\n");
    gotoxy(36,16);printf("[=] Nama 			: "); scanf("%s", X.nama); fflush(stdin);
    gotoxy(36,17);printf("[=] Jam Kedatangan 	        : "); scanf("%d" , &X.waktuKedatangan); fflush(stdin);
    gotoxy(36,18);printf("[=] Jumlah Penyakit	        : "); scanf("%d",&banyak); fflush(stdin);
	insertListQ(&X,banyak);
	hitungPoinPenyakit(&X.penyakit);
	enQueuePrior(Q, X);
}

void insertListQ(infoqueue *data, int jumlah){
	infotype Z;
	List penyakit;
	CreateList(&penyakit);
	int i;
	lihatTabelPenyakit(20);
    for(i = 1; i <= jumlah; i++){
    	gotoxy(70,10+(i*2));printf("[=] Nama Penyakit %d : \n",i);
        gotoxy(70,10+(i*2)+1);scanf("%[^\n]s", Z.nama); fflush(stdin);
		InsertLast(&penyakit, Z);
	}
	data->penyakit.namaPenyakit = penyakit;
}

/*Author : Wili Akbar Nugraga
 * Menghapus peasian pada antrian antrian paling depan
 * IS : antrian mungkin kosong
 * FS : Antrian paling depan di bebaskan, dan antrian ke 2 akan menjadi head
*/
void ProsesPelanggan(Queue *Q){
    addrNQ p;
    p = Q->Front;
    char pilihan;

    system("cls");
//    for (int i = 2; i <27 ; ++i) {
//        gotoxy(15,i);printf("||                                                                                     ||\n");
//    }
    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,5);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,6);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,7);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(15,10);printf("=========================================================================================\n");
//    gotoxy(15,27);printf("=========================================================================================\n");
    gotoxy(36,12);printf("[==========================================]\n");
	gotoxy(36,13);printf("[---            Proses Antrian          ---]\n");
	gotoxy(36,14);printf("[==========================================]\n\n");
	if(p == nil){
		gotoxy(36,16);printf(" !!! Tidak ada Antrian !!!\n");
	}else {
		gotoxy(25,16);printf("[=] Nama                  : %s \n", p->info.nama);
		gotoxy(25,17);printf("[=] Jam Kedatangan        : %d\n", p->info.waktuKedatangan);
		gotoxy(25,18);printf("[=] Jumlah Penyakit       : %d\n", HitungElement(p->info.penyakit.namaPenyakit));
		checkPenyakit(p->info.penyakit);
		gotoxy(25,19);printf("[=] Penyakit              : "); PrintInfo(p->info.penyakit.namaPenyakit);
		gotoxy(25,20);printf("[=] Estimasi Tunggu       : %d\n", hitungEstimasiTunggu(*Q, p));
		gotoxy(25,21);printf("[=] Estimasi Selesai      : %d\n\n", hitungEstimasiSelesai(*Q, p));

		gotoxy(36,23);printf("Apakah akan telah diobati ? [Y/N]"); scanf(" %c", &pilihan); fflush(stdin);
		if (pilihan == 'Y' || pilihan == 'y'){
			tulisFile(p);
			deQueue(Q);
			gotoxy(30,23);printf("======= Selamat kucing anda sudah sehat!!!!! ^_^ =======\n");
            gotoxy(40,24);printf("History Antiran berhasil dimasukan ^_^");
			gotoxy(35,25);printf("Pencet tombol apapun untuk kembali ke menu ^_^\n");
		}
		else if(pilihan == 'N' || pilihan == 'n'){
			gotoxy(30,23);printf("======= Kucing anda sedang dalam proses pengobatan =======\n");
			gotoxy(50,24);printf("Harap bersabar ^_^\n");
			gotoxy(35,25);printf("Penncet tombol apapun untuk kembali ke menu ^_^\n");
		}
	}
    
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
	}else if(Front(*Q) == Rear(*Q)){ // check apabila queue cuma satu
		 enQueue(Q, data);
		//  printf("data cuma 1\n");
	}else if(p->info.penyakit.nilaiSakit <= Q->Rear->info.penyakit.nilaiSakit ){
		// printf("rear %d", Q->Rear->info.penyakit.nilaiSakit);
		// printf("P %d", p->info.penyakit.nilaiSakit);
		enQueue(Q, data);
		//  printf("data 2\n");
	}else{
		// printf("rear %d", Q->Rear->info.penyakit.nilaiSakit);
		// printf("P %d", p->info.penyakit.nilaiSakit);
		addrNQ current, prev, temp;
		current = Q->Front->next;
		prev = Q->Front;
		// printf("sebelum sorting");
		while ((current->next != NULL) && (current->info.penyakit.nilaiSakit > p->info.penyakit.nilaiSakit )) {
			prev = current;
			current = current->next;
		}
		while ((current->next != NULL) && (current->info.penyakit.nilaiSakit == p->info.penyakit.nilaiSakit )) {
			prev = current;
			current = current->next;
		}
		prev->next = p;
		p->next = current;
		current = p;
		// printf("sorting");
		addrNQ last = Front(*Q);
		while(last->next != nil){
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
		
      	curr->info.waktuSelesai = prev->info.waktuKedatangan + hitungLamaPenyakit(curr->info.penyakit);
        return curr->info.waktuSelesai;
    }
}


/* Author : Temmy Mahesa Ridwan
 * Menampilkan semua Antrian ke layar apabila kosong akan di beritau bahwa antrian belum ada
 * IS : Queue mungkin kosong
 * FS : Menampilkan semua antrian ke layar
*/
void daftarPelanggan(Queue Q){
	addrNQ p;
	p = Q.Front;
	int i = 0;
	system("cls");
//    for (int j = 2; j <27 ; ++j) {
//        gotoxy(15,j);printf("||                                                                                     ||\n");
//    }
    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,5);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,6);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,7);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(15,10);printf("=========================================================================================\n");
//    gotoxy(15,27);printf("=========================================================================================\n");
	gotoxy(36,12);printf("[==========================================]\n");
	gotoxy(36,13);printf("[---            Lihat Antrian           ---]\n");
	gotoxy(36,14);printf("[==========================================]\n\n");

	if(p == nil){
		gotoxy(36,16);printf(" !!! Tidak ada Antrian !!!\n");
	}else{
//			gotoxy(30,16);printf("[------------------------------------------]\n");
//			gotoxy(30,17);printf("[               Antrian Utama              ]\n");
//			gotoxy(30,18);printf("[------------------------------------------]\n\n");
			while(p != nil){
                gotoxy(25,16+(i*16));printf("[Antrian ke %d]", i+1);
                gotoxy(25,17+(i*16)+1);printf("[=] Nama                 : %s", p->info.nama);
                gotoxy(25,18+(i*16)+2);printf("[=] Jam Kedatangan       : %d", p->info.waktuKedatangan);
                gotoxy(25,19+(i*16)+3);printf("[=] Jumlah Penyakit      : %d", HitungElement(p->info.penyakit.namaPenyakit));checkPenyakit(p->info.penyakit);
                gotoxy(25,20+(i*16)+4);printf("[=] Penyakit             : "); PrintInfo(p->info.penyakit.namaPenyakit);
                gotoxy(25,21+(i*16)+5);printf("[=] Estimasi Tunggu      : %d", hitungEstimasiTunggu(Q, p));
                gotoxy(25,22+(i*16)+6);printf("[=] Estimasi Selesai     : %d", hitungEstimasiSelesai(Q, p));
                // printf(" please %d\n", p->info.penyakit.nilaiSakit);
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
 * return S.nilaisakti * 5
 */
int hitungLamaPenyakit(sakit S){
	return S.nilaiSakit * 5;
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
        else strcpy(list->info.kategori, "BARU");
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
void hitungPoinPenyakit(sakit *S){
	address list = S->namaPenyakit.First;
	S->nilaiSakit = 0;
	toUpperStr(list->info.nama);
    while(list != Nil){
		toUpperStr(list->info.nama);
        if(strcmp(list->info.nama,"GATAL") == 0 || strcmp(list->info.nama,"JAMURAN") == 0 || strcmp(list->info.nama,"MENCRET") == 0 ) S->nilaiSakit = S->nilaiSakit + 1;
        else if(strcmp(list->info.nama,"DIABETES") == 0 || strcmp(list->info.nama,"RABIES") == 0 || strcmp(list->info.nama,"CACING HATI") == 0) S->nilaiSakit = S->nilaiSakit + 3;
        else if(strcmp(list->info.nama,"KANKER") == 0 || strcmp(list->info.nama,"FIV") == 0 || strcmp(list->info.nama,"INFEKSI PERNAFASAN") == 0) S->nilaiSakit = S->nilaiSakit + 5;
        else S->nilaiSakit = S->nilaiSakit + 2;
        list = list->next;
    }
	// printf("%d", S->nilaiSakit); 
  	
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
void lihatTabelPenyakit(int posisi){
    system("cls");
    for (int i = 2; i <27 ; ++i) {
        gotoxy(15,i);printf("||                                                                                     ||\n");
    }
    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,5);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,6);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,7);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(15,10);printf("=========================================================================================\n");
    gotoxy(15,27);printf("=========================================================================================\n");
    gotoxy(posisi,12);printf("||=========================================||\n");
    gotoxy(posisi,13);printf("||-----------  Tabel  Penyakit  -----------||\n");
	gotoxy(posisi,14);printf("||=========================================||\n");
  	gotoxy(posisi,15);printf("|| Kategori ||        Nama        || Point ||\n");
  	gotoxy(posisi,16);printf("||  Ringan  || Gatal              ||   1   ||\n");
    gotoxy(posisi,17);printf("||  Ringan  || Jamuran            ||   1   ||\n");
	gotoxy(posisi,18);printf("||  Ringan  || Mencret            ||   1   ||\n");
    gotoxy(posisi,19);printf("||  Sedang  || Diabetes           ||   3   ||\n");
    gotoxy(posisi,20);printf("||  Sedang  || Rabies             ||   3   ||\n");
    gotoxy(posisi,21);printf("||  Sedang  || Cacing Hati        ||   3   ||\n");
    gotoxy(posisi,22);printf("||  Berat   || Kanker             ||   5   ||\n");
    gotoxy(posisi,23);printf("||  Berat   || FIV                ||   5   ||\n");
    gotoxy(posisi,24);printf("||  Berat   || Infeksi Pernafasan ||   5   ||\n");
  	gotoxy(posisi,25);printf("||=========================================||\n");
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
	system("color a");
    for (int i = 2; i <27 ; ++i) {
        gotoxy(15,i);printf("||                                                                                     ||\n");
    }
    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("                                   WELCOME  TO                                   \n");
    gotoxy(19,6);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,7);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,9);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,10);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(19,12);printf("                                    PET  SHOP                                   \n");
    gotoxy(15,14);printf("=========================================================================================\n");
    gotoxy(15,27);printf("=========================================================================================\n");
    gotoxy(19,16);printf("                                   DAFTAR FITUR                                  \n");
    gotoxy(19,19);printf("        1.            2.           3.           4.            5.         6.      \n");
    gotoxy(19,20);printf("    Lihat Tabel     Tambah       Daftar       Proses       History      Exit     \n");
    gotoxy(19,21);printf("     Penyakit      Pendaftar    Pendaftar    Pendaftar    Pendaftar    Program   \n");
//    gotoxy(19,18);printf("                                                                                 \n");
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

void tulisFile(addrNQ data){
    FILE *fptr;
    char datang[5],tunggu[5],selesai[5],jumlah[5],namaSakit[34],kategoriSakit[10];
    int banyak,i;

    address penyakit;
    // membuka file
    fptr = fopen("log_antrian.txt","a+");

    // memindahkan
//    itoa(data->info.waktuKedatangan,datang,10);
//    itoa(data->info.waktuTunggu,tunggu,10);
//    itoa(data->info.waktuSelesai,selesai,10);

    banyak = HitungElement(data->info.penyakit.namaPenyakit);
    itoa(banyak,jumlah,10);

    penyakit = data->info.penyakit.namaPenyakit.First;

    // menulis ke text ke file
    fputs("[=] Nama                  : ", fptr); fputs(data->info.nama, fptr);
//    fputs("\n[=] Jam Kedatangan        : ", fptr); fputs(datang, fptr);
    fputs("\n[=] Jumlah Penyakit       : ", fptr); fputs(jumlah, fptr);
    fputs("\n[=] Penyakit              : ", fptr);
    while (penyakit != NULL ){
        strcpy(namaSakit,penyakit->info.nama);
        strcpy(kategoriSakit,penyakit->info.kategori);
        fputs(namaSakit, fptr); fputs(" ( ", fptr); fputs(kategoriSakit, fptr); fputs(" ), ", fptr);
        penyakit = penyakit->next;
    }
//    fputs("\n[=] Estimasi Tunggu       : ", fptr); fputs(tunggu, fptr);
//    fputs("\n[=] Estimasi Selesai      : ", fptr); fputs(selesai, fptr);
    fputs("\n\n", fptr);

    // tutup file
    fclose(fptr);
}

void bacaFile(){
    system("cls");
    system("color a");
    for (int i = 2; i <14 ; ++i) {
        gotoxy(15,i);printf("||                                                                                     ||\n");
    }

    gotoxy(15,2);printf("=========================================================================================\n");
    gotoxy(19,4);printf("                                   WELCOME  TO                                   \n");
    gotoxy(19,6);printf("***   ***   ******      ***   ***   *********   ******      ******      ***   ***\n");
    gotoxy(19,7);printf("***   ***   **    **    ***   ***   ***         **    **    **    **    ***   ***\n");
    gotoxy(19,8);printf("***   ***   **     **   ***   ***   *********   **     **   **     **   *********\n");
    gotoxy(19,9);printf("*********   **    **    *********         ***   **    **    **    **    ***   ***\n");
    gotoxy(19,10);printf("*********   ******      *********   *********   ******      ******      ***   ***\n");
    gotoxy(19,12);printf("                                    PET  SHOP                                   \n");
    gotoxy(15,14);printf("=========================================================================================\n");
//    gotoxy(15,27);printf("=========================================================================================\n");
    gotoxy(38,16);printf("[==========================================]\n");
    gotoxy(38,17);printf("[---            Lihat History           ---]\n");
    gotoxy(38,18);printf("[==========================================]\n\n");


    FILE *fp;
    char str[100];

    int j=1;
    /* opening file for reading */
    fp = fopen("log_antrian.txt" , "r");
    if(fp == NULL) {
        perror("Error opening file");
        return;
    }
    while(fgets (str, 100, fp)!=NULL ) {
        gotoxy(25,18+(j+1)); puts(str);
        j++;
    }
    fclose(fp);

    getch();
}