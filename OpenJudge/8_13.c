#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int tag;    // 0: free, 1: allocated
    int addr;
    int size;
    struct Block *next;
} Block;

// 按地址升序插入空闲块, 思路与8_14一样
void insert_sorted(Block **head, int tag, int addr, int size) {
    Block *p = (Block *)malloc(sizeof(Block));
    p->tag = tag;
    p->addr = addr;
    p->size = size;
    p->next = NULL;
    if (!(*head) || addr < (*head)->addr) {
        p->next = *head;
        *head = p;
        return;
    }
    Block *cur = *head;
    while (cur->next && cur->next->addr < addr) cur = cur->next;
    p->next = cur->next;
    cur->next = p;
}

// 合并相邻空闲块
void merge(Block *head) {
    Block *p = head;
    while (p && p->next) {
        if (p->tag == 0 && p->next->tag == 0 && p->addr + p->size == p->next->addr) {
            p->size += p->next->size;
            Block *tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
}

// 回收块，并合并左右相邻空闲块
void recycle(Block **head, int tag, int addr, int size) {
    insert_sorted(head, tag, addr, size);
    merge(*head);
}

// 打印所有空闲块
void print_free(Block *head) {
    Block *p = head;
    while (p) {
        if (p->tag == 0)
            printf("0 %d %d\n", p->addr, p->size);
        p = p->next;
    }
}


int main() {
    Block *head = NULL;
    int tag, addr, size;
    char line[128];

    // 读入初始空闲块
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n' || line[0] == '\0') break;
        if (sscanf(line, "%d %d %d", &tag, &addr, &size) == 3)
            insert_sorted(&head, tag, addr, size);
        else
            break;
    }

    // 读入回收块
    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d %d %d", &tag, &addr, &size) == 3)
            recycle(&head, 0, addr, size); // 回收后一定变成tag=0的空闲块
    }

    merge(head);
    print_free(head);
    return 0;
}