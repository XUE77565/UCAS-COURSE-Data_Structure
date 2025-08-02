#include<stdio.h>
#include<stdlib.h>



int func(int m,int n){
    if(m==0){
        return 0;
    }
    else{
        return func(m-1,2*n)+n;
    }
}

int main(){
    int m,n;
    scanf("%d,%d",&m,&n);
    int result = func(m,n);
    printf("%d",result);
}