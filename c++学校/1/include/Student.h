#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
    public:
        void setdata()
        {
            cout << "������������ѧ�ţ�������";
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
