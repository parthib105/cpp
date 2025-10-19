#include<iostream>
using namespace std;

int main()
{
    // ***************For Loop***************
    
    unsigned int count = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << i * i << endl;
        count += i * i;
    }
    cout << count << endl;
    
    // ***************While Loop***************

    unsigned int count = 0;
    int i = 0;
    while (i < 4)
    {
        cout << i * i << endl;
        count += i * i;
        i++;
    }
    cout << count << endl;

    // ***************Do While Loop***************

    unsigned int count = 0;
    int i = 0;
    do
    {
        cout << i * i << endl;
        count += i * i;
        i++;
    }while (i < 4);
    cout << count << endl;
        
    return 0;
}