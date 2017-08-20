//‘≠Ã‚¡¥Ω”£∫https://www.patest.cn/contests/pat-b-practise/1016

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int A,Da,B,Db,Pa=0,Pb=0;
    scanf("%d%d%d%d", &A, &Da, &B, &Db);
    while(A!=0){
        int temp = A%10;
        if(temp == Da)
            Pa = Pa*10 + temp;
        A = A/10;
    }
    while(B!=0){
        int temp = B%10;
        if(temp == Db)
            Pb = Pb*10 + temp;
        B = B/10;
    }
    printf("%d", Pa+Pb);
    return 0;
}
