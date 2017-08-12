#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr;
    char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int sum=0;
        for(int j=0; j<s.size()-1; j++){
            if(s[j]<'0' || s[j]>'9'){
                arr.push_back(s);
                break;
            }
            sum += (s[j]-'0')*weight[j];
        }
        if(M[sum%11] != s[17])
            arr.push_back(s);
    }
    if(arr.size() == 0){
        cout << "All passed" << endl;
        return 0;
    }
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
}
