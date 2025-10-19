/*
    Queues
*/

#include<bits/stdc++.h>
using namespace std;

template <class T> class Queue
{
private:
    T* arr;
    int f;
    int r;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        this->arr = new T[size];
        this->f = -1;
        this->r = -1;
    }

    bool isEmpty()
    {
        if (this->f == -1 && this->r == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(T val)
    {
        if (this->r == this->size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (this->isEmpty())
        {
            this->f = 0;
        }
        this->r += 1;
        this->arr[this->r] = val;
        cout << "Element " << val << " enqueued" << endl;
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty! Can't dequeue element" << endl;
            return;
        }
        else if (this->f == this->r)
        {
            this->r = this->f = -1;
        }
        else
        {
            this->f += 1;
        }
        cout << "Element dequeued" << endl;
    }

    T front()
    {
        return this->arr[this->f];
    }

    void printQ()
    {
        if (this->isEmpty())
        {
            cout << "Nothig in queue" << endl;
        }

        for (int i = this->f; i <= this->r; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Queue<string> Q(5);
    Q.enqueue("Parthib");
    Q.enqueue("is");
    Q.enqueue("a good");
    Q.enqueue("boy");
    // Q.dequeue();
    // Q.dequeue();
    // Q.dequeue();
    // Q.dequeue();
    // Q.dequeue();
    Q.printQ();

    return 0;
}