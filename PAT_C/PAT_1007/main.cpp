//原题链接 https://www.patest.cn/contests/pat-b-practise/1007
//题解 http://blog.csdn.net/whl_program/article/details/76601993

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int res = 0;
    int a=2,b=3;
    for(int i=5; i<=N; i++){
        bool temp = true;
        for(int j=2; j*j<=i; j++){//j*j很重要，减少运行时间
            if(i%j == 0){
                temp = false;
                break;
            }
        }
        if(temp){
            a = b;
            b = i;
            if((b-a)==2)
                res++;
        }
    }
    cout << res << endl;
    return 0;
}
