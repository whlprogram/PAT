//原题链接  https://www.patest.cn/contests/pat-a-practise/1003
//题解  http://blog.csdn.net/whl_program/article/details/77261182
//求无向图两结点间的最短路径，并求出最短路径的最大点权
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//城市数目n 路径总数目m 起点c1  终点c2
//dis[i]表示起点到i点的最短路径长度
//weight[i]表示i城市救援队数目，     e[a][b] 表示从a到b路径长度
//num[i]表示从出发点到i城市拥有的最短路径的条数，w[i]表示最短路径上能够找到的救援队的最大数目
int n, m, c1, c2;//默认0
int dis[501],weight[501],e[501][501],num[501],w[501];//默认0
bool visit[501];//默认false
const int inf = 99999999;//常数
int main()
{
    //初始化
    scanf("%d%d%d%d",&n, &m, &c1, &c2);
    for(int i=0; i<n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0]+501*501, inf);//赋值
    fill(dis, dis+501, inf);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;//记录路径长度
        e[b][a] = c;//无向图，所以记录双向路径长度
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i=0; i<n; i++){
        int u=-1,minn = inf;
        for(int j=0; j<n; j++){
            if(visit[j]==false && dis[j]<minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1)
            break;
        visit[u] = true;
        for(int v=0; v<n; v++){
            if(visit[v]==false && e[u][v]!=inf){//路径不包含v点 且u到v点有路径
                if(dis[u] + e[u][v] < dis[v]){//找到更短的路径
                    dis[v] = dis[u] + e[u][v];//最短路径长度更新
                    num[v] = num[u];//最短路径数量更新
                    w[v] = w[u] + weight[v];//最短路径点权更新(救援队数目)
                }else if(dis[u] + e[u][v] == dis[v]){//路径与最短路径长度相等
                    num[v] = num[v] + num[u];//最短路径数量更新
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}
