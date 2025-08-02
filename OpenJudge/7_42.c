#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110
#define INF 1000000000

typedef struct Edge {
    int to, w;
    struct Edge *next;
} Edge;

Edge* adj[MAXN];
int dist[MAXN];
int vis[MAXN];

//插入邻接表
void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->w = w;
    e->next = adj[u];
    adj[u] = e;
}

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    // 初始化邻接表
    for(int i=1; i<=n; i++) adj[i] = NULL;
    // 读边
    int u, v, w;
    while (scanf("%d-%d %d", &u, &v, &w) == 3) {
        addEdge(u, v, w);
    }

    // Dijkstra
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
        vis[i] = 0;
    }
    //初始化源点
    dist[s] = 0;

    for(int i=1; i<=n; i++) {
    //u0用来标记当前距离源点最近的点
        int minD = INF, u0 = -1;
        for(int j=1; j<=n; j++) {
    //找所有未访问过的点中, 里源点最近的点
            if(!vis[j] && dist[j]<minD) {
                minD = dist[j];
                u0 = j;
            }
        }
    // 表示联通的部分已经结束
        if(u0 == -1) break;
        vis[u0] = 1;
    //遍历所有从u0出发的点,来更新之后的值
        for(Edge* e = adj[u0]; e; e = e->next) {
            if(!vis[e->to] && dist[e->to] > dist[u0] + e->w) {
                dist[e->to] = dist[u0] + e->w;
            }
        }
    }

    // 输出
    int first = 1;
    for(int i=1; i<=n; i++) {
        if(i == s) continue;
        if(!first) printf(",");
        printf("%d", dist[i]==INF?-1:dist[i]);
        first = 0;
    }
    printf("\n");
    return 0;
}