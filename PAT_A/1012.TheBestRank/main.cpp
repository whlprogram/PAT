//原题链接  https://www.patest.cn/contests/pat-a-practise/1012
//题解 http://blog.csdn.net/whl_program/article/details/77591531
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int id,best;
    int score[4],rank[4];//分数  排名
}stu[2001];
int exist[1000000];//用于检查d是否存在
int flag = -1;
int cmd(node a, node b){return a.score[flag] > b.score[flag];}
int main()
{
    int n,m;
    cin >> n >> m;//n行学生成绩 m个要输出的人数
    for(int i=0; i<n; i++){//存储的时候就按照ACME的顺序存储可以简化程序逻辑
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3]+1.5)/3;//四舍五入
    }
    for(flag=0; flag<=3; flag++){//分别记录各科排名
        sort(stu, stu+n, cmd);
        stu[0].rank[flag] = 1;
        for(int i=1; i<n; i++){
            stu[i].rank[flag] = i+1;
            if(stu[i].score[flag] == stu[i-1].score[flag])//排名并列应该1、1、3、4、5，而不是1、1、2、3、4
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i=0; i<n; i++){
        exist[stu[i].id] = i+1;//记录学生目前的排名(最后一次排序)
        stu[i].best = 0;//找出学生四种排名中最好的
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
            printf("N/A\n");//id不存在
        }
    }
    return 0;
}
