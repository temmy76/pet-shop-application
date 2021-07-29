#include <stdio.h>
#include "Queue/queueDinamis.h"



int main(){
    int pilihan;
    Queue antrian;
    CreateQueue(&antrian);
    do{
        menu(); 
        gotoxy(30,16);printf("Pilih : "); scanf("%d",&pilihan);
        switch (pilihan) {
            case 1:
                lihatTabelPenyakit();getch();
                break;

            case 2:
                InsertPelanggan(&antrian);
                break;

            case 3:
                daftarPelanggan(antrian);
                break;

            case 4:
                ProsesPelanggan(&antrian);
                break;
            case 5:
                gotoxy(30,18);printf("Terimakasih sudah menggunakan aplikasi kami");
                getch();
                break;
        }
    }while(pilihan != 5);

    
    return 0;
}

