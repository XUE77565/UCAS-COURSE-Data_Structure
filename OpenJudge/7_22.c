#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

int adj[MAXN][MAXN]; // 邻接矩阵
int visited[MAXN];
int n; // 节点数

// 深度优先搜索
int dfs(int u, int target) {
    if(u == target) return 1;
    visited[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(adj[u][v] && !visited[v]) {
            if(dfs(v, target)) return 1;
        }
    }
    return 0;
}

int main() {
    // 读入节点数
    scanf("%d", &n);
    getchar(); // 吸收换行

    // 读入边
    char edge_line[1024];
    //直接读入一行

    int u, v;
    char c;
    while(1){
        scanf("%d-%d%c",&u,&v,&c);
        adj[u][v] = 1; // 有向图, 所以只加入一个
        if(c=='\n'){
            break;
        }
    }       

    // 读入起点和终点
    int start, end;
    scanf("%d,%d", &start, &end);

    memset(visited, 0, sizeof(visited));
    if(dfs(start, end))
        printf("yes");
    else
        printf("no");

    return 0;
}