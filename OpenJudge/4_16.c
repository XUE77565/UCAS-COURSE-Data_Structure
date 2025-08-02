#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s[MAX]  =  {0};
    char t[MAX]  =  {0};
    scanf("%s %s",s,t);
    int slen  =  strlen(s);
    s[slen]  =  '\0';
    int tlen  =  strlen(t);
    t[tlen]  =  '\0';
    int result  =  0;
    int p;
    for(p  =  0; s[p]&&t[p]&&s[p] == t[p];p++);
    if(s[p] > t[p]) result  =  1;
    else if(s[p] < t[p]) result  =  -1;
    else result  =  0;
    printf("%d",result);
    return 0;
}