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
        ans = sqrt(a*a + b*b);//����
        Max = ans>Max ? ans : Max;
    }
    printf("%.2f", Max);//�������뱣��С�����2λ
    return 0;
}
