//题解http://blog.csdn.net/whl_program/article/details/77535304
//原题链接 https://www.patest.cn/contests/pat-a-practise/1010
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
map<char, int> Map;//各个字符对应一个数字
string n1,n2;
int tag, radix;
vector<long long> ans;
long long toTen(string s, long long radix){//将radix进制转化为10进制数
    long long res = 0;
    for(int i=0; i<s.size(); i++){
        res = res*radix + Map[s[i]];
    }
    return res;
}
long long findLow(string s){//找出另一个数的基数下限
    long long res = -1;
    for(int i=0; i<s.size(); i++){
        if(Map[s[i]] > res)
            res = Map[s[i]];
    }
    return res+1;
}
int cmp(string n2, long long radix, long long t){//判断基数是否符合条件
    long long num = toTen(n2, radix);
    if(num < 0)//很重要
        return 1;
    if(num < t)//基数偏小
        return -1;
    else if (num > t)//基数偏大
        return 1;
    else
        return 0;//基数符合条件
}
long long binarySearch(string n2, long long left, long long right,long long t){//二分查找寻找符合条件基数
    long long mid;
    while(left <= right){
        mid = (right+left)/2;
        int flag = cmp(n2, mid, t);//判断基数是否符合条件
        if(flag == 0){
            ans.push_back(mid);
            right = mid - 1;
        }else if(flag == 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if(ans.size() == 0)
        return -1;
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    for(char c='0'; c<='9'; c++)
        Map[c] = c-'0';
    for(char c='a'; c<='z'; c++)
        Map[c] = c-'a'+10;
    cin >> n1 >> n2 >> tag >> radix;
    if(tag == 2){
        string temp = n1;
        n1 = n2;
        n2 = temp;
    }
    long long t = toTen(n1, radix);//将给出基数的数转化为十进制数
    long long low = findLow(n2);//找出另一个数的基数下限
    long long high = low>t ? low+1 : t+1;//找出另一个数的基数上限
    long long res = binarySearch(n2, low, high, t);//二分查找寻找符合条件基数
    if(res == -1)
        printf("Impossible");
    else
        printf("%lld", res);
    return 0;
}
