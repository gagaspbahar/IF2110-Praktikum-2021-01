// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Caesar Cipher

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "charmachine.c"
// #include "wordmachine.c"
#include <stdio.h>

int main(){
    Word temp;
    int i;
    startWord();
    int geser = currentWord.length % 26;
    for(i = 0; i < currentWord.length; i++){
        temp.contents[i] = currentWord.contents[i] + geser;
        if(temp.contents[i] > 90){
            temp.contents[i] -= 26;
        }
        printf("%c", temp.contents[i]);
    }
    advWord();
    while(!endWord){
        printf(" ");
        int len = currentWord.length;
        temp.length = len;
        for(i = 0; i < len; i++){
            temp.contents[i] = currentWord.contents[i] + geser;
            if(temp.contents[i] > 90){
                temp.contents[i] -= 26;
            }
            printf("%c", temp.contents[i]);
        }
        advWord();
    }
    printf(".\n");
}