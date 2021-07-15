#include <stdio.h>
//#include "queueDinamis.h"

void menu(){
	system("cls");
    printf("===========================\n");
    printf("Welcome To UDUSDDH Pet Shop\n");
    printf("===========================\n\n");
    printf("Option Pet Shop : \n");
    printf("1. Tambah Pendaftar\n");
    printf("2. Lihat Pendaftar\n");
    printf("3. Proses Pendaftar\n");
    printf("4. Exit Program\n\n");
}

void tambah(){
	int banyak,i=0;
	
	system("cls");
	printf("[==========================]\n");
	printf("[--  Tambah Pendaftaran  --]\n");
	printf("[==========================]\n\n");
    printf("[=] Nama 	: \n");
    printf("[=] Jam Kedatangan 	: \n");
    printf("[=] Jumlah Penyakit	: "); scanf("%d",&banyak);
    while(i < banyak){
    	printf("[=] Nama Penyakit 	: \n");
    	i++;
	}
    getch();
}

void lihat(){
	system("cls");
	printf("[==========================]\n");
	printf("[----  Lihat  Antrian  ----]\n");
	printf("[==========================]\n\n");
	
	printf("[--------------------------]\n");
	printf("[       Antrian Utama      ]\n");
	printf("[--------------------------]\n\n");
	printf("[1]\n");
    printf("[=] Nama 		: Udin\n");
    printf("[=] Jam Kedatangan 	: 08:20\n");
    printf("[=] Jumlah Penyakit	: 2\n");
    printf("[=] Penyakit		: Kurap , Gatal gatal\n");
    printf("[=] Kategori Penyakit	: Berat\n");
    printf("[=] Estimasi Proses	: 90 menit\n");
    printf("[=] Estimasi Selesai	: 09:00\n");
    
    printf("\n[--------------------------]\n");
	printf("[      Antrian Selesai     ]\n");
	printf("[--------------------------]\n\n");
	printf("[1]\n");
    printf("[=] Nama 		: Mani\n");
    printf("[=] Jam Kedatangan 	: 08:20\n");
    printf("[=] Jumlah Penyakit	: 2\n");
    printf("[=] Penyakit		: Kurap , Gatal gatal\n");
    printf("[=] Kategori Penyakit	: Berat\n");
    printf("[=] Estimasi Proses	: 90 menit\n");
    printf("[=] Estimasi Selesai	: 09:00\n");
    getch();
}

void proses(){
	system("cls");
	printf("[==========================]\n");
	printf("[----  Proses Antrian  ----]\n");
	printf("[==========================]\n\n");

    printf("[=] Nama 		: Udin\n");
    printf("[=] Jam Kedatangan 	: 08:20\n");
    printf("[=] Jumlah Penyakit	: 2\n");
    printf("[=] Penyakit		: Kurap , Gatal gatal\n");
    printf("[=] Kategori Penyakit	: Berat\n");
    printf("[=] Estimasi Proses	: 90 menit\n");
    printf("[=] Estimasi Selesai	: 09:00\n");
    
    printf("Apakah akan telah diobati ? [Y/N]");
    getch();
}

void program(int pilihan){
    switch (pilihan) {
        case 1:
            tambah();
            break;

        case 2:
            lihat();
            break;

        case 3:
            proses();
            break;

        case 4:
            break;
    }
}

int main(){
// masih kosong ya
    int pilih;
    
    do{
        menu(); 
        printf("Pilih : "); scanf("%d",&pilih);
        program(pilih);
    }while(pilih != 4);

    
    return 0;
}

