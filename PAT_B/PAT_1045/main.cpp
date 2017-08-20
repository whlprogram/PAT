//原题链接 https://www.patest.cn/contests/pat-b-practise/1045
//题解 http://blog.csdn.net/whl_program/article/details/76737900

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> res;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int Max = 0;
    for(int i=0; i<n; i++){
        if(a[i] == b[i] && b[i] > Max){
            res.push_back(a[i]);
        }
        if(b[i] > Max)//记录左边最大值
            Max = b[i];
    }
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++){
        if(i!=0)
            cout << " ";
        cout << res[i];
    }
    cout  << endl;
    return 0;
}
