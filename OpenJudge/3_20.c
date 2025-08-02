#include<stdio.h>
#define MAX 100
int M[MAX][MAX];
int r,c;
int color;
//利用旋转向量标记四个方向
int dir_x[] = {1,-1,0,0};
int dir_y[] = {0,0,1,-1};

int out(int x, int y){
    if(x < 0 || x >= r || y < 0 || y >= c){
        return 1;
    }
    else return 0;
}

void paint(int x,int y){
    M[x][y] = 2;
    int px,py;
    for(int i = 0; i < 4; i++){
        px = x + dir_x[i];
        py = y + dir_y[i];
        if(!out(px,py) && M[px][py]==color){
            //利用递归染色
            paint(px,py);
        }
    }
}



int main(){
    int x,y,dir;//分别代表五个输入, 不过dir貌似没什么必要
    scanf("%d %d %d %d %d",&r,&c,&x,&y,&dir);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d",&M[i][j]);
        }
    }
    color = M[x][y];
    paint(x,y);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d",M[i][j]);
        }  
        printf("\n");
    }
    return 0;
}

