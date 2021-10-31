// Driver Circular List - Gagas Praharsa Bahar

#include <stdio.h>
#include "list_circular.h"
#include "list_circular.c"

void addressPrinter(List l);

int main(){
    List l;
    int val;

    printf("--INITIALIZATION AND INSERTING--\n");
    CreateList(&l);
    if(isEmpty(l)){
        printf("kosong bos\n");
    }
    // Address p = allocate(5);
    // FIRST(l) = p;
    displayList(l); printf("\n");
    insertLast(&l, 30);
    displayList(l); printf("\n");
    insertFirst(&l, 10);
    displayList(l); printf("\n");
    insertLast(&l, 20);
    displayList(l); printf("\n");
    insertFirst(&l, 15);
    displayList(l); printf("\n");

    Address r = search(l, 30);
    if(addrSearch(l,r)){
        printf("search aman bos!\n");
    }

    Address q = allocate(25);
    // insertAfter(&l,q,p);
    // displayList(l); printf("\n");
    // deleteLast(&l,&val); displayList(l); printf("\n");
    
    // addressPrinter(l);


    // printf("--MISC--\n");
    

    // List l2;
    // CreateList(&l2);
    // insertLast(&l2,5);
    // insertFirst(&l2,6);
    // insertLast(&l2,7);

    // displayList(l2); printf("\n");

    printf("--DELETE--\n");
    displayList(l); printf("\n");
    // printf("%i\n", INFO(NEXT(q)));
    // Address s;
    // deleteAfter(&l,&s,r);
    // displayList(l); printf(" %i", INFO(s)); printf("\n");
    // addressPrinter(l);
    // printf("Last: %#X\n", LAST(l));

    deleteLast(&l,&val);
    displayList(l); printf(" %i", val); printf("\n");
    // addressPrinter(l);
    deleteFirst(&l, &val);
    displayList(l); printf(" %i", val); printf("\n");
    // addressPrinter(l);
    deleteFirst(&l, &val);
    displayList(l); printf(" %i", val); printf("\n");
    deleteFirst(&l, &val);
    displayList(l); printf(" %i", val); printf("\n");
}

void addressPrinter(List l){
    Address p = FIRST(l);
    int cnt = 0;
    while(p != NULL){
        printf("Address %i = %#X\n", cnt, p);
        p = NEXT(p);
        cnt++;
    }
}