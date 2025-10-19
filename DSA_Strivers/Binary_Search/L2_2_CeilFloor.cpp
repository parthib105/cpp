/*
    Ceil The Floor

    You're given a sorted array 'a' of 'n' integers and an integer 'x'.
    Find the floor and ceiling of 'x' in 'a[0..n-1]'.

    Note:
    Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
    Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

    Example:
    Input: 
    n=6, x=5, a=[3, 4, 7, 8, 8, 10]   

    Output:
    4

    Explanation:
    The floor and ceiling of 'x' = 5 are 4 and 7, respectively.

    Sample Input 1 :
    6 8
    3 4 4 7 8 10

    Sample Output 1 :
    8 8

    Explanation of sample input 1 :
    Since x = 8 is present in the array, it will be both floor and ceiling.

    Sample Input 2 :
    6 2
    3 4 4 7 8 10

    Sample Output 2 :
    -1 3

    Explanation of sample input 2 :
    Since no number is less than or equal to x = 2 in the array, its floor does not exist. The ceiling will be 3.

    Constraints :
    1 <= n <= 2 * 10^5      
    1 <= a[i] <= 10^9
    Time limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

int floorNum(vector<int> &arr, int n, int x)
{
	int s = 0, e = n - 1;
	int f = -1;

	while (s <= e)
	{
		int m = s + (e - s)/2;

		if (arr[m] <= x)
		{
			f = arr[m];
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}
	}
	return f;
}

int ceilNum(vector<int> &arr, int n, int x)
{
	int s = 0, e = n - 1;
	int c = -1;

	while (s <= e)
	{
		int m = s + (e - s)/2;

		if (arr[m] >= x)
		{
			c = arr[m];
			e = m - 1;
		}
		else
		{
			s = m + 1;
		}
	}

	return c;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) 
{
	// Get the floor
	int Floor = floorNum(a, n, x);

	// Get the ceil
	int Ceil = ceilNum(a, n, x);

	return {Floor, Ceil};
}

int main()
{
    int n = 6, x = 2;
    vector<int> arr = {3, 4, 4, 7, 8, 10};

    pair<int, int> CF = getFloorAndCeil(arr, n, x);

    cout << "Floor : " << CF.first << " , Ceil : " << CF.second << endl;
    return 0;
}