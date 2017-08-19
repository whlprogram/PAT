//原题链接  https://www.patest.cn/contests/pat-a-practise/1004
//题解  http://blog.csdn.net/whl_program/article/details/77284792
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& arr, int (&res)[100], int &maxDepth, int index, int depth){
    if(arr[index].size() == 0){
        res[depth]++;
        maxDepth = maxDepth>depth ? maxDepth : depth;
        return;
    }
    for(int i=0; i<arr[index].size(); i++)
        dfs(arr, res, maxDepth, arr[index][i], depth+1);
}
int main()
{
    vector<vector<int>> arr(100);//存储各个结点的孩子
    int res[100] = {0};//存储各层叶子结点数目
    int maxDepth = 0;//最大深度 从1开始计数
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int id,k;
        cin >> id >> k;
        for(int j=1; j<=k; j++){
            int temp;
            cin >> temp;
            arr[id].push_back(temp);
        }
    }
    dfs(arr, res, maxDepth, 1, 0);// 1表示根节点id, 0表示当前层是第0层
    cout << res[0];
    for(int i=1; i<=maxDepth; i++)
        cout << " " << res[i];
    return 0;
}
