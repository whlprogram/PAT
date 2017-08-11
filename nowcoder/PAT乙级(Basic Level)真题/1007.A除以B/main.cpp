#include <iostream>

using namespace std;

int main()
{
    string a;
    int b;
    cin >> a >> b;
    string q;//商
    int r=0;//余数
    for(int i=0; i<a.size(); i++){
        int temp = a[i]-'0' + r*10;
        if(temp < b){
            if(i != 0)
                q += '0';
            if(i == a.size()-1){//使得数组不会越界
                cout << q << " " << temp << endl;
                return 0;
            }
            temp = temp*10 + (a[i+1]-'0');
            i++;
        }
        r = temp%b;
        q += temp/b+'0';
    }
    cout << q << " " << r << endl;
    return 0;
}
