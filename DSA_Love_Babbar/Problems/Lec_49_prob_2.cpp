/*
    Merge two sorted linked lists

    Problem statement
    
    You are given two sorted linked lists. You have to merge them to produce a combined sorted 
    linked list. You need to return the head of the final linked list.

    Note:

    The given linked lists may or may not be null.

    For example:

    If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

    The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
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

Node* mergeTwoSortedLists(Node* head1, Node* head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    Node* prev = head1;
    Node* curr = head1->next;
    Node* temp = head2;

    while (temp != NULL && curr != NULL)
    {
        if (temp->data >= prev->data && temp->data <= curr->data)
        {
            Node* tempNext = temp->next;
            prev->next = temp;
            temp->next = curr;

            prev = temp;
            temp = tempNext;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr == NULL)
    {
        prev->next = temp;
    }

    return head1;
}

int main()
{
    Node* head1 = NULL;
    insertAtPosition(head1, 1, 1);
    insertAtPosition(head1, 2, 3);
    insertAtPosition(head1, 3, 5);
    insertAtPosition(head1, 4, 7);

    Node* head2 = NULL;
    insertAtPosition(head2, 1, 2);
    insertAtPosition(head2, 2, 4);
    insertAtPosition(head2, 3, 10);
    insertAtPosition(head2, 4, 8);

    cout << "LL1 : ";
    printList(head1);

    cout << "LL2 : ";
    printList(head2);

    Node* newHead = mergeTwoSortedLists(head1, head2);
    cout << "Sorted Linked List : " << endl;
    printList(newHead);
    return 0;
}