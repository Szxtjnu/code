#include<iostream>
using namespace std;
class Time
{
private:
    int hour;
    int minute;
    int sec;

public:
    Time(/* args */);
    ~Time();
    void set_time();
    void show_time();
};

Time::Time(/* args */)
{
}

Time::~Time()
{
}
void Time::set_time()
{
    cin >> hour >> minute >> sec;
}
void Time::show_time()
{
    cout << hour << ':' << minute << ':' << sec << endl;
}
int main()
{
    Time t;
    t.set_time();
    t.show_time();
    return 0;
}