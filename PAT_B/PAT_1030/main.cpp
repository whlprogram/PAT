//原题链接 https://www.patest.cn/contests/pat-b-practise/1030
//题解 http://blog.csdn.net/whl_program/article/details/76737855

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cmp(int a, int b){return a < b;}
int getMax(int a, int b){return a>b ? a : b;}
int main()
{
    int n;
    long long p;
    cin >> n >> p;
    if(n == 0){
        cout << n;
        return 0;
    }
    vector<long long int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    int res=1;
    for(int i=0; i<n-1; i++){
        for(int j=i+res; j<n; j++){
            if(arr[i]*p < arr[j])
                break;
            res = getMax(res, j-i+1);
        }
    }
    cout << res << endl;
    return 0;
}
