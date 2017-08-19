//ԭ������  https://www.patest.cn/contests/pat-a-practise/1004
//���  http://blog.csdn.net/whl_program/article/details/77284792
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
    vector<vector<int>> arr(100);//�洢�������ĺ���
    int res[100] = {0};//�洢����Ҷ�ӽ����Ŀ
    int maxDepth = 0;//������ ��1��ʼ����
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
    dfs(arr, res, maxDepth, 1, 0);// 1��ʾ���ڵ�id, 0��ʾ��ǰ���ǵ�0��
    cout << res[0];
    for(int i=1; i<=maxDepth; i++)
        cout << " " << res[i];
    return 0;
}
