/*
An array is a collection of items of similar type stored in
contiguous memory locations.
Sometimes, a simple variable isn't enough to hold all the data 
*/

#include<iostream>
using namespace std;

int main()
{
    int marks[4] = {23, 45, 56, 89};

    for (int i=0; i<4; ++i)
    {
        cout << "The value of marks " << i << " is " << marks[i] << endl;
    }

    int j = 0;
    while ( j < 4 )
    {
        cout << "The value of marks " << j << " is " << marks[j] << endl;
        j++;
    }

    int k = 0;
    do
    {
        cout << "The value of marks " << k << " is " << marks[j] << endl;
        k++;
    }while ( k < 4 );
    return 0;
}