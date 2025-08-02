#include <stdio.h>
#include <stdlib.h>

typedef struct binode{
    char data;
    struct binode *lchild,*rchild;
}Binode,*Bitree;

//根据这个先序的输入利用递归构造树
Bitree creatTree(){
    char c=getchar();
    if(c=='#')
        return NULL;
    else{
        Bitree T=(Bitree)malloc(sizeof(Binode));
        T->data=c;
        T->lchild=creatTree();
        T->rchild=creatTree();
        return T;
    }
    
}

//我们要考虑运算符的优先级, 类似逆波兰表达式
void printformula(Bitree T){
    if(!T) return ;
    if(T->lchild && (T->lchild->data=='+' || T->lchild->data=='-') && (T->data =='*' || T->data=='/')){
        printf("(");
        printformula(T->lchild);
        printf(")");
    }
    //如果没有优先级关系直接打印z左子树即可
    else{
        printformula(T->lchild);
    }
    printf("%c",T->data);
    //如果中心为乘除, 右边为加减, 右侧加括号和保持运算正确
    if(T->rchild && (T->rchild->data=='+'||T->rchild->data=='-') && (T->data=='*'||T->data=='/'||T->data=='-'))
    {
        printf("(");
        printformula(T->rchild);
        printf(")");
    }
    //保证运算的正确性
    else if(T->rchild && (T->rchild->data=='*'||T->rchild->data=='/')&& T->data=='/'){
        printf("(");
        printformula(T->rchild);
        printf(")");
    }
    else{
        printformula(T->rchild);
    }
}

int main(){
    Bitree T;
    T=creatTree();
    printformula(T);
    return 0;
}