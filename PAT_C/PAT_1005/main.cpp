//ԭ������  https://www.patest.cn/contests/pat-b-practise/1005
//���  http://blog.csdn.net/whl_program/article/details/76644119

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res(301);//���������99�����Զ��峤��Ϊ301
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        if(res[temp] > 0){//�����Ѿ���֤����������Ҳ����֤��
            continue;
        }
        res[temp]++;//�����ݶ�Ϊ�ؼ���
        while(temp != 1){
            if(temp%2 == 1){
                temp = 3*temp+1;
            }
            temp /= 2;
            if(res[temp] > 0){//�����Ѿ���֤����������Ҳ����֤��
                res[temp] += 2;
                break;
            }
            res[temp] += 2;//�������ǹؼ���
        }
    }
    bool a = true;
    for(int i=res.size()-1; i>1; i--){
        if(res[i] == 1){
            if(!a)
                cout << " ";
            cout << i;
            a = false;
        }
    }
    return 0;
}
