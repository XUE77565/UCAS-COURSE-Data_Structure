#include<stdio.h>
#include<stdlib.h>

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
    int L[MAX]  =  {0};
    int R[MAX]  =  {0};
    int length  =  0;
    char c;
    int n;
    while(1){
        //printf("break1\n");
        scanf("%d%c",&n,&c);
        L[length]  =  n;
        //printf("%d",L[length]);
        length++;
        if(c == '\n') break;
    }
   // printf("break1\n");
    for(int i  =  0; i < length; i++){
        scanf("%d%c",&R[i],&c);
        //printf("%d",L[i]);
    }
    //printf("break2\n");

    printf("%d",R[0]);
    for(int i  =  1; i < length ;i++){
        printf(" %d",R[i]);
    }
    printf("\n");
    printf("%d",L[0]);
    for(int i  =  1; i < length ;i++){
        printf(" %d",L[i]);
    }
    printf("\n");
    return 0;
}