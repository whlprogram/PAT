#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> score(101);
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        score[temp]++;
    }
    int c;
    cin >> c;
    vector<int> res;
    for(int i=0; i<c; i++){
        int temp;
        cin >> temp;
        res.push_back(score[temp]);
    }
    for(int i=0; i<res.size()-1; i++)
        cout << res[i] << " ";
    cout << res[res.size()-1];
    return 0;
}
