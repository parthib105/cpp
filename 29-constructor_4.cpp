// copy constructor
// When no copy constructor is found, compiler supplies its own constructor
#include<iostream>
using namespace std;

class Number
{
    int a;
    public:
        Number()
        {
            a = 0;
        }

        Number(int num)
        {
            a = num;
        }

        Number( Number &obj)
        {
            cout << "Copy constructor called!!!" << endl;
            a = obj.a;
        }

        void display()
        {
            cout << "The number for this object is " << a << endl;
        }
};

int main()
{
    Number x(34), y, z(45), z2;
    x.display();
    y.display();
    z.display();

    Number z1(x); // copy constructor invoked
    z1.display();

    z2 = z; //copy constructor not invoked
    z2.display();

    Number z3 = z; // copy constructor invoked
    z3.display();
    return 0;
}