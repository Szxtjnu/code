#include<iostream>
#include<cmath>
using namespace std;
class CR
{
    public:
        CR(float m = 0, float n = 0, float p = 1, float q = 1);
        bool isSquare();
        void PrintRe();
    private:
        float a, b, x, y;
};
CR ::CR(float a, float n, float p, float q)
{
    if((m == p)||(n == q))
    {
        a = b = 0;
        x = y = 1;
    }
    else {
        a = m;
        b = n;
        x = p;
        y = q;
    }
}

bool CR::isSquare()
{
    
}