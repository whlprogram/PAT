//原题链接 https://www.patest.cn/contests/pat-b-practise/1058
//题解 http://blog.csdn.net/whl_program/article/details/76601925


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> fullScore(M+1);//存储每道题满分值
    vector<string> answer(M+1);//存储每道题正确答案
    vector<int> stuScore(N+1);//存储每个学生所得分数
    vector<int> wrong(M+1);//存储每道题错误次数
    for(int i=1; i<=M; i++){
        int score,k,p;
        string temp="";
        cin >> score >> k >> p;
        fullScore[i] = score;
        for(int t=0; t<p; t++){
            char c;
            cin >> c;
            temp += c;
        }
        answer[i] = temp;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            char c1,c2;//输入的括号
            int a;//选中的选项个数
            cin >> c1 >> a;
            string ans;
            for(int s=0; s<a; s++){
                char tt;//输入选中的选项
                cin >> tt;
                ans += tt;
            }
            if(ans == answer[j])
                stuScore[i] += fullScore[j];
            else
                wrong[j]++;
            cin >> c2;//输入的右半括号
        }
    }
    for(int i=1; i<stuScore.size(); i++)
        cout << stuScore[i] << endl;
    int Max = 1;
    for(int i=2; i<wrong.size(); i++){
        if(wrong[Max] < wrong[i])
            Max = i;
    }
    if(wrong[Max] == 0){
        cout << "Too simple" << endl;
        return 0;
    }
    cout << wrong[Max] << " " << Max;
    for(int i=Max+1; i<wrong.size(); i++){
        if(wrong[Max] == wrong[i])
            cout << " " << i;
    }
    return 0;
}
