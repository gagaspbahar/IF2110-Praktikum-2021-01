// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Driver Point

#include <stdio.h>
#include "point.c"

int main(){
    POINT p;
    POINT p1, p2;

    //fungsi-fungsi awal
    printf("Masukkan point: ");
    BacaPOINT(&p);
    TulisPOINT(p);
    printf("\n");
    if (IsOrigin(p)){
        printf("Titik tersebut adalah titik origin.\n");
    }
    else{
        if (IsOnSbX(p)){
            printf("Titik tersebut terletak pada sumbu X.\n");
        }
        else if (IsOnSbY(p)){
            printf("Titik tersebut terletak pada sumbu Y.\n");
        }
    }
    //fungsi (satu variabel)
    printf("Kuadran dari titik diatas adalah Kuadran %i.\n", Kuadran(p));
    
    printf("Apabila point digeser satu ke kanan: ");
    TulisPOINT(NextX(p));
    printf("\n");

    printf("Apabila point digeser satu ke atas: ");
    TulisPOINT(NextY(p));
    printf("\n");

    printf("Apabila point digeser dua ke atas dan dua ke kanan: ");
    TulisPOINT(PlusDelta(p, 1, 1));
    printf("\n");

    printf("Pencerminan terhadap sumbu X dari point tersebut adalah: ");
    TulisPOINT(MirrorOf(p, 1));
    printf("\n");

    printf("Pencerminan terhadap sumbu Y dari point tersebut adalah: ");
    TulisPOINT(MirrorOf(p, 0));
    printf("\n");

    printf("Jarak point tersebut dari origin adalah: %.2f\n", Jarak0(p));

    // prosedur
    printf("\n*PROSEDUR*\nPoint sebelum diubah oleh prosedur-prosedur: ");
    TulisPOINT(p);
    printf("\n");

    GeserKeSbX(&p);
    printf("Apabila digeser ke Sumbu X: ");
    TulisPOINT(p);
    printf("\n");

    GeserKeSbY(&p);
    printf("Apabila digeser ke Sumbu Y: ");
    TulisPOINT(p);
    printf("\n");

    Geser(&p, 2, 1);
    printf("Apabila digeser ke <2,1>: ");
    TulisPOINT(p);
    printf("\n");

    Mirror(&p, 1);
    printf("Apabila dicerminkan terhadap sb. X: ");
    TulisPOINT(p);
    printf("\n");

    Mirror(&p, 0);
    printf("Apabila dicerminkan terhadap sb. Y: ");
    TulisPOINT(p);
    printf("\n");

    Putar(&p, 90);
    printf("Apabila diputar 90 derajat terhadap origin: ");
    TulisPOINT(p);
    printf("\n");

    //fungsi yang membutuhkan dua titik
    printf("\n*YANG MEMBUTUHKAN DUA TITIK*\n");
    printf("Masukkan dua titik: \n");
    BacaPOINT(&p1);
    BacaPOINT(&p2);
    if (EQ(p1, p2)){
        printf("Kedua titik adalah sama.\n");
    }
    else if(NEQ(p1, p2)){
        printf("Kedua titik berbeda.\n");
    }

    printf("Jarak antara kedua titik tersebut adalah: %.2f\n", Panjang(p1,p2));



}
