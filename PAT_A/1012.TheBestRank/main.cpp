//ԭ������  https://www.patest.cn/contests/pat-a-practise/1012
//��� http://blog.csdn.net/whl_program/article/details/77591531
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int id,best;
    int score[4],rank[4];//����  ����
}stu[2001];
int exist[1000000];//���ڼ��d�Ƿ����
int flag = -1;
int cmd(node a, node b){return a.score[flag] > b.score[flag];}
int main()
{
    int n,m;
    cin >> n >> m;//n��ѧ���ɼ� m��Ҫ���������
    for(int i=0; i<n; i++){//�洢��ʱ��Ͱ���ACME��˳��洢���Լ򻯳����߼�
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3]+1.5)/3;//��������
    }
    for(flag=0; flag<=3; flag++){//�ֱ��¼��������
        sort(stu, stu+n, cmd);
        stu[0].rank[flag] = 1;
        for(int i=1; i<n; i++){
            stu[i].rank[flag] = i+1;
            if(stu[i].score[flag] == stu[i-1].score[flag])//��������Ӧ��1��1��3��4��5��������1��1��2��3��4
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i=0; i<n; i++){
        exist[stu[i].id] = i+1;//��¼ѧ��Ŀǰ������(���һ������)
        stu[i].best = 0;//�ҳ�ѧ��������������õ�
        int t = stu[i].rank[0];
        for(int j=1; j<=3; j++){
            if(stu[i].rank[j] < t){
                t = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[] = {'A', 'C', 'M', 'E'};
    for(int i=0; i<m; i++){
        int id;
        scanf("%d", &id);
        int temp = exist[id];
        if(temp != 0){
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].rank[best], c[best]);
        }else{
            printf("N/A\n");//id������
        }
    }
    return 0;
}
