//原题链接 https://www.patest.cn/contests/pat-b-practise/1034
//题解    http://blog.csdn.net/whl_program/article/details/76696924

#include <iostream>
#include <cstdio>
using namespace std;
int gcd(long long a, long long b){//求最大公约数 辗转相除法
    long long r,Min,Max;
    Min = a>b ? b : a;
    Max = a>b ? a : b;
    r = Max%Min;
    while(r){
        Max = Min;
        Min = r;
        r = Max%Min;
    }
    return Min;
};
void helpPrint(long long a, long long b);
void Add(long long a1, long long b1, long long a2, long long b2);//加
void Minus(long long a1, long long b1, long long a2, long long b2);//减
void Multiply(long long a1, long long b1, long long a2, long long b2);//乘
void Except(long long a1, long long b1, long long a2, long long b2);//除
int main()
{
    long long a1,b1,a2,b2;
    while(~scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2)){
        Add(a1, b1, a2, b2);
        Minus(a1, b1, a2, b2);
        Multiply(a1, b1, a2, b2);
        Except(a1, b1, a2, b2);
    }
    return 0;
}
void helpPrint(long long a, long long b){
    long long flag=0, c, d, e;
    if(a < 0){
        a = -a;
        flag = 1;
    }
    if(a==0)
        printf("0");
    else{
        e = gcd(a,b);
        a /= e;
        b /= e;
        c = a/b;//整数部分
        d = a%b;//新的分子
        if(flag == 0){//正数
            if(d==0){
                printf("%lld", c);
            }else{
                if(c==0){
                    printf("%lld/%lld", a, b);
                }else{
                    printf("%lld %lld/%lld", c, d, b);
                }
            }
        }else{//负数
            if(d==0){
                printf("(-%lld)", c);
            }else{
                if(c==0){
                    printf("(-%lld/%lld)", a, b);
                }else{
                    printf("(-%lld %lld/%lld)", c, d, b);
                }
            }
        }
    }
}
void Add(long long a1, long long b1, long long a2, long long b2){//加
    helpPrint(a1, b1);
    printf(" + ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*b2+a2*b1, b1*b2);
    printf("\n");
}
void Minus(long long a1, long long b1, long long a2, long long b2){//减
    helpPrint(a1, b1);
    printf(" - ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*b2-a2*b1, b1*b2);
    printf("\n");
}
void Multiply(long long a1, long long b1, long long a2, long long b2){//乘
    helpPrint(a1, b1);
    printf(" * ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*a2, b1*b2);
    printf("\n");
}
void Except(long long a1, long long b1, long long a2, long long b2){//除
    helpPrint(a1, b1);
    printf(" / ");
    helpPrint(a2, b2);
    printf(" = ");
    if(a2==0){
        printf("Inf");
    }else{
        if(a2<0){
            a2 = -a2;
            a1 = -a1;
        }
        helpPrint(a1*b2, b1*a2);
    }
    printf("\n");
}
