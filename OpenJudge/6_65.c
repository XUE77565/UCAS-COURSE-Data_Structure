#include <stdio.h>
#include <string.h>

#define MAXN 100

char preorder[MAXN], inorder[MAXN];

void order(const char *pre, const char *in, int n) {
    if (n <= 0) return;
    char root = pre[0];
    int i;
    // 考虑利用先序来找到中序中根节点的位置
    for (i = 0; i < n; ++i) {
        if (in[i] == root) break;
    }
    // 左子树递归
    order(pre + 1, in, i);
    // 右子树递归
    order(pre + 1 + i, in + i + 1, n - i - 1);
    // 输出根节点
    putchar(root);
}

int main() {
    // 读入两行, 直接利用fgets
    fgets(preorder, sizeof(preorder), stdin);
    fgets(inorder, sizeof(inorder), stdin);
    // 去掉换行符
    preorder[strcspn(preorder, "\r\n")] = '\0';
    inorder[strcspn(inorder, "\r\n")] = '\0';
    int n = strlen(preorder);
    order(preorder, inorder, n);
    putchar('\n');
    return 0;
}