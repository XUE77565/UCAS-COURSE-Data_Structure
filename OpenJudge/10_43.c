#include<stdio.h>
#include<stdlib.h>

#define MAX  101

int main(){
    int length  =  0;
    int a[MAX];
    int c[MAX];
    char ch;
    int n;
    //每次都要这么设计输入, 真的好难受啊
    while(1){
        scanf("%d%c",&n,&ch);
        a[length++]  =  n;
        if(ch == '\n' || ch == '\0' || ch == EOF){
            break;
        }

    }
    for (int i  =  0; i < length; i++) {
        c[i]  =  0; // 必须初始化
        int pivot  =  a[i];
        for (int j  =  0; j < length; j++) {
            if (a[j] < pivot) {
                c[i]++;
            }
        }
    }
    //这个题竟然是输出c而不是输出排序过后的a, 好奇怪
    for(int i  =  0; i < length; i++){
        if(i) printf(" ");
        printf("%d",c[i]);
    }
    return 0;
}