#include<stdio.h>
#include<stdlib.h>

typedef struct qnode{
    int data;
    struct qnode* next;
}qnode;

typedef struct{
    qnode* tail;
}queue;

queue* Init();
void Enq(queue* Q,int n);
int Outq(queue* Q);
qnode* makenode();

int main(){
    int n;
    scanf("%d",&n);
    queue* Q  =  Init();
    int value;
    char c;
    for(int i  =  0; i < n; i++){
        scanf("%d%c",&value,&c);
        Enq(Q, value);
    }
    int out[n];
    for(int i  =  0; i < n; i++){
        out[i]  =  Outq(Q);
    }
    for(int i  =  0; i < n-1; i++){
        printf("%d,",out[i]);
    }
    printf("%d",out[n-1]);
    return 0;
}

//初始化队列, 这个p是尾指针
queue* Init(){
    queue* Q  =  (queue*)malloc(sizeof(queue));
    qnode* p;
    //设置头指针
    p  =  makenode(0);
    p->next  =  p;
    Q->tail  =  p;
    //构成环形队列
    return Q;
}

qnode* makenode(int n){
    qnode *p;
    p  =  (qnode*)malloc(sizeof(qnode));
    p->data  =  n;
    p->next  =  NULL;
    return p;
}

void Enq(queue* Q,int n){
    qnode *p;
    p  =  makenode(n);
    //将p作为队列结点插入队列, 首先p指向队头
    p->next  =  Q->tail->next;
    Q->tail->next  =  p;
    Q->tail  =  p;
}

int Outq(queue* Q){
    int value;
    if(Q->tail == NULL) return 0;
    else{
        qnode* p  =  Q->tail->next;
        if(p->next  ==  Q->tail){//表示只剩下了这个结点
            value  =  Q->tail->data;
            p->next  =  p;//行乘最开始的环形结构
        }
        else{
            value  =  p->next->data;
            p->next  =  p->next->next;
        }
    }
    return value;
}