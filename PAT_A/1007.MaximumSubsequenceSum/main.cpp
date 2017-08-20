//原题链接  https://www.patest.cn/contests/pat-a-practise/1007
//题解    http://blog.csdn.net/whl_program/article/details/77431896
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum=-1;//最大连续子序列和
    int tempsum=0;//临时的连续子序列和
    int left=0;//最大子序列左下标
    int right=0;//最大子序列右下标
    int index=0;//临时的序列左下标
    bool flag = true;//检验是否全是负数
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] >= 0)
            flag = false;
        tempsum += arr[i];
        if(tempsum > sum){
            sum = tempsum;
            left = index;
            right = i;
        }else if(tempsum < 0){//如果临时序列和已经小于sum的情况下还是负数，应该舍弃之前的序列
            index = i+1;
            tempsum = 0;
        }
    }
    if(flag){
        printf("0 %d %d", arr[0], arr[n-1]);
    }else{
        printf("%d %d %d", sum, arr[left], arr[right]);
    }
    return 0;
}
