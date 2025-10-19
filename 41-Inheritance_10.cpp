// Pointer to objects and arrow operator

#include<iostream>
using namespace std;

class Complex
{
private:
    int re;
    int im;

public:
    void setData(int a, int b)
    {
        re = a;
        im = b;
    }

    void getData()
    {
        cout << "The real part is " << re << endl;
        cout << "The imaginary part is " << im << endl;
    }
};

int main()
{
    Complex c1;
    c1.setData(4, 52);
    c1.getData();
    cout << '\n';

    // using pointers
    Complex c2;
    Complex *ptr = &c2;
    (*ptr).setData(6, 7);
    (*ptr).getData();
    cout << '\n';

    // using arrow operator
    Complex *p = new Complex;
    p->setData(9, 34);
    p->getData();
    return 0;
}