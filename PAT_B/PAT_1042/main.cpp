//原题链接 https://www.patest.cn/contests/pat-b-practise/1042
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int len = str.size();
    for(int i=0; i<len; i++)
        str[i] = tolower(str[i]);//大写字母转换为小写字母
    int HASH[26] = {0};
    for(int i=0; i<len; i++){
        if(str[i]>='a' && str[i]<='z'){
            HASH[str[i]-'a']++;
        }
    }
    int MAX = 0;
    for(int i=1; i<26; i++){
        if(HASH[i] > HASH[MAX]){
            MAX = i;
        }
    }
    char temp = MAX + 'a';
    cout << temp << " " << HASH[MAX] << endl;
    return 0;
}
