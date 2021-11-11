// Gagas Praharsa Bahar
// 13520016
// Mqueue

#include "queue_linked.h"
#include <stdio.h>

int main(){
    int n;
    Queue q;
    CreateQueue(&q);
    scanf("%d", &n);
    for(int t = 0; t < n; t++){
        int a;
        scanf("%d", &a);
        enqueue(&q, a);
        int temp;
        while(length(q) > 1 && q.addrTail->info-q.addrHead->info > 300){
            dequeue(&q, &temp);
        }
        printf("%d\n", length(q));
    }
}

