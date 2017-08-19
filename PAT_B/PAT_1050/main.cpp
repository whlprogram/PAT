//ԭ������  https://www.patest.cn/contests/pat-b-practise/1050
//���    http://blog.csdn.net/whl_program/article/details/76691299

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b){
    return a > b;
}
int findn(int N){
    int i = sqrt((double)N);//i��С��N��ƽ��������ӽ�N��ƽ��������
    while(i >= 1){
        if(N%i == 0)
            return i;
        i--;
    }
    return 1;
}
int main()
{
    int N;
    cin >> N;
    int n = findn(N);
    int m = N/n;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp);//��������
    vector<vector<int>> res(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[i][j] = 0;
        }
    }
    int i=0,j=0,k=0;
    res[i][j] = arr[k];//Ϊ���Ժ�ֵ�����Ƚ���һ��Ԫ�ظ�ֵ
    k++;
    while(k < N){
        while(j<n-1 && res[i][j+1]==0){//���Ҹ�ֵ && ������ֵ��λ��û������ֵ
            j++;//�������λ�ã�ʡȥ��һ��whileѭ����j--
            res[i][j] = arr[k];
            k++;
        }
        while(i<m-1 && res[i+1][j]==0){//���¸�ֵ && ������ֵ��λ��û������ֵ
            i++;
            res[i][j] = arr[k];
            k++;
        }
        while(j>0 && res[i][j-1]==0){//����ֵ && ������ֵ��λ��û������ֵ
            j--;
            res[i][j] = arr[k];
            k++;
        }
        while(i>0 && res[i-1][j]==0){//���ϸ�ֵ && ������ֵ��λ��û������ֵ
            i--;
            res[i][j] = arr[k];
            k++;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(j != 0)
                cout <<" ";
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
