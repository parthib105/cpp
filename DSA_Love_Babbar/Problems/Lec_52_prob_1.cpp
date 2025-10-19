/*
    Clone a linked list

    You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. 
    You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. 
    a->arb = b (arb is pointer to random node).

    Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set 
    to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to 
    new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
    None of the pointers in the new list should point to nodes in the original list.

    For example, if there are two nodes X and Y in the original list, where X.arb --> Y, then for the corresponding 
    two nodes x and y in the copied list, x.arb --> y.

    Return the head of the copied linked list.
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* arb;

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

void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* n = new Node(d);
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

void connectRandom(Node* &head, vector<pair<int, int>> reff)
{
    Node* curr = head;
    for (auto i : reff)
    {
        if (curr->data == i.first)
        {
            Node* temp = head;
            while (temp != NULL && temp->data != i.second)
            {
                temp = temp->next;
            }
            curr->arb = temp;
        }
        curr = curr->next;
    }
}


/******************** Approach 2 ********************/
// solution with T.C. : O(n), S.C. : O(n)
Node* copyList(Node* &head)     
{
    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* Old = head;
    while (Old != NULL)
    {
        insertAtTail(newHead, newTail, Old->data);
        Old = Old->next;
    }

    // storing in map
    unordered_map<Node*, Node*> oldToNew;
    Old = head;
    Node* New = newHead;
    while (Old != NULL)
    {
        oldToNew[Old] = New;
        Old = Old->next;
        New = New->next;
    }

    New = newHead;
    Old = head;
    while (Old != NULL)
    {
        New->arb = oldToNew[Old->arb];
        New = New->next;
        Old = Old->next;
    }
    return newHead;
}
/****************************************************/



/******************** Approach 3 ********************/
// solution with TC : O(n) & SC : O(1)

Node* copyList2(Node* &head)
{
    // step 1 : copy list with next ptr
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* originalNode = head;
    while (originalNode != NULL)
    {
        insertAtTail(cloneHead, cloneTail, originalNode->data);
        originalNode = originalNode->next;
    }

    // step 2 : add cloneNodes in between original list
    originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* nextNode = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = nextNode;

        nextNode = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = nextNode;
    }

    // step 3 : copy arbitrary pointers
    originalNode = head;
    cloneNode = originalNode->next;
    while (cloneNode != NULL && originalNode != NULL)
    {
        if (originalNode->arb != NULL)
        {
            cloneNode->arb = originalNode->arb->next;
        }
        else
        {
            cloneNode->arb = originalNode->arb;
        }

        originalNode = cloneNode->next;
        if (originalNode != NULL && originalNode->next != NULL)
        {
            cloneNode = originalNode->next;
        }
    }


    // Revert changes made in step 2
    originalNode = head;
    cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step 5 : return ans
    return cloneHead;
}


/****************************************************/

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
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 3);
    insertAtPosition(head, 4, 4);

    vector<pair<int, int>> reff;
    reff.push_back(make_pair(1, 3));
    reff.push_back(make_pair(2, 4));

    connectRandom(head, reff);

    cout << "LL1 : ";
    printList(head);
    return 0;
}