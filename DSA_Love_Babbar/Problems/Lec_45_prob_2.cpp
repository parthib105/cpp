/*
    Middle of the Linked List

    Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a 
    singly linked list. However, if the list has an even number of nodes, we return the second 
    middle node.

    Example :

    Sample Input 1 :
    5
    1 2 3 4 5
    Sample Output 1 :
    3 4 5
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

int getLength(Node* head)
{
    int len = 0;
    while (head != NULL)
    {
        len += 1;
        head = head->next;
    }
    return len;
}

Node* findMiddle(Node* head)
{
    int lengthLL = getLength(head);
    int ans = lengthLL / 2;

    int cnt = 0;
    while (cnt < ans)
    {
        cnt += 1;
        head = head->next;
    }
    return head;
}

// Approach 2
Node* findMiddle2(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node* head = new Node(1);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 3);
    insertAtPosition(head, 4, 4);
    insertAtPosition(head, 5, 5);

    printList(head);
    Node* middle = findMiddle(head);
    printList(middle);

    Node* middle2 = findMiddle2(head);
    printList(middle2);
    return 0;
}