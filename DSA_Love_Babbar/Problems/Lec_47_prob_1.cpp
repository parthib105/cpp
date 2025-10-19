/*
    Detect and Remove cycle
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

bool detectLoop(Node* &head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL)
    {
        if (visited[temp])
        {
            cout << "Loop present on element : " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

bool floydDetectLoop(Node* &head)
{
    if (head == NULL)
    {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

Node* getMeetingNode(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* meet = getMeetingNode(head);
    Node* slow = head;
    while (slow != meet)
    {
        slow = slow->next;
        meet = meet->next;
    }
    return slow;
}

void removeLoop(Node* &head)
{
    if (head == NULL)
    {
        return;
    }
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
       
    return 0;
}