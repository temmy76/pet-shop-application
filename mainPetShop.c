#include <stdio.h>
#include "Queue/queueDinamis.h"



int main(){
    int pilihan;
    Queue antrian;
    CreateQueue(&antrian);
    do{
        menu(); 
        gotoxy(55,25);printf("Pilih : "); scanf("%d",&pilihan);
        switch (pilihan) {
            case 1:
                lihatTabelPenyakit(36);getch();
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
                ProsesPelanggan(&antrian);
                break;
            case 6:
                gotoxy(40,25);printf("Terimakasih sudah menggunakan aplikasi kami");
                getch();
                break;
        }
    }while(pilihan != 6);

    
    return 0;
}

