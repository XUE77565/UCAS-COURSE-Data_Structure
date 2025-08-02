#include<stdio.h>
int fibo(int,int);
int main(){
    int k,m;
    scanf("%d",&k);
    scanf("%d",&m);
    printf("%d",fibo(k,m));
    return 0;
}

int fibo(int k,int m){
    int out = 0;
    if(m < k-1){
        out = 0;
    }
    else if(m == k-1){
        out = 1;
    }
    else{
        for(int i = 1; i <= k; i++){
            out = out + fibo(k, m-i);
        }
    }
    return out;
}