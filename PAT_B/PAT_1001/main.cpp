//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1001
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int num = 0;
    while(n != 1){
        if(n%2 == 0){
            n /= 2;
            num++;
            continue;
        }
        else{
            n = (3*n+1)/2;
            num++;
        }
    }
    printf("%d", num);
    return 0;
}
