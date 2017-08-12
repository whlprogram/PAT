#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int alen = a.size();
    int blen = b.size();
    int aHash[62] = {0};//[0-9]、[a-z]、[A-Z]
    int bHash[62] = {0};//[0-9]、[a-z]、[A-Z]
    for(int i=0; i<alen; i++){
        if(a[i]>='0' && a[i]<='9')
            aHash[a[i]-'0']++;
        if(a[i]>='a' && a[i]<='z')
            aHash[a[i]-'a'+10]++;
        if(a[i]>='A' && a[i]<='Z')
            aHash[a[i]-'A'+36]++;
    }
    for(int i=0; i<blen; i++){
        if(b[i]>='0' && b[i]<='9')
            bHash[b[i]-'0']++;
        if(b[i]>='a' && b[i]<='z')
            bHash[b[i]-'a'+10]++;
        if(b[i]>='A' && b[i]<='Z')
            bHash[b[i]-'A'+36]++;
    }
    int res=0;//缺的珠子数量
    for(int i=0; i<62; i++){
        if(bHash[i]!=0 && bHash[i]>aHash[i]){
            res += bHash[i]-aHash[i];
        }
    }
    if(res != 0)
        cout << "No " << res << endl;
    else
        cout << "Yes " << alen-blen << endl;
    return 0;
}
