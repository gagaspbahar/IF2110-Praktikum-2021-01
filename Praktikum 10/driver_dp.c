// Driver Doubly Linked List - Gagas Praharsa Bahar

#include <stdio.h>
#include "list_dp.h"
#include "list_dp.c"

void addressPrinter(List l);

int main(){
    List l;
    int val;

    printf("--INITIALIZATION AND INSERTING--\n");
    CreateList(&l);
    if(isEmpty(l)){
        printf("kosong bos\n");
    }
    Address p = allocate(5);
    FIRST(l) = p;
    LAST(l) = p;
    insertFirst(&l, 10);
    displayList(l); printf("\n");
    insertLast(&l, 30);
    displayList(l); printf("\n");
    Address q = allocate(25);
    insertAfter(&l,q,p);
    displayList(l); printf("\n");
    // deleteLast(&l,&val); displayList(l); printf("\n");
    
    addressPrinter(l);

    Address r = search(l, 5);

    printf("--MISC--\n");
    

    List l2;
    CreateList(&l2);
    insertLast(&l2,5);
    insertFirst(&l2,6);
    insertLast(&l2,7);

    displayList(l2); printf("\n");
    displayListBackwards(l2); printf("\n");

    printf("--DELETE--\n");
    displayList(l); printf("\n");
    Address s;
    deleteAfter(&l,&s,r);
    displayList(l); printf(" %i", INFO(s)); printf("\n");
    // addressPrinter(l);
    printf("Last: %#X\n", LAST(l));

    Address z = allocate(26);
    r = search(l,30);
    insertAfter(&l,z,r);
    displayList(l); printf("\n");
    addressPrinter(l);
    deleteLast(&l,&val);
    displayList(l); printf(" %i", val); printf("\n");
    addressPrinter(l);
    deleteFirst(&l, &val);
    displayList(l); printf(" %i", val); printf("\n");
    // printf("First: %#X\n", FIRST(l));
    // printf("Last: %#X\n", LAST(l));
    addressPrinter(l);
    deleteLast(&l,&val);
    displayList(l); printf(" %i", val); printf("\n");
    addressPrinter(l);
    printf("%#X\n", PREV(r));
    // deleteFirst(&l, &val);
    // displayList(l); printf(" %i", val); printf("\n");
}

void addressPrinter(List l){
    Address p = FIRST(l);
    int cnt = 0;
    while(p != NULL){
        printf("Address %i = %#X\n", p->info, p);
        p = NEXT(p);
        cnt++;
    }
}