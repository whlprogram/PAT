//原题链接 https://www.patest.cn/contests/pat-b-practise/1051
//题解 http://blog.csdn.net/whl_program/article/details/76735751

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double A, B;
    //r1*(cos(p1) + sin(p1)*i)  * r2*(cos(p2) + sin(p2)*i)  拆分可得下式(i*i = -1)
    A = r1*r2*cos(p1)*cos(p2) - r1*r2*sin(p1)*sin(p2);
    B = r1*r2*cos(p1)*sin(p2) + r1*r2*sin(p1)*cos(p2);
    //当A或者B小于0但是大于-0.01(比如-0.00001)时候，
    //如果按照"%.2f"的判断，会输出“-0.00”这样的结果,事实上应该输出“0.00”
    //【B同理，应该输出“+0.00i”】
    if(A+0.005>=0 && A<0)//四舍五入，所以+0.005
        printf("0.00");
    else
        printf("%.2f", A);
    if(B>=0)
        printf("+%.2fi", B);
    else if(B+0.01>=0 && B<0)//0.01其实也能通过， 0.05更严谨点儿
        printf("+0.00i");
    else
        printf("%.2fi", B);
    return 0;
}
