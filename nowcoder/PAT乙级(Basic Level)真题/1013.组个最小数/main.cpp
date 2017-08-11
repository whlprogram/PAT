#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[10] = {0};
    char c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string res = "";
    for(int i=0; i<10; i++)
        cin >> arr[i];
    for(int i=1; i<10; i++){
        if(arr[i] != 0){
            res += c[i];
            arr[i]--;
            break;
        }
    }
    for(int i=0; i<10; i++){
        while(arr[i] != 0){
            res += c[i];
            arr[i]--;
        }
    }
    cout << res << endl;
    return 0;
}
