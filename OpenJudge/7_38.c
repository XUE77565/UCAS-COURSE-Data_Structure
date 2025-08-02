#include <stdio.h>
#include <stdlib.h>

//节点标号
typedef struct Mnode
{
    int adj;
    struct Mnode *next;
} Mnode;


//用于存储符号的头节点
typedef struct Cnode
{
    char data;
    Mnode *first;
} Cnode;


Cnode *Adjlist[100];

Cnode *InsertAL(Cnode *p, int adj){
    // 依次将结点插入邻接表
    Mnode *t = (Mnode *)malloc(sizeof(Mnode));
    t->adj = adj;
    if (!p->first){
        p->first = t;
        p->first->next = NULL;
    }
    else{
        t->next = p->first;
        p->first = t;
    }
    return p;
}


void printGraph(Cnode *p){
    Mnode *t;
    if(p->first)
        for(t=p->first;t;t=t->next)
            printGraph(Adjlist[t->adj]);
    printf("%c",p->data);
    return ;
}



int main()
{
    int n; //node
    char c;
    scanf("%d%c", &n, &c);
    //依次读入n行, 构造邻接表
    for (int i = 0; i < n; i++){
        Cnode *p = (Cnode *)malloc(sizeof(Cnode));
        p->first = NULL;
        scanf("%c%c", &p->data, &c);
        //表示读到非空格, 说明是字母, 直接向下读
        if (c != ' '){
            Adjlist[i] = p;
            continue;
        }

        int adj;
        while (1){
            scanf("%d%c", &adj, &c);
            p = InsertAL(p, adj);
            if (c != ' '){
                Adjlist[i] = p;
                break;
            }
        }
    }
    printGraph(Adjlist[0]);
    return 0;
}
