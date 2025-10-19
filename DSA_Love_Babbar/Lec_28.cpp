// Reference variable | Static vs Dynamic Memory
// same memory with different names
// same same but diflent

#include<bits/stdc++.h>
using namespace std;

void update1(int n)
{
    n = n + 1;
}

void update2(int& n)
{
    n = n + 1;
}

int getSum(int* arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // int i = 5;
    // int& j = i;     // reference variable for i

    // cout << "Printing i : " << i << endl;
    // i ++;
    // cout << "Incrementing i and printing i : " << i << endl;
    // j ++;
    // cout << "Incrementing j and printing i : " << i << endl;
    // cout << "Incrementing j and printing j : " << j << endl;


    /******************* Reference variable in functions ********************/
    
    // int n = 5;
    // cout << "Before update1 function call, n : " << n << endl;
    // update1(n);
    // cout << "After update1 function call , n :  " << n << endl;

    // cout << "Before update2 function call, n : " << n << endl;
    // update2(n);
    // cout << "After update2 function call , n :  " << n << endl;
    
    /************************************************************************/


    /******************* Dynamic Memory Allocation **************************/

    // creating array dynamically
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "Sum : " << ans << endl;

    // clear memory
    delete[] arr;
    
    /************************************************************************/
    return 0;
}