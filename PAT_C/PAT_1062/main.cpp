//原题链接 https://www.patest.cn/contests/pat-b-practise/1062
//题解 http://blog.csdn.net/whl_program/article/details/76737767

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int gcd(int a, int b){
    int Max = a>b ? a : b;
    int Min = a>b ? b : a;
    int rem = Max%Min;//余数
    while(rem!=0){
        Max = Min;
        Min = rem;
        rem = Max%Min;
    }
    return Min;
}
int main()
{
    int n1, m1, n2, m2,k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if(n1*m2 > n2*m1) { //若输入的两个分数左边比右边大，则交换位置
        swap(n1, n2);
        swap(m1, m2);
    }
    bool flag = true;
    int num = n1*k/m1 + 1;  //因为不可能是原来的分数，除尽或者除不尽都要+1
    while(n1*k<m1*num && m2*num<n2*k){//对应分子比较  从num开始遍历看是不是最简
        if(gcd(num, k) == 1) {
            if(!flag)
                printf(" ");
            printf("%d/%d", num, k);
            flag = false;
        }
        num++;
    }
    return 0;
}
