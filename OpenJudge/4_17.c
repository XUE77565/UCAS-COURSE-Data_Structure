#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char s[MAX];
    char ind[MAX];
    char t[MAX];
    char c;
    int slen  =  0;
    int indlen  =  0;
    int tlen  =  0;
    scanf("%s %s %s", s, ind, t);

    slen  =  strlen(s);
    indlen  =  strlen(ind);
    tlen  =  strlen(t);
    //printf("break3\n");
    int search  =  -1;
    int ps,pind;
    for(int i  =  0; i<slen; i++){
        ps  =  i;
        pind  =  0;
        while(s[ps] == ind[pind] && ps<slen && pind<indlen){
            ps++; pind++;
        }
        if(pind == indlen){
            search  =  i;
            break;
        }
    }
    //直接利用打印的办法输出最终的结果串
    if(search  ==  -1){
        printf("%s",s);
    }
    else{
        for(int i  =  0; i < search; i++){
            printf("%c",s[i]);
        }
        printf("%s",t);
        for(int i  =  search + indlen; i < slen; i++){
            printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}