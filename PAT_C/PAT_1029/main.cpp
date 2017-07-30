//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1029
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int alen = a.size();
    int blen = b.size();
    for(int i=0; i<alen; i++)
        a[i] = toupper(a[i]);
    for(int i=0; i<blen; i++)
        b[i] = toupper(b[i]);
    for(int i=0; i<blen; i++){
        for(int j=0; j<alen; j++){
            if(b[i] == a[j])
                a[j] = '#';
        }
    }
    vector<char> res;
    for(int k=0; k<alen; k++){
        if(a[k] != '#'){
            bool temp = false;
            for(int n=0; n<res.size(); n++){
                if(res[n] == a[k]){
                     temp = true;
                     break;
                }
            }
        if(!temp)
            res.push_back(a[k]);
        }
    }
    for(int n=0; n<res.size(); n++)
        cout << res[n];
    return 0;
}
