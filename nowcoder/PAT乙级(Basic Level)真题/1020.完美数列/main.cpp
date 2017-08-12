#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b){return a<b;}
int getMax(int a, int b){return a>b ? a : b;}
int main()
{
    int n;
    long long p;
    cin >> n >> p;
    if(n == 0)
        return 0;
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);
    int res = 1;
    for(int i=0; i<n-1; i++){//��������arr[i]��Ϊ��С��
        for(int j=i+res; j<n; j++){//j��ΪҪ������Ը������г��ȵ�ֵ������ѭ������
            if(arr[i]*p < arr[j])//��������������ˣ�����һ��Ԫ��arr[i+1]��Ϊ��Сֵ
                break;
            res = getMax(res, j-i+1);//����˴εĳ��ȴ�����һ�Σ��������г���
        }
    }
    cout << res << endl;
    return 0;
}
