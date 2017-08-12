#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int t=0,p=0;//T数量 P数量
    long long sum=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'T')
            t++;
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'T')
            t--;
        if(s[i] == 'P')
            p++;
        if(s[i] == 'A')
            sum += t*p;
    }
    cout << sum%1000000007 << endl;
    return 0;
}
