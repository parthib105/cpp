/*
    Merge K Sorted Arrays

    You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all 
    the given arrays/list such that the output array/list should be sorted in ascending order.

    k = 2
     
    vector<vector<int>> kArrays = {{3, 5, 9}, {1, 2, 3, 8}}

    Sample Output 1:
    1 2 3 3 5 8 9 

    Explanation of Sample Input 1:

    After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].
*/

#include<bits/stdc++.h>
using namespace std;

// custom data structure to store in heap
class node
{
public:
    int data;
    int rowIdx;
    int colIdx;

    node(int val, int i, int j)
    {
        this->data = val;
        this->rowIdx = i;
        this->colIdx = j;
    }

};

// custom comparator
class compare
{
public:
    bool operator() (node* a, node* b)
    {
        return (a->data > b->data);
    }
};

// T.C. O(n*k * log(k))  S.C. O(n*k)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // vector to store ans
    vector<int> ans;

    // min heap
    priority_queue<node*, vector<node*>, compare> pq;

    // push 0th element of each row into min heap
    for (int i = 0; i < k; i++)
    {
        node* elm = new node(kArrays[i][0], i, 0);
        pq.push(elm);
    }

    while (pq.size() > 0)
    {
        node* topElm = pq.top();

        ans.push_back(topElm->data);
        pq.pop();

        int i = topElm->rowIdx;
        int j = topElm->colIdx;

        if (j + 1 < kArrays[i].size())
        {
            node* newElm = new node(kArrays[i][j+1], i, j + 1);
            pq.push(newElm);
        }
    }
    return ans;
}

int main()
{
    int k = 4;
    vector<vector<int>> kArrays = {{1, 5, 9}, {45, 90}, {2, 6, 78, 100, 234}, {0}};
    vector<int> ans = mergeKSortedArrays(kArrays, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}