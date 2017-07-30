//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1026
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int temp = (c2-c1)%100;
    int s = temp>=50 ? (c2-c1)/100+1 : (c2-c1)/100;
    int hh,mm,ss;
    ss = s%60;
    mm = (s%3600)/60;
    hh = s/3600;
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}
