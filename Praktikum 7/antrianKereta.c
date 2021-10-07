// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Antrian Kereta


#include <stdio.h>
#include "queue.h"


int main(){
    int op, waktu;
    int i, temp;    
    Queue q;
    int flag = 1;
    CreateQueue(&q);
    while(flag){
        scanf("%d", &op);
            if(op == 1){
                scanf("%d", &waktu);
                if(isFull(q)){
                    printf("Queue penuh\n");
                }
                else{
                    enqueue(&q, waktu);
                }
            }
            else if(op == 2){
                if(isEmpty(q)){
                    printf("Queue kosong\n");
                }
                else{
                    dequeue(&q, &temp);
                }
            }
            else if(op == 0){
                flag = 0;
            }
    }
    printf("%d\n", length(q));
    if(length(q) == 0){
        printf("Tidak bisa dihitung\n");
    }
    else{    
        float sum;
        int len = length(q);
        while(!isEmpty(q)){
            sum += HEAD(q);
            dequeue(&q,&temp);
        }
        printf("%.2f\n", sum/len);
    }
}