//Ô­ÌâÁ´½Ó https://www.patest.cn/contests/pat-b-practise/1018
//Ìâ½â http://blog.csdn.net/whl_program/article/details/76594427
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    char arr[3] = {'B', 'C', 'J'};
    vector<int> JIA(3);
    vector<int> JIAWin(3);//B C J
    vector<int> YIWin(3);
    for(int i=0; i<N; i++){
        char a, b;
        cin >> a >> b;
        if((a=='B' && b=='C') || (a=='C' && b=='J') || (a=='J' && b=='B')){
            JIA[0]++;//¼×Ó®
            if(a=='B')    JIAWin[0]++;//¼×Ó® B
            if(a=='C')    JIAWin[1]++;//¼×Ó® C
            if(a=='J')    JIAWin[2]++;//¼×Ó® J
        }
        if((b=='B' && a=='C') || (b=='C' && a=='J') || (b=='J' && a=='B')){
            JIA[2]++;//¼×Êä
            if(b=='B')    YIWin[0]++;//ÒÒÓ® B
            if(b=='C')    YIWin[1]++;//ÒÒÓ® C
            if(b=='J')    YIWin[2]++;//ÒÒÓ® J
        }
        if((a=='B' && b=='B') || (a=='C' && b=='C') || (a=='J' && b=='J'))
            JIA[1]++;//Æ½¾Ö
    }
    int JIAMAX=0;
    int YIMAX=0;
    for(int j=1; j<JIAWin.size(); j++){
        if(JIAWin[JIAMAX] < JIAWin[j])
            JIAMAX = j;
    }
    for(int j=1; j<YIWin.size(); j++){
        if(YIWin[YIMAX] < YIWin[j])
            YIMAX = j;
    }
    for(int i=0; i<JIA.size(); i++){
        if(i != 0)
            cout << " ";
        cout << JIA[i];
    }
    cout << endl;
    for(int i=JIA.size()-1; i>=0; i--){
        if(i != (JIA.size()-1))
            cout << " ";
        cout << JIA[i];
    }
    cout << endl;
    cout << arr[JIAMAX] << " " << arr[YIMAX] << endl;
    return 0;
}
