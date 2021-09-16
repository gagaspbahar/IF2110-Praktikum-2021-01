/* Nama: Gagas Praharsa Bahar
NIM: 13520016 
mlistpos.c */

#include <stdio.h>
#include "listpos.h"

int main(){
    ListPos l;
    int min, max, med, indMed, n, indN;
    CreateListPos(&l);
    readList(&l);
    displayList(l);
    printf("\n");
    scanf("%i", &n);
    extremes(l, &max, &min);
    indN = indexOf(l, n);
    if (indN != IDX_UNDEF){
        printf("%d\n", indN);
    }
    else{
        printf("%d tidak ada\n", n);
    }
    if (length(l) % 2 == 1){
        indMed = length(l) / 2;
    }
    else{
        indMed = length(l) / 2 - 1;
    }
    if(n == max){
        printf("maksimum\n");
    }
    if(n == min){
        printf("minimum\n");
    }
    sort(&l, true);
    if(n == ELMT(l, indMed)){
        printf("median\n");
    }
    

}