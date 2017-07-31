//Ô­ÌâÁ´½Óhttps://www.patest.cn/contests/pat-b-practise/1057
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int sum=0;
    for(int i=0; i<str.size(); i++){
        str[i] = tolower(str[i]);
        if(str[i]>='a' && str[i]<='z')
            sum += ((str[i]-'a')+1);
    }
    int a=0,b=0;
    while(sum != 0){
        if(sum%2 == 0)
            a++;
        else
            b++;
        sum /= 2;
    }
    cout << a << " " << b << endl;
    return 0;
}
