//ԭ������  https://www.patest.cn/contests/pat-b-practise/1035
//���  http://blog.csdn.net/whl_program/article/details/76652602

#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b){
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
    int i,j;
    for(i=0; i<n-1&&b[i]<=b[i+1]; i++);//�ж�b�����������һ��Ԫ���±�
    for(j=i+1; j<n; j++){//�жϺ���Ԫ���Ƿ���ԭ������ȣ�����ȫ��ͬ��Ϊ�������򣬷���Ϊ�鲢����
        if(a[j] != b[j])
            break;
    }
    if(j == n){ // ǰ�벿���������벿��δ�Ķ�����ȷ���ǲ�������
        cout << "Insertion Sort" << endl;
        sort(a, a+i+2, cmp);
    }else{
        cout << "Merge Sort" << endl;
        int k=1;//k��ʾ������Ϊ1,2,4,8...
        bool flag = false;
        while(!flag){
            flag = true;
            for(int i=0; i<n; i++){//���ж��Ƿ���ȣ��ٽ��й鲢��������Ϊ��Ļ����ں����ж�������һ�ι鲢����ѭ��
                if(a[i] != b[i])
                    flag = false;
            }
            for(int j=0; j<n; j+=k){
                int temp = j+k;
                if(temp>n) //�����Ԫ�ظ������㲽���������ΪN����
                    temp = n;
                sort(a+j, a+temp, cmp);
            }
            k *= 2;//����ÿ�γ���2
        }
    }
    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1];
    delete []a;
    delete []b;
    return 0;
}
