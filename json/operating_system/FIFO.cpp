#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int n, s = 0;
struct Block{
    int name;
    int number;
}pb[10];
Block *p = pb;
void FIFO(int n){
    int num;
    int t = 1;
    int flag = 0;
    int total = 0;
    ifstream openfile("data.txt");
    while (!openfile.eof())
    {
        cout << "FIFO:" << endl << "淘汰的为：";
        flag = 0;
        openfile>>num;
        t++;
        if(t>=n){
            for(int i=0; i<n; i++){
                if(num==pb[i].name){
                    flag = 1;
                }
            }
            if(flag==0){
                total++;
                cout << p->name << "  ";
                p->name = num;
                p++;
                if(total%n==0){
                    p = pb;
                }
            }
        }
    }
    openfile.close();
    cout << endl << "缺页的总次数为：" << total << endl;
    cout << "缺页率为：" << (total/(s+0.0))*100<<"%"<<endl<<endl;
}
int main(){
    ifstream openfile("data.txt");
    int num,n1,t=0,number=1;
    cout <<"系统需要调用的页面有：" << endl;
    while (!openfile.eof())
    {
        s++;
        openfile>>num;
        cout<<num << " ";
    }
    cout << endl;
    openfile.close();
    cout << "请输入物理块的个数：" << endl;
    cin >> n;
    n1 = n;
    ifstream openfile2("data.txt");
    while (n1--)
    {
        if(openfile2.eof()){
            cout << "引用串已经分配完毕" << endl;
            break;
        }
        openfile2 >> num;
        pb[t].number = 0;
        pb[t++].name = num;
    }
    openfile2.close();
    FIFO(n);
    
    
}