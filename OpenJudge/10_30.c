#include <stdio.h>

#define MAXN 105

// 交换两个整数
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 对长度<=3的区间直接插入排序
void simpleSort(int arr[], int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            if (arr[j] < arr[i]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

typedef struct {
    int l, r;
} StackNode;

int main() {
    int arr[MAXN], n = 0;
    char ch;

    // 输入一行整数
    while (scanf("%d%c", &arr[n], &ch)) {
        n++;
        if (ch == '\n') break;
    }

    StackNode stack[MAXN];
    int top = -1;
    //将初始的序列压入栈
    stack[++top].l = 0;
    stack[top].r = n - 1;

    while (top >= 0) {
        int l = stack[top].l;
        int r = stack[top--].r;
        //利用r和l标记序列位置
        if (r - l + 1 <= 3) {
            if (l < r) simpleSort(arr, l, r);
            continue;
        }

        // 快排一次
        int i = l, j = r, pivot = arr[l];
        while (i < j) {
            while (i < j && arr[j] >= pivot) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] <= pivot) i++;
            if (i < j) arr[j--] = arr[i];
        }
        arr[i] = pivot;

        int len_left = i - 1 - l + 1;
        int len_right = r - (i + 1) + 1;

        // 优先处理较短子区间
        if (len_left < len_right) {
            if (i + 1 < r) {
                stack[++top].l = i + 1;
                stack[top].r = r;
            }
            if (l < i - 1) {
                stack[++top].l = l;
                stack[top].r = i - 1;
            }
        } else {
            if (l < i - 1) {
                stack[++top].l = l;
                stack[top].r = i - 1;
            }
            if (i + 1 < r) {
                stack[++top].l = i + 1;
                stack[top].r = r;
            }
        }
    }

    // 输出
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}