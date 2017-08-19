//原题链接 https://www.patest.cn/contests/pat-b-practise/1027
//题解 http://blog.csdn.net/whl_program/article/details/76584989
#include <iostream>

using namespace std;

int main()
{
    int N;
    char C;
    cin >> N >> C;
    int n = 0;
    for(int i=1; i<=N; i++){//计算沙漏上部分行数n
        if((i+2)*i*2+1 > N){
            n = i-1;
            break;
        }
    }
    //输出沙漏上部分
    for(int i=n; i>=1; i--){
        for(int j=0; j<(n-i); j++)
            cout << " ";
        for(int k=0; k<(2*i+1); k++)
            cout << C;
        cout << endl;
    }
    //输出沙漏中间部分
    for(int i=0; i<n; i++)
        cout << " ";
    cout << C << endl;
    //输出沙漏下部分
    for(int i=1; i<=n; i++){
        for(int j=0; j<(n-i); j++)
            cout << " ";
        for(int k=0; k<(2*i+1); k++)
            cout << C;
        cout << endl;
    }
    //输出剩余符号数
    cout << N-((n+2)*n*2+1) << endl;
    return 0;
}
