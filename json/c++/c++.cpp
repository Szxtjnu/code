#include<iostream>
using namespace std;
float pi = 3.1415926;
class cir
{
    private:
        float r;
        float S1;
        float C1;

    public:
        void S(float r);
        void C(float r);
};
void cir::S(float r)
{
    S1 = ((pi * (r + 3) * (r + 3))-(pi * r * r))*20;
    cout << "The road money is: " << S1 << endl;
}
void cir::C(float r)
{
    C1 = pi * 2 * (r + 3) * 35;
    cout << "The fence money is: " << C1 << endl;
}

int main()
{
    float r = 0;
    cir pool;
    cin >> r;
    pool.C(r);
    pool.S(r);
    return 0;
}