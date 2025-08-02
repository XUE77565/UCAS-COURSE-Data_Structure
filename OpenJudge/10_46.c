#include <stdio.h>
#include <stdlib.h>
//为了保证每个记录值移动一次, 可以利用一个数组来存储这些要比较的关键字
//这个数组并不是纯的关键字数组, 他实际上是一个结构体, 指向自己所在的记录
//最后按照这个数组中的元素的顺序来防止记录就可以了
//时间不够了, 来不及写了, 以后再完善
int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 直接用标准库排序
    qsort(a, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    free(a);
    return 0;
}