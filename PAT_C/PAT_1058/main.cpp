//ԭ������ https://www.patest.cn/contests/pat-b-practise/1058
//��� http://blog.csdn.net/whl_program/article/details/76601925


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> fullScore(M+1);//�洢ÿ��������ֵ
    vector<string> answer(M+1);//�洢ÿ������ȷ��
    vector<int> stuScore(N+1);//�洢ÿ��ѧ�����÷���
    vector<int> wrong(M+1);//�洢ÿ����������
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
            char c1,c2;//���������
            int a;//ѡ�е�ѡ�����
            cin >> c1 >> a;
            string ans;
            for(int s=0; s<a; s++){
                char tt;//����ѡ�е�ѡ��
                cin >> tt;
                ans += tt;
            }
            if(ans == answer[j])
                stuScore[i] += fullScore[j];
            else
                wrong[j]++;
            cin >> c2;//������Ұ�����
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
