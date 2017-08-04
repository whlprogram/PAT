//原题链接  https://www.patest.cn/contests/pat-b-practise/1012
//题解  http://blog.csdn.net/whl_program/article/details/76652820

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a2=0,a5=0;//判断是否有符合范围的数
    int A1 = 0;
    int A2 = 0;
    int A3 = 0;
    double A4 = 0;
    int A5 = 0;
    bool flag = true;//符合A2求和时加减号
    int num = 0;//符合A4的数量
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp%5==0 && temp%2==0){
            A1 += temp;
        }
        else if(temp%5==1){
            if(flag){
                A2 += temp;
                flag = false;
            }else{
                A2 -= temp;
                flag = true;
            }
            a2 = 1;
        }
        else if(temp%5==2){
            A3++;
        }
        else if(temp%5==3){
            A4 += temp;
            num++;
        }
        else if(temp%5==4){
            if(temp > A5)
                A5 = temp;
            a5 = 1;
        }

    }
    if(A1 == 0)
        cout << "N ";
    else
        cout << A1 << " ";

    if(a2 == 0)
        cout << "N ";
    else
        cout << A2 << " ";

    if(A3 == 0)
        cout << "N ";
    else
        cout << A3 << " ";

    if(num == 0)
        cout << "N ";
    else
        printf("%.1f ", A4/num);

    if(a5 == 0)
        cout << "N";
    else
        cout << A5;
    return 0;
}
