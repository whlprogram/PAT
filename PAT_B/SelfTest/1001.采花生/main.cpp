//原题链接 https://www.nowcoder.com/pat/2/problem/249
//题解  http://blog.csdn.net/whl_program/article/details/77347579
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct node{
    int x;
    int y;
};
void sort(vector<int> &v, vector<node> &pos){
    int vlen = v.size();
    for(int i=0; i<vlen-1; i++){
        for(int j=i+1; j<vlen; j++){
            if(v[i] < v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;

                node temp1 = pos[i];
                pos[i] = pos[j];
                pos[j] = temp1;
            }
        }
    }
}
int len(node a, node b){//两坐标点间距离
    int m=0, n=0;
    m = a.x-b.x>0 ? a.x-b.x : b.x-a.x;
    n = a.y-b.y>0 ? a.y-b.y : b.y-a.y;
    return m+n;
}
int main()
{
    int m,n,k;
    while(~scanf("%d %d %d", &m, &n, &k)){
        if(k == 0){
            cout << 0;
            return 0;
        }
        int arr[m+1][n+1];
        vector<int> v;//地下有花生的个数
        vector<node> pos;//地下有花生的坐标
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                cin >> arr[i][j];
                if(arr[i][j] != 0){
                    v.push_back(arr[i][j]);
                    node temp;
                    temp.x = i;
                    temp.y = j;
                    pos.push_back(temp);
                }
            }
        }
        if(v.size() == 0){
            cout << 0;
            return 0;
        }
        sort(v, pos);//按照采摘顺序（花生数目从大到小）排序
        int res=0;//最大采摘数目
        node a; a.x = 0; a.y = pos[0].y;//起始位置
        int vlen = v.size();
        for(int i=0; i<vlen; i++){
            if(k >= len(pos[i],a)+1+pos[i].x){
                res += v[i];
                k -= len(pos[i],a)+1;//采摘时间减少
                a.x = pos[i].x;//获取新的起始位置
                a.y = pos[i].y;
            }else{
                break;
            }
        }
        cout << res;
    }

    return 0;
}
