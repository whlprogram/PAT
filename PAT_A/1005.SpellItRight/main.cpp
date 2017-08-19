//原题链接  https://www.patest.cn/contests/pat-a-practise/1005
//题解    http://blog.csdn.net/whl_program/article/details/77387732
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string v[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s;
    getline(cin, s);
    int sum = 0;
    for(int i=0; i<s.size(); i++){
        sum += s[i]-'0';
    }
    string res = "";
    while(sum >= 10){
        res = " " + v[sum%10] + res;
        sum /= 10;
    }
    if(sum < 10)
        res = v[sum] + res;
    cout << res << endl;
    return 0;
}
