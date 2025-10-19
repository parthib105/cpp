// Reverse an array

#include<bits/stdc++.h>
using namespace std;

/* Utility function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*
    1. Array Reverse Using an Extra Array (Non In-place):
        - Create a new array of the same size as the original array.
        - Copy elements from the original array to the new array in reverse order.

    => Time Complexity : O(n)
        - Copying elements to a new array is a linear operation.

    => Auxiliary Space Complexity : O(n)
        - Additional space is used to store the new array.
*/
void reverseArrayExtraArray(int arr[], int size)
{
    int reversedArr[size];
    for (int i = 0; i < size; i++) 
    {
        reversedArr[i] = arr[size - i - 1];
    }

    // Print reversed array
    cout << "Reversed Array: " << endl;
    printArray(reversedArr, size);
}


/*
    2. Array Reverse Using a Loop (In-place):
        - Iterate through the array using two pointers (start and end).
        - Swap elements at the start and end pointers.
        - Move the start pointer towards the end and the end pointer towards the start until they meet or cross each other.
    
    => Time Complexity: O(n)
        - The loop runs through half of the array, so it’s linear with respect to the array size.

    => Auxiliary Space Complexity: O(1)
        - In-place reversal, meaning it doesn’t use additional space. 
*/
void reverseArrayInPlace(int arr[], int start, int end)
{
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


/*
    4. Array Reverse Recursion (In-place or Non In-place):
        - Define a recursive function that takes an array as input.
        - Swap the first and last elements.
        - Recursively call the function with the remaining subarray.

    => Time Complexity: O(n). 
        - The recursion goes through each element once, so it’s linear.

    => Auxiliary Space Complexity: 
        - O(n) for non in-place, O(log n) for in-place (due to recursion stack).
*/
void reverseArrayRecursion(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    reverseArrayRecursion(arr, start + 1, end - 1);
}


/*
    5. Array Reverse Stack (Non In-place):
        - Push each element of the array onto a stack.
        - Pop elements from the stack to form the reversed array.

    => Time Complexity: O(n)
        - Pushing and popping each element onto/from the stack requires linear time.
    
    => Auxiliary Space Complexity: O(n)
        - Additional space is used to store the stack.
*/
void reverseArrayUsingStack(int arr[], int size)
{
    stack<int> stack;

    // Push elements onto the stack
    for (int i = 0; i < size; i++) 
    {
        stack.push(arr[i]);
    }

    // Pop elements from the stack to reverse the array
    for (int i = 0; i < size; i++) 
    {
        arr[i] = stack.top();
        stack.pop();
    }
}

int main()
{

    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    /******************** Method - 1 *********************/
    // To print original array
    cout << "Original array : " << endl;
    printArray(arr, n);

    // Function calling
    reverseArrayExtraArray(arr, n);
    /*****************************************************/


    /******************** Method - 2 *********************/
    // To print original array
    cout << "Original array : " << endl;
    printArray(arr, n);

    // Function calling
    reverseArrayInPlace(arr, 0, n - 1);

    // To print the Reversed array
    cout << "Reversed array : " << endl;
    printArray(arr, n);
    /*****************************************************/


    /******************** Method - 3 *********************/

    /*
        3. Array Reverse Inbuilt Methods (Non In-place):
            - Use inbuilt methods like reverse
        
        => Time Complexity: O(n) 
            - The reverse method typically has linear time complexity.
        
        => Auxiliary Space Complexity: O(n)
            - Additional space is used to store the reversed array.
    */

    // To print original array
    cout << "Original array : " << endl;
    printArray(arr, n);

    // Using inbuilt method in C++
    reverse(arr, arr + n);

    // To print the Reversed array
    cout << "Reversed array : " << endl;
    printArray(arr, n);
    /*****************************************************/


    /******************** Method - 4 *********************/
    // To print original array
    cout << "Original array : " << endl;
    printArray(arr, n);

    // Function calling
    reverseArrayRecursion(arr, 0, n - 1);

    // To print the Reversed array
    cout << "Reversed array : " << endl;
    printArray(arr, n);
    /*****************************************************/


    /******************** Method - 5 *********************/
    // To print original array
    cout << "Original array : " << endl;
    printArray(arr, n);

    // Function calling
    reverseArrayUsingStack(arr, n);

    // To print the Reversed array
    cout << "Reversed array : " << endl;
    printArray(arr, n);
    /*****************************************************/
    return 0;
}