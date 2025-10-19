#include<iostream>
using namespace std;

class complex
{
    int re, im;
    public:
        complex(int a, int b)
        {
            re = a;
            im = b;
        }

        complex(int a)
        {
            re = a;
            im = 0;
        }

        complex()
        {
            re = 0;
            im = 0;
        }

        void printNumber()
        {
            cout << "Your number is " << re << " + " << im << " i" << endl;
        }
};
int main()
{
    complex c1(3, 5);
    c1.printNumber();

    complex c2(4);
    c2.printNumber();

    complex c3;
    c3.printNumber();
    return 0;
}