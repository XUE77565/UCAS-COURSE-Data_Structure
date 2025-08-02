#include<stdio.h>
#include<string.h>
#define MAXLINE 100

int main(){
    char a[MAXLINE];
    char b[MAXLINE];
    scanf("%s",a);
    scanf("%s",b);
    int out = strcmp(a,b);
    int result = (out > 0)? 2:
                 (out < 0)? 1:
                 0;
    printf("%d\n",result);
    return 0;
}