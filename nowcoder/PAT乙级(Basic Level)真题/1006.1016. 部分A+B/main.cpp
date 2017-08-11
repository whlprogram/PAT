#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    int da, db;
    cin >> a >> da >> b >> db;
    int A=0,B=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]-'0' == da){
            A = A*10 + da;
        }
    }
    for(int i=0; i<b.size(); i++){
        if(b[i]-'0' == db){
            B = B*10 + db;
        }
    }
    cout << A+B << endl;
    return 0;
}
