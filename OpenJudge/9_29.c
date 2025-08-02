#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int search(int* s, int* t,int key,int len){
    if(*t == key){return 1;}
    //加上对下一个方向的值的判断, 防止死循环
    else if(*t < key && t-s<len && *(t+1) <= key){
        return search(s,t+1,key,len);
    }
    else if(*t > key && t>s && *(t-1) >= key){
        return search(s,t-1,key,len);
    }
    else return 0;
}


int main(){
    int slen = 0;
    int indlen = 0;
    int s[MAX];
    int ind[MAX];
    int n;
    char c;
    while(1){
        scanf("%d%c",&n,&c);
        s[slen++] = n;
        if(c=='\n'){break;}
    }
    while(1){
        scanf("%d%c",&n,&c);
        ind[indlen++] = n;
        if(c=='\n' || c==EOF){break;}
    }
    int *t = s;
    //h一直指向表头
    int *h = s;
    for(int i = 0; i < indlen; i++){
        int key = ind[i];
        printf("%d ",search(s,t,key,slen));
    }
}