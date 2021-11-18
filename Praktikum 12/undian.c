// Gagas Praharsa Bahar
// 13520016
// Undian

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

List elemenGanjil(List l);
List elemenGenap(List l);
List invList(List l);
List elementsBeforeX(List l, ElType x);

int main(){
    char ch;
    int k;
    List l = NULL;
    do
    {
        scanf("%c", &ch);
        if(ch == 'F'){
            scanf("%i", &k);
            l = konso(l, k);
        }
        else if(ch == 'B'){
            scanf("%i", &k);
            l = konsb(l, k);
        }
        else if(ch == 'O'){
            l = elemenGanjil(l);
        }
        else if(ch == 'E'){
            l = elemenGenap(l);
        }
        else if(ch == 'R'){
            l = invList(l);
        }
        else if(ch == 'P'){
            scanf("%i", &k);
            l = elementsBeforeX(l, k);
        }
    } while (ch != 'X');

    if(isEmpty(l)){
        printf("Semua gugur\n");
    }
    else{
        displayList(l);
    }
}

List elemenGanjil(List l){
    if(isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else if(length(l) == 2){
        return konso(NULL, head(l));
    }
    else{
        return konso(elemenGanjil(tail(tail(l))), head(l));
    }
}

List elemenGenap(List l){
    if(isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return NULL;
    }
    else{
        return konso(elemenGenap(tail(tail(l))), head(tail(l)));
    }
}

List invList(List l){
    if(isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{
        return konsb(invList(tail(l)), head(l));
    }
}

List elementsBeforeX(List l, ElType x){
    if(isEmpty(l)){
        return NULL;
    }
    if(head(l) == x){
        return NULL;
    }
    else{
        return konso(elementsBeforeX(tail(l), x), head(l));
    }
}