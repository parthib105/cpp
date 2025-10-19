/*
    Sort 0, 1, 2 in LL

    Problem statement
    
    Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
    You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

    Sample Input 1:
    1->0->2->1->0->2->1->NULL


    Sample Output 1:
    0->0->1->1->1->2->2->NULL

    Explanation: 
    In this example, the original linked list contains two 0s, three 1s, and two 2s. 
    The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.
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

// Approach 1 : count 0, 1 & 2 and traverse the LL and make entries 0, 1, 2 untill all counts become zero
void sortedList(Node* &head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount ++;
        }
        else if (temp->data == 1)
        {
            oneCount ++;
        }
        else
        {
            twoCount ++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount --;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount --;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount --;
        }
        temp = temp->next;
    }
}

// Apporach 2 : Make separate lists
void sortedList2(Node* &head)
{
    Node* Head_0 = new Node(-1);
    Node* Tail_0 = Head_0;
    Node* Head_1 = new Node(-2);
    Node* Tail_1 = Head_1;
    Node* Head_2 = new Node(-3);
    Node* Tail_2 = Head_2;

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            Tail_0->next = temp;
            Tail_0 = temp;
        }
        else if (temp->data == 1)
        {
            Tail_1->next = temp;
            Tail_1 = temp;
        }
        else
        {
            Tail_2->next = temp;
            Tail_2 = temp;
        }
        temp = temp->next;
    }

    if (Head_1->next == NULL)
    {
        Tail_0->next = Head_2->next;
    }
    else
    {
        Tail_0->next = Head_1->next;
        Tail_1->next = Head_2->next;
    }
    Tail_2->next = NULL;
    head = Head_0->next;

    delete Head_0;
    delete Head_1;
    delete Head_2;
}

int main()
{
    Node* head = NULL;
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 0);
    insertAtPosition(head, 3, 2);
    insertAtPosition(head, 4, 1);
    insertAtPosition(head, 5, 0);
    insertAtPosition(head, 6, 2);
    insertAtPosition(head, 7, 1);
    printList(head);
    sortedList2(head);
    printList(head);
    return 0;
}