// Constructors in derived class

/*
 Case 1:
    class B: public A
    {
        // Order of execution of constructor -> first A() then B()
    }

 Case 2:
    class A: public B, public C
    {
        // Order of execution of constructor -> B() then C() and A()
    }

 Case 3:
    class A: public B, virtual public C
    {
        // Order of execution of constructor -> first C() then B() and  A()
    }
*/

#include<iostream>
using namespace std;

class Base1
{
private:
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 class constructor called" << endl;
    }

    void printDataBase1(void)
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};

class Base2
{
private:
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 class constructor called" << endl;
    }

    void printDataBase2(void)
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};

class Derived: public Base1, public Base2
{
private:
    int derived1, derived2;

public:
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout << "Derived class constructor called" << endl;
    }

    void printDataDerived(void)
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};

int main()
{
    Derived parthib(2, 4, 6, 8);
    // parthib.printDataBase1();
    parthib.printDataBase2();
    // parthib.printDataDerived();
    return 0;
}