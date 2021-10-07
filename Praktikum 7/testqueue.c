#include "queue.h"
#include "queue.c"
#include <stdio.h>

int main(){
    Queue q;
    ElType val;
    q.buffer[0] = 12;
    q.buffer[1] = 32;
    q.buffer[2] = 51;
    q.idxHead = 0;
    q.idxTail = 2;
    enqueue(&q, 200);
    dequeue(&q, &val);
    displayQueue(q);
}