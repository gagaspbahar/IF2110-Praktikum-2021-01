#include <stdio.h>
#include "listpos.c"

int main(){
    ListPos l, l2, l3;
    int max, min, val, i;
    CreateListPos(&l);
    readList(&l);
    displayList(l);
    printf("panjang: %i\n", length(l));
    extremes(l, &max, &min);
    printf("max: %i, min: %i\n", max, min);
    isAllEven(l) ? printf("All even.\n") : printf("Not all even.\n");
    insertLast(&l, 10);
    displayList(l);
    deleteLast(&l, &val);
    displayList(l);
    sort(&l, true);
    displayList(l);
    sort(&l, false);
    displayList(l);
    scanf("%i", i);
    printf("%i", indexOf(l, i));
    printf("Masukkan list kedua: \n");
    CreateListPos(&l2);
    readList(&l2);
    displayList(l2);
    if (isListEqual(l, l2)){
        printf("List equal.\n");
    }
    l3 = plusMinusTab(l ,l2, true);
    displayList(l3);
    l3 = plusMinusTab(l, l2, false);
    displayList(l3);
}