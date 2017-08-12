#include <iostream>

using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int row = (n+1)/2;//行数 四舍五入取整
    for(int i=0; i<n; i++)
        cout << c;
    cout << endl;
    for(int i=0; i<row-2; i++){
        cout << c;
        for(int j=0; j<n-2; j++)
            cout << " ";
        cout << c << endl;
    }
    for(int i=0; i<n; i++)
        cout << c;
    return 0;
}
