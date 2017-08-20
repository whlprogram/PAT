//原题链接  https://www.patest.cn/contests/pat-b-practise/1048
//题解    http://blog.csdn.net/whl_program/article/details/76693626

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
        if(alen < blen){//a长度小于b时将a前面加'0',使其与b长度相等
            for(int i=0; i<blen-alen; i++)
                a = '0' + a;
            alen = a.size();//获取新的a长度
        }else{//a长度大于b时将b前面加'0',使其与a长度相等
            for(int i=0; i<alen-blen; i++)
                b = '0' + b;
            blen = b.size();//获取新的b长度
        }
    }
    string res="";
    bool flag = true;//表示奇数位
    char c[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    for(int i=blen-1; i>=0; i--){
        if(flag){//奇数位
            int temp = ((a[i]-'0')+(b[i]-'0'))%13;
            res = c[temp] + res;
            flag = false;
        }else{//偶数位
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
