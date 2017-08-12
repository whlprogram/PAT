#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int c1, c2;
    cin >> c1 >> c2;
    int temp = (c2-c1)%100;
    int c = temp>=50 ? (c2-c1)/100+1 : (c2-c1)/100;
    //int c = ((c2 - c1) + 50) / 100;//用这个方法四舍五入也行
    int hh = c/3600;
    int mm = (c%3600)/60;
    int ss = c%60;
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}
