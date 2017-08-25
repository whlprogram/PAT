//原题链接  https://www.patest.cn/contests/pat-a-practise/1011
//题解 http://blog.csdn.net/whl_program/article/details/77579267
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    char c[] = {'W', 'T', 'L'};
    vector<double> first(3);
    vector<double> secend(3);
    vector<double> third(3);
    vector<int> res;//存储最大值的下标
    int Max = 0;
    for(int i=0; i<3; i++){
        cin >> first[i];
        if(first[Max] <= first[i])
            Max = i;
    }
    res.push_back(Max);
    Max = 0;
    for(int i=0; i<3; i++){
        cin >> secend[i];
        if(secend[Max] <= secend[i])
            Max = i;
    }
    res.push_back(Max);
    Max = 0;
    for(int i=0; i<3; i++){
        cin >> third[i];
        if(third[Max] <= third[i])
            Max = i;
    }
    res.push_back(Max);
    cout << c[res[0]] << " " << c[res[1]] << " " << c[res[2]] << " ";
    printf("%.2f", (first[res[0]]*secend[res[1]]*third[res[2]]*0.65-1)*2);
    return 0;
}
