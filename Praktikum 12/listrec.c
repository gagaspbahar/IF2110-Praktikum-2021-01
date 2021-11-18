// Gagas Praharsa Bahar
// 13520016
// List Rekursif

#include "listrec.h"

/* Manajemen Memori */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}


/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return (l == NULL);
}

int isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return (!isEmpty(l) && isEmpty(tail(l)));
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return INFO(l);
}

List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    return NEXT(l);
}

List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    Address p;
    p = newNode(e);
    if (p == NULL){
        return l;
    }
    else{
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
    if(isEmpty(l)){
        return newNode(e);
    }
    else{
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}


/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if(isEmpty(l)){
        return 0;
    }
    else{
        return 1 + length(tail(l));
    }
}

void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if(!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}


ElType maxList(List l){
    if(isOneElmt(l)){
        return head(l);
    }
    else{
        if(head(l) > head(tail(l))){
            return maxList(konso(tail(tail(l)), head(l)));
        }
        else{
            return maxList(tail(l));
        }
    }
}

ElType minList(List l){
    if(isOneElmt(l)){
        return head(l);
    }
    else{
        if(head(l) < head(tail(l))){
            return minList(konso(tail(tail(l)), head(l)));
        }
        else{
            return minList(tail(l));
        }
    }
}

ElType sumList(List l){
    if(isEmpty(l)){
        return 0;
    }
    else{
        return head(l) + sumList(tail(l));
    }
}

float averageList(List l){
    float sum = sumList(l);
    float len = length(l);
    return sum/len;
}

List inverseList(List l){
    if(isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{
        return konsb(inverseList(tail(l)), head(l));
    }
}


void splitPosNeg(List l, List *l1, List *l2){
    if(isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        if(head(l) >= 0){
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        }
        else{
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2){
    if(isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        splitOnX(tail(l), x, l1, l2);
        if(head(l) < x){
            *l1 = konso(*l1, head(l));
        }
        else{
            *l2 = konso(*l2, head(l));
        }
   
    }
}
int compareList(List l1, List l2){
    if(isEmpty(l1)){
        if(isEmpty(l2)){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        if (isEmpty(l2)){
            return 1;
        }
        else if(head(l1) < head(l2)){
            return -1;
        }
        else if(head(l1) > head(l2)){
            return 1;
        }
        else{
            return compareList(tail(l1), tail(l2));
        }
    }
}

boolean isInList(List l, ElType x){
    if(isEmpty(l)){
        return false;
    }
    else{
        if(head(l) == x){
            return true;
        }
        else{
            return isInList(tail(l), x);
        }
    }
}

boolean isAllExist(List l1, List l2){
    if(!isEmpty(l1)){
        return(isInList(l2, head(l1)) && isAllExist(tail(l1), l2));
    }
}
