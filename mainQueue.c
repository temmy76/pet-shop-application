#include <stdio.h>
#include "queueDinamis.h"

int main(){
    Queue antri;
    CreateQueue(&antri);
    printInfoQueue(antri);
    enQueue(&antri, 2);
    enQueue(&antri, 4);
    enQueue(&antri, 5);
    enQueue(&antri, 6);
    enQueue(&antri, 5);
    deQueue(&antri);
    deQueue(&antri);
    printInfoQueue(antri);

    int a = NBElmt(antri);
    printf("%d\n", a);
    
    system("pause");
    
}