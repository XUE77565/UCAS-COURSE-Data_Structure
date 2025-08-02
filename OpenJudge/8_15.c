#include<stdio.h>
#include<stdlib.h>
int highbound;
int lowbound;
int size;

//用结构体来表示块
typedef struct{
    int tag;
    int addr;
}block;

int mergeblock(block* block_arr){
    int num = (highbound - lowbound)/size;
    //用于标记是否有空间
    int found = 0;
    for(int i = 0; i < num;){
        if(block_arr[i].tag == 0) {
        int start = block_arr[i].addr;
        int len = size;
        int j = i+1;
        while(j < num && block_arr[j].tag == 0) {
            len += size;
            j++;
        }
        // 输出一个可用空间
        printf("0 %d %d\n", start, len);
        found = 1;
        i = j; // 跳到下一个未合并的块
        } 
        else {
            i++;
        }
    }
    return found;
}

int main(){
    scanf("%d %d %d",&lowbound,&highbound,&size);
    int num = (highbound - lowbound)/size;
    block block_arr[num];
    //block_arr = (block *)malloc(num * sizeof(block));
    int a;
    int b = 0;
    for(int i = 0; i < num; i++){
        scanf("%d",&a);
        block_arr[i].tag = a;
        //注意
        block_arr[i].addr = lowbound +i * size;
    }

    int result = mergeblock(block_arr);

    if(result == 0){
        printf("0 0 0");
    }
    return 0;
}