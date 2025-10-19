#include<stdio.h>
#include<stdlib.h>

void swap (int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr, largest, i);
        Heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n/2; i > 0; i--)
    {
        Heapify(arr, n, i);
    }

    // printing the array
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}