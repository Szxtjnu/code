#include<iostream>
using namespace std;
class rectangle 
{
    private:
        int length;
        int width;
    public:
        rectangle(int l, int w) : length(l), width(w){};
        void display();
        bool operator>(rectangle);
};
void rectangle::display()
{
    cout << "面积=" << length * width << endl;
}
bool rectangle::operator>(rectangle rr)
{
    return width * length > rr.width * rr.length ? 1 : 0;
}
int main()
{
    rectangle r1(5, 6), r2(4, 8);
    cout << "r1";
    r1.display();
    cout << "r2";
    r2.display();
    if(r1>r2)
        cout << "r1>r2" << endl;
    else
        cout << "r1<r2" << endl;
}