/*
Q. Create two classes:
        1. SimpleCalculator - Takes input of 2 numbers using a utility function and
           performs +, -, *, / and displays the result using another function.
        2. ScientificCalculator - Takes input of 2 numbers using a utility function and 
           performs any four scintific operation of your choice and displays the results
           using another function.

    Create another class HybridCalculator and inherit it using these 2 classes.
    Create an onject of HybridCalculator and dispaly the result of simple and 
    scientific calculator.
*/


#include<iostream>
#include<math.h>
using namespace std;

class SimpleCalculator
{
private:
    double a1, b1;

public:
    void simInput(double n1, double n2)
    {
        a1 = n1;
        b1 = n2;
    }

    void simOutput(void)
    {
        cout << a1 << " + " << b1 << " = " << a1 + b1 << endl;
        cout << a1 << " - " << b1 << " = " << a1 - b1 << endl;
        cout << a1 << " * " << b1 << " = " << a1 * b1 << endl;
        cout << a1 << " / " << b1 << " = " << a1 / b1 << endl;
    }
};

class ScientificCalculator
{
private:
    double a2, b2;

public:
    void sciInput(double n1, double n2)
    {
        a2 = n1;
        b2 = n2;
    }

    void sciOutput(void)
    {
        cout << a2 << " to the power " << b2 << " = " << pow(a2, b2) << endl;
        cout << "The square root of " << a2 << " * " << b2 << " = " << sqrt(a2 * b2) << endl;
        cout << "sin(" << a2 << ")" << " to the power " << b2 << " = " << pow(sin(a2), b2) << endl;
        cout << "sin(" << a2 << ")" << " / " << "cos(" << b2 << ")" << " = " << sin(a2) / cos(b2) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
public:
    void hybridDisplay(void)
    {
        cout << "Result of simple calculator:" << endl;
        simOutput();
        
        cout << "Result of scientific calculator:" << endl;
        sciOutput();
    }
};


int main()
{
    HybridCalculator hyb;
    hyb.simInput(98.04, 67.76);
    hyb.sciInput(3.14159, 9.8695877281);
    hyb.hybridDisplay();
    return 0;
}