#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;

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

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *n = new Node(d);
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

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeSorted(Node *&left, Node *right)
{
    if (right == NULL)
    {
        return left;
    }
    if (left == NULL)
    {
        return right;
    }

    Node *prev = left;
    Node *curr = left->next;
    Node *temp = right;
    Node *merged = left;

    if (right->data < left->data)
    {
        prev = right;
        curr = right->next;
        temp = left;
        merged = right;
    }

    while (temp != NULL && curr != NULL)
    {
        if (temp->data >= prev->data && temp->data <= curr->data)
        {
            Node *tempNext = temp->next;
            prev->next = temp;
            temp->next = curr;

            temp = tempNext;
            prev = prev->next;
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

    return merged;
}

Node *mergeSort(Node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // find mid, break into two halves
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls to both parts to sort both parts
    left = mergeSort(left);
    right = mergeSort(right);

    // merge sorted lists
    Node *res = mergeSorted(left, right);

    return res;
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

int main()
{
    Node *head = NULL;
    insertAtPosition(head, 1, 4);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 1);
    insertAtPosition(head, 4, 3);
    insertAtPosition(head, 5, 7);

    cout << "Original List : ";
    printList(head);

    Node* sorted = mergeSort(head);
    cout << "Sorted List : ";
    printList(sorted);
    return 0;
}