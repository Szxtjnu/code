#include<iostream>
using namespace std;
void show(int a, int b = 2, int c = 3);
int main()
{
    show(1, 3, 5);
    show(2, 4);
    show(3);
    return 0;
}
void show(int a, int b, int c)
{
    cout << "a = " << a << ",b = " << b << ",c = " << c << endl;
}

