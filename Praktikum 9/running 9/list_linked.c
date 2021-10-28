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


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address now;
    boolean flag = false;
    now = L;
    while(now->next != NULL && !flag){
        if(now==P){
            flag = true;
        }
        now = now->next;
    }
    return flag;
}


Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    Address p = L;
    Address prev;
    while(p != NULL && p->info != X){
        prev = p;
        p = p->next;
    }
    if(p == NULL){
        return NULL;
    }
    else{
        return prev;
    }
}


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
// ElType max(List l)
ElType max(List l)
{
    int mx;
    Address p = l;
    mx = p->info;
    while(p != NULL){
        if(p->info > mx){
            mx = p->info;
        }
        p = p->next;
    }
    return mx;
}
/* Mengirimkan nilai info(P) yang maksimum */

Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    int mxs = max(l);
    Address p = l;
    while(p != NULL && p->info != mxs){
        p = p->next;
    }
    return p;
}
// ElType min(List l);
ElType min(List l)
{
    int mn;
    Address p = l;
    mn = p->info;
    while(p != NULL){
        if(p->info < mn){
            mn = p->info;
        }
        p = p->next;
    }
    return mn;
}
/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    int mns = min(l);
    Address p = l;
    while(p != NULL && p->info != mns){
        p = p->next;
    }
    return p;
}

float average(List l)
/* Mengirimkan nilai rata-rata info(P) */
{
    float sum = 0;
    int n = 0;
    Address p = l;
    while(p != NULL){
        sum += p->info;
        n++;
        p = p->next;
    }
    return sum/n;
}



void delAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    Address p = *l;
    int val;
    while(p != NULL){
        deleteFirst(l, &val);
        p = p->next;
    }
    *l = NULL;
}


void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    if(!isEmpty(*l)){
        int n = length(*l);
        int i;
        Address p = *l;
        Address prev;
        Address last;
        while(p->next != NULL){
            p = p->next;
        }
        last = p;
        while (p != *l){
            prev = *l;
            while(prev->next != p){
                prev = prev->next;
            }
            p->next = prev;
            p = prev;
        }
        p->next = NULL;
        *l = last;
    }
}


List fInverseList(List l)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List ans;
    ans = fCopyList(l);
    inverseList(&ans);
    return ans;
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    *l2 = *l1;
}


List fCopyList(List l)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List ans;
    List empty;
    CreateList(&empty);
    CreateList(&ans);
    boolean flag = true;
    Address p = l;
    Address p2 = NULL;
    Address temp;
    while(p != NULL && flag){
        temp = newNode(p->info);
        if(temp != NULL){
            if(p2 == NULL){
                ans = temp;
            }
            else{
                p2->next = temp;
            }
            p = p->next;
        }
        else{
            flag = false;
        }
        p2 = temp;
    }
    if(flag){
        return ans;
    }
    else{
        delAll(&ans);
        copyList(&ans, &empty);
        return ans;
    }
}


void cpAllocList(List lIn, List *lOut)
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
{
    *lOut = fCopyList(lIn);
}


void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
{
    CreateList(l1);
    CreateList(l2);
    int half = length(l) / 2;
    int cnt = 0;
    Address p = l;
    while(p != NULL){
        if(cnt < half){
            insertLast(l1, p->info);
        }
        else{
            insertLast(l2, p->info);
        }
        cnt++;
        p = p->next;
    }
}