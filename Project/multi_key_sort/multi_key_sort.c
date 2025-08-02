#include "multi_key.h"


//用于统计结果的main函数
int main(){
    struct timespec ts1, ts2;
    double time_lsd = 0.0;
    double time_msd = 0.0;
    double time_cnd = 0.0;
    int l = 0;
    //在程序中实现多次计算取平均值
    srand((unsigned)time(0));// 添加这行以随机化种子
    int loop;
    printf("please enter the number of loop:");
    scanf("%d",&loop);
    while(l < loop){
        int r = (rand() % MAX_RECORD) + 1;
        int k = (rand() % MAX_KEY) + 1;
        printf("Woring on sort [%d]\trecord number[%d]\tkeys per record[%d]\n",l+1,r,k);
        //printf("r=%d\nk=%d\n",r,k);
        int **array_record = (int **)malloc(r * sizeof(int*));//为多关键字记录序列以及结点分配空间
        for(int i = 0; i < r; i++){
            array_record[i] = (int *)malloc(k * sizeof(int));
            for(int j = 0; j < k ; j++){
                array_record[i][j] = (rand() % MAX);
            }
        }

        SLList list;
        for(int i = 0; i < r; i++){
            //初始化链表
            for(int j = 0; j < k; j++){
                list.array[i + 1].keys[j] =  array_record[i][j];
            }
            list.array[i].next = i + 1;
        }
        list.array[r].next = 0; // 构造出这个静态链表
        list.keynum = k;
        list.length = r;

        int** array_record_msd = (int **)malloc(r * sizeof(int*));//把同样的数据赋值给msd一份
        for(int i = 0; i < r; i++){
            array_record_msd[i] = (int *)malloc(k * sizeof(int));
            for(int j = 0; j < k ; j++){
                array_record_msd[i][j] = array_record[i][j];
            }
        }
        

        clock_gettime(CLOCK_MONOTONIC, &ts1);
        //进行lsd排序
        lsd_sort(array_record,r,k);
        clock_gettime(CLOCK_MONOTONIC, &ts2);
        time_lsd += (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;


        clock_gettime(CLOCK_MONOTONIC, &ts1);
        //利用递归的思路进行msd的排序
        msd_sort(array_record_msd,0,r-1,k,0);
        clock_gettime(CLOCK_MONOTONIC, &ts2);
        time_msd += (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;

        SLList *p = &list;

        clock_gettime(CLOCK_MONOTONIC, &ts1);
        //进行分配收集排序
        RadixSort(p);
        clock_gettime(CLOCK_MONOTONIC, &ts2);
        time_cnd += (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;


        //释放空间
        for(int i = 0; i < r; i++){
            free(array_record[i]);
        }
        free(array_record);

        l++;
    }
    
    printf("=========================================\n");
    printf("LSD_BUBBLE_AVRAGE_TIME = %.7f\n", time_lsd/LOOP);
    printf("=========================================\n");

    printf("=========================================\n");
    printf("MSD_BUBBLE_AVRAGE_TIME = %.7f\n", time_msd/LOOP);
    printf("=========================================\n");
    
    printf("=========================================\n");
    printf("LSD_DISTRIBUTE&COLLET = %.7f\n", time_cnd/LOOP);
    printf("=========================================\n");

    return 0;
}

//main函数部分, 生成最多10000个数据, 每个数据最多有5个记录, 用于检查排序结果的main函数
// int main(){
//     srand((unsigned)time(0)); // 添加这行以随机化种子
//     int r = (rand() % MAX_RECORD) + 1;
//     int k = (rand() % MAX_KEY) + 1;

//     printf("r=%d\nk=%d\n",r,k);
//     int **array_record = (int **)malloc(r * sizeof(int*));//为多关键字记录序列以及结点分配空间
//     for(int i = 0; i < r; i++){
//         array_record[i] = (int *)malloc(k * sizeof(int));
//         for(int j = 0; j < k ; j++){
//             array_record[i][j] = (rand() % MAX);
//         }
//     }

//     SLList list;
//     for(int i = 0; i < r; i++){
//         //初始化链表
//         for(int j = 0; j < k; j++){
//             list.array[i + 1].keys[j] =  array_record[i][j];
//         }
//         list.array[i].next = i + 1;
//     }
//     list.array[r].next = 0; // 构造出这个静态链表
//     list.keynum = k;
//     list.length = r;

//     int** array_record_msd = (int **)malloc(r * sizeof(int*));//把同样的数据赋值给msd一份
//     for(int i = 0; i < r; i++){
//         array_record_msd[i] = (int *)malloc(k * sizeof(int));
//         for(int j = 0; j < k ; j++){
//             array_record_msd[i][j] = array_record[i][j];
//         }
//     }
    
//     printf("=========================================\n");
//     printf("================BEFORE_SORTED============\n");
//     printf("=========================================\n");
//     print_arr(array_record,r,k);

//     struct timespec ts1, ts2;
//     clock_gettime(CLOCK_MONOTONIC, &ts1);
//     lsd_sort(array_record,r,k);
//     clock_gettime(CLOCK_MONOTONIC, &ts2);
//     double elapsed = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;
//     printf("LSD_BUBLLE_SORTED:\n");
//     print_arr(array_record,r,k);
//     printf("=========================================\n");
//     printf("LSD_BUBBLE_AVRAGE_TIME = %.7f\n", elapsed);
//     printf("=========================================\n");

//     clock_gettime(CLOCK_MONOTONIC, &ts1);
//     //利用递归的思路进行msd的排序
//     msd_sort(array_record_msd,0,r-1,k,0);
//     clock_gettime(CLOCK_MONOTONIC, &ts2);
//     elapsed = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;
//     printf("MSD_BUBLLE_SORTED:\n");
//     print_arr(array_record_msd,r,k);
//     printf("=========================================\n");
//     printf("MSD_BUBBLE_AVRAGE_TIME = %.7f\n", elapsed);
//     printf("=========================================\n");
    

//     SLList *p = &list;

//     clock_gettime(CLOCK_MONOTONIC, &ts1);
//     RadixSort(p);
//     clock_gettime(CLOCK_MONOTONIC, &ts2);
//     elapsed = (ts2.tv_sec - ts1.tv_sec) + (ts2.tv_nsec - ts1.tv_nsec) / 1e9;
//     printf("LSD_DISTRIBUTE&COLLET_SORTED:\n");
//     print_SLlist(p);
//     printf("=========================================\n");
//     printf("LSD_DISTRIBUTE&COLLET = %.7f\n", elapsed);
//     printf("=========================================\n");


//     for(int i = 0; i < r; i++){
//         free(array_record[i]);
//     }
//     free(array_record);
//     return 0;
// }

//LSD冒泡排序
//关键字序号越大, 优先级越低
void lsd_sort(int ** arr_record,int r,int k){
    for(int i = k - 1; i >= 0; i--){  //对每个关键字进行排序, 先从优先级低的排序, 采用冒泡排序
        int* temp;
        int j = r-1;
        int sorted = FALSE;
        while(!sorted){
            sorted = TRUE;
            for(int m = 0; m < j; m++){
                if(arr_record[m+1][i] < arr_record[m][i]){  
                    temp = arr_record[m+1];
                    arr_record[m+1] = arr_record[m];
                    arr_record[m] = temp;
                    sorted = FALSE;    //表示遇到了逆序对, sorted置为0
                }
            }
            j--;        
        }
    }
}

void print_arr(int**arr_record, int r, int k){
    for(int i = 0; i < r; i++){
        printf("array[%d]:",i);
        for(int j = 0; j < k; j++){
            printf("\t[%d]",arr_record[i][j]);
        }
        printf("\n");
    }
}


void RadixSort(SLList *L){
    int* f;
    int* e;
    //为f,e分配空间
    f = (int *)malloc(RADIX * sizeof(int));
    e = (int *)malloc(RADIX * sizeof(int));
    for(int i = L->keynum - 1; i >= 0; i--){//按照关键字排序, 最右侧的优先级最低
        Distribute(L->array,i,f,e);
        Collect(L->array,i,f,e);
    }
    free(f); free(e);
}

void Distribute(SLCell* array, int i, int* f, int* e){
    for(int j = 0; j < RADIX; j++) f[j] = 0;    //初始化f数组
    for(int p = array[0].next; p; p = array[p].next){
        //将p所指的结点插入到相应的子链表当中
        int m = array[p].keys[i];
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



void print_SLlist(SLList* L){
    int i = L->array[0].next;
    int j = 0;
    while(i){
        printf("array[%d]:",j);
        for(int k = 0; k < L->keynum; k++){
            printf("\t[%d]",L->array[i].keys[k]);
        }
        printf("\n");
        j++;
        i = L->array[i].next;
    }
}

//在序列中的left和right之间的进行对关键字key_num的排序, 同样采用冒泡排序
void bubblesort(int** array_record,int left, int right, int key_num){
    int j = right;
    int* temp;
    int sorted = FALSE;
    while(!sorted){
        sorted = TRUE;
        for(int m = left; m < j; m++){
            if(array_record[m+1][key_num] < array_record[m][key_num]){  
                temp = array_record[m+1];
                array_record[m+1] = array_record[m];
                array_record[m] = temp;
                sorted = FALSE;    //表示遇到了逆序对, sorted置为0
            }
        }
        j--;        
    }
}

//利用递归的思路来实现msd的算法
void msd_sort(int** array_record, int left, int right, int k, int key_num){
    if(key_num >= k || right <= left + 1) return ;//表示如果当前关键字已经排序完成, 或者当前同一关键字中只有1个元素
    bubblesort(array_record,left,right,key_num);//对key_num进行排序

    int start = left;//如果相同关键字有多个, 则递归调用msd, 对下一关键字进行排序
    while(start < right){
        int end = start + 1;
        while(end < right && array_record[start][key_num] == array_record[end][key_num]){
            end++;
        }
        msd_sort(array_record, start, end, k ,key_num + 1);//对更低优先级的关键字排序
        start = end;    //继续向下做排序
    }
}
