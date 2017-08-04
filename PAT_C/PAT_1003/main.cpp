//原题链接  https://www.patest.cn/contests/pat-b-practise/1003
//题解  http://blog.csdn.net/whl_program/article/details/76652890

#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool help(string s){
    int p=0,t=0;
    int len = s.size();
    for(int i=0; i<len; i++){
        if(s[i]!='P' && s[i]!='A' && s[i]!='T')
            return false;
        if(s[i] == 'P')
            p++;
        if(s[i] == 'T')
            t++;
    }
    if(p!=1 || t!=1)
        return false;
    int k,m;//记录P T位置
    for(int i=0; i<len; i++){
        if(s[i]=='P')   k = i;
        if(s[i]=='T')   m = i;
    }
    if(k == m-1)//P T中间没有A
        return false;
    if((k*(m-k-1)) != (len-1-m))//P前'A'的数量 * P和T之间'A'的数量 应该等于 T后'A'的数量
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        if( help(s[i]) )
            s[i] = "YES";
        else
            s[i] = "NO";
    }
    for(int i=0; i<n; i++)
        cout << s[i] << endl;
    return 0;
}
