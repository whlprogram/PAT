//ԭ������ https://www.patest.cn/contests/pat-b-practise/1067
//��� http://blog.csdn.net/whl_program/article/details/76737917


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string password;
    int n;
    cin >> password >> n;
    getchar();
    int countt=0;//��¼�������
    while(true){
        string temp;
        getline(cin, temp);//�Իس������Ŀ��ַ�����������getline��  ��cin��ͨ��
        if(temp == "#")
            break;
        countt++;
        if(countt<=n && temp==password){
            cout << "Welcome in";
            break;
        }else if(countt<=n && temp!=password){
            cout << "Wrong password: " << temp << endl;
            if(countt == n){//��ʹ���뵽�����ޣ�Ҳ������������룬Ȼ�����"Account locked"����
                cout << "Account locked";
                break;
            }
        }
    }
    return 0;
}
