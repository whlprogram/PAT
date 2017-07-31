//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1004
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> Name(n);
    vector<string> StuNum(n);
    vector<int> score(n);
    for(int i=0; i<n; i++){
        string a,b;
        int temp;
        cin >> a >> b >> temp;
        Name[i] = a;
        StuNum[i] = b;
        score[i] = temp;
    }
    int Max=0,Min=0;
    for(int j=1; j<score.size(); j++){
        if(score[Max] < score[j])
            Max = j;
        if(score[Min] > score[j])
            Min = j;
    }
    cout << Name[Max] << " " << StuNum[Max] << endl;
    cout << Name[Min] << " " << StuNum[Min] << endl;
    return 0;
}
