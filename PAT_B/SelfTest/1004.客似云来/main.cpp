//ԭ������ https://www.nowcoder.com/pat/2/problem/252
//��� http://blog.csdn.net/whl_program/article/details/77345852
#include <iostream>
#include <cstdio>
using namespace std;
long long arr[81] = {0};
long long help(int from, int to){//�ݹ� ����¼
    if(from == to)
        return arr[from];
    long long sum=0;
    for(int i=from; i<=to; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    int from,to;
    arr[1] = 1;
    arr[2] = 1;
    for(int n=3; n<81; n++){
        //arr[n] = (arr[n-1]-arr[n-2])+2*arr[n-2];
        arr[n] = arr[n-1]+arr[n-2];
    }
    while(~scanf("%d%d", &from, &to)){
        cout << help(from, to) << endl;
    }
    return 0;
}
