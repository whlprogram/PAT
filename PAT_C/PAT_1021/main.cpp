//‘≠Ã‚¡¥Ω” https://www.patest.cn/contests/pat-b-practise/1021

#include <iostream>
using namespace std;

int main()
{
    string num;
    cin >> num;
    int HASH[10] = {0};
    for(int i=0; i<num.size(); i++){
        if(num[i] == '0')       HASH[0]++;
        else if(num[i] == '1')  HASH[1]++;
        else if(num[i] == '2')  HASH[2]++;
        else if(num[i] == '3')  HASH[3]++;
        else if(num[i] == '4')  HASH[4]++;
        else if(num[i] == '5')  HASH[5]++;
        else if(num[i] == '6')  HASH[6]++;
        else if(num[i] == '7')  HASH[7]++;
        else if(num[i] == '8')  HASH[8]++;
        else                    HASH[9]++;
    }
    for(int i=0; i<=9; i++)
        if(HASH[i] != 0)
            cout << i << ":" << HASH[i] << endl;
    return 0;
}
