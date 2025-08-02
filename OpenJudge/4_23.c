#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    int len;
    scanf("%d",&len);
    char s[len];
    scanf("%s",s);

    int result = 1;
    int i,j;
    for(i = 0, j=len-1; i < j; i++,j--){
        if(s[i]!=s[j]){
            result = 0;
            break;
        } 
    }
    printf("%d",result);
    return 0;
}