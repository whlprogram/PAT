//原题链接 https://www.patest.cn/contests/pat-b-practise/1065
//题解    http://blog.csdn.net/whl_program/article/details/76696573

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> Map;//存储每对夫妻
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%05d %05d", &a, &b);
        Map[a] = b;
        Map[b] = a;
    }
    int m;
    cin >> m;
    int arr[100000] = {0};
    for(int i=0; i<m; i++){
        int temp;
        scanf("%05d", &temp);
        arr[temp] = 1;//来参加派对的人为1
    }
    vector<int> res;
    for(int i=0; i<100000; i++){
        if(arr[i]!=0 && arr[Map[i]]==0){//自己来参加派对的人并且对象没来
            res.push_back(i);
        }
    }
    printf("%d\n", res.size());
    for(int i=0; i<res.size(); i++){
        if(i!=0)
            printf(" ");
        printf("%05d", res[i]);
    }
    return 0;
}
