//ԭ������  https://www.patest.cn/contests/pat-b-practise/1013
//���    http://blog.csdn.net/whl_program/article/details/76691637

#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<int> res(n+1);
    int countt = 1;
    for(int i=2; i<2147483647; i++){//����m����n��������ӵ������Ӧλ��
        if(isPrime(i)){
            if(countt >= m)
                res[countt] = i;
            countt++;
        }
        if(countt == n+1)//��n��������ӵ������Ӧλ�ú����ѭ��
            break;
    }
    int t=0;
    for(int i=m; i<=n; i++){
        if(t != 0)
            cout << " ";
        cout << res[i];
        t++;
        if(t == 10){
            cout << endl;
            t = 0;
        }
    }
    return 0;
}
