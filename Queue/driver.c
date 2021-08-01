#include "queueDinamis.h"

int main(){
    Queue test;
    infoqueue X, Y, Z, W, B;
    CreateQueue(&test);

    X.penyakit.nilaiSakit = 7;
    Y.penyakit.nilaiSakit = 9;
    Z.penyakit.nilaiSakit = 11;
    W.penyakit.nilaiSakit = 4;
    B.penyakit.nilaiSakit = 11;
    

    enQueuePrior(&test, X);
    enQueuePrior(&test, Y);
    enQueuePrior(&test, Z);
    enQueuePrior(&test, W);
    enQueuePrior(&test, B);

    List Test1, Test2, Test3;
    CreateList(&Test1);
    CreateList(&Test2);
    CreateList(&Test3);
    
    
    infotype x, x2, x3, x4;
    strcpy(x.nama, "Testing nama 1\n");
    strcpy(x.kategori, "Testingg Kategori 1\n");
    InsertLast(&Test1, x);
    strcpy(x2.nama, "Testing nama 2\n");
    strcpy(x2.kategori, "Testingg Kategori 2\n");
    InsertLast(&Test2, x2);
    strcpy(x3.nama, "Testing nama 3\n");
    strcpy(x3.kategori, "Testingg Kategori 3\n");
    InsertLast(&Test3, x3);
    
    test.Front->info.penyakit.namaPenyakit = Test1;
    test.Front->next->info.penyakit.namaPenyakit = Test2;
    test.Front->next->next->info.penyakit.namaPenyakit = Test3;
    
    printInfoQueue(test);
    printf("rear %d\n", test.Rear->info.penyakit.nilaiSakit);

    // printf(" test 1 %s\n", test.Front->info.penyakit.namaPenyakit.First->info.kategori);
    // printf(" test 2 %s\n", test.Front->next->info.penyakit.namaPenyakit.First->info.kategori);
    // printf(" test 3 %s\n", test.Front->next->next->info.penyakit.namaPenyakit.First->info.kategori);
    system("pause");
    return 0;


}