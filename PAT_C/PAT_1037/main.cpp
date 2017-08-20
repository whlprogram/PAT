//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1037
#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
    int PG,PS,PK,AG,AS,AK;
    scanf("%d.%d.%d %d.%d.%d",&PG,&PS,&PK,&AG,&AS,&AK);
    int P = PK+PS*29+PG*29*17;
    int A = AK+AS*29+AG*29*17;
    bool B = true;
    if(P > A)
        B = false;
    int temp = abs(A-P);
    int CG = temp/(29*17);
    int CS = (temp%(29*17))/29;
    int CK = (temp%(29*17))%29;
    if(!B)
        printf("-%d.%d.%d", CG, CS, CK);
    else
        printf("%d.%d.%d", CG, CS, CK);
    return 0;
}
/*
int main()
{
    int PG,PS,PK;
    int AG,AS,AK;
    scanf("%d.%d.%d %d.%d.%d",&PG,&PS,&PK,&AG,&AS,&AK);
    bool B = true;
    if(PG>AG || (PG==AG&&PS>AS) || (PG==AG&&PS==AS&&PK>AK) )
        B = false;
    int CG,CS,CK;
    if(B){
        if(AK >= PK)
            CK = AK - PK;
        else{
            CK = AK + 29 - PK;
            AS--;
        }
        if(AS >= PS)
            CS = AS - PS;
        else{
            CS = AS + 17 - PS;
            AG--;
        }
        CG = AG - PG;
        printf("%d.%d.%d", CG, CS, CK);
    }
    else{
        if(AK <= PK)
            CK = PK - AK;
        else{
            CK = PK + 29 - AK;
            PS--;
        }
        if(AS <= PS)
            CS = PS - AS;
        else{
            CS = PS + 17 - AS;
            PG--;
        }
        CG = PG - AG;
        printf("-%d.%d.%d", CG, CS, CK);
    }

    return 0;
}
*/
