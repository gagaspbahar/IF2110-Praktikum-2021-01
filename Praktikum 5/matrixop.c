// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 23 September 2021
// Matrix Operations

#include "matrix.h"
#include <stdio.h>

float rowMean(Matrix m, Index i){
    int j;
    float sum = 0;
    for (j = 0; j < COLS(m); j++){
        sum += ELMT(m, i, j);
    }
    return sum/COLS(m);
}

float colMean(Matrix m, Index j)
{
    int i;
    float sum = 0;
    for (i = 0; i < ROWS(m); i++){
        sum += ELMT(m, i, j);
    }
    
    return sum/ROWS(m);
}

void rowExtremes(Matrix m, Index i, ElType *max, ElType *min){
    *max = ELMT(m,i,0);
    *min = *max;
    int j;
    for(j=1;j<COLS(m);j++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min){
            *min = ELMT(m,i,j);
        }
    }
}

void colExtremes(Matrix m, Index j, ElType *max, ElType *min){
    *max = ELMT(m,0,j);
    *min = *max;
    int i;
    for(i=1;i<ROWS(m); i++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min){
            *min = ELMT(m,i,j);
        }
    }
}

int countValOnRow(Matrix m, Index i, ElType val){
    int count = 0;
    int j;
    for(j = 0; j<COLS(m); j++){
        if(ELMT(m,i,j) == val){
            count += 1;
        }
    }
    return count;
}

int countValOnCol(Matrix m, Index j, ElType val){
    int count = 0;
    int i;
    for(i = 0; i<ROWS(m); i++){
        if(ELMT(m,i,j) == val){
            count += 1;
        }
    }
    return count;
}