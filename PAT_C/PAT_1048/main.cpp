//ԭ������  https://www.patest.cn/contests/pat-b-practise/1048
//���    http://blog.csdn.net/whl_program/article/details/76693626

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int alen = a.size();
    int blen = b.size();
    if(alen != blen){
        if(alen < blen){//a����С��bʱ��aǰ���'0',ʹ����b�������
            for(int i=0; i<blen-alen; i++)
                a = '0' + a;
            alen = a.size();//��ȡ�µ�a����
        }else{//a���ȴ���bʱ��bǰ���'0',ʹ����a�������
            for(int i=0; i<alen-blen; i++)
                b = '0' + b;
            blen = b.size();//��ȡ�µ�b����
        }
    }
    string res="";
    bool flag = true;//��ʾ����λ
    char c[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    for(int i=blen-1; i>=0; i--){
        if(flag){//����λ
            int temp = ((a[i]-'0')+(b[i]-'0'))%13;
            res = c[temp] + res;
            flag = false;
        }else{//ż��λ
            int temp1 = (b[i]-'0')-(a[i]-'0');
            if(temp1 < 0)
                temp1 += 10;
            res = c[temp1] + res;
            flag = true;
        }
    }
    cout << res << endl;
    return 0;
}
