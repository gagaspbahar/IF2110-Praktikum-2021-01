#include <stdio.h>
#include "node.h"
#include "node.c"
#include "list_linked.h"
#include "list_linked.c"
#include "boolean.h"

int main(){
    List l;
    int val;

    printf("--INITIALIZATION AND INSERTING--\n");
    CreateList(&l);
    if(isEmpty(l)){
        printf("kosong bos\n");
    }
    insertFirst(&l, 10);
    displayList(l); printf("\n");
    insertLast(&l, 30);
    displayList(l); printf("\n");
    insertAt(&l,20,2);
    displayList(l); printf("\n");

    printf("--MISC--\n");
    setElmt(&l, 2, 50);
    printf("Second Element: %i\n", getElmt(l, 1));
    printf("Index of 20: %i\n", indexOf(l,20));
    printf("Length: %i\n", length(l));

    printf("--CONCAT--\n");
    List l2, l3;
    CreateList(&l2);
    insertLast(&l2,5);
    insertFirst(&l2,6);
    insertLast(&l2,7);
    insertAt(&l2,2,3);

    displayList(l2); printf("\n");
    l3 = concat(l,l2);

    displayList(l3); printf("\n");
    

    printf("--DELETE--\n");
    deleteFirst(&l, &val);
    displayList(l); printf(" %i", val); printf("\n");
    deleteAt(&l,1,&val);
    displayList(l); printf(" %i", val); printf("\n");
    deleteLast(&l,&val);
    displayList(l); printf(" %i", val); printf("\n");
}