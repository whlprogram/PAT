#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    int res=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(v[i] != v[j])
                res += (v[i]*10+v[j]);
    printf("%d", res);
    return 0;
}
