/* Nama: Gagas Praharsa Bahar
NIM: 13520016 
list_mono.c */

#include <stdio.h>
#include "listpos.h"

int main(){
    ListPos l;
    int len, i;
    boolean isDesc = true, isAsc = true, isStat = true;
    CreateListPos(&l);
    readList(&l);
    len = length(l);
    for(i=0; i<len-1;i++){
        if(ELMT(l,i) != ELMT(l,i+1)){
            isStat = false;
        }
        if(ELMT(l,i) > ELMT(l,i+1)){
            isDesc = false;
        }
        if(ELMT(l,i) < ELMT(l,i+1)){
            isAsc = false;
        }
    }
    if(isStat){
        printf("Static Monotonic List\n");
    }
    else if(isDesc){
        printf("Non-descending Monotonic List\n");
    }
    else if(isAsc){
        printf("Non-ascending Monotonic List\n");
    }
    else{
        printf("Non-monotonic List\n");
    }
    
}