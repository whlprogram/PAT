//原题链接  https://www.patest.cn/contests/pat-a-practise/1015
//题解    http://blog.csdn.net/whl_program/article/details/77688399
#include <iostream>

using namespace std;
bool isPrime(int n){
    if(n <= 1)
        return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    bool flag = true;
    int n, d;
    while(flag){
        cin >> n;
        if(n < 0)
            break;
        cin >> d;//进制
        if(isPrime(n) == false){
            cout << "No" << endl;
            continue;
        }
        int revers = 0;//D进制下反转后的数
        while(n != 0){
            int temp = n%d;
            revers = revers*d + temp;
            n /= d;
        }
        if(isPrime(revers) == false){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}
