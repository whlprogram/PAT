#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);//输入N
    //定义二维数组结构
    vector< vector<int> > arr(N);
    for(int i=0; i<arr.size(); i++)
        arr[i].resize(4);
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++)
            scanf("%d", &arr[i][j]);
    int a=0,b=0;//a表示甲喝酒杯数  a表示乙喝酒杯数
    for(int i=0; i<arr.size(); i++){
        int sum = arr[i][0]+arr[i][2];
        if(sum == arr[i][1] && sum != arr[i][3])
            b++;
        if(sum != arr[i][1] && sum == arr[i][3])
            a++;
    }
    printf("%d %d", a, b);
    return 0;
}
