/* 
    Book Allocation Problem

    Given an array of integer numbers, where 'arr[i]' represents the number of pages in the 'i-th' book.
    There are 'm' number of students and the task is to aallocate all the books to their students.
    Allocate books in such a way that :
        1. Each student gets at least one book
        2. Each book should be allocated to a student.
        3. Book allocation should be in a contiguous manner.

    You have to allocate the book 'm' students such that the maximum no. of pages assigned to a student is minimum.

    Example : 
        Let's consider 'n = 4' (no. of books) and 'm = 2' (no. of students)

        arr[4] = {10, 20, 30, 40}

        10 | 20 30 40 -  sum of all the pages of books which allocated to student-1 = 10
                         and student-2 = 20 + 30 + 40 = 90, so maximum = 90
        
        10 20 | 30 40 -  sum of all the pages of books which allocated to student-1 = 10 + 20 = 30
                         and student-2 = 30 + 40 = 70, so maximum = 70

        10 20 30 | 40 -  sum of all the pages of books which allocated to student-1 = 10 + 20 + 30 = 60
                         and student-2 = 40 , so maximum = 60

        return solution : min{90, 70, 60} = 60
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount ++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
    
}

int allocateBooks(vector<int>& arr, int n, int m)
{
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    int i = 0;
    int j = arrSum;
    int ans;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 17, 100, 11};
    int n = arr.size();
    int m = 4;
    cout << allocateBooks(arr, n, m);
    return 0;
}