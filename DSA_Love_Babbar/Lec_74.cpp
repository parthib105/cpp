/*
    Heaps

    => Heap is a Complete Binary Tree that comes with a hear order property
*/

#include<bits/stdc++.h>
using namespace std;

class heap
{
private:
    int size; 
    int* arr;
    int freeIdx;
    int currSize;

public:
    heap()
    {
        this->arr = new int[10];
        this->size = 10;
        this->freeIdx = 0;
        this->currSize = 0;
    }

    ~heap()
    {
        delete[] this->arr;
    }

    void makeMoreSpace()
    {
        int n = 2 * this->size;
        int* newArr = new int[n];
        for (int i = 0; i < this->size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] this->arr;

        this->size = n;
        this->arr = newArr;
    }

    void insertInHeap(int val)        // T.C. O(log(n))
    {
        if (this->freeIdx == this->size)
        {
            this->makeMoreSpace();
        }
        this->arr[this->freeIdx] = val;

        // place it in the right position
        int idx = this->freeIdx;
        this->freeIdx += 1;
        this->currSize += 1;

        while (idx > 0)
        {
            int pIdx = static_cast<int>(idx - 1) / 2;
            if (this->arr[pIdx] < this->arr[idx])
            {
                swap(this->arr[pIdx], this->arr[idx]);
                idx = pIdx;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (this->currSize == 0)
        {
            cout << "Heap is empty, can't delete." << endl;
            return;
        }

        // replace with last index;
        this->freeIdx -= 1;
        this->currSize -= 1;
        this->arr[0] = this->arr[this->freeIdx];

        // place in the right position
        int idx = 0;
        while (idx < this->currSize)
        {
            int lc = 2 * idx + 1;
            int rc = 2 * idx + 2;
            int largest = idx;

            if (lc < this->currSize && this->arr[lc] > this->arr[largest])
            {
                largest = lc;
            }
            if (rc < this->currSize && this->arr[rc] > this->arr[largest])
            {
                largest = rc;
            }
            if (largest == idx)
            {
                return;
            }
            swap(this->arr[largest], this->arr[idx]);
            idx = largest;
        }
    }

    void printHeap()
    {
        cout << endl;
        if (this->currSize == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        cout << "Currently in the heap : ";
        for (int i = 0; i < this->currSize; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};

// heapify algorithm
// put the current element into it's right position
// leaf nodes lies from (n/2 + 1) to n
void heapify(int arr[], int n, int idx)
{
    int curr = idx;

    // find the left and right child
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;

    if (lc < n && arr[lc] > arr[curr])
    {
        curr = lc;
    }
    if (rc < n && arr[rc] > arr[curr])
    {
        curr = rc;
    }

    if (curr != idx)
    {
        swap(arr[curr], arr[idx]);
        heapify(arr, n, curr);
    }
}

int main()
{
    heap hp;
    hp.insertInHeap(50);
    hp.insertInHeap(55);
    hp.insertInHeap(53);
    hp.insertInHeap(52);
    hp.insertInHeap(54);
    hp.printHeap();

    hp.deleteFromHeap();
    hp.printHeap();

    hp.deleteFromHeap();
    hp.printHeap();

    hp.deleteFromHeap();
    hp.printHeap();

    /******************** Heapify ******************/
    // int n = 6;
    // int arr[n] = {-1, 54, 53, 55, 52, 50};

    // for (int i = n/2 - 1; i >= 0; i--)
    // {
    //     heapify(arr, n, i);
    // }

    // cout << "Print array : " << endl;
    // for (int i = 1; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // return 0;
}