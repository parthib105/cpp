#include<iostream>
using namespace std;

class Complex;

class Calculator
{
    public:
        int add(int a, int b)
        {
            return a+b;
        }

        int sumRealComplex(Complex, Complex);
        int sumCompComplex(Complex, Complex);
};

class Complex
{
    int re;
    int im;

    // *****Individually declearing functions as friends*****
    
    // friend int Calculator :: sumRealComplex(Complex, Complex);
    // friend int Calculator :: sumCompComplex(Complex, Complex);

    // Declearing the entire calculator as friends

    friend class Calculator;

    public:
        void setNumber(int a, int b)
        {
            re = a;
            im = b;
        }
        
        void printNumber()
        {
            cout << "Your number is " << re << " + " << im << " i" << endl;
        }
};

int Calculator :: sumRealComplex(Complex o1, Complex o2)
{
    return (o1.re + o2.re);
}

int Calculator :: sumCompComplex(Complex o1, Complex o2)
{
    return (o1.im + o2.im);
}


int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real parts is: " << res << endl;

    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of imaginary parts is: " << resc << endl;
    return 0;
}