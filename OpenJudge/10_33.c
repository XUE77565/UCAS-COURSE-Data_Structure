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



Lnode* makenode(char value){
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
    p = makenode('0');
    L->first = p;
    return L;
}

//添加结点
void Addnode(Llist* L, char value){
    Lnode* p = makenode(value);
    Lnode *q = L->first;
    while(q->next){
        q = q->next;
    }
    q -> next = p;
}

void printlist(Llist* L){
    Lnode *p;
    p = L->first->next;
    printf("%d",p->data);
    p = p->next;
    while(p){
        printf(" %d",p->data);
        p = p->next;
    }
}

void simplesort(Llist* L) {
    if (L->first->data < 2) return;
    int swapped;
    Lnode* p;
    Lnode* q = NULL;
    //对于链表的冒泡排序, q就相当于重点
    do {
        swapped = 0;
        p = L->first->next;
        while (p->next != q) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
        q = p;
    } while (swapped);
}


int main(){
    Llist * L;
    L = Init();
    char s;
    int n;
    while(1){
        scanf("%d%c",&n,&s);
        Addnode(L,n);
        L->first->data++;
        if(s=='\n' || s==EOF) break;
    }
    simplesort(L);
    printlist(L);
    return 0;
}
