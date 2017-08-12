#include <iostream>

using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int row = 0;//上半部分行数
    for(int i=0; i<n; i++){
        if((i+2)*i*2+1 > n){
            row = i-1;
            break;
        }
    }
    //输出上半部分
    for(int i=row; i>0; i--){
        for(int j=0; j<row-i; j++)
            cout << " ";
        for(int k=0; k<2*i+1; k++)
            cout << c;
        cout << endl;
    }
    //输出中间部分
    for(int i=0; i<row; i++)
        cout << " ";
    cout << c << endl;
    //输出下半部分
    for(int i=1; i<=row; i++){
        for(int j=0; j<row-i; j++)
            cout << " ";
        for(int k=0; k<2*i+1; k++)
            cout << c;
        cout << endl;
    }
    //输出没用到的符号数量
    cout << n-((row+2)*row*2+1) << endl;
    return 0;
}
