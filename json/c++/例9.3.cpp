/*建立一个对象数组，内放5个学生的数据（学号、成绩），用指针指向数组首元素，输出第1,3,5个学生的数据。*/
#include<iostream>
using namespace std;

class student
{
private:
    int num;
    int score;

public:
    student(int n,float s);
    ~student();
    void display();
};

student::student(int n,float s):num(n),score(s)
{
}

student::~student()
{
}

void student::display()
{
    cout << num << " " << score << endl;
}

int main()
{
    student s[5] = {student(1, 91), student(2, 92), student(3, 93), student(4, 94), student(5, 95)};
    student *ps = s;
    ps->display();
    ps++;
    ps++;
    ps->display();
    return 0;
}