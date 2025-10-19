/*
    Circular Queue
*/

#include<bits/stdc++.h>
using namespace std;

template <class T> class CircularQueue
{
private:
    int f;
    int r;
    T* arr;
    int size;

public:
    CircularQueue(int n)
    {
        this->size = n;
        this->arr = new T[n];
        this->f = -1;
        this->r = -1;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (this->f == -1 && this->r == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (this->f == (this->r + 1) % this->size)
        {
            return true;
        }
        return false;
    }

    void enqueue(int x)
    {
        if (this->isFull())
        {
            cout << "Queue is full! Can't enqueue element" << endl;
            return;
        }
        else if (this->isEmpty())
        {
            this->f = 0;
            this->r = 0;
        }
        else
        {
            this->r = (this->r + 1) % this->size;;
        }
        this->arr[this->r] = x;
        cout << "Element " << x << " is enqueued" << endl;
        return;
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
            this->f = -1;
            this->r = -1;
        }
        else
        {
            this->f = (this->f + 1) % this->size;;
        }
        
        cout << "Element is dequeued" << endl;
        return;
    }

    T peek()
    {
        if (this->isEmpty())
        {
            throw runtime_error("Queue is empty!");
            return T();
        }
        return this->arr[this->f];
    }

    void printQueue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = this->f;
        while (i <= this->r)
        {
            cout << this->arr[i] << " ";
            i = (i + 1) % this->size;
        }
        cout << endl;
    }

};

int main()
{
    CircularQueue<int> cq(7);

    cq.enqueue(5);
    cq.enqueue(7);
    cq.printQueue();

    cq.enqueue(0);
    cq.enqueue(9);
    cq.printQueue();

    cq.dequeue();
    cq.dequeue();
    cq.printQueue();

    cq.dequeue();
    cq.dequeue();
    cq.printQueue();

    cq.~CircularQueue();
    return 0;
}