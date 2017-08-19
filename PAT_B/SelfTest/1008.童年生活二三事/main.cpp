//原题链接 https://www.nowcoder.com/pat/2/problem/256
//题解 http://blog.csdn.net/whl_program/article/details/77345852
#include <iostream>
#include <cstdio>
using namespace std;
/*
int help(int n){//递归
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else
        return help(n-1)+help(n-2);
}*/
long long arr[100] = {0};
long long help(int n){//递归 备忘录
    if(arr[n] != 0)
        return arr[n];
    if(n == 1)
        arr[1] = 1;
    else if(n == 2)
        arr[2] = 2;
    else
        arr[n] = help(n-1)+help(n-2);
    return arr[n];
}
int main()
{
    int n;
    while(~scanf("%d", &n)){
        cout << help(n) << endl;
    }
    return 0;
}
