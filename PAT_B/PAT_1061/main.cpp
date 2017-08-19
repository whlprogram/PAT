#include <iostream>
#include <vector>
using namespace std;
vector<int> help(int Stu, vector<int> FullScore, vector<int> CorrectAnswer, vector<vector<int>> arr){
    vector<int> res(Stu);
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++){
            if(arr[i][j] == CorrectAnswer[j])
                res[i] += FullScore[j];
        }
    return res;
}
int main()
{
    int Stu,Num;
    cin >> Stu >> Num;
    vector<int> FullScore(Num);//����ֵ����
    for(int i=0; i<FullScore.size(); i++)
        cin >> FullScore[i];
    vector<int> CorrectAnswer(Num);//��ȷ������
    for(int i=0; i<CorrectAnswer.size(); i++)
        cin >> CorrectAnswer[i];
    vector< vector<int> > arr(Stu);//ѧ���𰸶�ά����
    for(int i=0; i<arr.size(); i++)
        arr[i].resize(Num);
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++)
            cin >> arr[i][j];
    vector<int> res = help(Stu, FullScore, CorrectAnswer, arr);
    for(int i=0; i<res.size(); i++)
         cout << res[i] << endl;
    return 0;
}

