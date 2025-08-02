#include<stdio.h>
#include<stdlib.h>
#define MAXN 100

typedef struct Lnode{
    int data;
    struct Lnode* next;
}Lnode;

typedef struct{
    Lnode* first;
}Llist;

Lnode* makenode(int value){
    Lnode* p;
    p = (Lnode*)malloc(sizeof(Lnode));
    p->data = value;
    p->next = NULL;
    return p;
}

Llist* Init(){
    Llist* L;
    Lnode* p;
    L = (Llist*)malloc(sizeof(Llist));
    //创建头节点
    p = makenode(0);
    L->first = p;
    return L;
}

//添加结点
void Addnote(Llist* L, int value){
    Lnode* p = makenode(value);
    Lnode *q = L->first;
    while(q->next){
        q = q->next;
    }
    q -> next = p;
}

void printlist(Llist* L){
    if(!L) return;
    Lnode *p;
    p = L->first->next;
    printf("%d",p->data);
    p = p->next;
    while(p){
        printf(" %d",p->data);
        p = p->next;
    }
}

//要注意等于的情况!!!!
void delete(Llist* L,int min,int max){
    Lnode *low;
    Lnode *high;
    low = L->first;
    //最终low指向最后一个小于等于min的元素
    while(low->next && low->next->data <= min){
        low = low->next;
    }
    //最终high指向最后一个比max小的元素
    high = low;
    while(high->next && high->next->data < max){
        high = high->next;
    }
    low->next = high->next;
}

int main(){
    int n;
    char c;
    Llist* L;
    L = Init();
    while(1){
        scanf("%d%c",&n,&c);
        Addnote(L,n);
        if(c=='\n'||c==EOF){
            break;
        }
    }
    int min,max;
    scanf("%d %d",&min,&max);
    delete(L,min,max);
    printlist(L);
    return 0;
}
