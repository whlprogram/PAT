//原题链接  https://www.patest.cn/contests/pat-b-practise/1044
//题解  http://blog.csdn.net/whl_program/article/details/76652761

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
void help1(string s);
void help2(string s);
int main()
{
    int n;
    cin >> n;
    getchar();//很重要
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);
        if(s[0] >='0' && s[0] <='9')
            help1(s);
        else
            help2(s);
    }
    return 0;
}
void help1(string s){
    string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};//0-12
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};//进位
    int len = s.length();
    if(len == 1){
        cout << a[s[0]-'0'] << endl;
        return;
    }
    int t;
    if(len == 2){
        t = (s[0]-'0')*10 + (s[1]-'0');
    }else{//len == 3
        t = (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0');
    }
    if(t <= 12){
        cout << a[t] << endl;
    }else if(t%13 == 0){
        cout << b[t/13] << endl;
    }else
        cout << b[t/13] << " " << a[t%13]<< endl;
}
void help2(string s){
    if(s == "tret"){
        cout << 0 << endl;
        return;
    }
    string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};//0-12
    string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};//进位
    int len = s.length();
    if(len == 3){//13以内或者13的倍数
        for(int j=1; j<=12; j++){
            if(s[0]==a[j][0] && s[1]==a[j][1] && s[2]==a[j][2])
                cout << j << endl;
            else if(s[0]==b[j][0] && s[1]==b[j][1] && s[2]==b[j][2]){
                cout << j*13 << endl;
            }
        }
    }else{//13+且不是13倍数
        int t1=0, t2=0;
        for(int j=1; j<=12; j++){
            if(s[0]==b[j][0] && s[1]==b[j][1] && s[2]==b[j][2])
                t1 = j;
            if(s[4]==a[j][0] && s[5]==a[j][1] && s[6]==a[j][2])
                t2 = j;
        }
        cout << t1*13+t2 << endl;
    }
}
