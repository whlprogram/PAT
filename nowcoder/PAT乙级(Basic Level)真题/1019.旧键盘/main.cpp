#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    string a,b;
    getline(cin, a);
    getline(cin, b);
    for(int i=0; i<a.size(); i++)
        a[i] = toupper(a[i]);
    for(int i=0; i<b.size(); i++)
        b[i] = toupper(b[i]);
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(a[j] == b[i]){
                a[j] = '#';
            }
        }
    }
    vector<char> res;
    for(int i=0; i<a.size(); i++){
        if(a[i] != '#'){
            bool flag = true;
            for(int j=0; j<res.size(); j++){
                if(a[i] == res[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(a[i]);
        }
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i];
    }
    return 0;
}
