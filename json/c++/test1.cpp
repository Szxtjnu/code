#include<iostream>
#include<string>
using namespace std;
class stu
{
    private:
        int no;
        string name;
        int deg;
        static int sum;
        static int num;
        
    public:
        void display();
        stu(int n, string nam, int d):no(n),name(nam),deg(d){ }
        static int aver();
};
void stu::display()
{
    cout << "名字：" << name << "学号" << no << "成绩：" << deg << endl;
}
int stu::aver()
{
    sum += deg;
    cout << "总数为：" << sum << endl;
    num += no;
    cout << "人数为：" << no << endl;
    return (sum / num);
}
int main()
{
    stu student1(1, "li", 89);
    student1.display();
    stu student2(2, "wang", 29);
    student2.display();
    stu student3(3, "ning", 89);
    student3.display();
    student1.aver();
    student2.aver();
    cout << student3.aver();
    return 0;
}