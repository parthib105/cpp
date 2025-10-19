#include<iostream>
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        TreeNode* tree1 = p;
        TreeNode* tree2 = q;

        if ( tree1 == nullptr && tree2 == nullptr){
            return true;
        }
        vector<int> l;
        while(tree1 != nullptr && tree2 != nullptr){
            l.push_back(tree1->val - tree2->val);
            if (l.back() == 0){
                l.pop_back();
                tree1 = tree1->left;
                tree2 = tree2->left;
            }
            else{
                return false;
            }
        }

        vector<int> r;
        while(p != nullptr && q != nullptr){
            r.push_back(p->val - q->val);
            if (r.back() == 0){
                r.pop_back();
                p = p->right;
                q = q->right;
            }
            else{
                return false;
            }
        }
        return l.empty() && r.empty();
    }
};

int main()
{
    return 0;
}