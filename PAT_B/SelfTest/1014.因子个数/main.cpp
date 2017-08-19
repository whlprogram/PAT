//原题链接 https://www.nowcoder.com/pat/2/problem/264
//题解  http://blog.csdn.net/whl_program/article/details/77346333
/*
超时代码！！！！！！
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> arr;//100000以内素数数组
bool isSushu(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int help(vector<int> &Yinzi, vector<int> res, int n){
    if(Yinzi[n] != 0)
        return Yinzi[n];
    int temp = n;
    bool flag = true;
    while(temp != 1){
        for(int i=0; i<arr.size(); i++){
            if(temp%arr[i] == 0){
                temp /= arr[i];
                if(Yinzi[temp] != 0){
                    if(res[arr[i]] != 0){
                        Yinzi[n] = Yinzi[temp];
                    }else{
                        Yinzi[n] = Yinzi[temp] + 1;
                    }
                    flag = false;
                    break;
                }
                res[arr[i]]++;
                break;
            }
        }
        if(!flag)
            break;
    }
    int countt  = 0;
    for(int i=0; i<=n; i++){
        if(res[i] != 0)
            countt++;
    }
    return Yinzi[n] = countt;
}

int main()
{
    vector<int> Yinzi(100001);//备忘录 存储各个整数的因子个数
    vector<int> res(100001);//存储因子个数
    int n;
    while(~scanf("%d", &n)){
        for(int i=2; i<=n; i++){
            if(isSushu(i))
                arr.push_back(i);
        }
        printf("%d\n", help(Yinzi, res, n));
    }
    return 0;
}
*/

//递归 73ms
#include <iostream>
#include <stdio.h>

using namespace std;

int cnt;

bool isPrime(int n)
{
    if(n<2) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i=3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

void countFactors(int n, int start)
{
    if(isPrime(n)) {
        cnt++; return;
    } else {
        for(int i=start; i<n; i++) {
            if(0 == n%i) {
                cnt++;
                while(0 == n%i) {
                    n /= i;
                }
                countFactors(n, i+1);
                return;
            }
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d", &n)) {
        cnt = 0;
        countFactors(n, 2);
        printf("%d\n", cnt);
    }
    return 0;
}

//循环嵌套 112ms
/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,sum=0;
        for(i=2;i<=sqrt(n);i++)
        {
                if(n%i==0)
                {
                    sum++;
                    n /= i;
                }
                while(n%i==0)
                {
                    n/=i;
                }
        }
        if(n != 1 )             //n为质数的情况
            sum++;
        printf("%d\n",sum);
    }
    return 0;
}
*/
