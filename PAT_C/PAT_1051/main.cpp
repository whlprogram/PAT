//ԭ������ https://www.patest.cn/contests/pat-b-practise/1051
//��� http://blog.csdn.net/whl_program/article/details/76735751

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double A, B;
    //r1*(cos(p1) + sin(p1)*i)  * r2*(cos(p2) + sin(p2)*i)  ��ֿɵ���ʽ(i*i = -1)
    A = r1*r2*cos(p1)*cos(p2) - r1*r2*sin(p1)*sin(p2);
    B = r1*r2*cos(p1)*sin(p2) + r1*r2*sin(p1)*cos(p2);
    //��A����BС��0���Ǵ���-0.01(����-0.00001)ʱ��
    //�������"%.2f"���жϣ��������-0.00�������Ľ��,��ʵ��Ӧ�������0.00��
    //��Bͬ��Ӧ�������+0.00i����
    if(A+0.005>=0 && A<0)//�������룬����+0.005
        printf("0.00");
    else
        printf("%.2f", A);
    if(B>=0)
        printf("+%.2fi", B);
    else if(B+0.01>=0 && B<0)//0.01��ʵҲ��ͨ���� 0.05���Ͻ����
        printf("+0.00i");
    else
        printf("%.2fi", B);
    return 0;
}
