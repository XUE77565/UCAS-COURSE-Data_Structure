#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    int pos[MAX]  =  {0};
    //用于存储在s中不在t中的字符
    char out[MAX]  =  {0};
    int outlen  =  0;
    char s[MAX]  =  {0};
    char t[MAX]  =  {0};
    scanf("%s %s",s,t);
    int slen  =  strlen(s);
    s[slen]  =  '\0';
    int tlen  =  strlen(t);
    t[tlen]  =  '\0';

    char c;
    int i,j,k;
    for(i  =  0; i < slen; i++){
        c  =  s[i];
        for(j  =  0; j < tlen; j++){
            if(s[i] == t[j]) break;
        }
        if(j  ==  tlen){//表示t中没有这个字符
            for(k  =  0; k < outlen; k++){
                if(s[i] == out[k]) break; //表示已经保存过这个字符了
            }
            if(k == outlen){//这个字符没有重复
                out[outlen]  =  s[i];
                pos[outlen]  =  i;
                outlen++;
            }
        }
    }

    if(outlen == 0){
        printf("-1");
    }
    else{
       printf("%s ",out);
        for(int i  =  0; i < outlen; i++){
            printf("%d",pos[i]);
        }    
    }
    
    return 0;

}