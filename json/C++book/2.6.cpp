#include<iostream>
using namespace std;
class Box
{
    public:
        void setDate();
        void Volume();
    private:
        float length;
        float width;
        float height;
        float value;
};

void Box::setDate()
{
    cin >> length >> width >> height;
}

void Box::Volume()
{
    cout << (length * width * height) << endl;
}

int main()
{
    Box t1, t2, t3;
    t1.setDate();
    t1.Volume();
    t2.setDate();
    t2.Volume();
    t3.setDate();
    t3.Volume();
    return 0;
}