/*
    Linked List Introduction

    -> A linear data structure consists of collection of node
    -> Node - (data, next), next -> link to next node
    -> Dynamic data structure, can grow/shrink on run time
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
        return;
    }
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int data)
{
    Node* n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtPosition(Node* &head, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(cnt < (pos - 1))
    {
        cnt ++;
        temp = temp->next;
    } 
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List is enpty!" << endl;
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    if (head->data == val)
    {
        head = head->next;
        curr->next = NULL;
        delete curr;
        return;
    }

    while ((curr != NULL) && (curr->data != val))
    {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL)
    {
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
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
    Node* head = new Node(10);
    printList(head);
    
    insertAtHead(head, 12);
    cout << "Inserted at head :" << endl;
    printList(head);
    cout << endl;

    insertAtHead(head, 15);
    cout << "Inserted at head :" << endl;
    printList(head);
    cout << endl;

    insertAtHead(head, 14);
    cout << "Inserted at head :" << endl;
    printList(head);
    cout << endl;
    
    insertAtTail(head, 20);
    cout << "Inserted at tail :" << endl;
    printList(head);
    cout << endl;

    insertAtTail(head, 29);
    cout << "Inserted at tail :" << endl;
    printList(head);
    cout << endl;

    insertAtPosition(head, 2, 34);
    cout << "Inserted at position 2 :" << endl;
    printList(head);
    cout << endl;

    deleteNode(head, 20);
    printList(head);
    cout << endl;

    deleteNode(head, 14);
    printList(head);
    cout << endl;

    deleteNode(head, 29);
    printList(head);
    cout << endl;

    return 0;
}