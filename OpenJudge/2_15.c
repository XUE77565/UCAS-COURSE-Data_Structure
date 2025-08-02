#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    struct Lnode* next;
}Lnode, Linkedlist;

int main(){
    int Len_a,Len_b;
    scanf("%d",&Len_a);
    scanf("%d",&Len_b);
    
    //build head node a
    Linkedlist* La;
    La = (Linkedlist *)malloc(sizeof(Lnode));
    La->next = NULL;

    //build head node b
    Linkedlist* Lb;
    Lb = (Linkedlist *)malloc(sizeof(Lnode));
    Lb->next = NULL;

    //build linkedlist a
    for(int i = 0; i < Len_a; i++){
        Lnode *p;
        p = (Lnode *)malloc(sizeof(Lnode));
        int n;
        scanf("%d",&n);
        p->data = n;
        p->next = La->next;

        La->next = p; 
    }

    //build linkedlist b
    for(int i = 0; i < Len_b; i++){
        Lnode *q;
        q = (Lnode *)malloc(sizeof(Lnode));
        int n;
        scanf("%d",&n);
        q->data = n;
        q->next = Lb->next;
        Lb->next = q;
    }

    //merge 2 linked list
    Lnode* p = La;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = Lb->next;

    Lnode* pp = La->next; 
    int reverse[Len_a+Len_b];
    int i = 0;
    while (pp != NULL) {
        reverse[i] = pp->data;
        pp = pp->next;
        i++;
    }
    for(int i = Len_a+Len_b-1; i>=0 ; i--){
        printf("%d ",reverse[i]);
    }
    return 0;
}