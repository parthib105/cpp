// function template
#include<iostream>
using namespace std;

template <class T1, class T2>
float funcAvg(T1 a, T2 b)
{
    float avg = (a + b) / 2;
    return avg;
}

template <class t>
void swapp(t &a, t &b)
{
    t temp = a;
    a = b;
    b = temp;
}

int main()
{
    float a;
    a = funcAvg(2.4, 5.4);
    cout << "The average of these numbers is " << a << endl;
    
    char x = 'e', y = 'p';
    swapp(x, y);
    cout << "The value of x = " << x << endl;
    cout << "The value of y = " << y << endl;
    return 0;
}