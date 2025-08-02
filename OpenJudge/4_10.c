#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

void reverse(char* s, int length);
int main(){
    char c;
    int length = 0;
    char* s;
    s = (char *)malloc(MAX * sizeof(char));
    while((c=getchar())!=EOF && c!='\n'){
        s[length++] = c;
    }
    //printf("%s\n",s);
    reverse(s,length);
    printf("%s",s);
    return 0;
}

void reverse(char *s, int length){
    char temp;
    int i = 0;
    int j = length - 1;
    for(; i < j; i++ , j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}