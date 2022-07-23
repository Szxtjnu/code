#include<iostream>
using namespace std;
class CR
{
    public:
        void move(int, int);
        void size(int, int);
        void where(int&, int&);
        double area();
        CR(int px,int py,int wid ,int hi)
        {
            position_x = px;
            position_y = py;
            width = wid;
            high = hi;
        }
    private:
        int position_x, position_y, width, high;
};

void CR::move(int x, int y)
{
    position_x = x;
    position_y = y;
}

void CR::size(int widthNum,int highNum)
{
    width = widthNum;
    high = highNum;
}

void CR::where(int &x, int &y)
{
    x = position_x;
    y = position_y;
}

double CR::area()
{
    return (width * high);
}

int main()
{
    CR cr1(0,0,50,50);
    cout << cr1.area() << endl;
    return 0;
}