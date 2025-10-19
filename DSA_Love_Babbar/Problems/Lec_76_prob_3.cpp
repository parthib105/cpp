/*
    Merge K sorted linked lists

    Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a
    single sorted linked list.

    Input:
    K = 4
    value = {{1,2,3},{4 5},{5 6},{7,8}}
    Output: 1 2 3 4 5 5 6 7 8
    Explanation:
    The test case has 4 sorted linked
    list of size 3, 2, 2, 2
    1st    list     1 -> 2-> 3
    2nd   list      4->5
    3rd    list      5->6
    4th    list      7->8
    The merged list will be
    1->2->3->4->5->5->6->7->8.
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
            delete this->next;
        }
    }
};

void printList(Node<int>* root)
{
    while (root != NULL)
    {
        cout << root->data << " -> ";
        root = root->next;
    }
    cout << "NULL";
}

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return (a->data > b->data);
    }
};

Node<int>* mergeKLists(vector<Node<int>*> arr, int K)
{
    // min heap
    priority_queue<Node<int>*, vector<Node<int>*>, compare> pq;

    Node<int>* dummyHead = new Node<int>(-1);
    Node<int>* temp = dummyHead;

    // push 0th element into queue
    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL)
        {
            pq.push(arr[i]);
        }
    }

    while (pq.size() > 0)
    {
        Node<int>* currNode = pq.top();
        pq.pop();

        temp->next = currNode;
        temp = temp->next;

        if (currNode->next != NULL)
        {
            pq.push(currNode->next);
        }
    }

    Node<int>* head = dummyHead->next;
    dummyHead->next = NULL;
    delete dummyHead;

    return head;
}

int main()
{
    Node<int>* head1 = new Node<int>(1);
    Node<int>* head2 = new Node<int>(4);
    Node<int>* head3 = new Node<int>(5);
    Node<int>* head4 = new Node<int>(7);
    Node<int>* temp = head1;

    temp->next = new Node<int>(2);
    temp = temp->next;
    temp->next = new Node<int>(3);

    temp = head2;
    temp->next = new Node<int>(5);

    temp = head3;
    temp->next = new Node<int>(6);

    temp = head4;
    temp->next = new Node<int>(8);

    vector<Node<int>*> kArray = {head1, head2, head3, head4};
    int k = 4;
    Node<int>* newRoot = mergeKLists(kArray, k);

    printList(newRoot);
    return 0;
}