/*
    Double Ended Queue
*/

#include<bits/stdc++.h>
using namespace std;

template <class T> class DeQue
{
private:
    T* arr;
    int size;
    int f;
    int r;

public:
    DeQue(int n)
    {
        this->size = n;
        this->arr = new T[n];
        this->f = -1;
        this->r = -1;
    }

    ~DeQue()
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

    void push_front(int x)
    {
        if (this->isFull())
        {
            cout << "Queue if full! Can't push element from front" << endl;
            return;
        }
        else if (this->isEmpty())
        {
            this->f = 0;
            this->r = 0;
        }
        else
        {
            this->f = (this->size + this->f - 1) % this->size;
        }
        this->arr[this->f] = x;
        return;
    }

    void push_back(int x)
    {
        if (this->isFull())
        {
            cout << "Queue if full! Can't push element from back" << endl;
            return;
        }
        else if (this->isEmpty())
        {
            this->f = 0;
            this->r = 0;
        }
        else
        {
            this->r = (this->r + 1) % this->size;
        }
        this->arr[this->r] = x;
        return;
    }

    void pop_front()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty! Can't pop element from front" << endl;
            return;
        }
        else if (this->f == this->r)
        {
            this->f = -1;
            this->r = -1;
        }
        else
        {
            this->f = (this->f + 1) % this->size;
        }
        cout << "Element is popped from front" << endl;
        return;
    }

    void pop_back()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty! Can't pop element from back" << endl;
            return;
        }
        else if (this->f == this->r)
        {
            this->f = -1;
            this->r = -1;
        }
        else
        {
            this->r = (this->size + this->r - 1) % this->size;
        }
        cout << "Element is popped from back" << endl;
        return;
    }
};

int main()
{
    
    return 0;
}