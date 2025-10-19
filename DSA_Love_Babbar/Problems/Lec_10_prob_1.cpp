/* 
    Swap Alternate :
    Ex.:
        [1, 2, 7, 8, 5]     -->  [2, 1, 8, 7, 5]
        [1, 2, 3, 4, 5, 6]  -->  [2, 1, 4, 3, 6, 5]
*/

#include <iostream>
using namespace std;

void swp(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            swp(arr, i, i + 1);
        }
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    swapAlternate(arr, 5);
    printArray(arr, 5);
    return 0;
}