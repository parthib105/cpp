/*
    Implement stacks using Linked List
*/

#include<bits/stdc++.h>
using namespace std;

template<class T> class Node
{
public:
    T data;
    Node<T>* next;

    Node(T d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        if (!this->next)
        {
            this->next = NULL;
        }
    }
};

template <class T> class stackLL
{
private:
    Node<T>* top;
    Node<T>* head;
    int size;
    int noOfElm;

public:

    stackLL(int size)
    {
        this->top = NULL;
        this->head = NULL;
        this->size = size;
        this->noOfElm = 0;
    }

    bool isEmpty()
    {
        if (this->top == NULL)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (this->noOfElm == this->size)
        {
            return true;
        }
        return false;
    }

    void push(T elm)
    {
        Node<T>* newNode = new Node<T>(elm);
        if (this->isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else if (this->head == NULL && this->top == NULL)
        {
            this->head = newNode;
            this->top = newNode;
            this->noOfElm += 1;
            return;
        }
        this->top->next = newNode;
        this->top = this->top->next;
        this->noOfElm += 1;
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else if (this->head == this->top)
        {
            delete this->top;
            this->head = NULL;
            this->top = NULL;
            this->noOfElm -= 1;
            return;
        }
        Node<T>* temp = this->head;
        while (temp != NULL && temp->next != this->top)
        {
            temp = temp->next;
        }
        this->noOfElm -= 1;
        Node<T>* toDelete = this->top;
        temp->next = NULL;
        this->top = temp;
        delete toDelete;
    }

    T peek()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return this->top->data;
    }

    void printStack()
    {
        Node<T>* temp = this->head;
        while (temp != this->top)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main()
{
    stackLL<int> stk(5);

    stk.push(4);
    stk.push(8);
    stk.push(9);
    stk.push(1);
    cout << stk.peek() << endl;

    stk.pop();
    cout << stk.peek() << endl;

    stk.pop();
    cout << stk.peek() << endl;

    stk.pop();
    cout << stk.peek() << endl;

    stk.pop();
    cout << stk.peek() << endl;

    return 0;
}