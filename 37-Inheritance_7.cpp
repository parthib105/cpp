// Virtual base class

/*
        | -----> test
student | 
        | -----> sports

test   |
       | -----> results
sports |
*/

#include<iostream>
using namespace std;

class stduent
{
protected:
    int roll_no;

public:
    void set_number( int a)
    {
        roll_no = a;
    }

    void print_number(void)
    {
        cout << "Your roll_no is " << roll_no << endl;
    }
};

class test : virtual public stduent
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void print_marks(void)
    {
        cout << "Your result us here :" << endl
             << "Maths: " << maths << endl
             << "Physics: " << physics << endl;
    }
};

class sports : virtual public stduent
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }

    void print_score(void)
    {
        cout << "Your Pt score is " << score << endl;
    }
};

class result : public test, public sports
{
private:
    float total;

public:
    void display(void)
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Your total score is: " << total << endl;
    }
};

int main()
{
    result anu;
    anu.set_number(1000);
    anu.set_marks(69.0, 79.5);
    anu.set_score(8);
    anu.display();
    return 0;
}