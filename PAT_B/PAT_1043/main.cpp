#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int P=0,A=0,T=0,e=0,s=0,t=0;
    string str;
    cin >> str;
    int arr[6] = {0,0,0,0,0,0};//存储各个字母个数
    for(int i=0; i<str.length(); i++){
        int j=0;
        if(str[i]=='P') j=1;
        if(str[i]=='A') j=2;
        if(str[i]=='T') j=3;
        if(str[i]=='e') j=4;
        if(str[i]=='s') j=5;
        if(str[i]=='t') j=6;
        switch(j){//switch中的表达式必须是整型、字符或枚举量值
            case 1:{
                arr[0]++;
                break;
            }
            case 2:{
                arr[1]++;
                break;
            }
            case 3:{
                arr[2]++;
                break;
            }
            case 4:{
                arr[3]++;
                break;
            }
            case 5:{
                arr[4]++;
                break;
            }
            case 6:{
                arr[5]++;
                break;
            }
        }
    }
    int arr_MAX = arr[0];
    for(int i=1; i<6; i++){
        if(arr[i]>arr_MAX)
            arr_MAX = arr[i];
    }
    string res = "";
    for(int i=1; i<=arr_MAX; i++){
        if(arr[0] != 0){
            res += 'P';
            arr[0]--;
        }
        if(arr[1] != 0){
            res += 'A';
            arr[1]--;
        }
        if(arr[2] != 0){
            res += 'T';
            arr[2]--;
        }
        if(arr[3] != 0){
            res += 'e';
            arr[3]--;
        }
        if(arr[4] != 0){
            res += 's';
            arr[4]--;
        }
        if(arr[5] != 0){
            res += 't';
            arr[5]--;
        }
    }
    cout << res << endl;
    return 0;
}
