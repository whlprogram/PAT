//原题链接 https://www.patest.cn/contests/pat-a-practise/1006
//题解    http://blog.csdn.net/whl_program/article/details/77415014
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    int m;
    scanf("%d", &m);
    string unlock_ID="",lock_ID="";//开门的人,锁门的人
    int unlock_time = 86400;//开门时间
    int lock_time = 0;//锁门时间
    for(int i=0; i<m; i++){
        string ID_number;
        cin >> ID_number;
        int h1,h2,m1,m2,s1,s2;
        scanf("%02d:%02d:%02d %02d:%02d:%02d", &h1, &m1, &s1, &h2, &m2, &s2);
        int timeIn = h1*3600+m1*60+s1;//转化成秒
        int timeOut = h2*3600+m2*60+s2;
        if(timeIn <= unlock_time){//如果此人来得更早，此人开门,更新开门时间
            unlock_ID = ID_number;
            unlock_time = timeIn;
        }
        if(timeOut >= lock_time){//如果此人走得更晚，此人锁门,更新锁门时间
            lock_ID = ID_number;
            lock_time = timeOut;
        }
    }
    cout << unlock_ID << " " << lock_ID;
    return 0;
}
/*
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct time{
    int hh;
    int mm;
    int ss;
};
bool isEarlier(time aa, time bb){
    if(aa.hh<=bb.hh || (aa.hh==bb.hh&&aa.mm<=bb.mm) || (aa.hh==bb.hh&&aa.mm==bb.mm&&aa.ss<=bb.ss))
        return true;
    return false;
}
int main()
{
    int m;
    scanf("%d", &m);
    string unlock_ID="",lock_ID="";//开门的人,锁门的人
    time unlock_time,lock_time;//开门时间,锁门时间
    unlock_time.hh = 23;
    unlock_time.mm = 59;
    unlock_time.ss = 59;
    lock_time.hh = 0;
    lock_time.mm = 0;
    lock_time.ss = 0;
    for(int i=0; i<m; i++){
        string ID_number;
        cin >> ID_number;
        time a; time b;
        scanf("%02d:%02d:%02d %02d:%02d:%02d", &a.hh, &a.mm, &a.ss, &b.hh, &b.mm, &b.ss);
        if(isEarlier(a, unlock_time)){//如果此人来得更早，此人开门,更新开门时间
            unlock_ID = ID_number;
            unlock_time = a;
        }
        if(isEarlier(lock_time, b)){//如果此人走得更晚，此人锁门,更新锁门时间
            lock_ID = ID_number;
            lock_time = b;
        }
    }
    cout << unlock_ID << " " << lock_ID;
    return 0;
}
*/
