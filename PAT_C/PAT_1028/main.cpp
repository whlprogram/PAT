//原题链接 https://www.patest.cn/contests/pat-b-practise/1028
//题解    http://blog.csdn.net/whl_program/article/details/76696952

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    int maxYear=0,maxMonth=0,maxDay=0,minYear=9999,minMonth=9999,minDay=9999;
    string maxName,minName;
    for(int i=0; i<n; i++){
        string name;
        int year, month, day;
        cin >> name;
        scanf("%d/%d/%d", &year, &month, &day);
        if((year<2014 || (year==2014&&month<9) || (year==2014&&month==9&&day<=6))
           && (year>1814 || (year==1814&&month>9) || (year==1814&&month==9&&day>=6))){
            res++;
            if(year<minYear || (year==minYear&&month<minMonth) || (year==minYear&&month==minMonth&&day<minDay)){
                minYear = year;
                minMonth = month;
                minDay = day;
                minName = name;
            }
            if(year>maxYear || (year==maxYear&&month>maxMonth) || (year==maxYear&&month==maxMonth&&day>maxDay)){
                maxYear = year;
                maxMonth = month;
                maxDay = day;
                maxName = name;
            }
        }
    }
    if(res != 0)
        cout << res << " " << minName << " " << maxName;
    else
        cout << res;
    return 0;
}
