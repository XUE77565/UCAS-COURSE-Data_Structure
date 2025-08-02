#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define MAX 100

typedef struct Binode{
    int data;
    int l,r;
    struct Binode* lchild;
    struct Binode* rchild;
}Binode,*Bitree;

int searchTree(Bitree p){
    if(!p) return 1;
    if(p->lchild && p->lchild->data >= p->data){
        return 0;
    }
    else if(p->rchild && p->rchild->data <= p->data){
        return 0;
    }
    //递归的检查两个子树是否是二叉排序树
    else return searchTree(p->lchild) && searchTree(p->rchild);
}

int main(){
    //为什么不给结点数目!!!!!!!
    int flag[MAX] = {0};//用于找根节点
    int n = 0;
    Bitree arr[MAX];
    int value,r,l;
    for (int i = 0;; i++) {
        char c;
        char k;
        int l, r;
        scanf("%d %d %d", &value, &l, &r); // 注意前面的空格
        Bitree p = (Bitree)malloc(sizeof(Binode));
        p->data = value;
        p->l = l;
        p->r = r;
        arr[i] = p;
        n=max(n,p->l);
        n=max(n,p->r);
        //printf("c=%c,i=%d,l=%d,r=%d,n=%d\n",c,i,l,r,n);
        p->lchild = NULL;
        p->rchild = NULL;
        if (l != -1) flag[l] = 1;
        if (r != -1) flag[r] = 1;
        if(i==n){
        //printf("break1\n");
            break;
        }
    }

    //建立父子关系
    for (int i = 0; i < n; i++) {
        Bitree p = arr[i];
        if (p->l != -1) p->lchild = arr[p->l];
        if (p->r != -1) p->rchild = arr[p->r];
    }
    //printf("break3\n");

    // 找根节点
    int root = 1;
    
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            root = i;
            break;
        }
    }
    //printf("

    printf("%d",searchTree(arr[root]));
    return 0;
}