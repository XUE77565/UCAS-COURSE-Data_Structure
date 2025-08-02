#include<stdio.h>
#define MAX 100

int main(){
    int s[MAX];
    int n;
    char c;
    int length  =  0;
    while(1){
        scanf("%d%c",&n,&c);
        s[length++]  =  n;
        if(c == '\n' || c == '\0' || c == EOF){
            break;
        }
    }
    int temp;
    int j  =  length-1;
    int sorted  =  0;
    while(!sorted){
        sorted  =  1;
        for(int m  =  0; m < j; m++){
            if(s[m+1] < s[m]){  
                temp  =  s[m+1];
                s[m+1]  =  s[m];
                s[m]  =  temp;
                sorted  =  0;    //表示遇到了逆序对, sorted置为0
            }
        }
        j--;        
    }
    for(int i  =  0; i < length; i ++){
        if(i) printf(" ");
        printf("%d",s[i]);
    }
    return 0;
}