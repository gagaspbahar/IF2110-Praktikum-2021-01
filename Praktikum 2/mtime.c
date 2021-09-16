// Gagas Praharsa Bahar
// 13520016
// mtime.c

#include <stdio.h>
#include "time.h"

int main(){
    int n;
    int i;
    TIME minStart, maxEnd, temp, start, end;
    int temph, tempm, temps;
    minStart = MakeTIME(23,59,59);
    maxEnd = MakeTIME(0,0,0);
    scanf("%i", &n);
    for (i = 0; i < n; i++){
        printf("[%i]\n", i+1);
        BacaTIME(&temp);
        start = temp;
        BacaTIME(&temp);
        end = temp;
        if (TGT(start, end)){
            temp = start;
            start = end;
            end = temp;
        }
        if(TLT(start, minStart)){
            minStart = start;
        }
        if(TGT(end, maxEnd)){
            maxEnd = end;
        }
        printf("%i\n", Durasi(start, end));
    }
    TulisTIME(minStart);
    printf("\n");
    TulisTIME(maxEnd);
    printf("\n");
}