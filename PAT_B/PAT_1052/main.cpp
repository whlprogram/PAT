//原题链接  https://www.patest.cn/contests/pat-b-practise/1052
//题解    http://blog.csdn.net/whl_program/article/details/76696137


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<string>> s(3);
    for(int i=0; i<3; i++){
        string t;
        getline(cin, t);
        int j=0,k=0;
        while(j<t.size()){
            if(t[j] == '['){
                k = j+1;
                while(k < t.size()){
                    if(t[k] == ']'){
                        s[i].push_back(t.substr(j+1, k-j-1));
                        break;
                    }
                    k++;
                }
            }
            j++;
        }
    }
    int n;
    cin >> n;
    vector<string> res;
    for(int i=0; i<n; i++){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        string temp="";
        if(a>s[0].size() || b>s[1].size() || c>s[2].size() || d>s[1].size() || e>s[0].size() || a < 1 || b < 1 || c < 1 || d < 1 || e < 1)
            temp = "Are you kidding me? @\\/@";// \是转义符，需要在前面加个\才能显示
        else
            temp = s[0][a-1] + '(' + s[1][b-1] + s[2][c-1] + s[1][d-1] + ')' + s[0][e-1];
        res.push_back(temp);
    }
    for(int i=0; i<res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
