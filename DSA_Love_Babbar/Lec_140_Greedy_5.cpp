/*
    Huffman Encoding

    Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i]
    frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

    Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of
    Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and
    other one to the right.

    Example 1:

    S = "abcdef"
    f[] = {5, 9, 12, 13, 16, 45}
    Output:
    0 100 101 1100 1101 111
    Explanation:
    Steps to print codes from Huffman Tree
    HuffmanCodes will be:
    f : 0
    c : 100
    d : 101
    a : 1100
    b : 1101
    e : 111
    Hence printing them in the PreOrder of Binary
    Tree.

    Expected Time complexity: O(N * log(N))
    Expected Space complexity: O(N)

    Constraints:
    1 <= N <= 26
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

void traverse(node *root, string code, vector<string> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(code);
        return;
    }

    traverse(root->left, code + '0', ans);
    traverse(root->right, code + '1', ans);
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    priority_queue<node *, vector<node *>, compare> pq;
    for (int i = 0; i < N; i++)
    {
        node *n = new node(f[i]);
        pq.push(n);
    }

    while (pq.size() != 1)
    {
        node *LC = pq.top();
        pq.pop();

        node *RC = pq.top();
        pq.pop();

        node *n = new node(LC->data + RC->data);
        n->left = LC;
        n->right = RC;
        pq.push(n);
    }

    node *root = pq.top();
    vector<string> ans;
    traverse(root, "", ans);
    return ans;
}

int main()
{
    int N = 6;
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};

    vector<string> ans = huffmanCodes(S, f, N);
    for (auto str : ans)
    {
        cout << str << " ";
    }
    return 0;
}