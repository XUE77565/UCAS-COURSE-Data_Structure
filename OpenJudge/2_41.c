#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//atoi的作用是将字符串前面的数字部分转化成整型

typedef struct PolyTerm {
    int base;
    int exp;
} PolyTerm;

typedef struct PolyNode {
    PolyTerm data;
    struct PolyNode *next;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly;

// 创建空多项式
LinkedPoly createPoly() {
    LinkedPoly head = (PolyNode *)malloc(sizeof(PolyNode));
    head->next = head;
    return head;
}

// 插入项(按降幂插入，合并同类项)
void insertPoly(LinkedPoly poly, int base, int exp) {
    if (base == 0) return;
    PolyNode *p = poly, *q = poly->next;
    while (q != poly && q->data.exp > exp) {
        p = q;
        q = q->next;
    }
    if (q != poly && q->data.exp == exp) {
        q->data.base += base;
        if (q->data.base == 0) {
            p->next = q->next;
            free(q);
        }
    } else {
        PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
        node->data.base = base;
        node->data.exp = exp;
        node->next = q;
        p->next = node;
    }
}

// 多项式求导
LinkedPoly derivativePoly(LinkedPoly poly) {
    LinkedPoly res = createPoly();
    PolyNode *p = poly->next;
    while (p != poly) {
        if (p->data.exp != 0) {
            //求导
            insertPoly(res, p->data.base * p->data.exp, p->data.exp - 1);
        }
        //求导后删除这个结点
        p = p->next;
    }
    return res;
}

// 去除字符串前后的空格
void trim(char *s) {
    char *p = s, *q = s;
    while (isspace(*p)) ++p;
    while (*p) *q++ = *p++;
    *q = 0;
    while (--q >= s && isspace(*q)) *q = 0;
}

// 解析输入字符串为多项式
void parsePoly(char *str, LinkedPoly poly) {
    trim(str);
    int i = 0, len = strlen(str);
    while (i < len) {
        int sign = 1, base = 0, exp = 0, hasbase = 0;
        // 跳过空格
        while (i < len && isspace(str[i])) ++i;
        // 读取符号
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') sign = -1;
            ++i;
        }
        // 跳过空格
        while (i < len && isspace(str[i])) ++i;
        // 读取系数
        int start = i;
        while (i < len && isdigit(str[i])) ++i;
        if (i > start) {
        //用str+start是表示从当前str+start部分开始读, 将系数转化成整型
            base = atoi(str + start);
            hasbase = 1;
        }
        // 检查 x
        if (i < len && str[i] == 'x') {
            if (!hasbase) base = 1;
            ++i;
            // 检查 ^
            if (i < len && str[i] == '^') {
                ++i;
                int exp_start = i;
                while (i < len && isdigit(str[i])) ++i;
                exp = atoi(str + exp_start);
            } else {
                exp = 1;
            }
        } 
        //对于常熟项, exp = 0;
        else {
            exp = 0;
        }
        //insertpoly是按照降序的
        insertPoly(poly, sign * base, exp);
        while (i < len && isspace(str[i])) ++i;
    }
}

// 打印多项式
void printPoly(LinkedPoly poly) {
    PolyNode *p = poly->next;
    int first = 1;
    while (p != poly) {
        int c = p->data.base, e = p->data.exp;
        if (!first) printf(" ");
        if (c < 0)
            printf("- ");
        else if (!first)
            printf("+ ");
        if (abs(c) != 1 || e == 0)
            printf("%d", abs(c));
        if (e > 0) {
            printf("x");
            if (e > 1) printf("^%d", e);
        }
        first = 0;
        p = p->next;
    }
    if (first) printf("0");
    printf("\n");
}

int main() {
    char s[500];
    //由于有空格的存在, 经过查阅资料, 直接用fgets来读取整行
    fgets(s, sizeof(s), stdin);
    if (s[strlen(s)-1] == '\n') s[strlen(s)-1] = '\0';

    LinkedPoly poly = createPoly();
    parsePoly(s, poly);
    LinkedPoly der = derivativePoly(poly);
    printPoly(der);

    return 0;
}