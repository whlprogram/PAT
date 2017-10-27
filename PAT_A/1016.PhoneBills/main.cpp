//原题链接  https://www.patest.cn/contests/pat-a-practise/1016
//题解    http://blog.csdn.net/whl_program/article/details/77720890
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;
int rate[25];//通话 每分钟/美分
struct node{
    string name;//客户名字
    int month,day,hour,minute;//通话时间
    int time;//从01:00:00到当前的通话时长 方便排序 同时避免计算跨天通话费用的麻烦
    string status;//通话状态 接通on-line 挂断off-line
};
int cmp(node a, node b){
    return a.name!=b.name ? a.name<b.name : a.time<b.time;
}
double bill(node a, int *rate){
    double res = rate[24]*60*(a.day-1);
    for(int i=0; i<a.hour; i++)
        res += rate[i]*60;
    res += rate[a.hour]*a.minute;
    return res/100;//题目返回美元 计费则是每分钟/美分 所以除以100
}
int main()
{
    for(int i=0; i<24; i++){
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    int n;
    scanf("%d", &n);
    vector<node> data(n);
    for(int i=0; i<n; i++){
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        cin >> data[i].status;
        data[i].time = (data[i].day-1)*24*60 + data[i].hour*60 + data[i].minute;//从01:00:00到当前的通话时长
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node>> effective;//有效的通话记录 一人对应一个数组
    for(int i=1; i<n; i++){//筛选有效通话记录
        if(data[i].name==data[i-1].name && data[i-1].status=="on-line" && data[i].status=="off-line"){
            effective[data[i].name].push_back(data[i-1]);
            effective[data[i].name].push_back(data[i]);
        }
    }
    for(auto eff : effective){
        vector<node> temp = eff.second;//用户有效通话记录数组
        cout << eff.first;//输出用户名字
        printf(" %02d\n", temp[0].month);
        double total = 0.0;//总的通话费用
        for(int i=1; i<temp.size(); i+=2){
            double t = bill(temp[i], rate) - bill(temp[i-1], rate);//每段通话的费用
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i-1].day, temp[i-1].hour, temp[i-1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time-temp[i-1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
