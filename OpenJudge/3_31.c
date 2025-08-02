#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s[MAX];
    int length = 0;
    char c;
    while((c=getchar())!='@'){
        s[length++] = c;
    }
    s[length] = '\0';
    int i;
    int j;
    int result = 1;
    for(i = 0, j=length-1; i<length && j>=0; i++,j--){
        if(s[i]!=s[j]) {
            result = 0;
            break;
        }
    }
    printf("%d",result);
    return 0;
}