//ԭ������ https://www.patest.cn/contests/pat-b-practise/1068
//��� http://blog.csdn.net/whl_program/article/details/76737983


#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
int m,n,tol;//�� �� ��ֵ
vector<vector<int>> v;
int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
bool judge(int i, int j){
    for(int k=0; k<8; k++){
        int x = i+arr[k][0];
        int y = j+arr[k][1];
        if(x>=0 && x<n && y>=0 && y<m && v[i][j]-v[x][y]>= 0-tol && v[i][j]-v[x][y]<=tol)
            return false;
    }
    return true;
}
int main()
{
    int cont=0, posX, posY;//�����������ص������λ��
    scanf("%d%d%d", &m, &n, &tol);
    v.resize(n, vector<int>(m));
    map<int, int> Map;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &v[i][j]);
            Map[v[i][j]]++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Map[v[i][j]]==1 && judge(i, j)==true){//��һ�޶��ҷ������ز��㹻��
                cont++;
                posX = i;
                posY = j;
            }
        }
    }
    if(cont == 1){
        printf("(%d, %d): %d", posY+1, posX+1, v[posX][posY]);
    }else if(cont > 1){
        printf("Not Unique");
    }else{
        printf("Not Exist");
    }
    return 0;
}
