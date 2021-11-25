// Gagas Praharsa Bahar
// 13520016
// ADT Binary Tree

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    Address t = newTreeNode(root);
    if(t != NULL){
        t->left = left_tree;
        t->right = right_tree;
    }
    return t;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    *p = newTreeNode(root);
    if(*p != NULL){
        (*p)->left = left_tree;
        (*p)->right = right_tree;
    }
}


Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
{
    Address p = (Address) malloc(sizeof(TreeNode));
    if(p != NULL){
        p->info = val;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    return p == NULL;
}


boolean isOneElmt (BinTree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    if(!isTreeEmpty(p)){
        return p->left == NULL && p->right == NULL;
    }
    else{
        return false;
    }
}

boolean isUnerLeft (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */
{
    if(!isTreeEmpty(p)){
        return p->left != NULL && p->right == NULL;
    }
    else{
        return false;
    }
}


boolean isUnerRight (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */
{
    if(!isTreeEmpty(p)){
        return p->left == NULL && p->right != NULL;
    }
    else{
        return false;
    }
}
boolean isBinary (BinTree p)
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */
{
    if(!isTreeEmpty(p)){
        return p->right != NULL && p->left != NULL;
    }
    else{
        return false;
    }
}
/* ****** Display Tree ***** */
void printPreorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printf("%d", p->info);
        printPreorder(p->left);
        printPreorder(p->right);
        printf(")");
    }
}


void printInorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printInorder(p->left);
        printf("%d", p->info);
        printInorder(p->right);
        printf(")");
    }
}


void printPostorder(BinTree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printPostorder(p->left);
        printPostorder(p->right);
        printf("%d", p->info);
        printf(")");
    }
}


void recursivePrintTree(BinTree p, int h, int dep){
    if(!isTreeEmpty(p)){
        for(int i = 0; i < h*dep; i++){
            printf(" ");
        }
        printf("%d\n", p->info);
        recursivePrintTree(p->left, h, dep+1);
        recursivePrintTree(p->right, h, dep+1);
    }
}
void printTree(BinTree p, int h)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    recursivePrintTree(p,h,0);
}
