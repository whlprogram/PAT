//原题链接 https://www.patest.cn/contests/pat-b-practise/1060
//题解 http://blog.csdn.net/whl_program/article/details/76735335

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int cmp(int a, int b){ return a > b; }
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    int res = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > i+1){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
