#include<iostream>
using namespace std;

// Base Class
class Employee
{
    public:
        int id;
        float salary;
        Employee(){}
        Employee(int inpId, int Sal)
        {
            id = inpId;
            salary = Sal;
        }
};

// Derived Class syntax

/*
 class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
 Note:
 1. Default visibility mode is private.
 2. Public Visibility mode : Public members of the base class becomes 'Public' members of the derived class
 3. Private Visibility mode: Public members of the base class becomes 'Private' members of the derived class
 4. Private members are never inherited.
*/

// Creating a Programmer class derived from Employee Base Class
class Programmer : Employee
{
    public:
        int languageCode = 9;
        Programmer(int inpId)
        {
            id = inpId;
        }

        void getData()
        {
            cout << id << endl;
        }
};

int main()
{
    Employee harry(1, 3456), rohan(2, 6534);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode << endl;
    skillF.getData();
    return 0;
}