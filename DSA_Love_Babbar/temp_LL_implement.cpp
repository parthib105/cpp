#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with value : " <<  val << endl;
    }
};

class LinkedList
{
public:
    Node* head = NULL;
    Node* tail = NULL;

    void insertAtHead(int val)
    {
        Node* n = new Node(val);
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
        Node* n = new Node(val);
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
        Node* curr = this->head;
        Node* prev = NULL;
        while ((curr != NULL) && (count < pos))
        {
            prev = curr;
            curr = curr->next;
            count ++;
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

        Node* newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
        cout << "Node with value " << val << " is inserted at pos = " << pos << endl;
        return;
    }

    void deleteNode(int pos)
    {
        Node* curr = this->head;
        if (pos == 1)
        {
            this->head = this->head->next;
            curr->next = NULL;
            cout << "Node is deleted at pos = " << pos << endl;
            delete curr;
            return;
        }

        int count = 1;
        Node* prev = NULL;
        while ((curr != NULL) && (count < pos))
        {
            prev = curr;
            curr = curr->next;
            count ++;
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
        curr->next = NULL;
        delete curr;
        cout << "Node is deleted at pos = " << pos << endl;
        return;
    }

    void printLL()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        Node* temp = this->head;
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
    LinkedList LL;
    
    // insert nodes
    LL.insertAtHead(3);
    LL.printLL();

    LL.insertAtHead(5);
    LL.printLL();

    LL.insertAtTail(7);
    LL.printLL();

    LL.insertAtTail(11);
    LL.printLL();

    LL.insertAtPosition(67, 5);
    LL.printLL();

    LL.insertAtPosition(76, 9);
    LL.printLL();

    LL.deleteNode(9);
    LL.printLL();

    LL.deleteNode(1);
    LL.printLL();

    LL.deleteNode(3);
    LL.printLL();
    return 0;
}