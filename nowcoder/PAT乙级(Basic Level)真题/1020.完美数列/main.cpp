#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b){return a<b;}
int getMax(int a, int b){return a>b ? a : b;}
int main()
{
    int n;
    long long p;
    cin >> n >> p;
    if(n == 0)
        return 0;
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    int res = 1;
    for(int i=0; i<n-1; i++){//遍历，将arr[i]作为最小数
        for(int j=i+res; j<n; j++){//j置为要满足可以更新数列长度的值，减少循环次数
            if(arr[i]*p < arr[j])//如果不满足条件了，则将下一个元素arr[i+1]最为最小值
                break;
            res = getMax(res, j-i+1);//如果此次的长度大于上一次，更新数列长度
        }
    }
    cout << res << endl;
    return 0;
}
