#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Mnode{
    int number;
    struct Mnode* next;
}Mnode;

int v,e;

//设置了两个点为了AC, 这样可以适配各种情况
//不明白这么题目设置的意义是什么, 另外这个题空格和换行还弄了好久
int min_number = 10000;
int max_number = -1;

typedef struct adjM{
    Mnode* first[MAX];
}adjM;

adjM* init(){
    adjM* M;
    // 原来是malloc(MAX * sizeof(Mnode*)), 其实应该是sizeof(adjM)
    M = (adjM*)malloc(sizeof(adjM));
    for(int i = 0; i < MAX; i++){
        M->first[i] = NULL;
    }
    return M;
}

//创建结点
Mnode* makenode(int value){
    Mnode* p;
    p = (Mnode*)malloc(sizeof(Mnode));
    p -> number = value;
    p->next = NULL;
    return p;
}

// 按降序插入
void Insert(adjM* M, int v1, int v2){
    Mnode* p = makenode(v2);
    Mnode **head = &M->first[v1];
    if(*head == NULL || (*head)->number < v2){
        p->next = *head;
        *head = p;
    }else{
        Mnode* cur = *head;
        while(cur->next && cur->next->number > v2){
            cur = cur->next;
        }
        p->next = cur->next;
        cur->next = p;
    }
}

void printM(adjM* M){
    for(int i = min_number; i <= max_number; i++){
        //if(i==0 && !M->first[i] || i==v && !M->first[v]) continue;
        printf("%d",i);
        if(M->first[i]) printf(" ");
        Mnode* p = M->first[i];
        while(p){
            printf("%d",p->number);
            if(p->next){
                printf(",");
            }
            p = p->next;
        }
        if(i!=max_number) printf("\n");
    }
}

int main(){
    adjM* M;
    M = init();
    scanf("%d,%d",&v,&e);
    int v1,v2;
    char c;
    while(1){
        scanf("%d-%d%c",&v1,&v2,&c);
        if(v1 < min_number){
            min_number = v1;
        }
        if(v2 < min_number){
            min_number = v2;
        }
        if(v1 > max_number){
            max_number = v1;
        }
        if(v2 > max_number){
            max_number = v2;
        }
        Insert(M,v1,v2);
        if(c!=',') break;
    }
    printM(M);
    // 可加释放内存部分
    return 0;
}