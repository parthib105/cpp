/*
    Implement K queues in a single array
*/

#include<bits/stdc++.h>
using namespace std;

template <class T> class kQueue
{
private:
    int n, k, freeSpot;
    int* f;
    int* r;
    int* next;
    T* arr;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        this->f = new int[k];
        this->r = new int[k];
        this->next = new int[n];
        this->arr = new T[n];
        this->freeSpot = 0;

        // initialize front and rear
        for (int i = 0; i < k; i++)
        {
            this->f[i] = -1;
            this->r[i] = -1;
        }

        // initialize next
        for (int i = 0; i < n; i++)
        {
            this->next[i] = i + 1;
        }
        this->next[n - 1] = -1;
    }

    void push(T data, int qn)
    {
        // check overflow condition
        if (this->freeSpot == -1)
        {
            cout << "No empty space is available" << endl;
            return;
        }

        // find free index
        int idx = this->freeSpot;

        // update freespot
        this->freeSpot = next[idx];

        // checking if it is first element
        if (this->f[qn - 1] == -1)
        {
            this->f[qn - 1] = idx;
        }
        else
        {
            // link new element to the prev element
            this->next[this->r[qn - 1]] = idx;
        }

        // update next
        this->next[idx] = -1;

        // update rear
        this->r[qn - 1] = idx;

        this->arr[idx] = data;
    }

    T pop(int qn)
    {
        // checking underflow condition
        if (this->f[qn - 1] == -1)
        {
            cout << "Queue " << qn << " is empty" << endl;
            return T();
        }

        // find index to pop
        int idx = this->f[qn - 1];

        // update front
        this->f[qn - 1] = this->next[idx];

        // maintain free spot
        this->next[idx] = this->freeSpot;
        this->freeSpot = idx;
        return this->arr[idx];
    }

};

int main()
{
    kQueue<int> q(10, 3);
    q.push(10, 1);
    q.push(15, 1);
    q.push(20, 2);
    q.push(25, 1);
    q.push(30, 2);

    cout << "Popping element from queue 1 : " << q.pop(1) << endl;
    cout << "Popping element from queue 1 : " << q.pop(1) << endl;
    cout << "Popping element from queue 2 : " << q.pop(2) << endl;
    cout << "Popping element from queue 1 : " << q.pop(1) << endl;
    cout << "Popping element from queue 2 : " << q.pop(2) << endl;
    return 0;
}