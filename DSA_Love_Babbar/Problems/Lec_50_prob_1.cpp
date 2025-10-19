/*
    Check palindrome

    Given a singly linked list of size N of integers. The task is to check if the given linked list
    is palindrome or not.

    Input:
    N = 3
    value[] = {1,2,1}
    Output: 1
    Explanation: The given linked list is
    1 2 1 , which is a palindrome and
    Hence, the output is 1.
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

bool isPalindrome(vector<int> &list)
{
    if (list.size() == 1)
    {
        return true;
    }

    bool ans = true;

    int i = 0;
    int j = list.size() - 1;
    while (i < j)
    {
        if (list[i] != list[j])
        {
            ans = false;
            break;
        }
        i++;
        j--;
    }
    return ans;
}

// Function to check whether the list is palindrome.
// Approach 1
bool isLLPalindrome(Node* head)
{
    if (head == NULL)
    {
        return false;
    }

    vector<int> list;
    Node *temp = head;
    while (temp != NULL)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    return isPalindrome(list);
}


// approach 2
Node* getMid(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool ispalindrome2(Node* head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // step 1 : get mid pointer
    Node* mid = getMid(head);

    // step 2 : reverse after mid elm
    Node* prevPtr = NULL;
    Node* currPtr = mid->next;
    Node* nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    mid->next = prevPtr;

    // step 3 : compare
    Node* head1 = head;
    Node* head2 = mid->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    insertAtPosition(head, 1, 2);
    insertAtPosition(head, 2, 1);
    insertAtPosition(head, 3, 8);
    insertAtPosition(head, 4, 9);
    insertAtPosition(head, 5, 5);
    insertAtPosition(head, 6, 2);

    cout << "LL1 : ";
    printList(head);

    if (ispalindrome2(head))
    {
        cout << "Linked List is palindrome" << endl;
    }
    else
    {
        cout << "Linked List is not palindrome" << endl;
    }
    return 0;
}