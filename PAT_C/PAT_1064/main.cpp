//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1064

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int Hash[37] = {0};
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        int sum = 0;
        while(temp != 0){
            sum += (temp%10);
            temp /= 10;
        }
        Hash[sum]++;
    }
    int num = 0;
    vector<int> res;
    for(int j=1; j<37; j++){
        if(Hash[j] != 0){
            num++;
            res.push_back(j);
        }
    }
    cout << num << endl;
    for(int i=0; i<num-1; i++)
        cout << res[i] << " ";
    cout << res[num-1];
    return 0;
}
