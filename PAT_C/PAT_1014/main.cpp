//原题链接 https://www.patest.cn/contests/pat-b-practise/1014
//题解 http://blog.csdn.net/whl_program/article/details/76737805

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    bool first = true;//判断是否是第一个相同的大写字母 用来输出星期
    bool second = false;//判断是否是第二个相同的字符 用来输出小时
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i] && ((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9')) && second){
            if(a[i]>='0'&&a[i]<='9'){
                printf("%02d:", a[i]-'0');
            }else{
                printf("%02d:", a[i]-'A'+10);
            }
            break;
        }
        if(a[i]==b[i] && a[i]>='A' && a[i]<='G' && first){
            cout << week[a[i]-'A'] << " ";
            first = false;
            second = true;
        }
    }
    for(int i=0; i<c.size(); i++){
        if(c[i]==d[i] && ((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))){
            printf("%02d", i);
        }
    }
    return 0;
}
