/*
Algorithm : 
        arr = [70, 60, 55, 45, 50]   

                        70
                       /  \
                      /    \
                     60    55
                    /  \
                   45  50

    1. swap arr[1](root) <=> arr[n] (last) and size --
    2. heapify it and size --
*/

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

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step 1 : swap
        swap(arr, 1, size);
        size--;

        // step 2 
        Heapify(arr, size, 1);
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

    heapSort(arr, n);

    // printing the array
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}