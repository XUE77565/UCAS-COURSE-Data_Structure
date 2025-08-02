#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

//简单的归并不满足时间的要求, 要用二分递归!!!

typedef struct Lnode {
    int data;
    struct Lnode* next;
} Lnode;

//利用尾指针法, 来减少时间复杂度
typedef struct {
    Lnode* first;
    Lnode* tail; // 新增
} Llist;

Lnode* makenode(int value) {
    Lnode* p;
    p  =  (Lnode*)malloc(sizeof(Lnode));
    p->data  =  value;
    p->next  =  NULL;
    return p;
}

Llist* Init() {
    Llist* L  =  (Llist*)malloc(sizeof(Llist));
    L->first  =  makenode(0);
    L->tail  =  L->first;
    return L;
}

void Addnode(Llist* L, int value) {
    Lnode* p  =  makenode(value);
    L->tail->next  =  p;
    L->tail  =  p;
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

// Llist* Mergesort(Llist* L) {
//     if (!L || !L->first->next || !L->first->next->next) return L;
//     // 快慢指针找到中间节点
//     Lnode *slow  =  L->first, *fast  =  L->first->next;
//     while (fast && fast->next) {
//         slow  =  slow->next;
//         fast  =  fast->next->next;
//     }
//     Llist* mid  =  Init();
//     mid->first->next  =  slow->next;
//     slow->next  =  NULL;

//     Llist* left  =  Mergesort(L);
//     Llist* right  =  Mergesort(mid);
//     return merge(left, right);
// }

int main() {
    Llist* L1;
    Llist* L2;
    L1  =  Init();
    L2  =  Init();
    int value;
    char c;
    while(1) {
        scanf("%d%c", &value,&c);
        Addnode(L1, value);
        if(c == '\n') break;
    }
    while(1) {
        scanf("%d%c", &value,&c);
        Addnode(L2, value);
        if(c == '\n') break;
    }
    Llist* L;
    L  =  Init();
    L  =  merge(L1,L2);
    printlist(L);
    return 0;
}