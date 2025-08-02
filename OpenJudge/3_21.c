#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// 操作符优先级
int precedence(char op) {
    if(op == '+' || op == '-') 
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

// 判断是否为操作符
int is_operator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/';
}

//转换为逆波兰表达式
void postfix(char* s, char* output) {
    char stack[MAX];
    int top = -1;
    int k = 0;
    int len = strlen(s);

    for(int i = 0; i < len; ++i) {
        char c = s[i];
        //压入操作数
        if (isalpha(c)) {
            output[k++] = c;
        } 
        //对于括号的情况
        else if (c == '(') {
            stack[++top] = c;
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') top--; // 弹出左括号
        } 
        //其他操作符
        else if (is_operator(c)) {
            //如果压入一个优先级低的操作符, 进行弹出
            while (top != -1 && precedence(stack[top]) >= precedence(c) && stack[top] != '(') {
                output[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        output[k++] = stack[top--];
    }
    output[k] = '\0';
}

int main() {
    char s[MAX];
    char output[MAX];
    // 输入表达式
    scanf("%s",s);
    s[strcspn(s, "\n")] = 0; // 去掉换行
    postfix(s, output);
    printf("%s\n", output);
    return 0;
}