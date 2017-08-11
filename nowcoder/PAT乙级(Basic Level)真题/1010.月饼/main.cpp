#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
void sort(vector<int> &a, vector<double> &b, vector<double> &c){
    for(int i=0; i<c.size()-1; i++){
        for(int j=i+1; j<c.size(); j++){
            if(c[i] < c[j]){
                double temp = c[i];
                c[i] = c[j];
                c[j] = temp;

                double temp1 = b[i];
                b[i] = b[j];
                b[j] = temp1;

                int temp2 = a[i];
                a[i] = a[j];
                a[j] = temp2;
            }
        }
    }
}
int main()
{
    int N,D;
    cin >> N >> D;
    vector<int> a(N);//库存量
    vector<double> b(N);//总售价
    vector<double> c(N);//性价比
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int i=0; i<N; i++){
        cin >> b[i];
        c[i] = b[i]/a[i];
    }
    sort(a, b, c);
    double sum = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] <= D){
            sum += b[i];
            D -= a[i];
            continue;
        }
        if(a[i] > D){
            sum += D*c[i];
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}
