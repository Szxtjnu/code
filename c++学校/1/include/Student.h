#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
    public:
        void setdata()
        {
            cout << "请输入姓名，学号，分数：";
            cin >> name >> num >> score ;
        }
        void display()
        {
            cout << name << " " << num << " " << score << endl;
        }

    private:
        Student();
        virtual ~Student();
        char name[10];
        int num,score;
};

#endif // STUDENT_H
