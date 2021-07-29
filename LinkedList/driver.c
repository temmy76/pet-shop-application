#include "List_penyakit.h"
#include <string.h>
int main(){
    List test;
    CreateList(&test);
    infotype X, x2, x3;
    strcpy(X.nama, "Testing nama 1\n");
    strcpy(X.kategori, "Testingg Kategori\n");
    InsertLast(&test, X);
    strcpy(x2.nama, "Testing nama 2\n");
    strcpy(x2.kategori, "Testingg Kategori\n");
    InsertLast(&test, x2);
    strcpy(x3.nama, "Testing nama 3\n");
    strcpy(x3.kategori, "Testingg Kategori\n");
    InsertLast(&test, x3);

    printf("%s %s", test.First->info.nama, test.First->info.kategori);
    printf("%s %s", test.First->next->info.nama, test.First->next->info.kategori);
    printf("%s %s", test.First->next->next->info.nama, test.First->next->next->info.kategori);
    system("pause");
    return 0;
}