// 'this' is a keyword which is a pointer which points to the object which invokes the member function

#include<iostream>
using namespace std;

class A
{
private:
    int a;

public:
    // A & setData(int a)
    void setData(int a)
    {
        this->a = a;
        // return *this;
    }

    void getData()
    {
        cout << "The value of a is " << a << endl;
    }
};

int main()
{
    A a;
    a.setData(6);
    a.getData();
    return 0;
}