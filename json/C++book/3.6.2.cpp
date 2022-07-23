#include<iostream>
using namespace std;
class student
{
    public:
        student(int n, float s): num(n),score(s) { }
        void change(int n, float s) { num = n;
            score = s;
        }
        void display()
        {
            cout << num << "   " << score << endl;
        }
    private:
        int num;
        float score;
};

int main()
{
    student stud(1001, 95);
    void fun(student & s);
    fun(stud);
    return 0;
}

void fun(student &s)
{
    s.display();
    s.change(1002, 98.2);
    s.display();
}