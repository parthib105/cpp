/*
    Smallest Range From K Sorted List

    You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. 
    You need to find the minimum length of a range such that at least one element of each list must be included in that range.

    For example :

    If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first 
    list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.

    N = 3, K = 2
    a = {{2, 4, 5}, {5, 6, 7}}

    Test case 1 :
    The given list are [2, 4, 5], [5, 6, 7]. The range [5, 5] will include 5 which is present in both the list and hence the 
    length of this range is 1. This is the only possible range having the minimum length.

    Input :
    N = 5, K = 3
    KSortedArray[][] = {{1 3 5 7 9}, {0 2 4 6 8}, {2 3 5 7 11}}

    Output: 1 2
    Explanation: K = 3
    A:[1 3 5 7 9]
    B:[0 2 4 6 8]
    C:[2 3 5 7 11]
    Smallest range is formed by number 1
    present in first list and 2 is present
    in both 2nd and 3rd list.
*/

#include<bits/stdc++.h>
using namespace std;

// custom data structure to store information
class Node
{
public:
    int data;
    int rowIdx;
    int colIdx;

    Node(int d, int r, int c)
    {
        this->data = d;
        this->rowIdx = r;
        this->colIdx = c;
    }
};

// custom comparator
class compare
{
public:
    bool operator() (Node* a, Node* b)
    {
        return (a->data > b->data);
    }
};

pair<int, int> kSorted(vector<vector<int>> &a, int k, int n) 
{
    // to store min and max element
    int maxElm = INT_MIN;
    int minElm = INT_MAX;

    // priority queue to store nodes
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        minElm = min(minElm, a[i][0]);
        maxElm = max(maxElm, a[i][0]);
        pq.push(new Node(a[i][0], i, 0));
    }
    
    int st = minElm;
    int ed = maxElm;
    while (!pq.empty())
    {
        Node* curr = pq.top();
        pq.pop();

        // update minElm
        minElm = curr->data;
        
        if (maxElm - minElm < ed - st)
        {
            st = minElm;
            ed = maxElm;
        }

        if (curr->colIdx + 1 < n)
        {
            maxElm = max(maxElm, a[curr->rowIdx][curr->colIdx + 1]);
            pq.push(new Node(a[curr->rowIdx][curr->colIdx + 1], curr->rowIdx, curr->colIdx + 1));
        }
        else
        {
            break;
        }
    }

    return make_pair(st,  ed);
}

int main()
{
    int n = 5, k = 3;
    vector<vector<int>> KSortedArray = {{1, 3, 5, 7, 9}, {0, 2, 4, 6, 8}, {2, 3, 5, 7, 11}};
    pair<int, int> ans = kSorted(KSortedArray, k, n);

    cout << ans.first << " " << ans.second << endl;
    return 0;
}