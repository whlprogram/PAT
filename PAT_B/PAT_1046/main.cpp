#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);//����N
    //�����ά����ṹ
    vector< vector<int> > arr(N);
    for(int i=0; i<arr.size(); i++)
        arr[i].resize(4);
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++)
            scanf("%d", &arr[i][j]);
    int a=0,b=0;//a��ʾ�׺ȾƱ���  a��ʾ�ҺȾƱ���
    for(int i=0; i<arr.size(); i++){
        int sum = arr[i][0]+arr[i][2];
        if(sum == arr[i][1] && sum != arr[i][3])
            b++;
        if(sum != arr[i][1] && sum == arr[i][3])
            a++;
    }
    printf("%d %d", a, b);
    return 0;
}
