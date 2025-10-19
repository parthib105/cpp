#include<iostream>
using namespace std;

class Employee
{
    private :
        int a, b, c;
    public :
        int d, e;
        void setData(int a1, int b1, int c1); // Declaration
        void getData()
        {
            cout << "The value of a is " << a << endl;
            cout << "The value of b is " << b << endl;
            cout << "The value of c is " << c << endl;
            cout << "The value of d is " << d << endl;
            cout << "The value of e is " << e << endl;
        }
};

void Employee :: setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee parthib;
    // parthib.a = 67; // This can't be done as 'a' is in private 
    parthib.d = 34;
    parthib.e = 23;
    parthib.setData(1, 3, 6);
    parthib.getData();
    return 0;
}