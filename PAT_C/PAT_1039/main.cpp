//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1039
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int alen = a.size();
    int blen = b.size();
    int aHash[62] = {0};//[0-9]°¢[a-z]°¢[A-Z]
    int bHash[62] = {0};
    for(int i=0; i<alen; i++){
        if(a[i]-'0'<=9){
            aHash[a[i]-'0']++;
            continue;
        }
        if(a[i]-'A'<26){
            aHash[a[i]-'A'+10]++;
            continue;
        }
        if(a[i]-'a'<26){
            aHash[a[i]-'a'+36]++;
            continue;
        }
    }
    for(int j=0; j<blen; j++){
        if(b[j]-'0'<=9){
            bHash[b[j]-'0']++;
            continue;
        }
        if(b[j]-'A'<26){
            bHash[b[j]-'A'+10]++;
            continue;
        }
        if(b[j]-'a'<26){
            bHash[b[j]-'a'+36]++;
            continue;
        }
    }
    int n = 0;
    for(int k=0; k<62; k++){
        if(bHash[k] != 0){
            if(bHash[k] > aHash[k]){
                n += (bHash[k]-aHash[k]);
            }
        }
    }
    if(n > 0)
        cout << "No " << n << endl;
    else
        cout << "Yes " << alen-blen << endl;
    return 0;
}
