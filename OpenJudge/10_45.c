#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_RECORD 10000
#define MAX_KEY 5
#define MAX  101   //每个记录的关键字大小不超过100
#define RADIX 101


//对于链表基数排序, 我直接复用了我大作业中的代码
typedef struct{
    int keys[MAX_KEY];
    int next;
}SLCell;

typedef struct{
    SLCell array[MAX_RECORD + 1];
    int keynum;
    int length;
}SLList;

void Distribute(SLCell* array, int i, int* f, int* e, int factor){
    for(int j = 0; j < RADIX; j++) f[j] = 0;    //初始化f数组
    for(int p = array[0].next; p; p = array[p].next){
        //将p所指的结点插入到相应的子链表当中
        //去除对应的位数
        int m = (array[p].keys[0]/factor)%10;
        if(!f[m]) {
            f[m] = p; //如果f[j]为空, 连接p
        }
        else{
            array[e[m]].next = p;
        }
        e[m] = p;
    }
}

void Collect(SLCell* array, int i, int* f, int* e){
    int j;
    for(j = 0; !f[j]; j++);//找到第一个非空子表
    array[0].next = f[j];
    int t = e[j];
    while(j < RADIX){
        for(j++; j < RADIX; j++){//找下一个非空的子表
            if(f[j]){
                array[t].next = f[j];   //将两个表合并
                t = e[j];
            }
        }
    }
    array[t].next = 0;
    //最后一个结点指向表头
}

void RadixSort(SLList *L){
    int* f = (int *)malloc(RADIX * sizeof(int));
    int* e = (int *)malloc(RADIX * sizeof(int));
    int max = 0;
    for(int i=1; i<=L->length; i++)
        if(L->array[i].keys[0]>max) max = L->array[i].keys[0];
    // 求最大位数
    int times = 0; 
    while(max){ times++; max/=10; }
    //用factor标记位数
    int factor = 1;
    for(int i = 0; i < times; i++){
        Distribute(L->array, i, f, e, factor);
        Collect(L->array, i, f, e);
        factor *= 10;
    }
    free(f); free(e);
}

void print_SLlist(SLList* L){
    int i = L->array[0].next;
    int j = 0;
    while(i){
        printf("%d", L->array[i].keys[0]);
        if(L->array[i].next) printf(" ");
        i = L->array[i].next;
    }
}                                                 
                                                                                                                                                       
              

int main(){
    SLList* L = (SLList*)malloc(sizeof(SLList));
    L->keynum = 1; // 一关键字
    L->length = 0;
    L->array[0].next = 1; // 头结点

    int num = 0, idx = 1,has_num = 0;
    char c;
    //每次因为输入都要处理很长时间, 希望可以改进一下,对输入更严谨一些
    while((c=getchar())!=EOF && c!='\n'){
        if(isdigit(c)){
            num = num*10 + (c-'0');
            has_num = 1;
        }else if(c==' ' && has_num){
            L->array[idx].keys[0] = num;
            L->array[idx].next = idx+1; 
            idx++; num=0; has_num=0;
        }
    }
    // 处理最后一个数据
    if(has_num){
        L->array[idx].keys[0] = num;
        L->array[idx].next = 0;
        idx++;
    }else if(idx>1){
        L->array[idx-1].next = 0;
    }
    L->length = idx-1;

    RadixSort(L);
    print_SLlist(L);

    free(L);
    return 0;
}