//原题链接  https://www.patest.cn/contests/pat-a-practise/1017
//题解   http://blog.csdn.net/whl_program/article/details/77726961
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int come;//到达时间
    int time;//办理业务所需要时间
};
int cmp(node a, node b){
    return a.come < b.come;
}
int main()
{
    int n, k;//n个人 k个窗口
    scanf("%d %d", &n, &k);
    vector<node> custom;
    for(int i=0; i<n; i++){
        int hh,mm,ss,time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh*3600 + mm*60 + ss;
        if(cometime > 61200)//顾客来的时间晚于17:00 直接跳过，无法办理
            continue;
        node temp;
        temp.come = cometime;
        temp.time = time*60;
        custom.push_back(temp);
    }
    sort(custom.begin(), custom.end(), cmp);
    vector<int> windowTime(k, 28800);//28800代表早上八点
    double res = 0.0;
    for(int i=0; i<custom.size(); i++){
        int minWindow=0;//最早结束的窗口 最早结束的窗口时间
        for(int j=1; j<k; j++){
            if(windowTime[minWindow] > windowTime[j]){
                minWindow = j;
            }
        }
        if(windowTime[minWindow] <= custom[i].come){//顾客来的时候就有空闲窗口
            windowTime[minWindow] = custom[i].come + custom[i].time;
        }else{//顾客来的时候需要等待
            res += (windowTime[minWindow] - custom[i].come);//顾客等待时间
            windowTime[minWindow] +=  custom[i].time;//更新窗口空闲时间
        }
    }
    if(custom.size() == 0){//有效人数为0，直接输出，除以0无意义
        printf("0.0");
    }else{
        printf("%.1f", res/60.0/custom.size());
    }
    return 0;
}
