//Ô­ÌâÁ´½Óhttps://www.patest.cn/contests/pat-b-practise/1008
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    if(M > N)
        M -= N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+M);
    reverse(arr.begin()+M,arr.end());
    for(int j=0; j<N; j++){
        if(j != 0)
            cout << " ";
        cout << arr[j];
    }
    return 0;
}
