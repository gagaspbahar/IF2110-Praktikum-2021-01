/* Nama: Gagas Praharsa Bahar
// NIM: 13520016
driver time */

#include <stdio.h>
#include "time.c"

int main(){
    TIME t, t1, t2;
    int s;

    //Fungsi fungsi awal

    BacaTIME(&t);
    TulisTIME(t);
    printf("\n");
    printf("Jam dalam satuan detik: %i\n", TIMEToDetik(t));
    
    printf("Apabila ditambah 1 detik: \n");
    TulisTIME(NextDetik(t));
    printf("\n");

    printf("Apabila ditambah 100 detik: \n");
    TulisTIME(NextNDetik(t, 100));
    printf("\n");

    printf("Apabila dikurang 1 detik: \n");
    TulisTIME(PrevDetik(t));
    printf("\n");

    printf("Apabila dikurang 100 detik: \n");
    TulisTIME(PrevNDetik(t, 100));
    printf("\n");

    printf("Masukkan detik: ");
    scanf("%i", &s);
    printf("Dalam bentuk jam: \n");
    TulisTIME(DetikToTIME(s));
    printf("\n");


    // fungsi/prosedur yang membutuhkan dua buah time

    printf("\n*YANG BERKAITAN DENGAN DUA TIME*\n");
    printf("Masukkan dua bentukan jam: \n");
    BacaTIME(&t1);
    BacaTIME(&t2);
    if (TEQ(t1, t2)){
        printf("Kedua jam adalah sama.\n");
    }
    else if(TNEQ(t1, t2)){
        printf("Kedua jam berbeda.\n");
    }
    if (TLT(t1, t2)){
        printf("Jam pertama lebih kecil dari jam kedua.\n");
    }
    else if(TGT(t1, t2)){
        printf("Jam pertama lebih besar dari jam kedua.\n");
    }

    printf("Durasi antara dua jam tersebut (t1-t2): %i\n", Durasi(t1, t2));
    printf("Durasi antara dua jam tersebut (t2-t1): %i\n", Durasi(t2, t1));
  
}