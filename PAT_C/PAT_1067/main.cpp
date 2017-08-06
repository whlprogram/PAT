//原题链接 https://www.patest.cn/contests/pat-b-practise/1067
//题解 http://blog.csdn.net/whl_program/article/details/76737917


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string password;
    int n;
    cin >> password >> n;
    getchar();
    int countt=0;//记录输入次数
    while(true){
        string temp;
        getline(cin, temp);//以回车结束的空字符串，必须用getline，  用cin不通过
        if(temp == "#")
            break;
        countt++;
        if(countt<=n && temp==password){
            cout << "Welcome in";
            break;
        }else if(countt<=n && temp!=password){
            cout << "Wrong password: " << temp << endl;
            if(countt == n){//即使输入到达上限，也先输出错误密码，然后输出"Account locked"结束
                cout << "Account locked";
                break;
            }
        }
    }
    return 0;
}
