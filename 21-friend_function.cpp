/*
 PROPERTIES OF FRIEND FUNCTION
 1. Not in the scope of class
 2. Since it is not in the scope of the class, it can't be called
    from the object of that class. c1.prodComplex == invalid
 3. Can be invoked without the help of any object
 4. Usually contains the objects as arguments
 5. Can be declared inside public or private section of the class
 6. It can't access the members directly by their names and need 
    object_name.member_name to accessany member.
*/


#include<iostream>
using namespace std;

class complex
{
    int re;
    int im;

    public:
        void setNumber(int a, int b)
        {
            re = a;
            im = b;
        }

        friend complex prodComplex(complex o1, complex o2);  // if this line is not there,
        //the compiler will throw errror as the function tries to access private variable
        
        void printNumber()
        {
            cout << "Your number is " << re << " + " << im << " i" << endl;
        }
};

complex prodComplex(complex o1, complex o2)
{
    complex o3;
    o3.setNumber((o1.re * o2.re - o1.im * o2.im), (o1.re * o2.im + o1.im * o2.re));
    return o3;
}

int main()
{
    complex c1, c2, prod;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    prod = prodComplex(c1, c2);
    prod.printNumber();
    return 0;
}