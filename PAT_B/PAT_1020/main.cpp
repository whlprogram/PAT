//原题链接  https://www.patest.cn/contests/pat-b-practise/1020
//题解  http://blog.csdn.net/whl_program/article/details/76652862

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
    vector<double> stock(N);//库存
    vector<double> price(N);//售价
    vector<double> unitPrice(N);//性价比 亿元/每万吨
    for(int i=0; i<N; i++)
        cin >> stock[i];
    for(int i=0; i<N; i++){
        cin >> price[i];
        unitPrice[i] = price[i]/stock[i];
    }
    sort(stock, price, unitPrice);//按照性价比从大到小排序
    double sum = 0;//售卖数量
    double res = 0;//最终利润
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
