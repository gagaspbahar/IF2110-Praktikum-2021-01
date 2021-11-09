// Gagas Praharsa Bahar
// 13520016
// ADT stack (Implementasi node)


#include "stack_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   
{
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL */
{
    return ADDR_TOP(s) == NULL;
}
void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = NULL;
}

void push(Stack *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address p;
    p = newNode(x);
    if(p != NULL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    Address p;
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NULL;
    free(p);
}