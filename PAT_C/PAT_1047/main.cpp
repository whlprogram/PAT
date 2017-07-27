#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, t, num, score;
    scanf("%d", &N);
    int team[1001] = {0};
    for(int i=0; i<N; i++){
        scanf("%d-%d %d", &t, &num, &score);
        team[t] += score;
    }
    int Max = 1;
    for(int i=2; i<=1000; i++){
        if(team[Max] < team[i])
            Max = i;
    }
    printf("%d %d", Max, team[Max]);
    return 0;
}
