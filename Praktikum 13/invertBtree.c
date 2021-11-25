// Gagas Praharsa Bahar
// 13520016
// Invert Binary Tree

#include <stdio.h>
#include "bintree.h"

void invertBtree(BinTree *p){
    // I.S. Pohon p terdefinisi
    // F.S. Pohon p diflip secara vertikal
    if(!isTreeEmpty(*p)){
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
        *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
    }
}

// int main(){
//     Address l1 = newTreeNode(3);
//     Address l2 = newTreeNode(4);
//     BinTree l = NewTree(2, l1, l2);
//     Address r1 = newTreeNode(6);
//     BinTree r = NewTree(5, r1, NULL);
//     BinTree b = NewTree(1, l, r);
//     printTree(b, 2);
//     invertBtree(&b);
//     printTree(b,2);
// }