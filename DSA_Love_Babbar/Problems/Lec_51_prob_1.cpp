/*
    Add two numbers

    Given two numbers, num1 and num2, represented by linked lists of size n and m respectively.
    The task is to return a linked list that represents the sum of these two numbers.

    For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25
    by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by
    2->1->5->null.

    You are required to return the head of the linked list 2->1->5->null.

    Note: There can be leading zeros in the input lists, but there should not be any leading zeros
    in the output list.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

void printList(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *reverseList(Node* &head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

void insertNode(Node* &head, Node* &tail, int val)
{
    Node* n = new Node(val);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = tail->next;
    }
    return;
}

Node* removeZeroes(Node* head)
{
    while (head && head->data == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

// Function to add two numbers represented by linked list.
Node* addTwoLists(Node* num1, Node* num2)
{
    // reverse the lists
    Node* newhead1 = reverseList(num1);
    Node* newhead2 = reverseList(num2);

    Node* newHead = NULL;
    Node* newTail = NULL;
    int carry = 0;
    while (newhead1 != NULL || newhead2 != NULL || carry != 0)
    {
        int val1 = 0, val2 = 0;
        if (newhead1 != NULL)
        {
            val1 = newhead1->data;
        }
        if (newhead2 != NULL)
        {
            val2 = newhead2->data;
        }
        int elmSum = val1 + val2 + carry;
        insertNode(newHead, newTail, elmSum % 10);
        carry = elmSum / 10;

        if (newhead1 != NULL)
        {
            newhead1 = newhead1->next;
        }
        if (newhead2 != NULL)
        {
            newhead2 = newhead2->next;
        }
    }

    Node* ans = reverseList(newHead);
    ans = removeZeroes(ans);
    if (ans)
    {
        return ans;
    }
    return new Node(0);
}

int main()
{
    Node* head1 = NULL;
    insertAtPosition(head1, 1, 9);
    insertAtPosition(head1, 2, 9);
    insertAtPosition(head1, 3, 9);
    insertAtPosition(head1, 4, 9);

    Node* head2 = NULL;
    insertAtPosition(head2, 1, 4);
    // insertAtPosition(head2, 2, 4);
    // insertAtPosition(head2, 3, 1);
    // insertAtPosition(head2, 4, 8);

    cout << "LL1 : ";
    printList(head1);

    cout << "LL2 : ";
    printList(head2);

    Node* added = addTwoLists(head1, head2);
    cout << endl << "Addition is : " << endl;
    printList(added);

    return 0;
}