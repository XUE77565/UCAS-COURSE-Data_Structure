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
    struct binode* first;
    struct binode* next;
} Binode, *Bitree;



void PrintTree(Bitree T, int depth){
    if(!T) return;
    else{
        int i = 0;
        while(i < depth){
            printf("-");
            i++;
        }
        printf("%c\n",T->data);
        PrintTree(T->first, depth+1);
        PrintTree(T->next, depth);
    }
}

int main(){
    int n = 1;
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
        p->first = NULL;
        p->next = NULL;
        //用于找到根节点
        if (l != -1) flag[l] = 1;
        if (r != -1) flag[r] = 1;
        if(i==n){
        //printf("break1\n");
            break;
        }
    }


    Bitree p;
    for(int i = 1; i <= n; i++){
        p = t[i];
        if(p->left > 0){
            p -> first = t[p->left];
        }
        if(p->right > 0){
            p -> next = t[p->right];
        }
    }
//printf("break2\n");
    int root = 1;
    
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            root = i;
            break;
        }
    }
//printf("break3\n");
    Bitree T = t[root];
    PrintTree(T,0);//利用递归的想法打印出这个树
    return 0;
}

