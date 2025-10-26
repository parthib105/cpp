/*
    Serialize and Deserialize Binary Tree

    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.


    Example 1:


    Input: root = [1,2,3,null,null,4,5]
    Output: [1,2,3,null,null,4,5]
    Example 2:

    Input: root = []
    Output: []
    

    Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode()
    {
        if (this->left)
            delete this->left;
        if (this->right)
            delete this->right;
    }
};

TreeNode<int> *buildTree(vector<int> &lo)
{
    int i = 1, n = lo.size();
    if (n == 0)
        return nullptr;

    TreeNode<int> *root = new TreeNode<int>(lo[0]);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty() && i < n)
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (i < n && lo[i] != -1)
        {
            curr->left = new TreeNode<int>(lo[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && lo[i] != -1)
        {
            curr->right = new TreeNode<int>(lo[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void printLevelOrder(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (!curr)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

class Codec 
{
private:
    string serializeLO(TreeNode<int>* root) {
        if (!root)
            return "";

        string s = "";
        queue<TreeNode<int>*> q;

        q.push(root);
        while (!q.empty()) {
            TreeNode<int>* curNode = q.front();
            q.pop();

            if (!curNode)
                s += "N,";
            else
                s += to_string(curNode->data) + ',';
            
            if (curNode) {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode<int>* deserializeLO(string dataStream)
    {
        if (dataStream.length() == 0)
            return nullptr;

        string str;
        stringstream s(dataStream);
        getline(s, str, ',');

        TreeNode<int>* root = new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode<int>* cur = q.front();
            q.pop();

            // left child
            getline(s, str, ',');
            if (str == "N")
                cur->left = nullptr;
            else
            {
                TreeNode<int>* lNode = new TreeNode<int>(stoi(str));
                cur->left = lNode;
                q.push(lNode);
            } 

            // right child
            getline(s, str, ',');
            if (str == "N")
                cur->right = nullptr;
            else
            {
                TreeNode<int>* rNode = new TreeNode<int>(stoi(str));
                cur->right = rNode;
                q.push(rNode);
            }   
        }
        return root;
    }

    string serializePreO(TreeNode<int>* root)
    {
        if (!root)
            return "N,";
        
        string lSub = serializePreO(root->left);
        string rSub = serializePreO(root->right);
        return to_string(root->data) + "," + lSub + rSub;
    }

    TreeNode<int>* deserializePreOUtil(queue<string> &q) 
    {
        string str = q.front();
        q.pop();

        if (str == "N")
            return nullptr;

        TreeNode<int>* node = new TreeNode<int>(stoi(str));
        node->left = deserializePreOUtil(q);
        node->right = deserializePreOUtil(q);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserializePreO(string dataStream) 
    {
        if (dataStream.empty()) 
            return nullptr;

        string str;
        stringstream s(dataStream);
        queue<string> q;

        while (getline(s, str, ',')) {
            q.push(str);
        }

        return deserializePreOUtil(q);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode<int>* root) 
    {
        // Using preorder
        // return serializePreO(root);

        // using level order
        return serializeLO(root);
    }

    // Decodes your encoded data to tree.
    TreeNode<int>* deserialize(string dataStream) 
    {
        // Using preorder
        // return deserializePreO(dataStream)

        // using level order
        return deserializeLO(dataStream);
    }
};

int main()
{
    vector<int> lo = {1, 5, 3, -1, 4, 10, 6, 9, 2};
    TreeNode<int>* root = buildTree(lo);

    Codec cod;
    string ser = cod.serialize(root);

    cout << ser << endl;

    TreeNode<int>* newRoot = cod.deserialize(ser);

    printLevelOrder(newRoot);
    return 0;
}