//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1036

#include <iostream>

using namespace std;

int main()
{
    int N;
    char C;
    cin >> N;
    cin >> C;
    int t=N/2+N%2;
    for(int i=0; i<t; i++){
        if(i==0 || i==(t-1)){
            for(int j=0; j<N; j++)
                cout << C;
            cout << endl;
        }
        else{
            cout << C;
            for(int k=1; k<N-1; k++)
                cout << ' ';
            cout << C << endl;
        }
    }
    return 0;
}
