// Gagas Praharsa Bahar
// 13520016
// ADT List Doubly Linked

#include <stdio.h>
#include <stdlib.h>
#include "list_dp.h"

/* Definisi list : */
/* List kosong : First(L) = NULL dan Last(L) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FIRST(l) == NULL && LAST(l) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
{
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
}


void deallocate (Address p)
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    free(p);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    Address p = FIRST(l);
    boolean found = false;
    while(p != NULL && !found){
        if(p->info == val){
            found = true;
        }
        else{
            p = p->next;
        }
    }
    if(found){
        return p;
    }
    else{
        return NULL;
    }
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    Address p = allocate(val);
    if(p != NULL){
        NEXT(p) = FIRST(*l);
        if(!isEmpty(*l)){
            PREV(FIRST(*l)) = p;
        }
        else{
            LAST(*l) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = allocate(val);
    if(p != NULL){
        PREV(p) = LAST(*l);
        if(!isEmpty(*l)){
            NEXT(LAST(*l)) = p;
        }
        else{
            FIRST(*l) = p;
        }
        LAST(*l) = p;
    }
}

void insertAfter(List *L, Address p, Address pRec)
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
{
    if(NEXT(pRec) != NULL){
        NEXT(p) = NEXT(pRec);
        PREV(p) = pRec;
        PREV(NEXT(pRec)) = p;
        NEXT(pRec) = p;
    }
    else{
        PREV(p) = LAST(*L);
        LAST(*L) = p;
        NEXT(p) = NULL;
        NEXT(pRec) = p;
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    *val = INFO(p);
    if(FIRST(*l) == LAST(*l)){
        LAST(*l) = NULL;
    }
    else{
        PREV(NEXT(FIRST(*l))) = NULL;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = LAST(*l);
    *val = INFO(p);
    if(FIRST(*l) == LAST(*l)){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(PREV(LAST(*l))) = NULL;
    }
    LAST(*l) = PREV(LAST(*l));
    free(p);
}

void deleteAfter(List *l, Address *pDel, Address pRec)
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */
{
    if(NEXT(NEXT(pRec)) != NULL){
        *pDel = NEXT(pRec);
        PREV(NEXT(NEXT(pRec))) = pRec;
        NEXT(pRec) = NEXT(NEXT(pRec));
    }
    else{
        *pDel = NEXT(pRec);
        LAST(*l) = pRec;
        NEXT(pRec) = NULL;
    }
    
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    Address p = l.first;
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

void displayListBackwards(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    Address p = l.last;
    printf("[");
    while(p != NULL){
        if(p->prev == NULL){
            printf("%i", p->info);
        }
        else{
            printf("%i,", p->info);
        }
        p = p->prev;
    }
    printf("]");
}