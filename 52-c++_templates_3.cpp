#include<iostream>
using namespace std;

template <class T1 = int, class T2 = float>
class parthib
{
public:
    T1 a;
    T2 b;

    parthib(T1 x, T2 y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
    }
};

int main()
{
    parthib<> p(5, 1.05);
    p.display();

    parthib<float, char> q(1.002537, 'q');
    q.display();
    return 0;
}