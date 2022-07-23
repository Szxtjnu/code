#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int num;
    string name;
    char sex;
};
int main()
{
    Student *p;
    p = new Student;
    p->num = 99001;
    p->name = "李明";
    (*p).sex = 'M';
    cout << p->num << endl
         << p->name << endl
         << p->sex << endl;
    delete p;
    return 0;
}