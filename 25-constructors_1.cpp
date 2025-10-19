/*
 Constructor is a special member function with the same name
 as of the class.
 It is used to initialize the objects of its class
 It is automatically invoked whenever an object is created

 PROPERTIES:
 1. It should be declared in the public section of the class.
 2. They are automatically invoked whenever the object is created
 3. They can't return values and do not have return types
 4. It can have default arguments
 5. We cannot refer to their address
*/


#include<iostream>
using namespace std;

class Complex
{
    int re, im;
public:
    Complex(int r, int i)  // constructor(default)
    {
        re = r;
        im = i;
    }

    void printNumber()
    {
        cout << "Your number is " << re << " + " << im << " i" << endl;
    }
};

int main()
{
    Complex c1(2, 4), c2(3, 7), c3(9, 4);
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();   
    return 0;
}