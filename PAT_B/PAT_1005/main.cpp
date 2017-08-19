//原题链接  https://www.patest.cn/contests/pat-b-practise/1005
//题解  http://blog.csdn.net/whl_program/article/details/76644119

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res(301);//输入可能是99，所以定义长度为301
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        if(res[temp] > 0){//该数已经验证过，随后的数也都验证过
            continue;
        }
        res[temp]++;//该数暂定为关键字
        while(temp != 1){
            if(temp%2 == 1){
                temp = 3*temp+1;
            }
            temp /= 2;
            if(res[temp] > 0){//该数已经验证过，随后的数也都验证过
                res[temp] += 2;
                break;
            }
            res[temp] += 2;//该数不是关键字
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
