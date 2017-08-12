#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(100001);
    int maxSocre=0;//最高分
    int maxSchool;//最高分学校
    for(int i=0; i<n; i++){
        int school, score;
        cin >> school >> score;
        arr[school] += score;
        if(arr[school] > maxSocre){
            maxSocre = arr[school];
            maxSchool = school;
        }
    }
    cout << maxSchool << " " << maxSocre << endl;
    return 0;
}
