// Gagas Praharsa Bahar
// 13520016
// Backspace


#include "stack_linked.h"
#include <stdio.h>


int main(){
    Stack s1;
    Stack s2;
    CreateStack(&s1);
    CreateStack(&s2);

    int n, m;
    scanf("%d %d", &m, &n);
    int temp;
    int tempbuangan;
    for(int i = 0; i < m; i++){
        scanf("%d", &temp);
        if(temp == 0){
            if(!isEmpty(s1)){
                pop(&s1, &tempbuangan);
            }
        }
        else if(temp > 0 && temp <= 9){
            push(&s1, temp);
        }
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        if(temp == 0){
            if(!isEmpty(s2)){
                pop(&s2, &tempbuangan);
            }
        }
        else if(temp > 0 && temp <= 9){
            push(&s2, temp);
        }
    }
    boolean flag = true;
    while(flag && (!isEmpty(s1) && !isEmpty(s2))){
        if(TOP(s1) == TOP(s2)){
            pop(&s1, &tempbuangan);
            pop(&s2, &tempbuangan);
        }
        else{
            flag = false;
        }
    }
    if(!isEmpty(s1) || !isEmpty(s2)){
        flag = false;
    }
    if(!flag){
        printf("Tidak sama\n");
    }
    else{
        printf("Sama\n");
    }
}