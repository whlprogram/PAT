//ԭ������  https://www.patest.cn/contests/pat-b-practise/1059
//���  http://blog.csdn.net/whl_program/article/details/76639120

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool isPrimeNum(int i){
    for(int j=2; j*j<=i; j++){//j*j����Ҫ����������ʱ��
        if(i%j == 0){
            return false;
        }
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    vector<int> arr(10001);
    for(int i=1; i<=N; i++){//��¼ÿ��id����
        int id;
        cin >> id;
        arr[id] = i;
    }
    int K;
    cin >> K;
    vector<int> aa(10001);//��¼ÿ��id��û�������Ʒ
    vector<int> res(K);
    for(int i=0; i<K; i++){
        cin >> res[i];//����Ҫ���ҵ�Id
    }
    for(int i=0; i<res.size(); i++){
        printf("%04d", res[i]);
        printf(": ");
        if(arr[res[i]] == 0){//���idû������
            cout << "Are you kidding?" << endl;
            continue;
        }
        if(aa[res[i]] == 1){//���id�����Ʒ
            cout << "Checked" << endl;
            continue;
        }
        if(aa[res[i]] == 0){//���id��û�������Ʒ
            if(arr[res[i]] == 1){
                cout << "Mystery Award" << endl;

            }
            else if(isPrimeNum(arr[res[i]])){
                cout << "Minion" << endl;
            }
            else
                cout << "Chocolate" << endl;
            aa[res[i]] = 1;
        }
    }
    return 0;
}
