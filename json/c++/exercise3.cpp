#include<iostream>
using namespace std;
class CClock;
ostream &operator<<(ostream &os, const CClock &rhs);
class CClock
{
    private:
        int hour;
        int minute;
        int sec;
    public:
        CClock(){};
        CClock(int h, int m, int s) : hour(h), minute(m), sec(s) {};
        void Set(int , int , int );
        bool equal(const CClock &rhs)
        {
            return (hour == rhs.hour && minute == rhs.minute && sec == rhs.sec);
        }
        CClock operator++(){
            sec++;
            if(sec>=60)
            {
                sec -= 60;
                minute++;
                if(minute == 60)
                {
                    hour++;
                    minute = 0;
                    if(hour == 24)
                        hour = 0;
                }
            }
            return *this;
        }
        CClock operator++(int)
        {
            CClock tmp(*this);
            ++*this;
            return tmp;
        }
        friend ostream &operator<<(ostream &os, const CClock &rhs);
};
ostream & operator<<(ostream &os, const CClock &rhs)
{
    os << rhs.hour << ":" << rhs.minute << ":" << rhs.sec ;
    return os;
}
void CClock::Set(int h,int m,int s)
{
    hour = h;
    minute = m;
    sec = s;
}
int main()
{
    CClock t1, t2(12, 0, 1);
    t1.Set(11, 59, 59);
    cout << t1 << endl;
    cout << t2 << endl;
    CClock t3;
    t3 = ++t1;
    cout << t3 << endl;
    t3 = t1++;
    cout << t3 << endl;
    if(t1.equal(t2))
        cout << "Equal" << endl;
    return 0;
}