#include <stdio.h>
#include "bintree.h"

int main(){
    int n;
    scanf("%d", &n);
    if(n <= 0){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }
    int temp = n;
    while(temp%2 == 0){
        temp /= 2;
    }
    if(temp != 1){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    int lim = (n*2)-1;
    BinTree ar[lim];
    for(int i = 0; i < n;i++){
        int x;
        scanf("%d", &x);
        BinTree t = NewTree(x, NULL, NULL);
        ar[i] = t;
    }
    int j = 0;
    while(n < lim){
        BinTree l, r;
        BinTree t;
        l = ar[j];
        r = ar[j+1];
        t = NewTree((ROOT(l) + ROOT(r)), l, r);
        ar[n] = t;
        j += 2;
        n++;
    }
    printTree(ar[lim-1], 2);
}