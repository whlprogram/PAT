//原题链接  https://www.patest.cn/contests/pat-b-practise/1024
//题解  http://blog.csdn.net/whl_program/article/details/76651484

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s[0] == '-')
        cout << '-';
    bool t = true;//指数为正数
    int pose = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'E'){
            pose = i;
            if(s[i+1] == '-')
                t = false;//指数为负数
            break;
        }
    }
    int after = 0;
    for(int i=pose+2; i<s.size(); i++)
        after = (s[i]-'0') + after*10;
    if(t){//指数为正数
        if (pose - 3 < after) {//指数为正数且最后需要加0
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
            for (int i = 0; i < after - (pose - 3); i++)
                cout << "0";
        }
        else {//指数为正数且最后不需要加0
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < pose; i++) {
                if (i == 3 + after)
                    cout << ".";
                if (s[i] >= '0' && s[i] <= '9')
                    cout << s[i];
            }
        }
    }else{//指数为负数
        if(after > 0){
            cout << "0.";
            for(int i=1; i<after; i++)
                cout << "0";
            for(int i=1; i<pose; i++){
                if(s[i]>='0' && s[i]<='9')
                    cout << s[i];
            }
        }else{//指数为0
            for(int i=1; i<pose; i++){
                if(i == 2)
                    cout << ".";
                if(s[i] >= '0' && s[i] <= '9')
                    cout << s[i];
            }
        }
    }
    return 0;
}
