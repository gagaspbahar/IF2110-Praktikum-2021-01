// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 21 September 2021
// Matrix

#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
   (*m).colEff = nCol;
   (*m).rowEff = nRow;

   int i, j;
   for (i = 0; i < nRow; i++){
      for (j=0; j < nCol; j++){
         ELMT(*m,i,j) = 0;
      }
   }
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
   return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
   return (m.rowEff - 1);
}
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m){
   return m.colEff - 1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
   return (i >= 0 && i < m.rowEff) && (j >= 0 && j < m.colEff);
}
ElType getElmtDiagonal(Matrix m, Index i)
/* Mengirimkan elemen m(i,i) */
{
   return ELMT(m,i,i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
   CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
   int i, j;
   for(i = 0; i < ROWS(*mRes); i++){
      for(j = 0; j < COLS(*mRes); j++){
         ELMT(*mRes, i, j) = ELMT(mIn, i, j);
      }
   }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
   CreateMatrix(nRow, nCol, m);
   int i, j;
   for(i=0;i<nRow;i++){
      for(j=0;j<nCol;j++){
         scanf("%i", &ELMT(*m,i,j));
      }
   }
}

void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
   int i, j;
   for (i = 0; i < m.rowEff; i++){
      for (j = 0; j < m.colEff; j++){
         if(j == m.colEff-1){
            if (i == m.rowEff-1){
               printf("%d", ELMT(m,i,j));
            }
            else{
               printf("%i\n", ELMT(m,i,j));
            }
         }
         else{
            printf("%i ", ELMT(m,i,j));
         }
      }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
   Matrix mAns;
   copyMatrix(m1, &mAns);
   int i,j;
   for (i=0; i<ROWS(mAns); i++){
      for(j=0;j<COLS(mAns);j++){
         ELMT(mAns,i,j) += ELMT(m2,i,j);
      }
   }
   return mAns;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
   Matrix mAns;
   copyMatrix(m1, &mAns);
   int i,j;
   for (i=0; i<ROWS(mAns); i++){
      for(j=0;j<COLS(mAns);j++){
         ELMT(mAns,i,j) -= ELMT(m2,i,j);
      }
   }
   return mAns;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
   Matrix ans;
   CreateMatrix(ROWS(m1), COLS(m2), &ans);
   int i, j, k;
   for(i = 0; i < ROWS(ans); i++){
      for(j = 0; j < COLS(ans); j++){
         int temp = 0;
         for (k=0; k < COLS(m1); k++){
            temp += (ELMT(m1,i,k) * ELMT(m2,k,j));
         }
         ELMT(ans,i,j) = temp;
      }
   }
   return ans;
}
Matrix multiplyConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
   Matrix mAns;
   copyMatrix(m, &mAns);
   int i,j;
   for (i=0; i<ROWS(mAns); i++){
      for(j=0;j<COLS(mAns);j++){
         ELMT(mAns,i,j) *= x;
      }
   }
   return mAns;
}
void pMultiplyConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
   int i,j;
   for (i=0; i<ROWS(*m); i++){
      for(j=0;j<COLS(*m);j++){
         ELMT(*m,i,j) *= k;
      }
   }
}



/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
   int i = 0, j = 0;
   boolean flag = true;
   if(count(m1) == count(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)){
      while (flag && i < ROWS(m1)){
         j=0;
         while(flag && j < COLS(m1)){
            if (ELMT(m1,i,j) != ELMT(m2,i,j)){
               flag = false;
            }
            else{
               j++;
            }
         }
         i++;
      }
      return flag;
   }
   else{
      return false;
   }
}
boolean isNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
   return !isEqual(m1,m2);
}
boolean isSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
   return(m1.rowEff == m2.rowEff) && (m1.colEff == m2.colEff);
}
/* ********** Operasi lain ********** */
int count(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
   return(m.rowEff*m.colEff);
}
/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
   return(m.rowEff==m.colEff);
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
   if (isSquare(m)){
      boolean flag = true;
      int i = 0, j = 0;
      while (i<ROWS(m) && flag){
         j = 0;
         while(j<COLS(m) && flag){
            if (ELMT(m, i, j) != ELMT(m, j, i)){
               flag = false;
            }
            j++;
         }
         i++;
      }
      return flag;
   }
   else{
      return false;
   }
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
   int i, j;
   boolean flag = true;
   if (isSquare(m)) {
      i = 0;
      while (i < ROWS(m) && flag) {
         j = 0;
         while (j < COLS(m) && flag) {
            if (i == j) {
               if (ELMT(m, i, j) != 1) {
                  flag = false;
               } else {
                  j++;
               }
            } else {
               if (ELMT(m, i, j) != 0) {
                  flag = false;
               } else {
                  j++;
               }
            }
         }
         i ++;
      }
      return flag;
   } else {
      return false;
   }
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
   int i,j;
   int max = (5*count(m))/100;
   int cnt = 0;
   for(i = 0; i<ROWS(m); i++){
      for(j = 0; j<COLS(m); j++){
         if (ELMT(m,i,j) != 0){
            cnt += 1;
         }
      }
   }
   return cnt <= max;
}
Matrix inverse1(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
   return multiplyConst(m, -1);
}
void pInverse1(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
   pMultiplyConst(m, -1);
}

void swap(Matrix *m, int i1, int j1, int i2, int j2){
    ElType temp;
    temp = ELMT(*m, i1, j1);
    ELMT(*m, i1, j1) = ELMT(*m, i2, j2);
    ELMT(*m, i2, j2) = temp;
}

float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
   if (!isSquare(m)){
      return 0;
   }
   int n = getLastIdxRow(m) + 1;
   int tmpRow[11];
   int i, j, k, idx, temp1, temp2;
   int det = 1;
   int co = 1;
   for(i = 0; i < n; i++){
      idx = i;
      while(ELMT(m,idx,i) == 0 && idx < n){
         idx++;
      }
      if (idx == n){
         return 0;
      }
      if (i != idx){
         for(j = 0; j < n; j++){
            swap(&m, idx, j, i, j);
         }
         det *= -1;
      }
      for(j = 0;j<n;j++){
         tmpRow[j] = ELMT(m,i,j);
      }
      for (j=i+1; j<n; j++){
         temp1 = tmpRow[i];
         temp2 = ELMT(m,j,i);
         for(k=0;k<n;k++){
            ELMT(m,j,k) = ((temp1 * ELMT(m,j,k)) - (temp2 * tmpRow[k]));
         }
         co *= temp1;
      }
   }
   for(i=0;i<n;i++){
      det *= ELMT(m,i,i);
   }
   return det/co;
}
void transpose(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
   Matrix temp;
   CreateMatrix(COLS(*m), ROWS(*m), &temp);
   int i, j;
   for(i=0;i<ROWS(*m);i++){
      for(j=0;j<COLS(*m);j++){
         ELMT(temp,i,j) = ELMT(*m,j,i);
      }
   }
   copyMatrix(temp,m);
}

