#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int result = 1;
    if(n==0){result = 1;}
    else{
        for(int i = n; i > 0; i = i/2){
            result *= i;
        }
    }
    printf("%d",result);
    return 0;
}