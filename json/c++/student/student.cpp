#include "student.h"
#include<iostream>

using namespace std;
void student::display()
{
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex:" << sex << endl;
}
void student::set_value()
{
    cin >> num;
    cin >> name;
    cin >> sex;
}