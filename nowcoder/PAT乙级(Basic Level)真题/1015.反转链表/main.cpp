#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int first,n,k;
    scanf("%05d %d %d", &first, &n, &k);
    int data[100000];
    int next[100000];
    int address[100000];
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int countt = 0;//��Ч�ڵ�����(����ڵ�������һ��ȫ����Ч)
    while(first != -1){
        address[countt] = first;
        first = next[first];
        countt++;
    }
    int m = countt - countt%k;//��Ҫ��ת�Ľڵ���
    for(int i=0; i<m; i+=k){
        reverse(begin(address)+i,begin(address)+i+k);
    }
    for(int i=0; i<countt-1; i++)
        printf("%05d %d %05d\n", address[i], data[address[i]], address[i+1]);
    printf("%05d %d -1", address[countt-1], data[address[countt-1]]);
    return 0;
}
