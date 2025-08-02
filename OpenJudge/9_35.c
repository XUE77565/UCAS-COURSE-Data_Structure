#include <stdio.h>
#include <stdlib.h>

typedef enum {Link, Thread} Tag;

typedef struct binode {
    int data;
    struct binode *lchild, *rchild;
    Tag Ltag, Rtag;
} Binode, *Bitree;

//一个用于标记前驱的指针
Bitree pre = NULL;

// 插入节点
Bitree Insert(Bitree T, int data) {
    if (!T) {
        Binode *p = (Binode *)malloc(sizeof(Binode));
        p->data = data;
        p->lchild = p->rchild = NULL;
        p->Ltag = p->Rtag = Thread;
        return p;
    }
    if (data < T->data) {
        T->Ltag = Link;
        T->lchild = Insert(T->lchild, data);
    } else if (data > T->data) {
        T->Rtag = Link;
        T->rchild = Insert(T->rchild, data);
    }
    // 相等的时候不插入
    return T;
}

// 线索化递归
void InThreading(Bitree p) {
    if (p) {
        InThreading(p->lchild);
        // 左线索
        if (!p->lchild) {
            p->Ltag = Thread;
            p->lchild = pre;
        }
        // 右线索
        if (pre && !pre->rchild) {
            pre->Rtag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

//线索化树
Bitree InOrderThreading(Bitree T) {
    Bitree Thrt = (Binode *)malloc(sizeof(Binode));
    Thrt->Ltag = Link;
    Thrt->Rtag = Thread;
    Thrt->rchild = Thrt;
    if (!T) {
        Thrt->lchild = Thrt;
    } else {
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        // 最右节点线索回指头结点
        pre->rchild = Thrt;
        pre->Rtag = Thread;
        Thrt->rchild = pre;
    }
    return Thrt;
}

// 区间遍历输出
void printTree(Bitree Thrt, int a, int b) {
    Bitree p = Thrt->lchild;
    while (p != Thrt) {
        // 移动到最左边
        while (p->Ltag == Link) p = p->lchild;
        if (p->data > a && p->data < b)
            printf("%d ", p->data);
        // 沿线索遍历
        while (p->Rtag == Thread && p->rchild != Thrt) {
            p = p->rchild;
            if (p->data > a && p->data < b)
                printf("%d ", p->data);
        }
        p = p->rchild;
    }
    printf("\n");
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
    //将树线索化
    Bitree Thrt = InOrderThreading(T);

    int a, b;
    scanf("%d%d", &a, &b);
    printTree(Thrt, a, b);
    return 0;
}