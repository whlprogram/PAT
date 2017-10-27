#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string z;
        cin >> z;
        int len = z.size();
        int a=0,b=0,c=0;
        for(int j=0; j<len/2; j++){
            a = a*10 + (z[j]-'0');
            c = c*10 + (z[j]-'0');
        }
        for(int j=len/2; j<len; j++){
            b = b*10 + (z[j]-'0');
            c = c*10 + (z[j]-'0');
        }
        if(b == 0){
            cout << "No" << endl;
            continue;
        }
        if(c%(a*b) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
