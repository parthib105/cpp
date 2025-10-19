/*
    Merge sort in Linked List
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* arb;

    // constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->arb = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        if (this->arb != NULL)
        {
            this->arb = NULL;
        }
        cout << "Memory is free for node with value : " << val << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        cout << "Node is inserted at position 1" << endl;
        return;
    }
    n->next = head;
    head = n;
    cout << "Node is inserted at position 1" << endl;
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* n = new Node(d);
    if (tail == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = tail->next;
}

void insertAtPosition(Node *&head, int pos, int data)
{
    Node *nodeToInsert = new Node(data);

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node *prev = NULL;
    Node *curr = head;
    while ((curr != NULL) && (cnt < pos))
    {
        cnt++;
        prev = curr;
        curr = curr->next;
    }

    if ((pos - cnt) > 2)
    {
        cout << "Can't insert element. Position is greater than size" << endl;
        return;
    }
    else if (curr == NULL)
    {
        prev->next = nodeToInsert;
    }

    nodeToInsert->next = curr;
    prev->next = nodeToInsert;

    cout << "Node inserted at position " << pos << endl;
}

void printList(Node* &head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    
    return 0;
}