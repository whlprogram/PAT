#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a1=0;//能被5整除的数字中所有偶数的和
    int a2=0;//将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
    int a3=0;//被5除后余2的数字的个数；
    double a4=0;//被5除后余3的数字的平均数，精确到小数点后1位；
    int a5=0;//被5除后余4的数字中最大数字。
    int A2=0;//统计符合a2要求的数字的数量
    int A4=0;//统计符合a4要求的数字的数量
    bool b2=true;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp%2==0 && temp%5==0)
            a1 += temp;
        if(temp%5 == 1){
            if(b2){
                a2 += temp;
                A2++;
                b2 = false;
            }else{
                a2 -= temp;
                A2++;
                b2 = true;
            }
        }
        if(temp%5 == 2)
            a3++;
        if(temp%5 == 3){
            a4 += temp;
            A4++;
        }
        if(temp%5 == 4){
            if(temp > a5)
                a5 = temp;
        }

    }
    if(a1 == 0){
        printf("N ");
    }else{
        printf("%d ", a1);
    }
    if(A2 == 0){
        printf("N ");
    }else{
        printf("%d ", a2);
    }
    if(a3 == 0){
        printf("N ");
    }else{
        printf("%d ", a3);
    }
    if(A4 == 0){
        printf("N ");
    }else{
        printf("%.1f ", a4/A4);
    }
    if(a5 == 0){
        printf("N");
    }else{
        printf("%d", a5);
    }
    return 0;
}
