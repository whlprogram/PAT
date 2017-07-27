#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    float Max = 0;
    for(int i=0; i<n; i++){
        float a, b, ans;
        scanf("%f%f", &a, &b);
        ans = sqrt(a*a + b*b);//开方
        Max = ans>Max ? ans : Max;
    }
    printf("%.2f", Max);//四舍五入保留小数点后2位
    return 0;
}
