#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    for(int i=0; i<a.size(); i++){
        if(a[i]>='A' && a[i]<='Z')
            a[i] = tolower(a[i]);
    }
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i] == '+'){
                if(b[j]>='A' && b[j]<='Z')
                    b[j] = '#';
            }
            if(a[i]==b[j] || a[i]==tolower(b[j])){
                b[j] = '#';
            }
        }
    }
    string res="";
    for(int i=0; i<b.size(); i++){
        if(b[i] != '#')
            res += b[i];
    }
    if(res != "")
        cout << res << endl;
    else
        cout << endl;
    return 0;
}
