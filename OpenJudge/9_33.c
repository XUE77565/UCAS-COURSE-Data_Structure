#include <stdio.h>
#include <stdlib.h>


typedef struct binode {
    int data;
    struct binode *lchild, *rchild;
} Binode, *Bitree;

// 插入节点
Bitree Insert(Bitree T, int data) {
    if (!T) {
        Binode *p = (Binode *)malloc(sizeof(Binode));
        p->data = data;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (data < T->data) {
        T->lchild = Insert(T->lchild, data);
    } else if (data > T->data) {
        T->rchild = Insert(T->rchild, data);
    }
    // 相等的时候不插入
    return T;
}

void SearchPrint(Bitree T,int key){
    if(!T) return;
    Binode* p = T;
    //先搜索大的
    SearchPrint(T->rchild,key);
    
    if(p->data >= key){
        printf("%d ",p->data);
    //没有必要再搜左子树了
        if(p->data==key){return;}
        SearchPrint(T->lchild,key);
    }
    else return;
}

int main() {
    int n, top = 0, tmp[100];
    char c;
    while (scanf("%d%c", &n, &c) == 2) {
        tmp[top++] = n;
        if (c == '\n') break;
    }
    Bitree T = NULL;
    //按照中序建树
    for (int i = 0; i < top; i++)
        T = Insert(T, tmp[i]);

    int key;
    scanf("%d",&key);

    SearchPrint(T,key);

    return 0;
}