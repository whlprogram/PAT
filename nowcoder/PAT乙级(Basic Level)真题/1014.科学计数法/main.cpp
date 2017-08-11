#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s[0] == '-')
        cout << '-';
    bool flag = true;//指数为正数
    int pose = 0;//E的位置
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'E'){
            pose = i;
            if(s[pose+1] == '-')
                flag = false;
        }
    }
    int t = 0;
    for(int i=pose+2; i<s.size(); i++){//计算指数大小
        t = t*10 + (s[i]-'0');
    }
    if(flag){//指数为正数,小数点右移
        if(pose-3 >= t){//不用后面补0
            if(s[1] != '0')
                cout << s[1];
            for(int i=3; 1<pose; i++){
                if(i == t+3)
                    cout << '.';
                if(s[1]<='9' && s[1]>='0')
                    cout << s[i];
            }
        }else{//需要后面补0
            if(s[1] != '0')
                cout << s[1];
            for(int i=3; i<pose; i++){
                if(s[1]<='9' && s[1]>='0')
                    cout << s[i];
            }
            for(int i=0; i<t-(pose-3); i++)
                cout << '0';
        }
    }else{//指数为负数,小数点左移
        if(t > 0){
            cout << "0.";
            for(int i=1; i<t; i++)
                cout << '0';
            for(int i=1; i<pose; i++){
                if(s[i]>='0' && s[i]<='9')
                    cout << s[i];
            }
        }else{//指数为0
            for(int i=1; i<pose; i++){
                cout << s[i];
            }
        }
    }
    return 0;
}
