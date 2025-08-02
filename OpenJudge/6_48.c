#include <stdio.h>
#include <stdlib.h>

typedef struct binode{
    char data;
    struct binode *lchild,*rchild,*parent;
}Binode,*Bitree;

//用带父亲指针的递归建树
Bitree createTree(Bitree parent, char input) {
    if (input == '^') return NULL;
    Bitree T = (Bitree)malloc(sizeof(Binode));
    T->data = input;
    T->parent = parent;
    char c = getchar();
    T->lchild = createTree(T, c);
    c = getchar();
    T->rchild = createTree(T, c);
    return T;
}

//利用递归的思路来判断, 要求父节点不能是自己, 有点麻烦
char NearAnsce(Bitree T, char u, char v) {
    if (!T) return 0;
    if (T->data == u || T->data == v) {
        return T->parent ? T->parent->data : 0;
    }
    char anl = NearAnsce(T->lchild, u, v);
    char anr = NearAnsce(T->rchild, u, v);
    if (anl && anr)
        return T->data;
    else if (anl)
        return anl;
    else if (anr)
        return anr;
    return 0;
}



int main(){
    Bitree T;
    char c = getchar();
    T=createTree(NULL,c);
    //将第一行的回车吸收
    getchar();
    char u,v;
    scanf("%c %c",&u,&v);
    char n = NearAnsce(T,u,v);
    printf("%c",n);
    return 0;
}