#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define MAX 110

typedef struct {
    char data;
    int left;
    int right;
} Binode, *Bitree;

int main() {
    int n;
    scanf("%d", &n);
    Bitree t[MAX] = {NULL}; // t[1]~t[n]，下标即编号
    int flag[MAX] = {0};

    // 读入节点信息
    for (int i = 1;; i++) {
        char c;
        int l, r;
        scanf(" %c %d %d", &c, &l, &r); // 注意前面的空格
        Bitree p = (Bitree)malloc(sizeof(Binode));
        p->data = c;
        p->left = l;
        p->right = r;
        t[i] = p;
        n=max(n,p->left);
        n=max(n,p->right);
        if(i==n){
            break;
        }
        if (l != -1) flag[l] = 1;
        if (r != -1) flag[r] = 1;
    }

    // 找根节点
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            root = i;
            break;
        }
    }

    // 非递归先序遍历
    int stack[MAX];
    int top = 0;
    stack[++top] = root;
    while (top) {
        int idx = stack[top--];
        printf("%c ", t[idx]->data);
        if (t[idx]->right != -1) stack[++top] = t[idx]->right; // 先右
        if (t[idx]->left != -1) stack[++top] = t[idx]->left;   // 后左
    }
    printf("\n");

    // 释放内存
    for (int i = 1; i <= n; i++) free(t[i]);
    return 0;
}