#include<stdio.h>
#include<string.h>
#define MAX 100

int bracket_check(char* s);

int main(){
    char s[MAX];
    scanf("%s",s);
    int result;
    result = bracket_check(s);
    printf("%d",result);
    return 0;
}

int bracket_check(char* s){
    char c;
    char stack[MAX];
    int top = -1;
    int check = 1;
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        c = s[i];
        //遇到左括号,压栈
        if(c=='('){
            stack[++top] = c;
        }
        //遇到右括号,弹栈
        else if(c==')'){
            if(top<0){
                check = 0;
                break;
            }
            top--;
        }
    }
    if(top>=0){
        check = 0;
    }
    return check;
}