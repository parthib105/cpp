// member function templates & overloding template function

#include<iostream>
using namespace std;

template <class T>
class parthib
{
public:
    T data;
    parthib(T a)
    {
        data = a;
    }

    void display();
    // void display()
    // {
    //     cout << data << endl;
    // }
};

template <class T>
void parthib<T> :: display()
{
    cout << data << endl;
}

void func(int k)
{
    cout << "I am first func() " << k << endl;
}

template <class T>
void func(T k)
{
    cout << "I am templatised func() " << k << endl;
}

int main()
{
    parthib<float> p1(3.14159);
    parthib<char> p2('a');
    parthib<bool> p3(false);
    p1.display();
    p2.display();
    p3.display();

    //****function overloding****

    func(6);  // exact match takes the hignest priority
    func(9.86);
     
    return 0;
}