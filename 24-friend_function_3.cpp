#include<iostream>
using namespace std;

class C2;

class C1
{
    int val1;
    friend void exchange( C1 &, C2 &);
    public:
        void inData(int a)
        {
            val1 = a;
        }

        void display(void)
        {
            cout << val1 << endl;
        }
};

class C2
{
    int val2;
    friend void exchange( C1 &, C2 &);
    public:
        void inData(int a)
        {
            val2 = a;
        }

        void display(void)
        {
            cout << val2 << endl;
        }
};

void exchange(C1 &x, C2 &y)
{
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main()
{
    C1 oC1;
    C2 oC2;

    oC1.inData(34);
    oC2.inData(67);
    exchange(oC1, oC2);

    cout << "The value of c1 after exchanging becomes: ";
    oC1.display();
    cout << "The value of c1 after exchanging becomes: ";
    oC2.display();
    return 0;
}