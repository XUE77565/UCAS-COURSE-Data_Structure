#include <stdio.h>
#include <stdlib.h>


typedef struct binode {
    int data;
    struct binode *lchild, *rchild;
} Binode, *Bitree;

// 插入节点
Bitree Insert(Bitree T, int data) {
    if (!T) {
        Binode *p  =  (Binode *)malloc(sizeof(Binode));
        p->data  =  data;
        p->lchild  =  p->rchild  =  NULL;
        return p;
    }
    if(data  ==  -1){return T;}
    if (data < T->data) {
        T->lchild  =  Insert(T->lchild, data);
    } else if (data > T->data) {
        T->rchild  =  Insert(T->rchild, data);
    }
    // 相等的时候不插入
    return T;
}

Bitree Merge(Bitree T1, Bitree T2){
    if(!T2){
        return T1;
    }
    T1  =  Insert(T1,T2->data);
    T1  =  Merge(T1, T2->lchild);
    T1  =  Merge(T1, T2->rchild);
    return T1;
}

void printInorder(Bitree T){
    if(!T){
        return;
    }
    printInorder(T->lchild);
    printf("%d ",T->data);
    printInorder(T->rchild);
}

int main() {
    int n, top1  =  0, top2 = 0,tmp1[100],tmp2[100];
    char c;
    while (scanf("%d%c", &n, &c)  ==  2) {
        tmp1[top1++]  =  n;
        if (c  ==  '\n') break;
    }
    Bitree T1  =  NULL;
    //建树1
    for (int i  =  0; i < top1; i++)
        T1  =  Insert(T1, tmp1[i]);


    while (scanf("%d%c", &n, &c)  ==  2) {
        tmp2[top2++]  =  n;
        if (c  ==  '\n') break;
    }
    Bitree T2  =  NULL;
    //建树2
    for (int i  =  0; i < top2; i++)
        T2  =  Insert(T2, tmp2[i]);

    Bitree T  =  Merge(T1,T2);
    printInorder(T);
    return 0;
}