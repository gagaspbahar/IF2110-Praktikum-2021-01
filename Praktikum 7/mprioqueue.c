// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// mprioqueue.c

#include <stdio.h>
#include "prioqueue.h"
#include "prioqueue.c"


int main(){
    int tc;
    ElType tempcl;
    ElType tempArr[CAPACITY];
    PrioQueue pq;
    CreatePrioQueue(&pq);
    scanf("%d", &tc);
    if(tc == 0){
        printf("Tidak ada layanan\n");
    }
    else{
        int n = 1;
        int i;
        for(i = 0; i < tc; i++){
            scanf("%d %d %d %d", &tempArr[i].tArrival, &tempArr[i].id, &tempArr[i].score, &tempArr[i].dService);
        }
        int currTime = 1;
        int timeLastServed = 0;
        int timeBeginServe = 1;

        i = 0;
        while(i < tc || !isEmpty(pq)){
            if(currTime == tempArr[i].tArrival){
                enqueue(&pq, tempArr[i]);
                i++;
            }
            if(currTime == timeLastServed + HEAD(pq).dService){
                dequeue(&pq, &tempcl);
                printf("%d %d %d\n", timeLastServed+1, tempcl.id, timeBeginServe-tempcl.tArrival);
                timeLastServed = currTime;
                timeBeginServe = currTime+1;
            }
            currTime++;
        }
    }
}