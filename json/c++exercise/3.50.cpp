#include<iostream>
using namespace std;
class CRectangle
{
    private:
        int length;
        int weight;

    public:
        CRectangle(int l = 1, int w = 1)
        {
            set(l, w);
        }
        void set(int , int);
        void Perimeter();
};

void CRectangle::set(int l, int w)
{
    cin >> length >> weight;
    if(length <= 0 && length >=50)
        length = 1;
    if(weight <= 0 && weight >=50)
        weight = 1;
}

void CRectangle::Perimeter()
{
    cout << (length * 2 + weight * 2) << endl;
}

int main()
{
    CRectangle tangle1;
    tangle1.set();
    tangle1.Perimeter();
    return 0;
}