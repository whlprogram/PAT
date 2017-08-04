//原题链接  https://www.patest.cn/contests/pat-b-practise/1035
//题解  http://blog.csdn.net/whl_program/article/details/76652602

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
    for(i=0; i<n-1&&b[i]<=b[i+1]; i++);//判断b有序序列最后一个元素下标
    for(j=i+1; j<n; j++){//判断后面元素是否与原数组相等，若完全相同即为插入排序，否则为归并排序
        if(a[j] != b[j])
            break;
    }
    if(j == n){ // 前半部分有序而后半部分未改动可以确定是插入排序
        cout << "Insertion Sort" << endl;
        sort(a, a+i+2, cmp);
    }else{
        cout << "Merge Sort" << endl;
        int k=1;//k表示步长，为1,2,4,8...
        bool flag = false;
        while(!flag){
            flag = true;
            for(int i=0; i<n; i++){//先判断是否相等，再进行归并，这样若为真的话，在后面判断则会进行一次归并结束循环
                if(a[i] != b[i])
                    flag = false;
            }
            for(int j=0; j<n; j+=k){
                int temp = j+k;
                if(temp>n) //若最后元素个数不足步长，则最大为N即可
                    temp = n;
                sort(a+j, a+temp, cmp);
            }
            k *= 2;//步长每次乘以2
        }
    }
    for(int i=0; i<n-1; i++)
        cout << a[i] << " ";
    cout << a[n-1];
    delete []a;
    delete []b;
    return 0;
}
