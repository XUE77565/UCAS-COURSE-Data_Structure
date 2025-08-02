#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b)   (((a)>(b))?(a):(b))

typedef struct Mnode{
    int number;
    struct Mnode *next;
}Mnode;

//无向图双方

//双向邻接链表
Mnode * M[100];
int simplepath(int u,int v,int dep,int s[],int len);//dfs len为路径长度，s[]为先前访问结点
int k;//depth

//在邻接链表中插入弧
Mnode * InsertAL(Mnode *head,int data){
    Mnode *p=(Mnode *)malloc(sizeof(Mnode));
    p->number=data;
    p->next=NULL;
    if(!head)
        head=p;
    else if(head->number<p->number)
    {
        p->next=head;
        head=p;
    }
    else{
        Mnode *t=head;
        while(t->next && t->next->number>data){
            t=t->next;
        }
        p->next=t->next;
        t->next=p;
    }   
    return head;
}

int pathlen(int u){
    Mnode *p= M[u];
    if(!p)
        return 0;
    else{
        int top=0;
        while(p){
            top=max(top,pathlen(p->number)+1);
            p=p->next;
        }
        return top;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char c;
    while(1){
        int u,v;
        //有向图添加一个弧
        scanf("%d-%d%c",&u,&v,&c);
        M[u]=InsertAL(M[u],v);
        if(c!=',')
            break;
    }

    printf("%d",pathlen(1));
    for(int i=2;i<=n;i++)
    printf(",%d",pathlen(i));

    return 0;
}