//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1031
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char check[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    vector<string> res;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        int sum=0;
        for(int j=0; j<17; j++)
            sum += ((temp[j]-'0')*weight[j]);
        if(temp[17] != check[sum%11])
            res.push_back(temp);
    }
    if(res.size() == 0)
        cout << "All passed" << endl;
    else{
        for(int i=0; i<res.size(); i++)
        cout << res[i] << endl;
    }
    return 0;
}
