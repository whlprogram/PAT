//原题链接 https://www.patest.cn/contests/pat-b-practise/1033
//题解    http://blog.csdn.net/whl_program/article/details/76696764

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin, s1);//为了防止第一行是空的，不能用cin >> s1,用getline(cin, s1)
    getline(cin, s2);
    bool falg = true;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] == '+')
            falg = false;
    }
    string res="";
    for(int i=0; i<s2.size(); i++){
        if(s2[i]>='A'&&s2[i]<='Z'&&!falg)
            continue;
        bool temp = true;
        for(int j=0; j<s1.size(); j++){
            //判断是否是坏键
            if(s2[i]==s1[j] || ((s2[i]-'a')==(s1[j]-'A')&&s2[i]>='a'&&s2[i]<='z'&&s1[j]>='A'&&s1[j]<='Z')){
                temp = false;
                break;
            }
        }
        if(temp)
            res += s2[i];
    }
    if(res != "")
        cout << res << endl;
    else
        cout << endl;//如果没有一个字符能被打出，则输出空行
    return 0;
}
