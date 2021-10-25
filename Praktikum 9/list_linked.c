// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// ADT Linked List


#include "list_linked.h"
#include <stdio.h>


/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    *l = NULL;
}


/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (l == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    int cnt = 0;
    Address p = l;
    while(cnt < idx){
        cnt++;
        p = p->next;
    }
    return(p->info);
}
void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    int cnt = 0;
    Address p = *l;
    while(cnt < idx){
        cnt++;
        p = p->next;
    }
    p->info = val;
}
int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int cnt = 0;
    Address p = l;
    boolean found = false;
    while(p != NULL && !found){
        if(p->info == val){
            found=true;
        }
        else{
            cnt++;
            p = p->next;
        }
    }
    if(found){
        return cnt;
    }
    else{
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p;
    p = newNode(val);
    if(p != NULL){
        p->next = *l;
        *l = p;
    }
}


void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address p, last;
        p = newNode(val);
        if(p != NULL){
            last = *l;
            while(last->next != NULL){
                last = last->next;
            }
            last->next = p;
        }
    }
}


void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    int cnt = 0;
    Address p, loc;
    if(idx==0){
        insertFirst(l, val);
    }
    else{
        p = newNode(val);
        if(p != NULL){
            loc = *l;
            while(cnt<idx-1){
                cnt++;
                loc = loc->next;
            }
            p->next = loc->next;
            loc->next = p;
        }
    }
}



/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = *l;
    *val = p->info;
    *l = p->next;
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = *l;
    Address loc = NULL;
    while(p->next != NULL){
        loc = p;
        p = p->next;
    }
    if(loc==NULL){
        *l = NULL;
    }
    else{
        loc->next = NULL;
    }
    *val = p->info;
    free(p);

}


void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    if(idx == 0){
        deleteFirst(l, val);
    }
    else{
        int cnt = 0;
        Address p, loc;
        loc = *l;
        while(cnt<idx-1){
            cnt++;
            loc = loc->next;
        }
        p = loc->next;
        *val = p->info;
        loc->next = p->next;
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    Address p = l;
    printf("[");
    while(p != NULL){
        if(p->next == NULL){
            printf("%i", p->info);
        }
        else{
            printf("%i,", p->info);
        }
        p = p->next;
    }
    printf("]");
}


int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    Address p = l;
    if(isEmpty(l)){
        return cnt;
    }
    else{
        while(p != NULL){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) 
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);
    Address p = l1;
    while(p != NULL){
        insertLast(&l3, p->info);
        p = p->next;
    }
    p = l2;
    while(p != NULL){
        insertLast(&l3, p->info);
        p = p->next;
    }
    return l3;
}