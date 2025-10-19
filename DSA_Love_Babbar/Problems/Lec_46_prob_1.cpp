/*
    Reverse in k groups

    You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.

    Your task is to reverse the order of each group of 'k' consecutive nodes.

    For example, if the linked list is 1->2->3->4->5, and 'k' is 3. Thus, the final linked list being 3->2->1->5->4.

    Implement a function that performs this reversal, and returns the head of the modified linked list.

    Example:
    Input: 'list' = [1, 2, 3, 4], 'k' = 2

    Output: 2 1 4 3

    Explanation:
    We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the 
    next 2 elements, giving us 2->1->4->3.
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

Node* kReverse(Node* head, int k) {
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }

    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;
    int count = 0;
    while (currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count ++;
    }

    if (nextPtr != NULL)
    {
        head->next = kReverse(nextPtr, k);
    }

    return prevPtr;
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
    
    int k = 2;
    Node* newHead = kReverse(head, k);
    printList(newHead);
    return 0;
}