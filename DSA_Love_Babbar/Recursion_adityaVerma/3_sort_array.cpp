#include<bits/stdc++.h>
using namespace std;

void insertAtCorrectPosition(vector<int> &arr, int elm)
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= elm)
    {
        arr.push_back(elm);
        return;
    }

    // store the last elemet
    int val = arr[arr.size() - 1];
    arr.pop_back();

    insertAtCorrectPosition(arr, elm);

    arr.push_back(val);
}

void sortArray(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }

    // sort n - 1 elements
    int lastElm = arr[arr.size() - 1];
    arr.pop_back();

    sortArray(arr);

    // put the last element in the correct position
    insertAtCorrectPosition(arr, lastElm);
}

int main()
{
    vector<int> arr = {0, -1, 4, 7, 2, 9, 1};
    sortArray(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}