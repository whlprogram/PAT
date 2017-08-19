//原题链接  https://www.patest.cn/contests/pat-a-practise/1002
//题解  http://blog.csdn.net/whl_program/article/details/77262791
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<double> arr(1001);
    int A;
    cin >> A;
    for(int i=0; i<A; i++){
        int n;
        double an;
        cin >> n >> an;
        arr[n] += an;
    }
    int B;
    cin >> B;
    for(int i=0; i<B; i++){
        int n;
        double an;
        cin >> n >> an;
        arr[n] += an;
    }
    vector<int> res;
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i] != 0){
            res.push_back(i);
        }
    }
    cout << res.size();
    for(int i=0; i<res.size(); i++){
        printf(" %d %.1f", res[i], arr[res[i]]);
    }
    return 0;
}
