//原题链接 https://www.patest.cn/contests/pat-b-practise/1054
//题解 http://blog.csdn.net/whl_program/article/details/76732253

#include <iostream>
#include <cstdio>
using namespace std;
double atof(string s);
int main()
{
    int N;
    cin >> N;
    int countt = 0;
    double sum = 0;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        bool flag = true;//判断输入是否合法
        bool isPoint = false;//判断前面是否已经有小数点
        int point = 0;//计算小数点个数
        int point_ = 0;//计算小数点后的位数
        int F = 0;//计算负号的个数
        if(s.size() > 8){//符合条件数字最多有8个字符
            cout << "ERROR: "<< s<< " is not a legal number" << endl;
            continue;
        }
        for(int j=0; j<s.size(); j++){
            if(s[j]=='-' || s[j]=='.' || (s[j]-'0'>=0&&s[j]-'0'<=9)){//只能存在小数点，负号和数字
                if(isPoint)//前面已经有小数点了
                    point_++;
                if(s[0] == '-')//负号只能在第一位
                    F++;
                if(s[j] == '.'){
                    point++;
                    isPoint = true;
                }
                if(point_>=3 || point>1 || (s[j]=='-'&&j!=0)){
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        if(!flag){//输入不合法
            cout << "ERROR: "<< s << " is not a legal number" << endl;
        }else{
            double temp = atof(s);//将字符串转化为数字
            if(temp<=1000 && temp>=-1000){
                sum += temp;
                countt++;
            }else{
                cout << "ERROR: "<< s << " is not a legal number" << endl;
            }
        }
    }
    if(countt == 1){
        printf("The average of 1 number is %.2f", sum);//注意是number 不是numbers
    }else if(countt > 1){
        printf("The average of %d numbers is %.2f", countt, sum/countt);//精确到小数点后两位
    }else{
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
double atof(string s){
    double res = 0;
    double res1 = 0;
    bool flag = false;//判断是否是负数
    bool isPoint = false;
    double point_ = 1;//计算小数点后的位数
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-'){
            flag = true;
            continue;
        }
        if(s[i] == '.'){
            isPoint = true;
            continue;
        }
        if(!isPoint){//整数部分
            res = (s[i]-'0') + res*10;
        }else{//小数部分
            point_ *= 10;
            res1 = (s[i]-'0') + res1*10;
        }
    }
    if(point_ != 0)
        res = res + res1/point_;
    if(flag)//负数
        return -res;
    return res;
}
