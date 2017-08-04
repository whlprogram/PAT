//原题链接  https://www.patest.cn/contests/pat-b-practise/1040
//题解  http://blog.csdn.net/whl_program/article/details/76651686

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int p=0,a=0,t=0;
    int res=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'T')
            t++;
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'P')
            p++;
        if(s[i] == 'T')
            t--;
        if(s[i] == 'A')
            res = (res + (p*t)%1000000007)%1000000007;
    }
    cout << res << endl;
    return 0;
}
