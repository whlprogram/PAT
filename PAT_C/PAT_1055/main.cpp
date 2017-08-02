//ԭ������ https://www.patest.cn/contests/pat-b-practise/1055
//��� http://blog.csdn.net/whl_program/article/details/76599746

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct node{
    string name;
    int height;
};
int cmp(struct node a, struct node b){
    return a.height != b.height ? a.height>b.height : a.name<b.name;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<node> stu(n);
    for(int i=0; i<n; i++){
        cin >> stu[i].name;
        cin >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    int t=0,row=k;
    while(row){
        int m;
        if(row == k)
            m = n-n/k*(k-1);
        else
            m = n/k;
        vector<string> str(m);
        str[m/2] = stu[t].name;
        //��ǰ�ŵ����
        int j = m/2-1;
        for(int i=t+1; i<t+m; i+=2)
            str[j--] = stu[i].name;
        //��ǰ�ŵ��ұ�
        j = m/2+1;
        for(int i=t+2; i<t+m; i+=2)
            str[j++] = stu[i].name;
        //�����ǰ��
        cout << str[0];
        for(int p=1; p<str.size(); p++)
            cout << " " << str[p];
        cout << endl;
        t += m;
        row--;
    }
    return 0;
}
