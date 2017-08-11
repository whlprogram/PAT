#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%04d", &n);
    if(n%1111==0){
        printf("%04d - %04d = 0000", n, n);
        return 0;
    }
    while(true){
        int a[4];
        a[0] = n/1000;
        a[1] = n/100%10;
        a[2] = n/10%10;
        a[3] = n%10;
        sort(a, a+4);
        int A = a[3]*1000+a[2]*100+a[1]*10+a[0];
        int B = a[0]*1000+a[1]*100+a[2]*10+a[3];
        printf("%04d - %04d = %04d\n", A, B, A-B);
        n = A - B;
        if(A-B == 6174)
            break;
    }
    return 0;
}
