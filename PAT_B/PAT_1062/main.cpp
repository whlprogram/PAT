//ԭ������ https://www.patest.cn/contests/pat-b-practise/1062
//��� http://blog.csdn.net/whl_program/article/details/76737767

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int gcd(int a, int b){
    int Max = a>b ? a : b;
    int Min = a>b ? b : a;
    int rem = Max%Min;//����
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
    if(n1*m2 > n2*m1) { //�����������������߱��ұߴ��򽻻�λ��
        swap(n1, n2);
        swap(m1, m2);
    }
    bool flag = true;
    int num = n1*k/m1 + 1;  //��Ϊ��������ԭ���ķ������������߳�������Ҫ+1
    while(n1*k<m1*num && m2*num<n2*k){//��Ӧ���ӱȽ�  ��num��ʼ�������ǲ������
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
