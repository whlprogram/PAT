//原题链接  https://www.patest.cn/contests/pat-a-practise/1001
//题解  http://blog.csdn.net/whl_program/article/details/77261774
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int sum = a + b;
    string res="";
    bool flag = true;//正数
    if(sum < 0){
        flag = false;
        sum = -sum;
    }
    int t=0;
    do{
        if(t == 3){
            res = ',' + res;
            t = 0;
        }
        char c = sum%10+'0';
        res = c + res;
        t++;
        sum /= 10;
    }while(sum != 0);
    if(!flag)
        res = '-' + res;
    cout << res;
    return 0;
}
