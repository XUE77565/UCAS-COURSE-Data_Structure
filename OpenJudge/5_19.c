#include<stdio.h>
#define MAX 100


int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    int M[r][c];
    for(int i  =  0; i < r; i++){
        for(int j  =  0; j < c; j++){
            scanf("%d",&M[i][j]);
        }
    }

    int out[MAX];
    int outlen  =  0;

    for(int i  =  0; i < r ; i++){
        for(int j  =  0; j < c; j++){
            int result  =  1;
            for(int m  =  0; m < c; m++){
            //检查是否是行中的最小
                if(M[i][m] < M[i][j])
                    result  =  0;
            }
            for(int n  =  0; n < r; n++){
            //检查是否是列中的最大
                if(M[n][j] > M[i][j])
                    result  =  0;
            }
            if(result){
                out[outlen++]  =  M[i][j];
            }
        }
    }

    for(int i  =  0; i < outlen; i++){
        if(!i) printf("%d",out[i]);
        else printf(" %d",out[i]);
    }
    return 0;
}