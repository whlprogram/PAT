//原题链接 https://www.patest.cn/contests/pat-b-practise/1038
//题解 http://blog.csdn.net/whl_program/article/details/76595392

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> score(100);
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        score[temp]++;
    }
    int K;
    cin >> K;
    vector<int> res(K);
    for(int i=0; i<K; i++){
        int temp1;
        cin >> temp1;
        res[i] = score[temp1];
    }
    for(int i=0; i<K; i++){
        if(i != 0)
            cout << " ";
        cout << res[i];
    }
    return 0;
}
