//原题链接 https://www.patest.cn/contests/pat-b-practise/1010
//题解    http://blog.csdn.net/whl_program/article/details/76696672

#include <cstdio>

using namespace std;

int main()
{
    int a,b;
    bool isfirst = true;
    while(~scanf("%d %d", &a, &b)){
        if(b == 0)
            continue;
        if(!isfirst)
            printf(" ");
        else
            isfirst = false;
        printf("%d %d", a*b, b-1);
    }
    if(isfirst)
        printf("0 0");
    return 0;
}
