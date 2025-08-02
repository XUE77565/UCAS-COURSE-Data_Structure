#include <stdio.h>
#define MAXINT 4294967295U

int main() {
    int n, arrsize;
    int a[25]; // arrsize < =  20
    scanf("%d %d", &n, &arrsize);

    if (n > arrsize || n <=  0 || arrsize > 20) {
        printf("-1\n");
        return 0;
    }

    //利用无符号数及逆行溢出的判断, 因为如果a * b > MAX则a > MAX/b
    unsigned int fact  =  1, two  =  1;
    for (int i  =  0; i < n; i++) {
        if (i > 0) {
            if (fact > MAXINT / i) { // 判断阶乘是否溢出
                printf("-1\n"); return 0;
            }
            fact *=  i;
        }
        if (i > 0) {
            if (two > MAXINT / 2) { // 判断2的幂是否溢出
                printf("-1\n"); return 0;
            }
            two *=  2;
        }
        if (fact > MAXINT / two) { // 判断乘积是否溢出
            printf("-1\n"); return 0;
        }
        //利用类型转换将无符号数转换回来
        a[i]  =  (int)fact * two;
    }

    for (int i  =  0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}