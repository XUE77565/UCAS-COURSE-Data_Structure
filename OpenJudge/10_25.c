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
    p  =  (Lnode*)malloc(sizeof(Lnode));
    p->data  =  value;
    p->next  =  NULL;
    return p;
}

Llist* Init(){
    Llist* L;
    Lnode* p;
    L  =  (Llist*)malloc(sizeof(Llist));
    //创建头节点
    p  =  makenode(0);
    L->first  =  p;
    return L;
}

//添加结点
void Addnode(Llist* L, int value){
    Lnode* p  =  makenode(value);
    Lnode *q  =  L->first;
    while(q->next){
        q  =  q->next;
    }
    q -> next  =  p;
}

void printlist(Llist* L){
    Lnode *p;
    p  =  L->first->next;
    printf("%d",p->data);
    p  =  p->next;
    while(p){
        printf(" %d",p->data);
        p  =  p->next;
    }
}

// void Insertsort(Llist* L) {
//     if (L->first->data < 2) return;
//     Lnode* start;
//     Lnode* p  =  L ->first->next;
//     //利用q来当作p的结尾位置, 意思是q是下一个需要插入的结点
//     //p是已排序列的最后一个结点
//     Lnode* q  =  p->next;
//     while(q){
//         q  =  p->next;
//         //将q结点提取出来
//         p->next  =  q->next;
//         start  =  L->first;
//         //start指向最后一个小于data的结点
//         while(start->next->data < q->data && start->next! = p){
//             start  =  start->next;
//         }
//         start->next  =  q;
//         q->next  =  start->next->next;         
//         q  =  q->next;
//     }
// }

void Insertsort(Llist* L) {
    //表示已排序列表
    Lnode* sorted  =  NULL; 
    //待排序的第一个
    Lnode* curr  =  L->first->next;
    while (curr) {
        Lnode* next  =  curr->next;
        if (!sorted || curr->data < sorted->data) {
            curr->next  =  sorted;
            sorted  =  curr;
        } else {
            Lnode* p  =  sorted;
            while (p->next && p->next->data < curr->data) {
                p  =  p->next;
            }
            curr->next  =  p->next;
            p->next  =  curr;
        }
        curr  =  next;
    }
    //构造了新链表, 防止出现插入的混乱
    L->first->next  =  sorted;
}

int main(){
    Llist * L;
    L  =  Init();
    char s;
    int n;
    scanf("%d",&n);
    L->first->data  =  n;
    int value;
    for(int i  =  0; i < n; i++){
        scanf("%d",&value);
        Addnode(L,value);
    }
    Insertsort(L);
    printlist(L);
    return 0;
}
