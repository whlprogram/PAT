//原题链接  https://www.patest.cn/contests/pat-a-practise/1014
//题解    http://blog.csdn.net/whl_program/article/details/77687337
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node{
    int poptime, endtime;//队首的人出队(结束)时间  队尾的人结束时间
    queue<int> q;
};
int main()
{
    //n个窗口(n<=20) m为黄线内最大容量(m<=10) k个顾客(k<=1000) q为要查询的顾客人数(q<=1000)
    int n, m, k, p, index=1;
    scanf("%d%d%d%d", &n, &m, &k, &p);
    vector<int> time(k+1), result(k+1);//顾客办理业务所需时间  顾客办理业务结束时间
    for(int i=1; i<=k; i++)
        scanf("%d", &time[i]);
    vector<node> window(n+1);//n个窗口n个队
    vector<bool> sorry(k+1, false);
    //处理开始就在黄线内顾客 前面m*n
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(index <= k){
                window[j].q.push(time[index]);
                if(window[j].endtime >= 540)//队尾的人结束时间超过下午五点
                    sorry[index] = true;
                window[j].endtime += time[index];
                result[index] = window[j].endtime;
                index++;
            }
        }
    }
    //开始无法排进黄线内  m*n以后的人
    while(index <= k){
        int minPoptime=window[1].poptime, minWindow=1;
        for(int i=2; i<=n; i++){//寻找最先有人出来的窗口
            if(window[i].poptime < minPoptime){
                minPoptime = window[i].poptime;
                minWindow = i;
            }
        }
        window[minWindow].q.pop();//出队一个
        window[minWindow].q.push(time[index]);//入队
        window[minWindow].poptime += window[minWindow].q.front();//更新队首结束时间
        if(window[minWindow].endtime >= 540)
            sorry[index] = true;
        window[minWindow].endtime += time[index];//更新队尾结束时间
        result[index] = window[minWindow].endtime;//记录该顾客结束时间
        index++;
    }
    for(int i=1; i<=p; i++){
        int check;
        scanf("%d", &check);
        int temp = result[check];
        if(sorry[check] == true)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", (temp+480)/60, (temp+480)%60);//480 早上八点
    }
    return 0;
}
