/*
    Doubly linked list
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        if (this->prev != NULL)
        {
            this->prev = NULL;
        }
        cout << "Memory is free for the node with value " << val << endl;
    }
};

class DoublyLinkedList
{
public:
    Node* head = NULL;
    Node* tail = NULL;
    int len = 0;

    void printLL()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is enpty!" << endl;
            return;
        }
        Node* temp = this->head;
        cout << "NULL <- ";
        while (temp->next != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << temp->data << " -> NULL" << endl; 
    }

    bool insertAtHead(int val)
    {
        Node* newNode = new Node(val);
        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
            this->len ++;
            return true;
        }
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
        this->len ++;
        return true;
    }

    bool insertAtTail(int val)
    {
        Node* newNode = new Node(val);
        if (this->tail == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
            this->len ++;
            return true;
        }
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->len ++;
        return true;
    }

    bool insertAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            return insertAtHead(val);
        }
        else if (pos == this->len + 1)
        {
            return insertAtTail(val);
        }
        else if (pos > this->len + 1)
        {
            return false;
        }

        Node* currPtr = this->head;
        Node* prevPtr = NULL;
        int cnt = 1; 
        while ((currPtr != NULL) && (cnt < pos))
        {
            cnt ++;
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        Node* newNode = new Node(val);
        prevPtr->next = newNode;
        newNode->prev = prevPtr;
        newNode->next = currPtr;
        currPtr->prev = newNode;
        len ++;
        return true;
    }

    bool deleteNode(int pos)
    {
        if (pos == 1)
        {
            Node* temp = this->head;
            this->head = this->head->next;
            this->head->prev = NULL;

            delete temp;
            len -= 1;
            return true;
        }
        else if (pos == this->len)
        {
            Node* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = NULL;

            delete temp;
            len -= 1;
            return true;
        }
        else if (pos > this->len + 1)
        {
            return false;
        }

        Node* currPtr = this->head;
        Node* prevPtr = NULL;
        int cnt = 1; 
        while ((currPtr != NULL) && (cnt < pos))
        {
            cnt ++;
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        prevPtr->next = currPtr->next;
        currPtr->next->prev = prevPtr;

        delete currPtr;
        len -= 1;
        return true;
    }
};

int main()
{
    DoublyLinkedList DLL;

    if (DLL.insertAtHead(10))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }

    if (DLL.insertAtHead(11))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }

    if (DLL.insertAtHead(13))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }

    if (DLL.insertAtTail(25))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }

    if (DLL.insertAtHead(8))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }

    if (DLL.insertAtPosition(29, 2))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }
    else
    {
        cerr << "Given position is greater than the length of the DLL" << endl;
    }   

    if (DLL.insertAtPosition(100, 4))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }
    else
    {
        cerr << "Given position is greater than the length of the DLL" << endl;
    }

    if (DLL.deleteNode(6))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }
    else
    {
        cerr << "Given position is greater than the length of the DLL" << endl;
    }

    if (DLL.deleteNode(6))
    {
        DLL.printLL();
        cout << "Length : " << DLL.len << endl << endl;
    }
    else
    {
        cerr << "Given position is greater than the length of the DLL" << endl;
    }

    return 0;
}