/*
    Is Circular?
    You are given the head of a linked list containing integers. You need to find out whether the given linked list is 
    circular or not.

    Note :

    1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form 
       a circle i.e. the next pointer of last node points to the first node.
    2. An empty linked will also be considered as circular.
    3. All the integers in the linked list are unique.
    4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer 
       (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.

*/

#include <bits/stdc++.h>
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

bool isCircular(Node* &head)
{
    if (head == NULL)
    {
        return true;
    }

    Node* temp = head->next;
    while (temp != NULL)
    {
        if (temp == head)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
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

int main()
{
    Node* head = NULL;
    insertAtPosition(head, 1, 5);
    insertAtPosition(head, 2, 6);
    insertAtPosition(head, 3, 8);
    insertAtPosition(head, 4, 1);
    insertAtPosition(head, 5, 9);
    insertAtPosition(head, 6, 2);
    printList(head);

    cout << isCircular(head) << endl;
    return 0;
}