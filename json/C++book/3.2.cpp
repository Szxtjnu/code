/*构造函数的重载*/

#include<iostream>
using namespace std;
class date
{
    public:
        date(int, int, int);
        date(int, int);
        date(int);
        date();
        void Display();
    private:
        int month;
        int day;
        int year;
};

date::date(int m,int d,int y):month(m),day(d),year(y) {}

date::date(int m,int d):month(m),day(d)
{
    year = 2021;
}
date::date(int m):month(m)
{
    year = 2021;
    day = 1;
}

date::date()
{
    year = 2021;
    day = 1;
    month = 1;
}

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
