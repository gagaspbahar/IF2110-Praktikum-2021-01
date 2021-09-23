#include <stdio.h>
#include "matrix.h"
#include "matrix.c"
#include "matrixop.c"

int main() {
    /* KAMUS */
    int m, n;
    Matrix m1, m2, temp;
    ElType max, min;
    /* ALGORITMA */
    scanf("%d %d", &m, &n);
    readMatrix(&m1, m, n);
    printf("\n");
    
    printf("row mean: %lf\n",rowMean(m1,0));
    printf("col mean: %lf\n",colMean(m1,0));
    rowExtremes(m1,0,&max,&min);
    printf("row extremes: %d, %d\n",max, min);
    colExtremes(m1,0,&max,&min);
    printf("col extremes: %d, %d\n",max, min);
    printf("1 in row: %d\n", countValOnRow(m1,0,1));
    printf("1 in col: %d\n", countValOnCol(m1,0,1));
    
    scanf("%d %d", &m, &n);
    readMatrix(&m2, m, n);
    printf("\n");

    if (isEqual(m1, m2)) {
        printf("M1 = M2\n");
        printf("\n");
    }

    if (isIdentity(m1)) {
        printf("M1 adalah matriks identitas\n");
        printf("\n");
    }

    if (isIdentity(m2)) {
        printf("M2 adalah matriks identitas\n");
        printf("\n");
    }

    if (isSparse(m1)) {
        printf("M1 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSparse(m2)) {
        printf("M2 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSymmetric(m1)) {
        printf("M1 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSymmetric(m2)) {
        printf("M2 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSquare(m1)) {
        printf("Transpose M1 =\n");
        copyMatrix(m1, &temp);
        transpose(&temp);
        displayMatrix(temp);
        printf("\n\n");

        printf("Determinan M1 = %.2f\n", determinant(m1));
        printf("\n");
    }

    if (isSquare(m2)) {
        printf("Transpose M2 =\n");
        copyMatrix(m2, &temp);
        transpose(&temp);
        displayMatrix(temp);
        printf("\n\n");

        printf("Determinan M2 = %.2f\n", determinant(m2));
        printf("\n");
    }

    if (isSizeEqual(m1, m2)) {
        printf("M1 + M2 =\n");
        displayMatrix(addMatrix(m1, m2));
        printf("\n\n");

        printf("M1 - M2 =\n");
        displayMatrix(subtractMatrix(m1, m2));
        printf("\n\n");
    }

    if (COLS(m1) == ROWS(m2)) {
        printf("M1 x M2 =\n");
        displayMatrix(multiplyMatrix(m1, m2));
        printf("\n\n");
    }
}