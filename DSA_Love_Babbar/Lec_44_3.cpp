/*
    Circular Linked List
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        cout << "Memory if free for node with value " << val << endl;
    }
};

class CircularLinkedList
{
public:
    Node* head = NULL;
    int len = 0;

    bool insertNode(int elm, int val)
    {
        Node* newNode = new Node(val);
        if (this->head == NULL)
        {
            this->head = newNode;
            newNode->next = this->head;
            this->len += 1;
            return true;
        }
        else if (this->head->data == elm)
        {
            newNode->next = this->head->next;
            this->head->next = newNode;
            this->len += 1;
            return true;
        }
        
        Node* currNode = this->head->next;
        int countHead = 1;
        while (currNode->data != elm)
        {
            if (currNode->data = this->head->data)
            {
                countHead ++;
                break;
            }
            currNode = currNode->next;
        }

        if (countHead == 2)
        {
            return false; 
        }

        newNode->next = currNode->next;
        currNode->next = newNode;
        this->len += 1;
        return true;
    }

    bool deleteNode(int val)
    {
        if (this->head == NULL)
        {
            return false;
        }

        Node* curr = this->head->next;
        Node* prev = this->head;
        int visited = prev->data;

        while (curr->data != val)
        {
            if (curr->data == visited)
            {
                return false;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == this->head)
        {
            this->head = prev;
        }
        prev->next = curr->next;
        delete curr;
        this->len -= 1;
        return true;
    }

    void printCLL()
    {
        if (this->head == NULL)
        {
            cout << "Linked List is enpty!" << endl;
            return;
        }
        Node* temp = this->head->next;
        cout << this->head->data << " -> ";
        while (temp != this->head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << this->head->data << endl;
    }
};

int main()
{
    CircularLinkedList CLL;
    
    if (CLL.insertNode(-1, 5))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't insert element with given position" << endl;
    }

    if (CLL.insertNode(5, 2))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't insert element with given position" << endl;
    }

    if (CLL.insertNode(5, 6))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't insert element with given position" << endl;
    }

    if (CLL.insertNode(6, 8))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't insert element with given position" << endl;
    }

    if (CLL.insertNode(6, 20))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't insert element with given position" << endl;
    }

    if (CLL.deleteNode(20))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't delete element! Either it is not present or list is empty" << endl;
    }

    if (CLL.deleteNode(5))
    {
        CLL.printCLL();
        cout << "Length : " << CLL.len << endl;
    }
    else
    {
        cout << "Can't delete element! Either it is not present or list is empty" << endl;
    }
    return 0;
}