// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Big Integer


#include <stdio.h>
#include "stack.h"

int main(){
    Stack s1, s2, ans;
    int temp1, temp2;
    int carry = 0;
    CreateStack(&s1);
    CreateStack(&s2);
    CreateStack(&ans);
    char tempc;
    int i = 0;
    scanf("%c", &tempc);
    
    while(tempc != '#'){
        push(&s1, tempc - 48);
        scanf("%c", &tempc);
        i++;
    }

    i = 0;
    scanf("%c", &tempc);
    scanf("%c", &tempc);
    while(tempc != '#'){
        push(&s2, tempc - 48);
        scanf("%c", &tempc);
        i++;
    }

    while(!isEmpty(s1) && !isEmpty(s2)){
        pop(&s1, &temp1);
        pop(&s2, &temp2);
        push(&ans, (temp1+temp2+carry) % 10);
        carry = (temp1+temp2+carry) / 10;
    }
    if(isEmpty(s1)){
        while(!isEmpty(s2)){
            pop(&s2, &temp2);
            push(&ans, (temp2+carry) % 10);
            carry = (temp2+carry)/10;
        }
    }
    else{
        while(!isEmpty(s1)){
            pop(&s1, &temp1);
            push(&ans, (temp1+carry) % 10);
            carry = (temp1+carry)/10;
        }
    }
    
    if(carry != 0){
        push(&ans, carry);
    }

    while(!isEmpty(ans)){
        pop(&ans, &temp1);
        printf("%i", temp1);
    }
    printf("\n");
}

// 12345678#
// 123456789#

// 0#
// 12345#