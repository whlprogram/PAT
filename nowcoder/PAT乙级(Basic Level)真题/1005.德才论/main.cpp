#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id;
    int de;
    int cai;
};
int cmp(struct node a, struct node b){
    if(a.de+a.cai != b.de+b.cai)
        return a.de+a.cai > b.de+b.cai;
    else if(a.de != b.de)
        return a.de > b.de;
    else
        return a.id < b.id;
}
int main()
{
    int N,L,H;
    cin >> N >> L >> H;
    vector<node> first;
    vector<node> second;
    vector<node> third;
    vector<node> fourth;
    int countt = 0;
    for(int i=0; i<N; i++){
        node temp;
        cin >> temp.id >> temp.de >> temp.cai;
        if(temp.cai<L || temp.de<L)
            continue;
        if(temp.cai>=H && temp.de>=H){
            first.push_back(temp);
            countt++;
            continue;
        }
        if(temp.cai<H && temp.de>=H){
            second.push_back(temp);
            countt++;
            continue;
        }
        if(temp.cai<H && temp.de<H && temp.de>=temp.cai){
            third.push_back(temp);
            countt++;
            continue;
        }
        fourth.push_back(temp);
        countt++;
    }
    sort(first.begin(), first.end(), cmp);
    sort(second.begin(), second.end(), cmp);
    sort(third.begin(), third.end(), cmp);
    sort(fourth.begin(), fourth.end(), cmp);
    cout << countt << endl;
    for(int i=0; i<first.size(); i++)
        cout << first[i].id << " " << first[i].de << " " << first[i].cai << endl;
    for(int i=0; i<second.size(); i++)
        cout << second[i].id << " " << second[i].de << " " << second[i].cai << endl;
    for(int i=0; i<third.size(); i++)
        cout << third[i].id << " " << third[i].de << " " << third[i].cai << endl;
    for(int i=0; i<fourth.size(); i++)
        cout << fourth[i].id << " " << fourth[i].de << " " << fourth[i].cai << endl;
    return 0;
}
