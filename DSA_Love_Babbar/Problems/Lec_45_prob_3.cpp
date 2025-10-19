#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

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

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        cout << "Node inserted at head" << endl;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << "Node inserted at head" << endl;
    return;
}

void insertAtPosition(Node* &head, int val, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }

    Node *currPtr = head;
    Node *prevPtr = NULL;
    int cnt = 1;
    while ((currPtr != NULL) && (cnt < pos))
    {
        cnt++;
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }

    if ((pos - cnt) > 1)
    {
        cout << "Given position is greater than length of the linked list. Can't insert element" << endl;
        return;
    }

    Node *newNode = new Node(val);
    prevPtr->next = newNode;
    newNode->prev = prevPtr;
    newNode->next = currPtr;
    if (currPtr != NULL)
    {
        currPtr->prev = newNode;
    }

    cout << "Given node with value " << val << " is inserted at position " << pos << endl;
    return;
}

void reverseDLL(Node* &head)
{
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;

        // change links
        currPtr->next = prevPtr;
        currPtr->prev = nextPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    head = prevPtr;
}

void reverseDLLRecur(Node* &head, Node* currPtr, Node* prevPtr)
{
    if (currPtr == NULL)
    {
        head = prevPtr;
        return;
    }

    Node* nextPtr = currPtr->next;
    reverseDLLRecur(head, nextPtr, currPtr);
    currPtr->next = prevPtr;
    currPtr->prev = nextPtr;
}

void printLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is enpty!" << endl;
        return;
    }
    Node *temp = head;
    cout << "NULL <- ";
    while (temp->next != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << temp->data << " -> NULL" << endl;
}

int main()
{
    Node* head = new Node(5);
    insertAtPosition(head, 6, 2);
    insertAtPosition(head, 8, 3);
    insertAtPosition(head, 1, 4);
    insertAtPosition(head, 9, 5);
    insertAtPosition(head, 2, 6);

    printLL(head);
    reverseDLLRecur(head, head, NULL);
    printLL(head);


    return 0;
}