#include <stdio.h>
#include <string.h>
#define MAX 200


typedef struct Node {
    char chdata;
    int succ; //后继, -1表示结尾
    int next; //KMP算法用的next指针, 表示对应的在数组中的位置
} Node;

void buildList(Node list[], char* str, int len) {
    for (int i = 1; i <= len; i++) {
        list[i].chdata = str[i-1];
        list[i].succ = (i == len) ? -1 : (i+1);
        list[i].next = 0; //初始化
    }
}

//KMP算法
void buildNext(Node ind[], int plen) {
    int i = 1, j = 0;
    ind[1].next = 0;
    while (i < plen) {
        if (j == 0 || ind[i].chdata == ind[j].chdata) {
            i++; j++;
            ind[i].next = j;
        } else {
            j = ind[j].next;
        }
    }
}

int kmpMatch(Node txt[], int tlen, Node ind[], int plen) {
    int i = 1, j = 1;
    while (i <= tlen && j <= plen) {
        if (j == 0 || txt[i].chdata == ind[j].chdata) {
            i++; j++;
        } else {
            j = ind[j].next;
        }
    }
    if (j > plen) return i - plen - 1; // 返回主串下标（0开始）
    else return -1;
}

int main() {
    int tlen, plen;
    char t[MAX], p[MAX];
    scanf("%d %d", &tlen, &plen);
    scanf("%s", t);
    scanf("%s", p);

    Node txt[MAX], ind[MAX];
    //根据输入来改造成链表
    buildList(txt, t, tlen);
    buildList(ind, p, plen);
    buildNext(ind, plen);

    int ans = kmpMatch(txt, tlen, ind, plen);
    printf("%d\n", ans);
    return 0;
}