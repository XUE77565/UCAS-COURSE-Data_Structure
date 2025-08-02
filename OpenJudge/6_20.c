#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct binode{
    int data;
    int left,right;
    struct binode *lchild,*rchild;
}Binode,*Bitree;


Bitree stack[MAX];

int flag[MAX]={0};
//非零表示为孩子，森林根结点为0
Bitree root[MAX];

int top=0;

typedef struct linknode{
    int data;
    struct linknode *l,*r;
}node;

//双向链表
typedef struct linklist{
    node *head,*tail;
}list;

int L[3][MAX]={0};
int R[3][MAX]={0};


list * newlist(){
    list *li=(list *)malloc(sizeof(list));
    li->head=li->tail=NULL;
    return li;
}


list *Insert(list *li,int data){
    //创建新节点
    node *p=(node *)malloc(sizeof(node));
    p->data=data;
    p->r=NULL;
    if(li->head==NULL){
        p->l=NULL;
        li->head=li->tail=p;
    }
    else{
        li->tail->r=p;
        p->l=li->tail;
        li->tail=p;
    }
    return li;
}

//利用递归进行线索化
list * Prethreading(list *l1,Bitree T){
    if(!T)
        return l1;
    else{
        l1=Insert(l1,T->data);
        if(T->lchild)
            l1=Prethreading(l1,T->lchild);
        if(T->rchild)
            l1=Prethreading(l1,T->rchild);
    }
    return l1;
}


list * Inthreading(list *l2,Bitree T){
    if(!T)
        return l2;
    else{
        if(T->lchild)
            l2=Inthreading(l2,T->lchild);
        l2=Insert(l2,T->data);
        if(T->rchild)
            l2=Inthreading(l2,T->rchild);
    }
    return l2;
}


list * Postthreading(list *l3,Bitree T){
    if(!T)
        return l3;
    else{
        if(T->lchild)
            l3=Postthreading(l3,T->lchild);
        if(T->rchild)
            l3=Postthreading(l3,T->rchild);
        l3=Insert(l3,T->data);   
    }
    return l3;
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        Bitree p=(Bitree)malloc(sizeof(Binode));
        scanf("%d %d %d",&p->data,&p->left,&p->right);
        stack[i]=p;
    }

    //生成树
    Bitree t;
    for(int i=1;i<=n;i++){
        t=stack[i];
        if(t->left==0){
            t->lchild=NULL;
        }
        else{
            t->lchild=stack[t->left];
            flag[t->left]++;//对应的节点为孩子
            for(int j=0;j<3;j++)
                L[j][t->data]=t->left;
        }
        if(t->right==0){
            t->rchild=NULL;
        }
        else{
            t->rchild=stack[t->right];
            flag[t->right]++;//该节点为孩子
            for(int j=0;j<3;j++)
                R[j][t->data]=t->right;
        }
    }
//由于输入是一个森林, 所以根节点可能并没有相互连接

//找根节点
    for(int i=1;i<=n;i++)
    if(flag[i]==0){
        root[top++]=stack[i];
    }
    Bitree T=root[0];
    //将根节点化成二叉树
    for(int i=0;i<top-1;i++){
        root[i]->rchild=root[i+1];
        for(int j=0;j<3;j++)
            R[j][root[i]->data]=root[i]->rchild->data;
    }
    
    for(int i=0;i<3;i++)
        L[i][0]=R[i][0]=1;
    
    list *l1,*l2,*l3;
    l1=newlist();
    l2=newlist();
    l3=newlist();
    l1=Prethreading(l1,T);
    l2=Inthreading(l2,T);
    l3=Postthreading(l3,T);

    node *ptr;
    //先序输出
    for(int i=1;i<=n;i++){
        if(L[0][i]==0){
            for(ptr=l1->head;ptr;ptr=ptr->r)
                if(ptr->data==i && ptr!=l1->head){
                    L[0][i]=ptr->l->data;
                }
        }
    }
    //中序
    for(int i=1;i<=n;i++){
        if(L[1][i]==0){
            for(ptr=l2->head;ptr;ptr=ptr->r)
                if(ptr->data==i && ptr!=l2->head)
                    L[1][i]=ptr->l->data;
        }
    }
    for(int i=1;i<=n;i++){
        if(R[1][i]==0){
            for(ptr=l2->head;ptr;ptr=ptr->r)
                if(ptr->data==i && ptr!=l2->tail)
                    R[1][i]=ptr->r->data;
        }
    }
    //后续
    for(int i=1;i<=n;i++){
        if(R[2][i]==0){
            for(ptr=l3->head;ptr;ptr=ptr->r)
                if(ptr->data==i && ptr!=l3->tail)
                    R[2][i]=ptr->r->data;
        }
    }
    for(int k=0;k<3;k++){
        printf("1");
        for(int i=1;i<=n;i++)
            printf(" %d",L[k][i]);
        printf("\n");
        printf("1");
        for(int i=1;i<=n;i++)
            printf(" %d",R[k][i]);
        printf("\n");
    }
    return 0;

}
