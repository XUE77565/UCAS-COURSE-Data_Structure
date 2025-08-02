#include <stdio.h>
#include <stdlib.h>

//利用双向链表
typedef struct block{
    int tag;
    int addr;
    int k;
    struct block *llink,*rlink;
}block;

block *FreeList[32];


void Insert(int addr,int k){
    block *p = (block *)malloc(sizeof(block));
    p->addr = addr;
    p->k = k;
    p->llink = p->rlink = NULL;
    if(!FreeList[k])
    {   FreeList[k] = p;
        return ;}
    else{
        //按照升序来插入
        block *head = FreeList[k];
        if(head->addr > p->addr){
            head->llink = p;
            p->rlink = head;
            FreeList[k] = p;
            return;
        }
        else{
            for(;head->rlink && head->rlink->addr < p->addr; head = head->rlink)
            ;
            p->rlink = head->rlink;
            head->rlink = p;
            p->llink = head;
            if(p->rlink)
                p->rlink->llink = p;
            return ;
        }    
    }
}

//合并之后, 原本的块
void Del(block *p){
    //此操作考虑左节点为空，即头结点情形
    if(p == FreeList[p->k])
        FreeList[p->k] = p->rlink;
    else
        p->llink->rlink = p->rlink;
    if(p->rlink)
        p->rlink->llink = p->llink;
    return ;
}

void  Merge(){
    for(int i = 0; i < 32 ; i++){
        if(FreeList[i]){
            block *head  = FreeList[i];
            while(head && head->rlink){
                if(head->addr % (2<<head->k) == 0 && head->rlink->addr == head->addr + (1<<head->k)){
                    Insert(head->addr,head->k+1);
                    block *next = head->rlink->rlink;
                    Del(head->rlink);
                    Del(head);
                    head = next;
                }
                else    
                    head = head->rlink;
            }
        }
    }
}

void printFreeList(){
    for(int k = 0;k<32;k++)
    if(FreeList[k]){
        printf("%d",k);
        block *p = FreeList[k];
        while(p){
            printf(" %d",p->addr);
            p = p->rlink;
        }
        printf("\n");
    }
    return ;
}

int main(){
    int addr,k;
    int n;
    char c;
    int mode = 0;// 0读取k，1读取地址
    while(scanf("%d%c",&n,&c) ==  2){
        if(mode == 0){
            k = n;
            mode = 1;
        }
        else{
            addr = n;
            Insert(addr,k);
        }
        if(c == '\n')
            mode = 0;
    }
    Merge();
    printFreeList();
    return 0;
}