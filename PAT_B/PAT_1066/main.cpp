//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1066
#include <cstdio>
using namespace std;

int main()
{
    int M,N,A,B,t;
    scanf("%d%d%d%d%d", &M, &N, &A, &B, &t);
    int temp[M][N] = {0};
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &temp[i][j]);
            if(temp[i][j]>=A && temp[i][j]<=B)
                temp[i][j] = t;
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(j != 0)
                printf(" ");
            printf("%03d", temp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
