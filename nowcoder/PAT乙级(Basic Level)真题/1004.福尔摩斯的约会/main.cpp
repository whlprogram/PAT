#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a,b,c,d;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    getline(cin, d);
    string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    bool flag = true;
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[i] && ((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9')) && !flag){
            if(a[i]>='0'&&a[i]<='9')
                printf("%02d:", a[i]-'0');
            else
                printf("%02d:", a[i]-'A'+10);
            break;
        }
        if(a[i]==b[i] && a[i]>='A' && a[i]<='G' && flag){
            cout << day[a[i]-'A'] << " ";
            flag = false;
        }
    }
    for(int i=0; i<c.size(); i++){
        if(c[i]==d[i] && ((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))){
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
