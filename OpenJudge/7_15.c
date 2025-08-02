#include <stdio.h>

int M[100][100]={0};
//节点个数
int n;

//插入点
void IV(int v){
    if(v==n){
        for(int i=0;i<=n;i++)
            M[n][i]=0,M[i][n]=0;
            n++;
    }
    //相当于插队, 要进行平移
    else if(v<n){
        for(int i=n-1;i>=v;i--)
            for(int j=0;j<n;j++)
            M[i+1][j]=M[i][j];
        
        for(int j=n-1;j>=v;j--)
            for(int i=0;i<=n;i++)
            M[i][j+1]=M[i][j];

        for(int i=0;i<=n;i++)
            M[v][i]=0,M[i][v]=0;
            n++;
    }
}

//删除点
void DV(int v){
    for(int i=v+1;i<n;i++)
        for(int j=0;j<n;j++)
        M[i-1][j]=M[i][j];
    
    for(int j=v+1;j<n;j++)
        for(int i=0;i<n-1;i++)
        M[i][j-1]=M[i][j];
    
    for(int i=0;i<n;i++)
        M[i][n-1]=M[n-1][i]=0;
    
    n--;
}

//插入弧, 注意无向图, 所以要插入和删除两个
void IA(int u,int v){
    M[u][v]=M[v][u]=1;
}

//删除弧
void DA(int u,int v){
    M[u][v]=M[v][u]=0;
}



int main(){
    char c;
    int u,v;
    scanf("%d%c",&n,&c);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d%c",&M[i][j],&c);
    
    while(1){
        c=getchar();
        //插入
        if(c=='I'){
            c=getchar();
            if(c=='A'){
                getchar();
                scanf("%d %d",&u,&v);
                IA(u,v);
            }
            else if(c=='V'){
                getchar();
                scanf("%d",&v);
                IV(v);
            }
        }
        //删除
        else if(c=='D'){
            c=getchar();
            if(c=='A'){
                getchar();
                scanf("%d %d",&u,&v);
                DA(u,v);
            }
            else if(c=='V'){
                getchar();
                scanf("%d",&v);
                DV(v);
            }
        }
        else break;
        if((c=getchar())==EOF)
            break;
    }

    for(int i=0;i<n;i++){
        printf("%d",M[i][0]);
        for(int j=1;j<n;j++)
            printf(" %d",M[i][j]);
        printf("\n");
    }
    
    return 0;
}
