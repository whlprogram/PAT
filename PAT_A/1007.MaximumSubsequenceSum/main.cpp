//ԭ������  https://www.patest.cn/contests/pat-a-practise/1007
//���    http://blog.csdn.net/whl_program/article/details/77431896
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum=-1;//������������к�
    int tempsum=0;//��ʱ�����������к�
    int left=0;//������������±�
    int right=0;//������������±�
    int index=0;//��ʱ���������±�
    bool flag = true;//�����Ƿ�ȫ�Ǹ���
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] >= 0)
            flag = false;
        tempsum += arr[i];
        if(tempsum > sum){
            sum = tempsum;
            left = index;
            right = i;
        }else if(tempsum < 0){//�����ʱ���к��Ѿ�С��sum������»��Ǹ�����Ӧ������֮ǰ������
            index = i+1;
            tempsum = 0;
        }
    }
    if(flag){
        printf("0 %d %d", arr[0], arr[n-1]);
    }else{
        printf("%d %d %d", sum, arr[left], arr[right]);
    }
    return 0;
}
