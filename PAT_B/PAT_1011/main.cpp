//原题链接 https://www.patest.cn/contests/pat-b-practise/1011
//题解 http://blog.csdn.net/whl_program/article/details/76600111

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<bool> res(T);
    for(int i=0; i<T; i++){
        long long int a,b,c;
        cin >> a >> b >> c;
        if(a+b > c)
            res[i] = true;
        else
            res[i] = false;
    }
    for(int j=0; j<res.size(); j++){
        string temp;
        res[j] == 0 ? temp = ": false" : temp = ": true";
        cout << "Case #" << (j+1) << temp << endl;
    }
    return 0;
}
