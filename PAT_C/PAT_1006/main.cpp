//‘≠Ã‚¡¥Ω”

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int H = n/100;
    int T = (n/10)%10;
    int B = n%10;
    for(int i=1; i<=H; i++)
        printf("%s", "B");
    for(int i=1; i<=T; i++)
        printf("%s", "S");
    for(int i=1; i<=B; i++)
        printf("%d", i);
    return 0;
}
