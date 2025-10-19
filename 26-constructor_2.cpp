// Parameterized Constructor

#include<iostream>
using namespace std;

class Complex
{
    int re, im;
    public:
        Complex(int a, int b)
        {
            re = a;
            im = b;
        }

        void printNumber()
        {
            cout << "Your number is " << re << " + " << im << " i" << endl;
        }
};

int main()
{
    // Implicit Call
    Complex o1(4, 6);
    o1.printNumber();

    // Explicit Call
    Complex o2 = Complex(5, 7);
    o2.printNumber();

    return 0;
}