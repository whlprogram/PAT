//ԭ������  https://www.patest.cn/contests/pat-a-practise/1014
//���    http://blog.csdn.net/whl_program/article/details/77687337
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node{
    int poptime, endtime;//���׵��˳���(����)ʱ��  ��β���˽���ʱ��
    queue<int> q;
};
int main()
{
    //n������(n<=20) mΪ�������������(m<=10) k���˿�(k<=1000) qΪҪ��ѯ�Ĺ˿�����(q<=1000)
    int n, m, k, p, index=1;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    vector<int> time(k+1), result(k+1);//�˿Ͱ���ҵ������ʱ��  �˿Ͱ���ҵ�����ʱ��
    for(int i=1; i<=k; i++)
        scanf("%d", &time[i]);
    vector<node> window(n+1);//n������n����
    vector<bool> sorry(k+1, false);
    //����ʼ���ڻ����ڹ˿� ǰ��m*n
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(index <= k){
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)//��β���˽���ʱ�䳬���������
                    sorry[index] = true;
                window[j].endtime += time[index];
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    //��ʼ�޷��Ž�������  m*n�Ժ����
    while(index <= k){
        int minPoptime=window[1].poptime, minWindow=1;
        for(int i=2; i<=n; i++){//Ѱ���������˳����Ĵ���
            if(window[i].poptime < minPoptime){
                minPoptime = window[i].poptime;
                minWindow = i;
            }
        }
        window[minWindow].q.pop();//����һ��
        window[minWindow].q.push(time[index]);//���
        window[minWindow].poptime += window[minWindow].q.front();//���¶��׽���ʱ��
        if(window[minWindow].endtime >= 540)
            sorry[index] = true;
        window[minWindow].endtime += time[index];//���¶�β����ʱ��
        result[index] = window[minWindow].endtime;//��¼�ù˿ͽ���ʱ��
        index++;
    }
    for(int i=1; i<=p; i++){
        int check;
        scanf("%d", &check);
        int temp = result[check];
        if(sorry[check] == true)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", (temp+480)/60, (temp+480)%60);//480 ���ϰ˵�
    }
    return 0;
}
