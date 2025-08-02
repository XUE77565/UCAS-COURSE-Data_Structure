#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int s[MAX],fst[MAX],lst[MAX];



int findpath(int u,int v){
    for(int i=fst[u];i<lst[u];i++)
        if(s[i]==v)
            return 1;
        else if(findpath(s[i],v)==1)
            return 1;
    
    return 0;
}


int main(){
    int top = 0;
    int n;
    char c;
    scanf("%d%c",&n,&c);
    while(1){
        //读入数组s
        scanf("%d%c",&s[top++],&c);
        if(c!=' ')
        break;
    }

    //读入数组fst
    for(int i=0;i<=n;i++)
        scanf("%d",&fst[i]);

    //读入数组lst
    for(int i=0;i<=n;i++)
        scanf("%d",&lst[i]);

    int result=0;
    for(int i=0;i<=n;i++)
    //利用从i到i的路径来判断贿赂
        if(findpath(i,i)==1)
        {
            result=1;
            break;
        }

    if(result==1)
        printf("yes");
    else    
        printf("no");
    
    return 0;
}
