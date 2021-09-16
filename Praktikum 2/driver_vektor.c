#include <stdio.h>
#include "vector.h"
#include "vector.c"

int main() {
  VECTOR v1, v2;

  float x, y;
  printf("Masukkan vektor 1: ");
  scanf("%f %f", &x, &y);
  v1 = MakeVector(x, y);
  TulisVector(v1);
  printf("\n");

  printf("Masukkan vektor 2: ");
  scanf("%f %f", &x, &y);
  v2 = MakeVector(x, y);
  TulisVector(v2);
  printf("\n");

  printf("Magnitude dari vektor 1 adalah %.2f\n", Magnitude(v1));

  printf("Vektor 1 + Vektor 2 = ");
  TulisVector(Add(v1, v2));
  printf("\n");
  
  printf("Vektor 1 - Vektor 2 = ");
  TulisVector(Substract(v1, v2));
  printf("\n");

  printf("Vektor 1 . Vektor 2 = %.2f", Dot(v1, v2));
  printf("\n");

  printf("Masukkan suatu pengali: ");
  scanf("%f", &x);
  printf("Vektor 1 * %.2f = ", x);
  TulisVector(Multiply(v1, x));
  printf("\n");

  return 0;
}