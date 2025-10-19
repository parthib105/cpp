// Minimum and Maximum of an array

#include<bits/stdc++.h>
using namespace std;

/*
1. Maximum and minimum of an array (Brute Force) :
    - Write functions to find the minimum (setmini) and maximum (setmaxi) values in the array.
    - In the setmini function:
        - Initialize a variable (mini) to INT_MAX.
        - Iterate through the array, and if an element is smaller than the current mini, update mini to that element.
        - Return the final value of mini.

    - In the setmaxi function:
        - Initialize a variable (maxi) to INT_MIN.
        - Iterate through the array, and if an element is larger than the current maxi, update maxi to that element.
        - Return the final value of maxi.

    - In the main function:
        - Declare an array and its size.
        - Print the result ,Call the setminimum and setmaxi functions to find the minimum and maximum values.
    
    - Time Complexity: O(N)
    - Auxiliary Space: O(1)
*/
int setmini(int A[], int N)
{
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) 
    {
        if (A[i] < mini) 
        {
            mini = A[i];
        }
    }
    return mini;
}

int setmaxi(int A[], int N)
{
    int maxi = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > maxi) 
        {
            maxi = A[i];
        }
    }
    return maxi;
}


/*
2. Maximum and minimum of an array using Sorting:
    - Initialize an array.
    - Sort the array in ascending order.
    - The first element of the array will be the minimum element.
    - The last element of the array will be the maximum element.
    - Print the minimum and maximum element.

=> Time complexity: O(n log n)
    - here n is the number of elements in the array, as we are using a sorting algorithm.

=> Auxilary Space: is O(1)
    - since we are not using any extra space.
*/
struct Pair 
{
    int min;
    int max;
};

Pair getMinMaxUsingSorting(int arr[], int n)
{
    Pair minmax;

    sort(arr, arr + n);

    minmax.min = arr[0];
    minmax.max = arr[n - 1];

    return minmax;
}


/*
3. Maximum and minimum of an array using Linear search:
    - Initialize values of min and max as minimum and maximum of the first two elements respectively. 
    - Starting from 3rd, compare each element with max and min, and change max and min accordingly 
    - (i.e., if the element is smaller than min then change min, else if the element is greater 
      than max then change max, else ignore the element)

=> Time Complexity: O(n)

=> Auxiliary Space: O(1) as no extra space was needed. 
*/
Pair getMinMaxUsingLinearSearch(int arr[], int n)
{
    struct Pair minmax;     
    int i;
    
    // If there is only one element 
    // then return it as min and max both
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];     
        return minmax;
    } 
    
    // If there are more than one elements,
    // then initialize min and max
    if (arr[0] > arr[1]) 
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    } 
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    } 
    
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max) 
        {    
            minmax.max = arr[i];
        }     
        else if (arr[i] < minmax.min) 
        {    
            minmax.min = arr[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[] = { 4, 9, 6, 5, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    /******************** Method - 1 *********************/
    cout << "Minimum element is: " << setmini(arr, n) << endl;
    cout << "Maximum element is: " << setmaxi(arr, n) << endl;
    /*****************************************************/


    /******************** Method - 2 *********************/
    Pair minmax = getMinMaxUsingSorting(arr, n);

    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;
    /*****************************************************/


    /******************** Method - 3 *********************/
    Pair min_max = getMinMaxUsingLinearSearch(arr, n);

    cout << "Minimum element is " << min_max.min << endl;
    cout << "Maximum element is " << min_max.max << endl;
    /*****************************************************/

    return 0;
}