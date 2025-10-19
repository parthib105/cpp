#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    //Multiplication table using do-while

    int n;
    cout << "Enter the number whose table is to be printed ";
    cin >> n;
    int i = 1;
    do
    {
        cout << n << "x" << setw(2) << i << " = " << n * i << endl;
        i++;
    } while (i <= 10);
    
}
