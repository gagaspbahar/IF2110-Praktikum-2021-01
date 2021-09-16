// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 16 September 2021
// Main: Dynamic List

#include <stdio.h>
#include "listdin.h"

int main(){
    int Cap, q, i, menu, num;
    ListDin l;
    scanf("%i", &Cap);
    CreateListDin(&l, Cap);
    readList(&l);
    scanf("%i", &q);
    for(i = 0; i<q; i++){
        int flag = 1;
        scanf("%i", &menu);
        if (menu != 4){
            scanf("%i", &num);
        }
        if (menu == 1){
            if(isFull(l)){
                printf("list sudah penuh\n");
                flag = 0;
            }
            else{
                insertLast(&l, num);
            }
        }
        else if (menu == 2){
            growList(&l, num);
        }
        else if (menu == 3){
            if(num > CAPACITY(l)){
                printf("list terlalu kecil\n");
                flag = 0;
            }
            else{
                shrinkList(&l, num);
            }
        }
        else if (menu == 4){
            compactList(&l);
        }
        if (flag){
            printf("%i ", CAPACITY(l)); displayList(l); printf("\n");
        }
    }
}