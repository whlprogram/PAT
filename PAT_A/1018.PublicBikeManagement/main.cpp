#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 99999999;
int main()
{
    int cmax, n, sp, m;//��վ������� n����վ �����⳵վsp  m����·
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    int weight[n+1] = {0};//��¼������վ������Ŀ
    int v[n+1][n+1];//��¼��·����
    int dis[n+1];//dis[i]��ʾ��PBMC��i������·������
    int num[n+1] = {0};//num[i]��ʾ��PBMC��i��ӵ�е����·��������
    bool visit[n+1];
    fill(v[0], v[0]+(n+1)*(n+1), inf);//��ֵ
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
            if(visit[k]==false && v[u][k]!=inf){//·��������k�� ��u��k����·��
                if(dis[u]+v[u][k] < dis[k]){//�ҵ����̵�·��
                    dis[k] = dis[u]+v[u][k];//���·�����ȸ���
                    num[k] = num[u];//���·����������
                    //���г���������
                }else if(dis[u]+v[u][k] == dis[k]){//·�������·���������
                    num[k] = num[k] + num[u];//���·����������
                }
            }
        }
    }
    return 0;
}
