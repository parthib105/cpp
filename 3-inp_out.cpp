/*
C++ comes with libraries which helps us in performing input/output.
In C++ sequence of bytes corresponding to input & output are commonly
known as 'streams'

'Input Stream' : Direction of flow of bytes takes place from
                input device to the main memory
'Output Stream': Direction of flow of bytes takes palce from
                main memory to the output device.
*/

// endl used to create newline

#include<iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter the value of num1: " << endl; //'<<' is called insertion operator
    cin >> num1; //'>>' is called extraction operator

    cout << "Enter the value of num2: " << endl;
    cin >> num2;

    cout << "The sum is : " << num1 + num2;
}