//原题链接 https://www.patest.cn/contests/pat-b-practise/1069
//题解 http://blog.csdn.net/whl_program/article/details/76599985

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int M,N,S;
    cin >> M >> N >> S;
    if(M < S){
        cout << "Keep going..." << endl;
        return 0;
    }
    map<string, int> Map;
    vector<string> res;
    for(int i=1; i<=M; i++){
        string str;
        cin >> str;
        if(Map[str] == 1)
            S++;
        if(Map[str]==0 && i==S){
            res.push_back(str);
            Map[str] = 1;
            S += N;
        }
    }
    for(int i=0; i<res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
