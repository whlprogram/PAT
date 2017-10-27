//ԭ������  https://www.patest.cn/contests/pat-a-practise/1017
//���   http://blog.csdn.net/whl_program/article/details/77726961
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int come;//����ʱ��
    int time;//����ҵ������Ҫʱ��
};
int cmp(node a, node b){
    return a.come < b.come;
}
int main()
{
    int n, k;//n���� k������
    scanf("%d %d", &n, &k);
    vector<node> custom;
    for(int i=0; i<n; i++){
        int hh,mm,ss,time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh*3600 + mm*60 + ss;
        if(cometime > 61200)//�˿�����ʱ������17:00 ֱ���������޷�����
            continue;
        node temp;
        temp.come = cometime;
        temp.time = time*60;
        custom.push_back(temp);
    }
    sort(custom.begin(), custom.end(), cmp);
    vector<int> windowTime(k, 28800);//28800�������ϰ˵�
    double res = 0.0;
    for(int i=0; i<custom.size(); i++){
        int minWindow=0;//��������Ĵ��� ��������Ĵ���ʱ��
        for(int j=1; j<k; j++){
            if(windowTime[minWindow] > windowTime[j]){
                minWindow = j;
            }
        }
        if(windowTime[minWindow] <= custom[i].come){//�˿�����ʱ����п��д���
            windowTime[minWindow] = custom[i].come + custom[i].time;
        }else{//�˿�����ʱ����Ҫ�ȴ�
            res += (windowTime[minWindow] - custom[i].come);//�˿͵ȴ�ʱ��
            windowTime[minWindow] +=  custom[i].time;//���´��ڿ���ʱ��
        }
    }
    if(custom.size() == 0){//��Ч����Ϊ0��ֱ�����������0������
        printf("0.0");
    }else{
        printf("%.1f", res/60.0/custom.size());
    }
    return 0;
}
