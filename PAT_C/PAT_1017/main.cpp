//原题链接 https://www.patest.cn/contests/pat-b-practise/1017
//题解 http://blog.csdn.net/whl_program/article/details/76600653

#include <iostream>

using namespace std;

int main()
{
    string a;
    int b;
    cin >> a >> b;
    int t = (a[0]-'0')/b;
    if((t!=0&&a.size()>1) || a.size()==1)
        cout << t;
    int temp = (a[0]-'0')%b;
    for(int i=1; i<a.size(); i++){
        t = (temp*10+(a[i]-'0'))/b;
        cout << t;
        temp = (temp*10+(a[i]-'0'))%b;
    }
    cout <<" " << temp << endl;
    return 0;
}
