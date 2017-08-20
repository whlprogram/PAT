//ԭ������  https://www.patest.cn/contests/pat-b-practise/1020
//���  http://blog.csdn.net/whl_program/article/details/76652862

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
void sort(vector<double> &stock, vector<double> &price, vector<double> &unitPrice) {
    for(int i=0; i<unitPrice.size(); i++){
        for(int j=i+1; j<unitPrice.size(); j++){
            if(unitPrice[i] < unitPrice[j]){
                double t1 = unitPrice[i];
                unitPrice[i] = unitPrice[j];
                unitPrice[j] = t1;

                double t2 = stock[i];
                stock[i] = stock[j];
                stock[j] = t2;

                double t3 = price[i];
                price[i] = price[j];
                price[j] = t3;
            }
        }
    }
}
int main()
{
    int N, D;
    cin >> N >> D;
    vector<double> stock(N);//���
    vector<double> price(N);//�ۼ�
    vector<double> unitPrice(N);//�Լ۱� ��Ԫ/ÿ���
    for(int i=0; i<N; i++)
        cin >> stock[i];
    for(int i=0; i<N; i++){
        cin >> price[i];
        unitPrice[i] = price[i]/stock[i];
    }
    sort(stock, price, unitPrice);//�����Լ۱ȴӴ�С����
    double sum = 0;//��������
    double res = 0;//��������
    for(int i=0; i<N; i++){
        sum += stock[i];
        if(sum >= D){
            double temp = D - (sum-stock[i]);
            res += temp*unitPrice[i];
            break;
        }
        res += price[i];
    }
    printf("%.2f", res);
    return 0;
}
