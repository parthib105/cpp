// Arrays

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void update(int arr[], int size)
{
    cout << endl << "Inside the undate function" << endl;

    // updating array's first element
    arr[0] = 120;

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Going back to main function" << endl;
}

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // ********** Arrays **********

    // // Declaration
    // int number[15] ;

    // // accessing an array
    // cout << "value at 14 index : " << number[14] << endl;

    // // error
    // cout << "value at 20 index : " << number[20] << endl;

    // // Initializing an array
    // int second[3] = {5, 7, 11};

    // // Accessing an element
    // cout << "value at 2 index : " << second[2] << endl;

    // int third[5] = {2, 7, 10, 3, 4};

    // // Printing the array
    // cout << "Printing the array : ";
    // printArray(third, 5);
    
    // ********** Array Scope **********

    // int arr[3] = {1, 2, 3};

    // update(arr, 3);

    // // printing the array
    // cout << endl << "Printing in main function" << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    // ********** Linear Search **********

    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};

    int key;
    cout << "Enter the element to search for : ";
    cin >> key;

    bool found = search(arr, 10, key);
    if (found)
    {
        cout << key << " is present in the array" << endl;
    }
    else
    {
        cout << key << " is not present in the array" << endl;
    }
    return 0;
}