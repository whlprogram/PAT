#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s[0] == '-')
        cout << '-';
    bool flag = true;//ָ��Ϊ����
    int pose = 0;//E��λ��
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'E'){
            pose = i;
            if(s[pose+1] == '-')
                flag = false;
        }
    }
    int t = 0;
    for(int i=pose+2; i<s.size(); i++){//����ָ����С
        t = t*10 + (s[i]-'0');
    }
    if(flag){//ָ��Ϊ����,С��������
        if(pose-3 >= t){//���ú��油0
            if(s[1] != '0')
                cout << s[1];
            for(int i=3; 1<pose; i++){
                if(i == t+3)
                    cout << '.';
                if(s[1]<='9' && s[1]>='0')
                    cout << s[i];
            }
        }else{//��Ҫ���油0
            if(s[1] != '0')
                cout << s[1];
            for(int i=3; i<pose; i++){
                if(s[1]<='9' && s[1]>='0')
                    cout << s[i];
            }
            for(int i=0; i<t-(pose-3); i++)
                cout << '0';
        }
    }else{//ָ��Ϊ����,С��������
        if(t > 0){
            cout << "0.";
            for(int i=1; i<t; i++)
                cout << '0';
            for(int i=1; i<pose; i++){
                if(s[i]>='0' && s[i]<='9')
                    cout << s[i];
            }
        }else{//ָ��Ϊ0
            for(int i=1; i<pose; i++){
                cout << s[i];
            }
        }
    }
    return 0;
}
