#include<stdio.h>
#define MAX 100
int main(){
    int array[MAX];
    int len = 0;
    while(~scanf("%d ",&array[len])){
        len++;
    };
    int n = array[len-1];
    len--;
    int pos = 0;
    for(; pos<len;pos++){
        if(n < array[pos])
            break;
    }
    for(int j = len ; j>pos ; j--){
        array[j] = array[j-1];
    }
    array[pos] = n;
    len++;
    for(int i = 0; i<len;i++){
        printf("%d ",array[i]);
    }
    return 0;
}