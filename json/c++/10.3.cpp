#include<iostream>
using namespace std;
const int n = 1;
struct date
{
    int year;
    int month;
    int day;
};
struct student
{
    int num;
    char name[10];
    char sex[5];
    struct date birthday;
    float grade[5];
}stu[n];

void input(student stu[])
{
    cin >> stu->num;
    cin >> stu->name;
    cin >> stu->sex;
    cin >> stu->birthday.day;
    cin >> stu->birthday.month;
    cin >> stu->birthday.year;
    for (int i = 0; i < 5; ++i)
        cin >> stu->grade[i];
}

void output(student stu[])
{
    cout << stu->num << endl;
    cout << stu->name << endl;
    cout << stu->sex << endl;
}

void average(student stu[])
{
    float ave = 0;
    for (int i = 0; i < 5; ++i)
        ave += stu->grade[i];
    ave = ave / 5.0;
    cout << ave << endl;
}

int main()
{
    int i;
    for (i = 0; i < n; ++i)
    {
        input(stu);
        output(stu);
        average(stu);
    }
    return 0;
}