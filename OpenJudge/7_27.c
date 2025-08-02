#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//找路径
int simplepath(int u,int v,int dep,int s[],int len){
    for(int i=0;i<len;i++)
        if(s[i]==u)
            return 0;

    s[len++]=u;
    Mnode *p=M[u];
    while(p){
        if(dep==k && p->number==v){
            int flag=1;
            //检查路径里有没有环
            for(int i=0;i<len;i++)
                if(s[i]==v){
                    flag=0;
                    break;
                }
            if(flag==1)
                return 1;
        }
        //利用递归找
        else if(simplepath(p->number,v,dep+1,s,len)==1)
            return 1;
        p=p->next;
    }
    return 0;
}

int main(){
    int n;
    char c;
    scanf("%d,%d%c",&n,&k,&c);
    int x,y;
    scanf("%d,%d%c",&x,&y,&c);
    while(1){
        int u,v;
        //要添加两条弧, 因为是无向图
        scanf("%d-%d%c",&u,&v,&c);
        M[u]=InsertAL(M[u],v);
        M[v]=InsertAL(M[v],u);
        if(c!=',')
            break;
    }
    int s[100]={0};
    int len=0;
    if(simplepath(x,y,1,s,len)==1)
        printf("yes");
    else
        printf("no");
    return 0;
}