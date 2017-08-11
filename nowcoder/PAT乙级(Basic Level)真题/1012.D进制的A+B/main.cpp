#include <iostream>

using namespace std;

int main()
{
    long long A, B;
    int D;
    cin >> A >> B >> D;
    long long C = A + B;
    if(C == 0){
        cout << 0 << endl;
        return 0;
    }
    string res = "";
    while(C != 0){
        char q = C%D+'0';
        res = q + res;
        C /= D;
    }
    cout << res << endl;
    return 0;
}
