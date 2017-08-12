#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    scanf("%d.%d.%d", &a, &b, &c);//应付的价钱P
    scanf("%d.%d.%d", &d, &e, &f);//实付的钱A
    if(d<a || (d==a&&e<b) || (d==a&&e==b&&f<c)){
        cout << '-';
        int t1=a,t2=b,t3=c;
        a = d;
        b = e;
        c = f;
        d = t1;
        e = t2;
        f = t3;
    }
    int r1,r2,r3;
    if(f >= c){
        r3 = f-c;
    }else{
        f += 29;
        r3 = f-c;
        e--;
    }
    if(e >= b){
        r2 = e-b;
    }else{
        e += 17;
        r2 = e-b;
        d--;
    }
    r1 = d-a;
    printf("%d.%d.%d", r1, r2, r3);
    return 0;
}
