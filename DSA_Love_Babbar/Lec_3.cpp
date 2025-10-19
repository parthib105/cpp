// If-Else & While loop
// cin do not read tab, space and enter
// to take input of tab, space and enter, use cin.get()

#include<iostream>
using namespace std;

int main()
{
    // if-else statement

    int N;
    cout << "Enter the value of n : ";
    cin >> N;

    if (N > 0)
    {
        cout << "N is positive" << endl;
    }
    else
    {
        cout << "N is negative" << endl;
    }

    // cin.get()

    int b;
    b = cin.get();
    cout << "Value of a is : " << b << endl;

    // if - elseif statement

    int a;
    cout << "Enter the value of a : ";
    cin >> a;

    if (a > 0)
    {
        cout << "a is a positive number";
    }
    else if (a < 0)
    {
        cout << "a is a negative number";
    }
    else
    {
        cout << "a is 0";
    }

    // while loop

    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int sum = 0;
    int i = 1;

    while (i <= n)
    {
        sum += i;
        i += 1;
    }

    cout << "The sum up to " << n << " is : " << sum;

    return 0;
}