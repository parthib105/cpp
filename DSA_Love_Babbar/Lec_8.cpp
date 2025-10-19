// Switch Case and Functions

#include <iostream>
using namespace std;

// function Signature
int power(int a, int b)
{
    // function body
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

bool isEven(int a)
{
    if (a & 1)         // 3 -> 011, 5 -> 101
    {
        return 0;
    }
    return 1;
}

int main()
{
    // ********** Switch Statement example **********

    // int num = 3;

    // switch (num)
    // {
    // case 1:
    //     cout << "This is first" << endl;
    //     break;

    // case 2:
    //     cout << "This is second" << endl;
    //     break;

    // default:
    //     cout << "Default case" << endl;
    // }

    // ********** Mini calculator **********

    // int a, b;
    // cout << "Enter the values of a and b, separated by a space : ";
    // cin >> a >> b;

    // char op;
    // cout << "Enter the Operation you want to perform : ";
    // cin >> op;

    // switch (op)
    // {
    // case '+':
    //     cout << "a + b = " << (a+b) << endl;
    //     break;
    // case '-':
    //     cout << "a - b = " << (a-b) << endl;
    //     break;
    // case '*':
    //     cout << "a * b = " << (a*b) << endl;
    //     break;
    // case '/':
    //     cout << "a / b = " << (a/b) << endl;
    //     break;
    // case '%':
    //     cout << "a % b = " << (a%b) << endl;
    //     break;
    // }

    // ********** Functions **********
    
        // helps to reduce bulkness of code
        // Ex. Print a to the power b
    
    int a, b;

    cout << "Enter the values of a and b : ";
    cin >> a >> b;

    if (isEven(a))
    {
        cout << a << " is even" << endl;
    }
    else
    {
        cout << a << " is odd" << endl;
    }

    if (isEven(b) /* function call */)
    {
        cout << b << " is even" << endl;
    }
    else
    {
        cout << b << " is odd" << endl;
    }

    cout << a << " to the power " << b << " : " << power(a, b);


    return 0;
}