// Reverse an array of size n

#include <iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int st = 0;
    int ed = n - 1;

    while (st < ed)
    {
        int temp = arr[st];
        arr[st] = arr[ed];
        arr[ed] = temp;

        st ++;
        ed --;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {1, 4, 0, 5, -2, 15};
    int brr[5] = {2, 6, 3, 9, 4};

    reverse(arr, 6);
    reverse(brr, 5);

    cout << "Reversing 1st array : ";
    printArray(arr, 6);
    cout << "Reversing 2nd array : ";
    printArray(brr, 5);
    return 0;
}