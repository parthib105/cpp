#include<iostream>
using namespace std;

int main()
{
    // ***************If-Else***************

    int age;
    cout << "Tell me your age" << endl;
    cin >> age;
    if ((age > 0) && (age < 18))
    {
        cout << "You can't come to my party" << endl;
    }
    else if(age == 18)
    {
        cout << "You are a kid and you will get a kid pass to the party" << endl;
    }
    else if (age < 1)
    {
        cout << "You are not yet born" << endl;
    }
    else
    {
        cout << "You can come to my party" << endl;
    }

    // ***************Switch***************

    int age;
    cout << "Tell me your age" << endl;
    cin >> age;
    switch (age)
    {
    case 18:
        cout << "You are 18" << endl;
        break;
    case 22:
        cout << "you are 22" << endl;
        break;
    case 2:
        cout << "You are 2" << endl;
        break;
    default:
        cout << "No special cases" << endl;
        break;
    }

    return 0;
}