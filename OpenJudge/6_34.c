#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct binode{
    char data;
    int left;
    int right;
    int number;
    struct binode* lchild;
    struct binode* rchild;
} Binode, *Bitree;

int main(){
    int T[MAX]  =  {0};
    int length  =  0;
    char c;
    int n;
    while(1){
        scanf("%d%c",&n,&c);
        T[length]  =  n;
        //printf("%d",T[length]);
        length++;
        if(c == '\n') break;
    }
    //printf("break1\n");
    int L[length+1];
    int R[length+1];
    for(int i  =  0; i < length; i++){
        scanf("%d%c",&L[i],&c);
        //printf("%d",L[i]);
    }
    //printf("break2\n");
    for(int i  =  0; i < length; i++){
        scanf("%d%c",&R[i],&c);
       // printf("%d",T[i]);

    }
    //printf("break3\n");

    int result  =  0;
    int u,v;
    scanf("%d %d",&u,&v);
    //printf("%d,%d\n",u,v);
   // printf("\n");
    while(T[u]){
        if(T[u] == v){
            result  =  1;
            break;
           // printf("break4\n");
        }
        else{ //如果u的父亲结点不是v,则继续想上找
            u  =  T[u];
            // printf("break5\n");
        }
    }
    printf("%d",result);
    return 0;
}