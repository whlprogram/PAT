//原题链接  https://www.patest.cn/contests/pat-b-practise/1050
//题解    http://blog.csdn.net/whl_program/article/details/76691299

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b){
    return a > b;
}
int findn(int N){
    int i = sqrt((double)N);//i是小于N的平方根并最接近N的平方根整数
    while(i >= 1){
        if(N%i == 0)
            return i;
        i--;
    }
    return 1;
}
int main()
{
    int N;
    cin >> N;
    int n = findn(N);
    int m = N/n;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);//降序排列
    vector<vector<int>> res(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[i][j] = 0;
        }
    }
    int i=0,j=0,k=0;
    res[i][j] = arr[k];//为了以后赋值方便先将第一个元素赋值
    k++;
    while(k < N){
        while(j<n-1 && res[i][j+1]==0){//往右赋值 && 即将赋值的位置没被赋过值
            j++;//放在这个位置，省去下一个while循环的j--
            res[i][j] = arr[k];
            k++;
        }
        while(i<m-1 && res[i+1][j]==0){//往下赋值 && 即将赋值的位置没被赋过值
            i++;
            res[i][j] = arr[k];
            k++;
        }
        while(j>0 && res[i][j-1]==0){//往左赋值 && 即将赋值的位置没被赋过值
            j--;
            res[i][j] = arr[k];
            k++;
        }
        while(i>0 && res[i-1][j]==0){//往上赋值 && 即将赋值的位置没被赋过值
            i--;
            res[i][j] = arr[k];
            k++;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(j != 0)
                cout <<" ";
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
