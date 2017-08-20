//原题链接 https://www.patest.cn/contests/pat-b-practise/1049
//题解 http://blog.csdn.net/whl_program/article/details/76602058

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double res = 0;
    for(int i=0; i<N; i++){
        double temp;
        cin >> temp;
        res += temp*(N-i)*(i+1);
    }
    printf("%.2f", res);
    return 0;
}

