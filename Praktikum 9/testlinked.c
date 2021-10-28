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

    printf("---NEW BEGINNING---\n");
    Address m = newNode(99);
    m->next = l2;
    l2 = m;

    displayList(l2); printf("\n");

    if(fSearch(l2, m)){
        printf("Ada!\n");
    }
    Address o = searchPrec(l2, 6);
    printf("%#X\n", o);

    int temp = mx(l2);
    printf("%i\n", temp);

    o = adrMax(l2);
    printf("%#X\n", o);

    temp = mn(l2);
    printf("%i\n", temp);

    o = adrMin(l2);
    printf("%#X\n", o);

    float tempf = average(l2);
    printf("%f\n", tempf);

    inverseList(&l2);
    displayList(l2); printf("\n");

    List l2copy;
    l2copy = fCopyList(l2);
    displayList(l2copy); printf(" l2copy\n");

    List l2rev;
    l2rev = fInverseList(l2);
    displayList(l2rev); printf(" l2rev\n");

    List l4;
    copyList(&l2, &l4);
    displayList(l4); printf(" l4(l2copy)\n");

    // printf("msk\n");


    List lAns1, lAns2;
    splitList(&lAns1, &lAns2, l3);
    displayList(lAns1); printf(" "); displayList(lAns2); printf(" l3 split\n");
}