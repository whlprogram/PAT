//原题链接 https://www.patest.cn/contests/pat-b-practise/1032
//题解 http://blog.csdn.net/whl_program/article/details/76595278
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> score(N);
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        score[a] += b;
    }
    int MAX = 1;
    for(int i=2; i<score.size(); i++)
        if(score[MAX] < score[i])
            MAX = i;
    cout << MAX << " " << score[MAX] << endl;
    return 0;
}
