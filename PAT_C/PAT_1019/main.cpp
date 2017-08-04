//ԭ������  https://www.patest.cn/contests/pat-b-practise/1019
//���  http://blog.csdn.net/whl_program/article/details/76652841

#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n%1111 == 0){
        printf("%04d", n);
        printf(" - ");
        printf("%04d", n);
        printf(" = 0000\n");
        return 0;
    }
    do{//��ĿҪ��ֱ��6174��Ϊ����ֲ�ֹͣ����ʹ����6174Ҳ�ý������¹���
        int arr[4] = {n/1000, n/100%10, n/10%10, n%10};
        sort(arr, arr+4);//����
        int t1, t2;
        t1 = arr[3]*1000 + arr[2]*100 + arr[1]*10 + arr[0];
        t2 = arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
        n = t1 - t2;
        printf("%04d", t1);
        printf(" - ");
        printf("%04d", t2);
        printf(" = %04d\n", n);
    }while(n != 6174);

    return 0;
}
