//原题链接  https://www.patest.cn/contests/pat-b-practise/1059
//题解  http://blog.csdn.net/whl_program/article/details/76639120

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool isPrimeNum(int i){
    for(int j=2; j*j<=i; j++){//j*j很重要，减少运行时间
        if(i%j == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    vector<int> arr(10001);
    for(int i=1; i<=N; i++){//记录每个id排名
        int id;
        cin >> id;
        arr[id] = i;
    }
    int K;
    cin >> K;
    vector<int> aa(10001);//记录每个id有没有领过奖品
    vector<int> res(K);
    for(int i=0; i<K; i++){
        cin >> res[i];//输入要查找的Id
    }
    for(int i=0; i<res.size(); i++){
        printf("%04d", res[i]);
        printf(": ");
        if(arr[res[i]] == 0){//如果id没有排名
            cout << "Are you kidding?" << endl;
            continue;
        }
        if(aa[res[i]] == 1){//如果id领过奖品
            cout << "Checked" << endl;
            continue;
        }
        if(aa[res[i]] == 0){//如果id有没有领过奖品
            if(arr[res[i]] == 1){
                cout << "Mystery Award" << endl;

            }
            else if(isPrimeNum(arr[res[i]])){
                cout << "Minion" << endl;
            }
            else
                cout << "Chocolate" << endl;
            aa[res[i]] = 1;
        }
    }
    return 0;
}
