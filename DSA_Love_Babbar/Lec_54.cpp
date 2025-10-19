/*
    Introduction to Stack : Implementation
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T> class Stack
{
private:
    T* arr;
    int size;
    T top;

public:
    Stack(int sz)
    {
        this->size = sz;
        this->arr = new T[this->size];
        this->top = -1;
    }

    void push(T elm)
    {
        if ((this->size - this->top) > 1)
        {
            this->top ++;
            this->arr[this->top] = elm;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (this->top >= 0)
        {
            this->top --;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    T peek()
    {
        if (this->top >= 0 && this->top < this->size)
        {
            return this->arr[this->top];
        }
        cout << "stack is empty" << endl;
        return -1;
    }

    bool isEmpty()
    {
        if (this->top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (this->top >= this->size - 1)
        {
            return true;
        }
        false;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<int> st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout << "Top element of the stack : " << st.peek() << endl;
    st.pop();
    cout << "Top element of the stack : " << st.peek() << endl;
    st.pop();
    cout << "Top element of the stack : " << st.peek() << endl;
    st.pop();
    cout << "Top element of the stack : " << st.peek() << endl;
    return 0;
}