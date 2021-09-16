#include <stdio.h>
#include "garis.c"

int main() {
  GARIS l1, l2;
  float dx, dy;

  BacaGARIS(&l1);
  printf("Garis 1: ");
  TulisGARIS(l1);

  printf("\n");
  
  BacaGARIS(&l2);
  printf("Garis 2: ");
  TulisGARIS(l2);

  printf("\n");
  
  printf("Panjang garis 1: %.2f\n", PanjangGARIS(l1));
  printf("Gradien garis 1: %.2f\n", Gradien(l1));

  printf("Masukkan dx dan dy: ");
  scanf("%f %f", &dx, &dy);
  GeserGARIS(&l2, dx, dy);
  printf("Garis 2 setelah digeser: ");
  TulisGARIS(l2);
  
  printf("\n");

  if (IsTegakLurus(l1, l2)) {
    printf("Garis 1 dan garis 2 tegak lurus.\n");
  } 
  if (IsSejajar(l1, l2)) {
    printf("Garis 1 dan garis 2 sejajar.\n");
  }

  return 0;
}