// NIM: 13520016
// Nama: Gagas Praharsa Bahar
// 16 September 2021
// Dynamic List Pos


#include "boolean.h"
#include "listdinpos.h"
#include <stdio.h>
#include <stdlib.h>

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  List kosong: semua elemen bernilai VAL_UNDEF
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
                                             sehingga l.buffer[i] != VAL_UNDEF
  Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
                                             dan l.buffer[nEff-1] != VAL_UNDEF */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
{
   BUFFER(*l) = (int*) malloc(capacity*sizeof(int));
   CAPACITY(*l) = capacity;
   int i;
   for (i = 0; i<CAPACITY(*l); i++){
      ELMT(*l, i) = VAL_UNDEF;
   }
}
void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
{
   free(BUFFER(*l));
   CAPACITY(*l) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
   int i = 0;
   while (ELMT(l, i) != VAL_UNDEF && i != CAPACITY(l)){
      i++;
   }
   return (i);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   return length(l) - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
{
   return (i >= 0 && i < length(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
   return (length(l) == 0);
}

/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
   return (length(l) == CAPACITY(l));
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
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
   int n;
   int i;  
   scanf("%i", &n);
   while (n < 0 || n > CAPACITY(*l)){
      scanf("%i", &n);
   }
   CreateListDin(l, n);
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
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
   ListDin l;
   int i, len;
   CreateListDin(&l, CAPACITY(l1));
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
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan VAL_UNDEF */
/* Menghasilkan nilai tak terdefinisi (VAL_UNDEF) jika list l kosong */
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
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
   dealocate(lOut);
   CreateListDin(lOut, CAPACITY(lIn));
   int i;
   for (i = 0 ; i<length(lIn); i++){
      ELMT(*lOut, i) = ELMT(lIn, i);
   }
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
   while (ELMT(l,i) % 2 == 0 && i != length(l)){
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
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   ELMT(*l, length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, length(*l)-1);
   ELMT(*l, length(*l)-1) = VAL_UNDEF;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
   ListDin temp;
   CreateListDin(&temp, CAPACITY(*l));
   copyList(*l, &temp);
   dealocate(l);
   CreateListDin(l, CAPACITY(temp) + num);
   
   int i;
   for (i = 0; i < length(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
   }
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
   ListDin temp;
   CreateListDin(&temp, CAPACITY(*l));
   copyList(*l, &temp);
   dealocate(l);
   CreateListDin(l, CAPACITY(temp) - num);
   
   int i;
   for (i = 0; i < length(temp); i++) {
      ELMT(*l, i) = ELMT(temp, i);
   }
}
void compactList(ListDin *l)
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
{
   shrinkList(l, CAPACITY(*l)-length(*l));
}
