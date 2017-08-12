#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxYear=0,maxMouth=0,maxDay=0,minYear=9999,minMouth=9999,minDay=9999;
    string maxName,minName;
    int countt=0;
    for(int i=0; i<n; i++){
        string name;
        int year,mouth,day;
        cin >> name;
        scanf("%04d/%02d/%02d", &year, &mouth, &day);
        if(year>2014 || (year==2014&&mouth>9) || (year==2014&&mouth==9&&day>6)
           || year<1814 || (year==1814&&mouth<9) || (year==1814&&mouth==9&&day<6))
            continue;
        if(year>maxYear || (year==maxYear&&mouth>maxMouth) || (year==maxYear&&mouth==maxMouth&&day>maxDay)){
            maxYear = year;
            maxMouth = mouth;
            maxDay = day;
            maxName = name;
        }
        if(year<minYear || (year==minYear&&mouth<minMouth) || (year==minYear&&mouth==minMouth&&day<minDay)){
            minYear = year;
            minMouth = mouth;
            minDay = day;
            minName = name;
        }
        countt++;
    }
    cout << countt << " " << minName << " "  << maxName << endl;
    return 0;
}
