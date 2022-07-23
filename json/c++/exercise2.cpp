#include<iostream>
using namespace std;
class CTest
{
    public:
        CTest(int part1 = 0, int part2 = 0);
        CTest operator+(const CTest &rhs);
        CTest operator-(const CTest &rhs);
        friend ostream &operator<<(ostream &s, const CTest &rhs);
        void init(int part1, int part2)
        {
            m_part1 = part1;
            m_part2 = part2;
        }
        void print()
        {
            cout << m_part1 << "-" << m_part2 << "=" << m_part1 - m_part2 << endl;
        }
    private:
        int m_part1, m_part2;
};

CTest::CTest(int part1, int part2):m_part1(part1),m_part2(part2) { }
CTest CTest::operator+(const CTest &rhs)
{
    return CTest(m_part1 + rhs.m_part1, m_part2 + rhs.m_part2);
}
CTest CTest::operator-(const CTest &rhs)
{
    return CTest(m_part1 - rhs.m_part1, m_part2 - rhs.m_part2);
}
ostream & operator<<(ostream &s,const CTest &rhs)
{
    s << "<" << rhs.m_part1 << "," << rhs.m_part2 << ">" << endl;
    return s;
}

int main()
{
    CTest X, Y(200, 100), Z;
    X.init(300, 400);
    X.print();
    Y.print();
    Z = X + Y;
    Z.print();
    cout << Z;
    return 0;
}