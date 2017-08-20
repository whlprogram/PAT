//原题链接  https://www.patest.cn/contests/pat-a-practise/1009
//题解 http://blog.csdn.net/whl_program/article/details/77439464
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<double> v(2001);//存储最终系数
    int m;
    cin >> m;
    vector<int> NK;//指数
    vector<double> ank;//系数
    for(int i=0; i<m; i++){
        int a;
        double b;
        cin >> a >> b;
        NK.push_back(a);
        ank.push_back(b);
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;//指数
        double b;//系数
        cin >> a >> b;
        for(int j=0; j<ank.size(); j++){
            v[a+NK[j]] += b*ank[j];
        }
    }
    vector<int> res;//保存要输出的指数
    for(int i=v.size()-1; i>=0; i--){
        if(v[i] != 0)
            res.push_back(i);
    }
    cout << res.size();
    for(int i=0; i<res.size(); i++)
        printf(" %d %.1f", res[i], v[res[i]]);
    return 0;
}
