#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 110

// 将逗号删去
int parse(char *line, char arr[]) {
    int cnt  =  0;
    char *p  =  line;
    for (int i  =  0; line[i]; i++) {
        if (line[i]  ==  ',' || line[i]  ==  '\n' || line[i]  ==  '\r') continue;
        arr[cnt++]  =  line[i];
    }
    return cnt;
}

// 判断元素x是否在数组arr中，长度为len
int in(char x, char arr[], int len) {
    for (int i  =  0; i < len; i++)
        if (arr[i]  ==  x) return 1;
    return 0;
}

int main() {
    char lineA[MAXN], lineB[MAXN], lineC[MAXN];
    char A[MAXN], B[MAXN], C[MAXN];
    int Alen, Blen, Clen;
    
    // 有逗号, 所以直接用fgets读入三行
    fgets(lineA, MAXN, stdin);
    fgets(lineB, MAXN, stdin);
    fgets(lineC, MAXN, stdin);


    Alen  =  parse(lineA, A);
    Blen  =  parse(lineB, B);
    Clen  =  parse(lineC, C);

    int first  =  1;
    for (int i  =  0; i < Alen; i++) {
        // 如果A[i]同时在B和C中，不输出
        if (in(A[i], B, Blen) && in(A[i], C, Clen)) continue;
        if (!first) printf(",");
        printf("%c", A[i]);
        first  =  0;
    }
    printf("\n");
    return 0;
}