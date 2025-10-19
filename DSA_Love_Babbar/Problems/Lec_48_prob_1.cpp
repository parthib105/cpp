/*
    Remove duplicates from a sorted list
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        cout << "Memory is free for node with value : " <<  val << endl;
    }
};

void insertAtHead(Node* &head, int data)
{
    Node* n = new Node(data);
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

void insertAtPosition(Node* &head, int pos, int data)
{
    Node* nodeToInsert = new Node(data);

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node* prev = NULL;
    Node* curr = head;
    while((curr != NULL) && (cnt < pos))
    {
        cnt ++;
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
    if(head == NULL)
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

void removeDuplicate(Node* &head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL)
    {
        if (prev->data == curr->data)
        {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 2);
    insertAtPosition(head, 4, 2);
    insertAtPosition(head, 5, 3);
    // insertAtPosition(head, 6, 4);
    printList(head);
    removeDuplicate(head);
    printList(head);
    return 0;
}