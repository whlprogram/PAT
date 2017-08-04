//原题链接 https://www.patest.cn/contests/pat-b-practise/1015
//题解    http://blog.csdn.net/whl_program/article/details/76696939

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int num;
    int de;
    int cai;
};
int cmp(struct node a, struct node b){
    if((a.de+a.cai) != (b.de+b.cai)){
        return (a.de+a.cai) > (b.de+b.cai);
    }else if(a.de != b.de){
        return a.de > b.de;
    }else{
        return a.num < b.num;
    }
}
int main()
{
    int n, low, high;
    scanf("%d %d %d", &n, &low, &high);
    vector<node> a,b,c,d;//录取分四类人
    int res = n;
    for(int i=0; i<n; i++){
        node temp;
        scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
        if(temp.de<low || temp.cai<low){
            res--;
            continue;
        }else if(temp.de>=high && temp.cai>=high){
            a.push_back(temp);
        }else if(temp.de>=high && temp.cai<high){
            b.push_back(temp);
        }else if(temp.de<high && temp.cai<high && temp.de>=temp.cai){
            c.push_back(temp);
        }else{
            d.push_back(temp);
        }
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    sort(c.begin(), c.end(), cmp);
    sort(d.begin(), d.end(), cmp);
    printf("%d\n", res);
    for(int i=0; i<a.size(); i++)
        printf("%d %d %d\n", a[i].num, a[i].de, a[i].cai);
    for(int i=0; i<b.size(); i++)
        printf("%d %d %d\n", b[i].num, b[i].de, b[i].cai);
    for(int i=0; i<c.size(); i++)
        printf("%d %d %d\n", c[i].num, c[i].de, c[i].cai);
    for(int i=0; i<d.size(); i++)
        printf("%d %d %d\n", d[i].num, d[i].de, d[i].cai);
    return 0;
}
