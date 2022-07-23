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
    stud.display();
    stud.change(1002, 98.5);
    stud.display();
    return 0;
}