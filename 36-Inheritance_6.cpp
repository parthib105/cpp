// Ambiguity Resolution in Inheritance

#include<iostream>
using namespace std;

class base1
{
public:
    void greet()
    {
        cout << "How are you?" << endl;
    }
};

class base2
{
public:
    void greet()
    {
        cout << "Kaise ho?" << endl;
    }
};

class derived : public base1, public base2
{
    int a;

public:
    void greet()
    {
        base1 :: greet();
    }
};

class B
{
public:
    void say()
    {
        cout << "Hello World!" << endl;
    }
};

class D : public B
{
    int a;

// D's new say() method will override  base class's say() method
public:
    void say()
    {
        cout << "Hello my beautiful people" << endl;
    }
};

int main()
{
    // Ambiguity 1

    // base1 base1obj;
    // base2 base2obj;
    // base1obj.greet();
    // base2obj.greet();
    // derived d;
    // d.greet();

    // Ambiguity 2

    B b;
    b.say();

    D d;
    d.say();
    return 0;
}