/*
    Reverse a Linked List

    Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

    For example:
    The given linked list is 1 -> 2 -> 3 -> 4-> NULL.
    Then the reverse linked list is 4 -> 3 -> 2 -> 1 -> NULL and the head of the reversed linked list will be 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
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
        cout << "Memory is free for node with value : " << val << endl;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void insertAtHead(int val)
    {
        Node *n = new Node(val);
        if (this->head == NULL)
        {
            this->head = n;
            this->tail = n;
            cout << "Node inserted at head" << endl;
            return;
        }
        n->next = this->head;
        this->head = n;
        cout << "Node inserted at head" << endl;
        return;
    }

    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (this->tail == NULL)
        {
            this->head = n;
            this->tail = n;
            cout << "Node inserted at tail" << endl;
            return;
        }
        this->tail->next = n;
        this->tail = n;
        cout << "Node inserted at tail" << endl;
        return;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos == 1)
        {
            insertAtHead(val);
            cout << "Node with value " << val << " is inserted at pos = " << pos << endl;
            return;
        }

        int count = 1;
        Node *curr = this->head;
        Node *prev = NULL;
        while ((curr != NULL) && (count < pos))
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        // If last node
        if ((pos - count) > 1)
        {
            cout << "Given position is greater than length of the Linked List. Can't insert " << val << endl;
            return;
        }
        else if (curr == NULL)
        {
            insertAtTail(val);
            cout << "Node with value " << val << " is inserted at pos = " << pos << endl;
            return;
        }

        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
        cout << "Node with value " << val << " is inserted at pos = " << pos << endl;
        return;
    }

    void deleteNode(int pos)
    {
        Node *curr = this->head;
        if (pos == 1)
        {
            this->head = this->head->next;
            delete curr;
            cout << "Node is deleted at pos = " << pos << endl;
            return;
        }

        int count = 1;
        Node *prev = NULL;
        while ((curr != NULL) && (count < pos))
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == NULL)
        {
            cout << "Position is greater than length of the Linked List. Can't delete element" << endl;
            return;
        }
        else if (curr->next == NULL)
        {
            this->tail = prev;
            prev->next = NULL;
            delete curr;
            cout << "Node is deleted at pos = " << pos << endl;
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Node is deleted at pos = " << pos << endl;
        return;
    }

    void reverseLL()        // Time COmplexity : O(n), Space Complexity : O(1)
    {
        if (this->head == NULL || this->head->next == NULL)
        {
            cout << "Linked List is reversed." << endl;
            return;
        }

        this->tail = this->head;

        Node* prev = NULL;
        Node* curr = this->head;
        Node* forward;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forward;
        }
        this->head = prev;
        cout << "Linked List is reversed." << endl;
        return;
    }

    void reveseLLRecur1(Node* curr, Node* prev)
    {
        // base case
        if (curr == NULL)
        {
            this->head = prev;
            return;
        }

        reveseLLRecur1(curr->next, curr);
        curr->next = prev;
    }

    Node* reveseLLRecur2(Node* Head)
    {
        // base case
        if (Head == NULL || Head->next == NULL)
        {
            return Head;
        }

        Node* smallerHead = reveseLLRecur2(Head->next);

        Head->next->next = Head;
        Head->next = NULL;

        return smallerHead;
    }

    void printLL()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // 10 21 3 2 4
    LinkedList LL;
    LL.insertAtPosition(10, 1);
    LL.insertAtPosition(21, 2);
    LL.insertAtPosition(3, 3);
    LL.insertAtPosition(2, 4);
    LL.insertAtPosition(4, 5);

    LL.printLL();
    Node* temphead = LL.reveseLLRecur2(LL.head);
    LL.head = temphead;
    LL.printLL();

    return 0;
}