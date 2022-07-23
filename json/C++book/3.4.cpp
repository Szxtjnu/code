#include<iostream>
using namespace std;
class student
{
    private:
        int number;
        float score;
    public:
        student(int n, float s) : number(n), score(s){}
        void display();
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
    ptr->display();
    (ptr + 2)->display();
    (ptr + 4)->display();
    return 0;
}