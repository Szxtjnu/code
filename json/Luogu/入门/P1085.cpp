#include<iostream>
using namespace std;
struct Time{
    int school;
    int partTime;
    int total;
};
int main() {
    Time time[10];
    int temp;
    int idx = 0;
    for(int i = 1; i <= 7; i++){
        cin >> time[i].school >> time[i].partTime;
        time[i].total = time[i].school + time[i].partTime;
    }
    temp = time[1].total;
    for(int i = 1; i <= 7; i++) {
        if(time[i].total>temp){
            temp = time[i].total;
            idx = i;
        }
    }
    cout << idx;
    return 0;
}