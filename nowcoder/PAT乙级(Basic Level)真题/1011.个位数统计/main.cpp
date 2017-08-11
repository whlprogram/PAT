#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<int> arr(10);
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'0']++;
    }
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != 0)
            cout << i << ":" << arr[i] << endl;
    }
    return 0;
}
