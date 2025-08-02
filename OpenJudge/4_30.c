#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
    char c;
    char s[MAX];
    int length = 0;
    while((c=getchar())!=EOF && c!='\n' && c!=' '){
        s[length++] = c; 
    }
    char temp[MAX] = {0};
    char longe[MAX] = {0};
    int templen = 0;
    int longlen = 0;
    int position = -1;
    char reset[] = "\0";

    for(int i = 0; i < length; i++){
        for(int j = i+1 ; j < length; j++){
            int ps = i, pt = j;
            //这一步很关键, 用来清空temp, 或者每次都引入一个局部变量temp, 但是这样会占用内存比较多
            //memset(temp,0,sizeof(temp));
            char temp[MAX] = {0};
            templen = 0;
            while(s[ps]==s[pt] && pt < length){
                temp[templen++] = s[pt];
                pt++;
                ps++;
            }
            //如果检查到更长的重复串, 则将longe更新
            if(templen > longlen){
                strcpy(longe,temp);
                longlen = strlen(longe);
                position = i;
            }
        }
    }

    if(position < 0){
        printf ("%d",position);
    }
    else{
        printf ("%s",longe);
        printf (" %d",position);
    }

    return 0;
}