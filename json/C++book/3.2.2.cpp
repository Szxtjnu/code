/*构造函数的默认参数*/

#include<iostream>
using namespace std;
class date
{
    public:
        date(int = 1, int = 1, int = 2021);
        void Display();
    private:
        int month;
        int day;
        int year;
};

date::date(int m, int d,int y):month(m),day(d),year(y) {}

void date::Display()
{
    cout << month << "/" << day << "/" << year << endl;
}

int main()
{
    date d1(10, 13, 2021);
    date d2(12, 30);
    date d3(10);
    date d4;
    d1.Display();
    d2.Display();
    d3.Display();
    d4.Display();
    return 0;
}
