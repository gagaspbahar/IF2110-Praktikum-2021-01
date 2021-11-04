// Gagas Praharsa Bahar
// 13520016
// Round Robin

#include "list_circular.h"
#include <stdio.h>
// #include "list_circular.c"

// int checkLast(List l){
//     Address p;
//     p = FIRST(l);
//     while(NEXT(p) != FIRST(l)){
//         p = p->next;
//     }
//     return INFO(p);
// }

float average(List l){
    Address p;
    int n = 0;
    float sum = 0;
    p = FIRST(l);
    do{
        n++;
        sum += INFO(p);
        p = p->next;
    } while(p != FIRST(l));
    return sum/n;
}

void deleteRR(List *l, ElType tq){
    Address last = FIRST(*l);
    while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }
    // printf("%i\n", last);
    int tempval;
    // displayList(*l);
    // printf("LAST: %d\n", last);
    // printf("tq: %d\n", tq);
    if(INFO(last) > tq){
        // printf("masukz\n");
        INFO(last) -= tq;
        FIRST(*l) = last;
        printf("%i\n", tq);
    }
    else{
        deleteLast(l, &tempval);
        printf("%i\n", tempval);
    }
}

int main(){
    int tq;
    int tempint;
    char op;
    boolean endGame = false;
    do{
        scanf("%i", &tq);
    }while (tq < 1);
        // scanf("%c", &op);

    List l;
    CreateList(&l);

    do{
        scanf(" %c", &op);
        // printf("%c", op);
        if(op == 'F'){
            // displayList(l);
            if(isEmpty(l)){
                printf("Proses selesai\n");
            }
            else{
                printf("%.2f\n", average(l));
            }
            endGame = true;
        }
        else if(op == 'A'){
            scanf("%i", &tempint);
            // scanf("%c", &op);
            if(tempint > 0){
                insertFirst(&l, tempint);
            }
        }
        else if(op == 'D'){
            if(isEmpty(l)){
                printf("List kosong\n");
            }
            else{
                deleteRR(&l, tq);
            }
        }
        else{
            printf("Kode salah\n");
        }
    }while(!endGame);
    return 0;
}

/* Testcases
5
A
5
A
10
A
15
A
14
D
D
F

10
X
A
10
D
D
F


-5
0
5
A
4
A
10
A
15
D
A
14
D
D
D
D
F

10
X
F */