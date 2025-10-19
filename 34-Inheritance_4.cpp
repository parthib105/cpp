// Multilevel Inheritance

#include <iostream>
using namespace std;

class student
{
protected:
    int roll_number;

public:
    void set_roll_number(int r)
    {
        roll_number = r;
    }

    void get_roll_number(void)
    {
        cout << "The roll number is " << roll_number << endl;
    }
};

class exam : public student // protected members of 'student' will remain protected.
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void get_marks(void)
    {
        cout << "The marks obtained in maths is " << maths << endl;
        cout << "The marks obtained in physics is " << physics << endl;
    }
};

class result : public exam
{
    float percentage;

public:
    void display()
    {
        get_roll_number();
        get_marks();
        cout << "Your result is " << (maths + physics) / 2 << " %" << endl;
    }
};

int main()
{
    /*
    Notes:
        If we are inheriting B from A and C from B : [ A--->B--->C ]
        1. A is the 'Base Class' for B and B is the 'Base Class' for C
        2. A--->B--->C is called the Inheritance path
    */

    result parthib;
    parthib.set_roll_number(12);
    parthib.set_marks(100.0, 95.0);
    parthib.display();
    return 0;
}