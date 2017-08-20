//原题链接 https://www.patest.cn/contests/pat-b-practise/1002
//题解 http://blog.csdn.net/whl_program/article/details/76595712

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    string arr[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string res = "";
    for(int i=0; i<s.size(); i++){
        sum += (s[i]-'0');
    }
    while(sum >= 10){
        int temp = sum%10;
        res = " " + arr[temp] + res;
        sum /= 10;
    }
    res = arr[sum] + res;
    cout << res << endl;
    return 0;
}
