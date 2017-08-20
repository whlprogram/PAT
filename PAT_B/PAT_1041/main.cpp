//原题链接https://www.patest.cn/contests/pat-b-practise/1041

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string ID[N] = {""};//存储准考证号
    int Tnum[N] = {0};//存储试机座位号码
    int num[N] = {0};//存储考试座位号码
    for(int i=0; i<N; i++){
        cin >> ID[i];
        cin >> Tnum[i];
        cin >> num[i];
    }
    int M;
    cin >> M;
    int Mnum[M] = {0};//存储需要查询的试机座位号码
    for(int i=0; i<M; i++){
        cin >> Mnum[i];
        for(int j=0; j<N; j++){
            if(Mnum[i] == Tnum[j]){
                cout << ID[j] << " " << num[j] << endl;
                break;
            }
        }
    }
    return 0;
}
