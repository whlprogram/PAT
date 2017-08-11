#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int win[] = {0, 0, 0};
    int jia[] = {0, 0, 0};//B C J
    int yi[] = {0, 0, 0};//B C J
    char F[] = {'B', 'C', 'J'};
    for(int i=0; i<n; i++){
        char a,b;
        cin >> a >> b;
        if(a == b){//Æ½¾Ö
            win[1]++;
            continue;
        }
        if((a=='B'&&b=='C')||(a=='C'&&b=='J')||(a=='J'&&b=='B')){//¼×Ó®
            win[0]++;
            if(a=='B') jia[0]++;
            if(a=='C') jia[1]++;
            if(a=='J') jia[2]++;
        }
        if((a=='C'&&b=='B')||(a=='J'&&b=='C')||(a=='B'&&b=='J')){//ÒÒÓ®
            win[2]++;
            if(b=='B') yi[0]++;
            if(b=='C') yi[1]++;
            if(b=='J') yi[2]++;
        }
    }
    cout << win[0] << " " << win[1] << " " << win[2] << endl;
    cout << win[2] << " " << win[1] << " " << win[0] << endl;
    int jiaMax = 0,yiMax = 0;
    for(int i=1; i<3; i++){
        if(jia[jiaMax] < jia[i])
            jiaMax = i;
        if(yi[yiMax] < yi[i])
            yiMax = i;
    }
    cout << F[jiaMax] << " " << F[yiMax];
    return 0;
}
