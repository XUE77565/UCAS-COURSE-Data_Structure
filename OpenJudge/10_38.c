#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

typedef struct Lnode {
    int data;
    struct Lnode* next;
} Lnode;

typedef struct {
    Lnode* first;
} Llist;

Lnode* makenode(int value) {
    Lnode* p;
    p  =  (Lnode*)malloc(sizeof(Lnode));
    p->data  =  value;
    p->next  =  NULL;
    return p;
}

Llist* Init() {
    Llist* L;
    Lnode* p;
    L  =  (Llist*)malloc(sizeof(Llist));
    //创建头节点
    p  =  makenode(0);
    L->first  =  p;
    return L;
}

void Addnode(Llist* L, int value) {
    Lnode* p  =  makenode(value);
    Lnode *q  =  L->first;
    while(q->next) {
        q  =  q->next;
    }
    q->next  =  p;
}

void printlist(Llist* L) {
    if(!L->first->next) {
        printf("NULL");
        return;
    }
    Lnode *p;
    p  =  L->first->next;
    printf("%d", p->data);
    p  =  p->next;
    while(p) {
        printf(" %d", p->data);
        p  =  p->next;
    }
}

// 正确归并两个有序链表，返回新的Llist*
Llist* merge(Llist* L1, Llist* L2) {
    Llist* L  =  Init();
    Lnode* head  =  L->first;
    Lnode* p1  =  L1->first->next;
    Lnode* p2  =  L2->first->next;

    while (p1 && p2) {
        if (p1->data < p2->data) {
            head->next  =  p1;
            p1  =  p1->next;
        } else {
            head->next  =  p2;
            p2  =  p2->next;
        }
        head  =  head->next;
    }
    if (p1) head->next  =  p1;
    if (p2) head->next  =  p2;
    return L;
}

Llist* Mergesort(Llist* L) {
    if (!L || !L->first->next || !L->first->next->next) return L;
    // 快慢指针找到中间节点
    Lnode *slow  =  L->first, *fast  =  L->first->next;
    while (fast && fast->next) {
        slow  =  slow->next;
        fast  =  fast->next->next;
    }
    Llist* mid  =  Init();
    mid->first->next  =  slow->next;
    slow->next  =  NULL;

    Llist* left  =  Mergesort(L);
    Llist* right  =  Mergesort(mid);
    return merge(left, right);
}

int main() {
    int n;
    scanf("%d", &n);
    Llist* L;
    L  =  Init();
    int value;
    for(int i  =  0; i < n; i++) {
        scanf("%d", &value);
        Addnode(L, value);
    }
    L  =  Mergesort(L);
    printlist(L);
    return 0;
}