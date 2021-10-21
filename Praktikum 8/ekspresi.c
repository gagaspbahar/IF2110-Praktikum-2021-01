// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Mesin Ekspresi

#include <stdio.h>
#include "stack.h"
#include "tokenmachine.h"
#include <math.h>


int evaluate(int a, int b, char t){
    if(t == '+'){
        return a+b;
    }
    else if(t == '-'){
        return a-b;
    }
    else if(t == '*'){
        return a*b;
    }
    else if(t == '/'){
        return a/b;
    }
    else if(t == '^'){
        return pow(a,b);
    }
}

boolean isOp(char c){
    int i;
    char tokens[] = "+-*/^";
    boolean flag = false;
    for(i = 0; i < 5; i++){
        if(c == tokens[i]){
            flag = true;
        }
    }
    return flag;
}

int main(){
    Stack s;
    int temp1, temp2;
    CreateStack(&s);
    startToken();
    if(endToken){
        printf("Ekspresi kosong\n");
    }
    else{
        while(!endToken){
            if (!isOp(currentToken.tkn)){
                push(&s, currentToken.val);
                printf("%i\n", currentToken.val);
            }
            else{
                pop(&s, &temp2);
                pop(&s, &temp1);
                printf("%i %c %i\n", temp1, currentToken.tkn, temp2);
                push(&s, evaluate(temp1, temp2, currentToken.tkn));
                printf("%i\n", TOP(s));
            }
            advToken();
        }
        printf("Hasil=%i\n", TOP(s));
    } 
}

// 25 10 * 15 +.
// 4 5 * 3 10 * 1 3 + / +.
// 25 .
// .