//ԭ������ https://www.patest.cn/contests/pat-b-practise/1054
//��� http://blog.csdn.net/whl_program/article/details/76732253

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
        bool flag = true;//�ж������Ƿ�Ϸ�
        bool isPoint = false;//�ж�ǰ���Ƿ��Ѿ���С����
        int point = 0;//����С�������
        int point_ = 0;//����С������λ��
        int F = 0;//���㸺�ŵĸ���
        if(s.size() > 8){//�����������������8���ַ�
            cout << "ERROR: "<< s<< " is not a legal number" << endl;
            continue;
        }
        for(int j=0; j<s.size(); j++){
            if(s[j]=='-' || s[j]=='.' || (s[j]-'0'>=0&&s[j]-'0'<=9)){//ֻ�ܴ���С���㣬���ź�����
                if(isPoint)//ǰ���Ѿ���С������
                    point_++;
                if(s[0] == '-')//����ֻ���ڵ�һλ
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
        if(!flag){//���벻�Ϸ�
            cout << "ERROR: "<< s << " is not a legal number" << endl;
        }else{
            double temp = atof(s);//���ַ���ת��Ϊ����
            if(temp<=1000 && temp>=-1000){
                sum += temp;
                countt++;
            }else{
                cout << "ERROR: "<< s << " is not a legal number" << endl;
            }
        }
    }
    if(countt == 1){
        printf("The average of 1 number is %.2f", sum);//ע����number ����numbers
    }else if(countt > 1){
        printf("The average of %d numbers is %.2f", countt, sum/countt);//��ȷ��С�������λ
    }else{
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
double atof(string s){
    double res = 0;
    double res1 = 0;
    bool flag = false;//�ж��Ƿ��Ǹ���
    bool isPoint = false;
    double point_ = 1;//����С������λ��
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-'){
            flag = true;
            continue;
        }
        if(s[i] == '.'){
            isPoint = true;
            continue;
        }
        if(!isPoint){//��������
            res = (s[i]-'0') + res*10;
        }else{//С������
            point_ *= 10;
            res1 = (s[i]-'0') + res1*10;
        }
    }
    if(point_ != 0)
        res = res + res1/point_;
    if(flag)//����
        return -res;
    return res;
}
