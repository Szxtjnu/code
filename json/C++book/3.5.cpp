#include<iostream>
using namespace std;
class student
{
    public:
        student(int n, float s) : number(n), score(s){}
        void display();
        void max();
        int number;
        float score;
};

void student::display()
{
    cout << number << "   " << score << endl;
}

int main()
{
    student a[5] = {student(1, 90), student(2, 80), student(3, 70), student(4, 60), student(5, 100)};
    student *ptr;
    ptr = a;
    void max(student * p);
    max(ptr);
    return 0;
}

void max(student *p)
{
    int idx = 0;
    float temp = (p->score);
    for (int i = 1; i < 5; i++)
    {
        if((p+i)->score > temp)
        {
            temp = (p + i)->score;
            idx = i;
        }
    }
    cout << temp << "   "<< (idx + 1) << endl;
}
