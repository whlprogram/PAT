//‘≠Ã‚¡¥Ω”https://www.patest.cn/contests/pat-b-practise/1070
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
void sort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n] = {0};
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    int res = arr[0];
    for(int i=1; i<n; i++){
        res = (res+arr[i])/2;
    }
    printf("%d", res);
    return 0;
}*/
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int res = arr[0];
    for(int i=1; i<n; i++){
        res = (res+arr[i])/2;
    }
    printf("%d", res);
    return 0;
}
