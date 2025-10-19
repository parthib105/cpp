// Given an amount of money, print the no. of 100, 50, 20 and 1 rupees notes required to the sum

#include <iostream>
using namespace std;

int main()
{
    int amount;
    cout << "Enter the amount of money : ";
    cin >> amount;

    int i = 100;
    switch (i)
    {
    case 100:
        cout << "Rs. 100 notes required = " << amount / 100 << endl;
        amount = amount % 100;
    case 50:
        cout << "Rs. 50 notes required = " << amount / 50 << endl;
        amount = amount % 50;
    case 20:
        cout << "Rs. 20 notes required = " << amount / 20 << endl;
        amount = amount % 20;
    case 1:
        cout << "Rs. 1 notes required = " << amount / 1 << endl;
        amount = amount % 1;
    }
    return 0;
}