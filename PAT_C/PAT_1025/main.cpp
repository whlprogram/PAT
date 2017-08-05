//原题链接 https://www.patest.cn/contests/pat-b-practise/1025
//题解 http://blog.csdn.net/whl_program/article/details/76737672

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int first,n,k;
    cin >> first >> n >> k;
    int address[100001];
    int data[100001];
    int next[100001];
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int countt = 0;//有效节点数量 (输入的节点不一定都有效)
    while(first != -1){
        address[countt] = first;
        countt++;
        first = next[first];
    }
    int m = countt - countt%k;//需要反转的节点数
    for(int i=0; i<m; i+=k){
        reverse(begin(address)+i, begin(address)+i+k);
    }
    for(int i=0; i<countt-1; i++){
        printf("%05d %d %05d\n", address[i], data[address[i]], address[i+1]);
    }
    printf("%05d %d -1", address[countt-1], data[address[countt-1]]);
    return 0;
}
