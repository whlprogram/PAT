#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 99999999;
int main()
{
    int cmax, n, sp, m;//车站最大容量 n个车站 出问题车站sp  m条道路
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    int weight[n+1] = {0};//记录各个车站车辆数目
    int v[n+1][n+1];//记录道路长度
    int dis[n+1];//dis[i]表示从PBMC到i点的最短路径长度
    int num[n+1] = {0};//num[i]表示从PBMC到i点拥有的最短路径的条数
    bool visit[n+1];
    fill(v[0], v[0]+(n+1)*(n+1), inf);//赋值
    fill(dis, dis+(n+1), inf);
    for(int i=1; i<=n; i++){
        scanf("%d", &weight[i]);
        weight[0] += weight[i];
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        v[a][b] = c;
        v[b][a] = c;
    }
    dis[0] = 0;
    num[0] = 1;
    for(int i=0; i<=n; i++){
        int u=-1, minn = inf;
        for(int j=0; j<=n; j++){
            if(visit[j]==false && dis[j]<minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int k=0; k<=n; k++){
            if(visit[k]==false && v[u][k]!=inf){//路径不包含k点 且u到k点有路径
                if(dis[u]+v[u][k] < dis[k]){//找到更短的路径
                    dis[k] = dis[u]+v[u][k];//最短路径长度更新
                    num[k] = num[u];//最短路径数量更新
                    //自行车数量更新
                }else if(dis[u]+v[u][k] == dis[k]){//路径与最短路径长度相等
                    num[k] = num[k] + num[u];//最短路径数量更新
                }
            }
        }
    }
    return 0;
}
