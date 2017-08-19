//原题链接 https://www.patest.cn/contests/pat-b-practise/1023

#include <iostream>
using namespace std;
string help(int n){
    if(n == 0) return "0";
    if(n == 1) return "1";
    if(n == 2) return "2";
    if(n == 3) return "3";
    if(n == 4) return "4";
    if(n == 5) return "5";
    if(n == 6) return "6";
    if(n == 7) return "7";
    if(n == 8) return "8";
    if(n == 9) return "9";
}
int main()
{
    int HASH[10] = {0};
    for(int i=0; i<10; i++){
        int n;
        cin >> n;
        HASH[i] = n;
    }
    string res = "";
    for(int i=1; i<10; i++){
        if(HASH[i] != 0){
            res += help(i);
            HASH[i]--;
            break;
        }
    }
    for(int i=0; i<10; i++){
        while(HASH[i] != 0){
            res += help(i);
            HASH[i]--;
        }
    }
    cout << res << endl;
    return 0;
}
/*
方法2：
#include <iostream>
using namespace std;

int main()
{
    int HASH[10] = {0};
    for(int i=0; i<10; i++){
        int n;
        cin >> n;
        HASH[i] = n;
    }
    for(int i=1; i<10; i++){
        if(HASH[i] != 0){
            cout << i;
            HASH[i]--;
            break;
        }
    }
    for(int i=0; i<10; i++){
        while(HASH[i] != 0){
            cout << i;
            HASH[i]--;
        }
    }
    return 0;
}
*/
