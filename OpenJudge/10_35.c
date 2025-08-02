#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

//定义交换大小
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

typedef struct{
    int record[MAX];
    int length;
}Heap;

//实际上三叉树和二叉树差不多,只不过把2变成3
void Heapsort(Heap *H){

}

//这个要调整的比较多
void HeapAdjust(Heap* H,int s,int m){
    int temp = H->record[s];
    int max;
    for(int j=3*s -1; j <= m; j = 3*j-1){
        max = j;
        //max为前两个中的比较大的
        if(max<m && H->record[max] < H->record[max+1]) max++;
        //这个j+2表示的是有三个元素
        if(j+2<=m && H->record[max] < H->record[j+2]) j = j+2;
        else j = max;
        //调整完成
        if(temp >= H->record[j]) break;
        else{
            //交换位置
            H->record[s] = H->record[j];
            s = j;
        }
    }
    H->record[s] = temp;
}

void HeapSort(Heap* H){
    for(int i = (H->length - 1)/3; i > 0; --i){
        HeapAdjust(H,i,H->length);
    }
    for(int i = H->length; i > 1; --i){
        swap(&H->record[1],&H->record[i]);
        HeapAdjust(H, 1, i-1);
    }
}

int main(){
    int s[MAX], length = 0;
    char ch;
    Heap* H = (Heap*)malloc(sizeof(Heap));
    // 输入一行整数
    while (scanf("%d%c", &H->record[++length], &ch)) {
        if (ch == '\n') break;
    }

    H->length = length;

    HeapSort(H);
    for(int j=1;j<=H->length;j++){
        if(j>1) printf(" ");
        printf("%d",H->record[j]);
    }
    return 0;
    
}