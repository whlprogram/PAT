//ԭ������  https://www.patest.cn/contests/pat-a-practise/1003
//���  http://blog.csdn.net/whl_program/article/details/77261182
//������ͼ����������·������������·��������Ȩ
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//������Ŀn ·������Ŀm ���c1  �յ�c2
//dis[i]��ʾ��㵽i������·������
//weight[i]��ʾi���о�Ԯ����Ŀ��     e[a][b] ��ʾ��a��b·������
//num[i]��ʾ�ӳ����㵽i����ӵ�е����·����������w[i]��ʾ���·�����ܹ��ҵ��ľ�Ԯ�ӵ������Ŀ
int n, m, c1, c2;//Ĭ��0
int dis[501],weight[501],e[501][501],num[501],w[501];//Ĭ��0
bool visit[501];//Ĭ��false
const int inf = 99999999;//����
int main()
{
    //��ʼ��
    scanf("%d%d%d%d",&n, &m, &c1, &c2);
    for(int i=0; i<n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0]+501*501, inf);//��ֵ
    fill(dis, dis+501, inf);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;//��¼·������
        e[b][a] = c;//����ͼ�����Լ�¼˫��·������
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
            if(visit[v]==false && e[u][v]!=inf){//·��������v�� ��u��v����·��
                if(dis[u] + e[u][v] < dis[v]){//�ҵ����̵�·��
                    dis[v] = dis[u] + e[u][v];//���·�����ȸ���
                    num[v] = num[u];//���·����������
                    w[v] = w[u] + weight[v];//���·����Ȩ����(��Ԯ����Ŀ)
                }else if(dis[u] + e[u][v] == dis[v]){//·�������·���������
                    num[v] = num[v] + num[u];//���·����������
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}
