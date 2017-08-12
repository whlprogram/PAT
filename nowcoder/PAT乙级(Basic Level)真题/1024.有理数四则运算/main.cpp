#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a, long long b){//�����Լ��
    long long r,Min,Max;
    Max = a>b ? a : b;
    Min = a>b ? b : a;
    r = Max%Min;
    while(r != 0){
        Max = Min;
        Min = r;
        r = Max % Min;
    }
    return Min;
}
void helpPrint(long long a, long long b){
    long long flag=0,c,d,e;
    if(a < 0){
        a = -a;
        flag = 1;
    }
    if(a == 0){
        printf("0");
    }else{
        e = gcd(a, b);//���Լ��
        a /= e;
        b /= e;
        c = a/b;//�µ���������
        d = a%b;//�µķ���
        if(flag == 0){//����
            if(d == 0){
                printf("%lld", c);
            }else{
                if(c == 0){
                    printf("%lld/%lld", a, b);
                }else{
                    printf("%lld %lld/%lld", c, d, b);
                }
            }
        }else{//����
            if(d == 0){
                printf("(-%lld)", c);
            }else{
                if(c == 0){
                    printf("(-%lld/%lld)", a, b);
                }else{
                    printf("(-%lld %lld/%lld)", c, d, b);
                }
            }
        }
    }
}
void Add(long long a1, long long b1, long long a2, long long b2){//��
    helpPrint(a1, b1);
    printf(" + ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*b2+a2*b1, b1*b2);
    printf("\n");
}
void Minus(long long a1, long long b1, long long a2, long long b2){//��
    helpPrint(a1, b1);
    printf(" - ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*b2-a2*b1, b1*b2);
    printf("\n");
}
void Multiply(long long a1, long long b1, long long a2, long long b2){//��
    helpPrint(a1, b1);
    printf(" * ");
    helpPrint(a2, b2);
    printf(" = ");
    helpPrint(a1*a2, b1*b2);
    printf("\n");
}
void Except(long long a1, long long b1, long long a2, long long b2){//��
    helpPrint(a1, b1);
    printf(" / ");
    helpPrint(a2, b2);
    printf(" = ");
    if(a2 == 0){
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
int main()
{
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    Add(a1, b1, a2, b2);
    Minus(a1, b1, a2, b2);
    Multiply(a1, b1, a2, b2);
    Except(a1, b1, a2, b2);
    return 0;
}
