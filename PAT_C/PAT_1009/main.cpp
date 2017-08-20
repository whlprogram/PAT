//原题链接 https://www.patest.cn/contests/pat-b-practise/1009

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int len = str.size();
    string res = "";
    string temp = "";
    for(int i=0; i<len; i++){
        if(str[i] != ' ')
            temp += str[i];
        if(str[i] == ' '){
            res = ' ' + temp + res;
            temp = "";
        }
    }
    res = temp + res;
    cout << res << endl;
    return 0;
}
/*
方法2
#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string> v;
    string s;
    while(cin >> s) {
        v.push(s);
    }
    cout << v.top();
    v.pop();
    while(!v.empty()) {
        cout << " " << v.top();
        v.pop();
    }
    return 0;
}
*/
