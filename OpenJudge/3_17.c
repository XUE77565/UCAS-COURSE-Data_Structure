#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    int slen=0;
    int tlen=0;
    char s[MAX];
    char t[MAX];
    char c;
    while((c=getchar())!='&'){
        s[slen++] = c;
    }
    s[slen] = '\0';
    while((c=getchar())!='@'){
        t[tlen++] = c;
    }
    t[tlen] = '\0';

    int result = 1;
    if(slen != tlen){result = 0;}
    else{
        int len = slen;
        int i,j;
        //逐个匹配两个串
        for(i = 0,j = len - 1; i < len && j >=0; i++, j--){
            if(s[i]!=t[j]){
                result = 0;
                break;
            }
        }
    }
    printf("%d",result);
    return 0;
}