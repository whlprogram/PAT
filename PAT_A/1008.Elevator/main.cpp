//原题链接  https://www.patest.cn/contests/pat-a-practise/1008
//题解   http://blog.csdn.net/whl_program/article/details/77433910
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum=0;
    int after = 0;//表示上次停留的层数
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp > after)
            sum += (temp-after)*6;
        else
            sum += (after-temp)*4;
        sum += 5;
        after = temp;
    }
    cout << sum << endl;
    return 0;
}
