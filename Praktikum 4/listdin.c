// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 15 September 2021
// Dynamic List

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */



#include "boolean.h"
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
   BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
   NEFF(*l) = 0;
   CAPACITY(*l) = capacity;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
   free(BUFFER(*l));
   NEFF(*l) = 0;
   CAPACITY(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
   return NEFF(l);
}


/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   return NEFF(l) - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
   return (i >= 0 && i < NEFF(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
   return (NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
   return (NEFF(l) == CAPACITY(l));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
   int n, i;
   scanf("%i", &n);
   while (n < 0 || n > CAPACITY(*l)){
        scanf("%i", &n);
   }
   NEFF(*l) = n;
   if (n != 0){
      for (i=0; i<n; i++){
         scanf("%i", &ELMT(*l, i));
      }
   }
}

void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

{
   int i, len;
   len = length(l);
   printf("[");
   if (len != 0){
       for (i = 0; i < len-1; i++){
           printf("%i,", ELMT(l, i));
       }
       printf("%i", ELMT(l, len-1));
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
   ListDin l;
   int i, len;
   CreateListDin(&l, CAPACITY(l1));
   NEFF(l) = NEFF(l1);
   len = length(l1);
   if (plus){
       for (i=0; i<len; i++){
           ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
       }
   }
   else{
       for (i=0; i<len; i++){
           ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
       }
   }
   return l;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
   int i = 0;
   if (length(l1) == length(l2)){
      while (ELMT(l1, i) == ELMT(l2, i) && i != length(l1)){
          i++;
      }
      return (i == length(l1));
   }
   else{
      return false;
   }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
   if (isEmpty(l)){
      return IDX_UNDEF;
   }
   int i = 0;
   while ((ELMT(l,i) != val) && i != length(l)){
      i++;
   }
   if (i == length(l)){
      return IDX_UNDEF;
   }
   else{
      return i;
   }
}


/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    int i, len;
    len = length(l);
    for (i=1; i<len; i++){
        if (ELMT(l,i) > *max){
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min){
            *min = ELMT(l,i);
        }
    }
}
/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
   dealocate(lOut);
   CreateListDin(lOut, CAPACITY(lIn));
   int i;
   for (i = 0 ; i<NEFF(lIn); i++){
      ELMT(*lOut, i) = ELMT(lIn, i);
   }
   NEFF(*lOut) = NEFF(lIn);
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
   int i;
   int sum = 0;
   for (i = 0; i < length(l); i++){
      sum += ELMT(l,i);
   }
   return sum;
}

int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
   int count = 0;
   int i;
   for (i = 0; i<length(l); i++){
      if(ELMT(l,i) == val){
         count++;
      }
   }
   return count;
}

boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
   int i = 0;
   while (ELMT(l,i) % 2 == 0 && i != NEFF(l)){
      i++;
   }
   
   return (length(l) == i);
}
/* ********** SORTING ********** */
void swap(ListDin *l, int idx1, int idx2){
    int temp;
    temp = ELMT(*l, idx1);
    ELMT(*l, idx1) = ELMT(*l, idx2);
    ELMT(*l, idx2) = temp;
}
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
   int i, j;
   int len = length(*l);
   if (len > 1){
      if (asc) {
         for(i = 0; i < len; i++){
            for(j = 0; j < len-i-1; j++){
               if (ELMT(*l, j) > ELMT(*l, j+1)){
                  swap(l, j, j+1);
               }
            }
         }
      }
      else{
         for(i = 0; i < len; i++){
            for(j = 0; j < len-i-1; j++){
               if (ELMT(*l, j) < ELMT(*l, j+1)){
                  swap(l, j, j+1);
               }
            }
         }
      }
   }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   ELMT(*l, NEFF(*l)) = val;
   NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, NEFF(*l)-1);
   NEFF(*l)--;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
   // ListDin temp;
   // copyList(*l, &temp);
   // realloc(l, (CAPACITY(*l)+num)*sizeof(int));
   // copyList(temp, l);
   // CAPACITY(*l) += num;

   // ListDin temp;
   // CreateListDin(&temp, CAPACITY(*l));
   // copyList(*l, &temp);
   // dealocate(l);
   // CreateListDin(l, CAPACITY(temp)+num);
   // copyList(temp, l);
   // CAPACITY(*l) += num;

   ListDin temp;
   CreateListDin(&temp, CAPACITY(*l));
   copyList(*l, &temp);
   int tempNeff = NEFF(*l);
   dealocate(l);
   CreateListDin(l, CAPACITY(temp) + num);
   NEFF(*l) = tempNeff;
   
   int i;
   for (i = 0; i < length(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
   }
}


void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
   // ListDin temp;
   // copyList(*l, &temp);
   // realloc(l, (CAPACITY(*l)-num)*sizeof(int));
   // copyList(temp, l);
   // CAPACITY(*l) -= num;

   // ListDin temp;
   // CreateListDin(&temp, CAPACITY(*l));
   // copyList(*l, &temp);
   // dealocate(l);
   // CreateListDin(l, CAPACITY(temp)-num);
   // copyList(temp, l);
   // CAPACITY(*l) -= num;

   ListDin temp;
   CreateListDin(&temp, CAPACITY(*l));
   copyList(*l, &temp);
   int tempNeff = NEFF(*l);
   // dealocate(l);
   CreateListDin(l, CAPACITY(temp) - num);
   NEFF(*l) = tempNeff;
   if(CAPACITY(temp) - num < NEFF(*l)){
      NEFF(*l) = CAPACITY(temp) - num;
   }
   
   int i;
   for (i = 0; i < length(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
   }
}

void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
   shrinkList(l, CAPACITY(*l)-NEFF(*l));
}