/* Program: queue.h
 * Deskripsi: Spesifikasi ADT Queue menggunakan Linked List
 * Nama: Ardhiansyah
 * Tanggal: 23 April 2011
 * Compiler: GCC 4.9.2
 * Update: Muhammad Saiful Islam
 * Tanggal Update: 7 April 2015
 * Tanggal Update 2: 20 Mei 2015
 * Update: Asri Maspupah
 * Tanggal Update: 7 Mei 2021
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../LinkedList/List_penyakit.h"
#include <string.h>
#include <windows.h>

#define Front(Q) (Q).Front 
#define Rear(Q) (Q).Rear 
#define InfoFront(Q) (Q).Front->info 
#define InfoRear(Q) (Q).Rear->info  
#define Info(P) (P)->info  
#define nil NULL

/* Definisi elemen dan address */ 
typedef struct{
    /* List penyakit berupa String dan akan di define menjadi integer yang mana akan digunakan sebagai pertimbangan untuk priority queue */
   List namaPenyakit;
   /* penampung nilai penyakit pada linkedlist namaPenyakit*/
   int nilaiSakit;
}sakit;
typedef struct infoqueue {
   char nama[35]; // Nama Pendaftar
   int waktuKedatangan; // waktu kedatangan pendaftar ke dokter
   int waktuTunggu;
   int waktuSelesai;
   sakit penyakit;
}infoqueue;
typedef struct NodeQueue *addrNQ;
typedef struct NodeQueue {
    infoqueue info; 
    addrNQ next;
} NodeQueue;
typedef struct {
    addrNQ Front; // tag antrian depan
    addrNQ Rear; // tag antrian belakang
} Queue;

/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
 * Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
 * P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
 * Jika alokasi gagal, modul mengembalikan NULL.
 */
addrNQ AlokasiQ(infoqueue X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node queue).
 * I.S.: P terdefinisi.
 * F.S.: P dikembalikan ke sistem.
 */
void DealokasiQ(addrNQ *P);

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) = Nil 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak. 
   mengirimkan true, jika Queue Kosong yaitu Front(Q) = Nil dan Rear (Q) = Nil
   Sebaliknya false
*/
bool IsQueueEmpty(Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */ 
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear yang lama mengaitkan pointernya ke node yang baru */ 
void enQueue(Queue *Q, infoqueue data);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */  
/* F.S. info yang diambil = nilai elemen Front pd I.S. */ 
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q mungkin kosong */ 
void deQueue(Queue *Q);


/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau 
   mengirimkan 0 jika Q kosong 
*/ 
int NBElmt(Queue Q);

/*Menampilkan info queue, jika Q kosong akan menampilkan nil*/
void printInfoQueue(Queue Q);

/* Author : Wili Akbar Nugraha
 * Menambahkan pelanggan ke dalam proses antrian
 * I.S.: Queue Mungkin kosong 
 * F.S.: Antrian berhasil masuk ke Queue
 */
void InsertPelanggan(Queue *Q);

/* Author : Wili Akbar Nugraha
 * Memproses pelanggan ( deQueue )
 * I.S.: Queue Mungkin kosong 
 * F.S.: Pelanggan antrian berhasil keluar dari Queue ( antrian )
 */

void ProsesPelanggan(Queue Q);
/* menambah data pelanggan serta mengurutkan Data Pelanggan berdasarkan jumlah nilaiPenyakit 
 * apabila nilaiPenyakit pelanggan nya lebih besar dari pada pelanggan yang duluan datang 
 * maka pelanggan dengan nilaiPenyakit terbesar didahulukan terkecuali pelanngan pertama pada antrian
 * IS : Antian mungkin kosong
 * FS : Antrian sudah disort dengan ketentuan apabila nilaiPenyakit nya lebih besar 
 *      maka pelanggan tersebut didahulukan, terkecuali pelanggan paling pertama
 */  
void enQueuePrior(Queue *Q, infoqueue data);
/* Menghitung Estimasi waktu tunggu pada antrian pelanggan
 * I.S.: Waktu Tunggu pelanggan belum di ketahui 
 * F.S.: Mengembalikan nilai integer waktuTunggu 
 */
int hitungEstimasiTunggu(Queue Q, addrNQ data);

/* Menghitung Estimasi waktu tunggu pada antrian pelanggan
 * I.S.: Waktu Tunggu pelanggan belum di ketahui 
 * F.S.: Mengembalikan nilai integer waktuTunggu 
 */
int hitungEstimasiSelesai(Queue Q, addrNQ data);

/* Menampilkan List penyakit ke layar
 * IS : list mungkin kosong
 * FS : List penyakit tertampil di layar 
*/
void daftarPelanggan(Queue Q);
/* Menghitung waktu lama penyakit untuk memproses grooming
   I.S.: Lama proses untuk kucing tidak diketahui
   F.S.: Mengembalikan nilai lama proses grooming */
int hitungLamaPenyakit(sakit S);

/* Mengecek kategori dari setiap penyakit
   I.S.: Kategori penyakit masih kosong
   F.S.: Kategori dari setiap penyakit diketahui */
void checkPenyakit(sakit S);

/* Menghitung poin dari list penyakit
   I.S.: nilai sakit kosong
   F.S.: Mengembalikan nilai poin nilai penyakit */
int hitungPoinPenyakit(sakit S);

/* Memperlihatkan tabel penyakit dengan poin sakit
   I.S.: tidak ada tabel
   F.S.: Mengetahui poin-poin dari setiap penyakit */
void lihatTabelPenyakit();

/* Memperlihatkan menu dari aplikasi
   I.S.: layar kosong
   F.S.: Mengetahui fitur-fitur aplikasi */
void menu();

void toUpperStr(char str[]);
#endif // QUEUE_H
