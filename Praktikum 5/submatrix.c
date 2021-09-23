// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 23 September 2021
// SubMatrix
#include "matrix.h"
#include <stdio.h>

float sumSubmatrix(Matrix m, int startRow, int startCol, int n);

int main(){
    int tc;
    int t;
    int N;
    int sub;
    int tempsum;
    int maxsum;
    int startRow, startCol;
    Matrix m, ans;

    scanf("%d", &tc);
    for(t = 0; t<tc; t++){
        maxsum = 0;
        scanf("%d", &N);
        readMatrix(&m, N, N);
        scanf("%d", &sub);
        CreateMatrix(sub, sub, &ans);
        for(startRow=0; startRow<ROWS(m)-sub+1; startRow++){
            for(startCol=0; startCol<COLS(m)-sub+1;startCol++){
                tempsum = sumSubmatrix(m, startRow, startCol, sub);
                if (tempsum>maxsum){
                    maxsum = tempsum;
                }
            }
        }
        printf("%d\n", maxsum);
    }
}


float sumSubmatrix(Matrix m, int startRow, int startCol, int n){
    float sum = 0;
    int i, j;
    for(i=startRow;i<startRow+n;i++){
        for(j=startCol;j<startCol+n;j++){
            sum += ELMT(m,i,j);
        }
    }
    return sum;
}
/* Testcase:
1
5
9 10 2 3 4
3 2 2 2 1
10 9 2 2 2
9 10 3 4 5
5 6 9 4 0
2

return 38 */