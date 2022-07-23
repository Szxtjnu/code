#include<iostream>
#include<cstring>
using namespace std;
class employee
{
    private:
        string no;
        string name;
    public:
        void getvalue()
        {
            cout << "请输入工号和姓名" << endl;
            cin >> no >> name;
        }
        string No_display() { return (no); }
        string Name_display() { return (name); }
};

class commissionWorker:public employee
{
    private:
        double basesalary;
        double salemoney;
        double commper;
    public:
        void get_value();
        double getPay();
};
void commissionWorker::get_value()
{
    cout << "请分别输入底薪、提成率、销售额：" << endl;
    cin >> basesalary >> commper >> salemoney;
}
double commissionWorker::getPay()
{
    return (basesalary + (salemoney * commper));
}

class HourlyWorker:public employee
{
    private:
        double Hour;
        double PerHour;
    public:
        void hour_get_value()
        {
            cout << "请输入工作时长和工作时薪" << endl;
            cin >> Hour >> PerHour;
        }
        double hour_get_salary();
};
double HourlyWorker::hour_get_salary()
{
    if (Hour>40) return(40*PerHour+(Hour-40)*PerHour*1.5);
	else return (Hour*PerHour);
}

class PieceWorker:public employee
{
    private:
	    double piece;
        double eachmoney;
    public:
        void piece_get_value()
        {
            cout << "请输入件数和每件薪资" << endl;
            cin >> piece >> eachmoney;
        }
        double piece_get_salary()
        {
            return (piece * eachmoney);
        }
};

int main()
{do{
    int i;
    cout << "求哪种工人的薪资？销售员请输入1，小时工请输入2，计件工请输入3." << endl;
    cin >> i;
    if(i == 1){
    commissionWorker c1;
    c1.getvalue();
    c1.get_value();
    cout << c1.No_display() <<"  "<< c1.Name_display() << "的工资是" << c1.getPay() << endl;
    }
    if(i==2){
    HourlyWorker h1;
    h1.getvalue();
    h1.hour_get_value();
    cout << h1.No_display() << " " << h1.Name_display() << "的工资是" << h1.hour_get_salary() << endl;
    }
    if(i==3){
    PieceWorker p1;
    p1.getvalue();
    p1.piece_get_value();
    cout << p1.No_display() << " " << p1.Name_display() << "的工资是" << p1.piece_get_salary() << endl;
    }
    } while (1);
    return 0;
}
