#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    cin >> s1;
    char n = 0;
    n = s1.size();
    for (char i = n - 1; i >= 0; --i)
    {
        cout << s1[i];
    }
    return 0;
}