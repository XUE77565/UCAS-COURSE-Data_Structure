#ifndef MULTI_KEY_H

#define MULTI_KEY_H

#define MAX_RECORD 10000
#define MAX_KEY 5
#define MAX  101   //每个记录的关键字大小不超过100
#define FALSE 0
#define TRUE 1
#define RADIX 101
/**
 * @brief 利用LOOP循环多次求平均值结果
 */
#define LOOP 1000 //设置平均时间, 用于测定多次实验得到的统计数据

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 静态链表结点
 * 每个结点包含多个关键字
 * 每个结点的next指向下一个结点
 * @note 结点的next为0表示链表结束
 * @note keys数组存储多个关键字
 */
typedef struct{
    int keys[MAX_KEY];
    int next;
}SLCell;


/**
 * @brief 静态链表
 * 包含一个数组来存储结点
 * keynum表示每个结点的关键字数量
 * length表示链表的长度
 * @note 结点的索引从1开始, 0号结点为头结点
 * @note 头结点的next指向链表的第一个结点
 * @note 结点的next为0表示链表结束
 * @note keys数组存储多个关键字
 */
typedef struct{
    SLCell array[MAX_RECORD + 1];
    int keynum;
    int length;
}SLList;

/**
 * @brief 对多关键字记录序列进行LSD排序
 * @param arr_record 多关键字记录序列
 * @param r 记录的数量
 * @param k 每个记录的关键字数量
 * @return void
 * @note 该函数用于对多关键字记录序列进行LSD排序
 * @note 该函数将按照每个记录的关键字进行排序
 * @note 关键字序号越大，优先级越低
 * @note 该函数使用冒泡排序实现LSD排序
 * @note 每次排序从最后一个关键字开始，逐个向前排序
 * @note 该函数会修改arr_record数组中的内容
 */
void lsd_sort(int ** arr_record,int r,int k);

/**
 * @brief 打印多关键字记录序列
 * @param arr_record 多关键字记录序列
 * @param r 记录的数量
 * @param k 每个记录的关键字数量
 * @return void
 * @note 该函数用于打印多关键字记录序列
 * @note 每行打印一个记录的所有关键字
 * @note 记录的索引从0开始
 */
void print_arr(int**arr_record, int r, int k);

/**
 * @brief 对静态链表进行基于收集和分配的计数LSD排序
 * @param array 静态链表
 * @param i 当前排序的关键字索引
 * @param f 分布数组
 * @param e 结束数组
 * @return void
 * @note f数组用于记录每个子链表的头结点索引
 * @note e数组用于记录每个子链表的尾结点索引
 * @note 该函数将静态链表中的结点按照第i个关键
 * 字进行分布
 * @note 该函数将静态链表中的结点按照第i个关键字进行收集
 * @note 之后按照优先级从小到大的顺序一次进行
 * @note 该函数会修改静态链表的next指针，使得结点按照第i个关键字排序
 */
void Distribute(SLCell* array, int i, int* f, int* e);

/**
 * @brief 对静态链表进行收集
 * @param array 静态链表
 * @param i 当前排序的关键字索引
 * @param f 分布数组
 * @param e 结束数组    
 * @return void
 * @note f数组用于记录每个子链表的头结点索引
 * @note e数组用于记录每个子链表的尾结点索引
 * @note 该函数将静态链表中的结点按照第i个关键字进行收集
 * @note 该函数会修改静态链表的next指针，使得结点按照第i个关键字排序
 * @note 该函数将所有子链表合并成一个完整的静态链表
 */
void Collect(SLCell* array, int i, int* f, int* e);

/**
 * @brief 对静态链表进行基数排序
 * @param L 静态链表
 * @return void
 * @note 该函数对静态链表进行基数排序
 * @note 该函数将按照每个结点的关键字进行排序
 * @note 该函数会修改静态链表的next指针，使得结点按照关键字排序
 * @note 该函数从最后一个关键字开始，逐个向前排序
 * @param L->keynum 表示每个结点的关键字数量
 * @param L->length 表示静态链表的长度
 */
void RadixSort(SLList *L);

/**
 * @brief 打印静态链表
 * @param L 静态链表
 * @return void
 * @note 该函数用于打印静态链表
 * @note 每行打印一个结点的所有关键字
 * @note 结点的索引从1开始，0号结点为头结点
 * @note 头结点的next指向链表的第一个结点
 */
void print_SLlist(SLList* L);

/**
 * @brief 对多关键字记录序列进行冒泡排序
 * @param array_record 多关键字记录序列
 * @param left 排序的起始索引
 * @param right 排序的结束索引
 * @param key_num 关键字的数量
 * @return void
 * @note 该函数用于对多关键字记录序列进行冒泡排序
 * @note 该函数将按照每个记录的关键字进行排序
 * @note 关键字序号越大，优先级越低
 * @note 该函数使用冒泡排序实现
 * @note 每次排序从左到右比较相邻的记录，如果前一个记录的关键字大于后一个记录的关键字，则交换它们的位置
 * @note 该函数会修改array_record数组中的内容
 */
void bubblesort(int** array_record,int left, int right, int key_num);

/**
 * @brief 对多关键字记录序列进行MSD排序
 * @param array_record 多关键字记录序列
 * @param left 排序的起始索引
 * @param right 排序的结束索引
 * @param k 关键字的数量
 * @param key_num 当前排序的关键字索引
 * @return void
 * @note 该函数用于对多关键字记录序列进行MSD排序
 * @note 该函数将按照每个记录的关键字进行排序
 * @note 关键字序号越大，优先级越低
 * @note 该函数使用递归的方式实现MSD排序
 * @note 每次排序从当前关键字开始，递归地对每个子序列进行排序, 递归的排序采用冒泡排序
 * @note 该函数会修改array_record数组中的内容
 * @note 当left等于right时，表示只有一个记录，不需要排序
 * @note 当key_num等于k时，表示所有关键字都已排序完成
 */
void msd_sort(int** array_record, int left, int right, int k, int key_num);
#endif

