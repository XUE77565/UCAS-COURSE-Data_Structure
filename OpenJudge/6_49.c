#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define TRUE 1
#define FALSE 0
#define MAX 110

int flag[MAX] = {0};
int count[MAX] = {0};
typedef struct binode{
    char data;
    int left;
    int right;
    int number;
    struct binode* lchild;
    struct binode* rchild;
} Binode, *Bitree;

void makeBitree(Bitree T){
    if(!T) return;
    else{
        count[T->number] = 1;
        if(T->lchild){
            T->lchild->number = 2*T->number;
            makeBitree(T->lchild);
        }
        if(T->rchild){
            T->rchild->number = 2*T->number+1;
            makeBitree(T->rchild);
        }
    }
    return;
}

int main(){
    int n = 1;
;
    Bitree t[MAX] = {NULL}; // t[1]~t[n]，下标即编号

    // 读入节点信息
    char c;
    for (int i = 1;; i++) {
        char c;
        char k;
        int l, r;
        scanf("%c %d %d%c", &c, &l, &r, &k); // 注意前面的空格
        Bitree p = (Bitree)malloc(sizeof(Binode));
        p->data = c;
        p->left = l;
        p->right = r;
        t[i] = p;
        n=max(n,p->left);
        n=max(n,p->right);
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
//printf("break2\n");

    for (int i = 1; i <= n; i++) {
        Bitree p = t[i];
        if (p->left != -1) p->lchild = t[p->left];
        if (p->right != -1) p->rchild = t[p->right];
    }
//printf("break3\n");

    // 找根节点
    int root = 1;
    
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            root = i;
            break;
        }
    }
//printf("break4\n");
    Bitree T = t[root];
    T->number = 1;
    count[T->number] = 1;
    makeBitree(T);//按照编号编完全二叉树
//printf("break5\n");
    int result = TRUE;

    for(int i = 1; i <= n; i++){
        if(!count[i]){
            result = FALSE;
            break;
        }
    }
    if(result == TRUE){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

