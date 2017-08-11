#include <iostream>
#include <vector>
using namespace std;
bool help(long long a){
    for(int i=2; i*i<=a; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int M,N;
    cin >> M >> N;
    vector<int> arr(10001);
    int temp = 1;
    for(int i=2; i<2147483647; i++){
        if(help(i)){
            arr[temp] = i;
            temp++;
        }
        if(temp > N)
            break;
    }
    int j=1;
    for(int i=M; i<=N; i++){
        if(j==10){
            cout << arr[i] << endl;
            j=1;
            continue;
        }
        if(i == N){
            cout << arr[i];
            break;
        }
        cout << arr[i] << " ";
        j++;
    }
    return 0;
}
