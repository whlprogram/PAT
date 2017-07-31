//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1022
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A,B,D;
    cin >> A >> B >> D;
    int sum = A+B;
    if(sum == 0){
        cout << 0;
        return 0;
    }
    vector<int> res;
    while(sum != 0){
        int temp = sum%D;
        res.push_back(temp);
        sum /= D;
    }
    for(int i=res.size()-1; i>=0; i--)
        cout << res[i];
    return 0;
}
