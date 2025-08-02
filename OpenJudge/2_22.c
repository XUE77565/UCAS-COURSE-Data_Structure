#include<stdio.h>
#include<stdlib.h>
#define MAXN 100

typedef struct Lnode{
    char data;
    struct Lnode* next;
}Lnode;

typedef struct{
    Lnode* first;
}Llist;

int parse(char* line,char* s){
    int cnt = 0;
    char *p = line;
    for (int i = 0; line[i]; i++) {
        if (line[i] == ',' || line[i] == '\n' || line[i] == '\r') continue;
        s[cnt++] = line[i];
    }
    return cnt;
}

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
    p = makenode('\0');
    L->first = p;
    return L;
}

//添加结点
void Addnote(Llist* L, char value){
    Lnode* p = makenode(value);
    Lnode *q = L->first;
    while(q->next){
        q = q->next;
    }
    q -> next = p;
}

//反转链表
void reverse(Llist* L,int len){
    Lnode *head = L->first;
    Lnode *tail = L->first;
    int i;
    //考虑逐个将第一个结点放到最后一个
    //tail一直指向结尾的结点
    while(tail->next){
        tail = tail->next;
    }
    for(int i = 1; i < len; i++){//一共移动len-1次
        Lnode* p = L->first->next;
        L->first->next = p->next;
        p->next = tail->next;
        tail->next = p;
    }
}

void printlist(Llist* L){
    Lnode *p;
    p = L->first->next;
    printf("%c",p->data);
    p = p->next;
    while(p){
        printf(",%c",p->data);
        p = p->next;
    }
}

int main(){
    char lineS[MAXN];
    char s[MAXN];
    int slen = 0;
    fgets(lineS, MAXN, stdin);    
    slen = parse(lineS, s);
    Llist* L;
    L = Init();
    for(int i = 0; i<slen; i++){
        Addnote(L,s[i]);
    }
    reverse(L,slen);
    printlist(L);
    return 0;
}
