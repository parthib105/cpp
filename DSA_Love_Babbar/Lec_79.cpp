/*
    Trie
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char val;
    vector<TrieNode*> children;
    bool isTerminal;

    TrieNode(char c)
    {
        this->val = c;
        this->isTerminal = false;
        this->children.resize(26, nullptr);
    }

    bool isEmpty()
    {
        for (int i = 0; i < 26; i++)
        {
            if (this->children[i] != NULL)
                return false;
        }
        return true;
    }
};

class Trie 
{
private:
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode('#');
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode(ch);

            // moves to the reference trie
            curr = curr->children[idx]; 
        }
        curr->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* curr = this->root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return curr->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = this->root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (!curr->children[idx])
                return false;
            curr = curr->children[idx];
        }
        return true;
    }

    void deleteWord(string& word)
    {
        TrieNode* curr = this->root;
        stack<pair<TrieNode*, int>> st;

        // store the words to be deleted
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (!curr->children[idx])
            {
                cout << "Word not present, can't delete" << endl;
                return;
            }
            st.push({curr, idx});
            curr = curr->children[idx];
        }

        // if word not present as complete word
        if (!curr->isTerminal)
        {
            cout << "Word not present, can't delete" << endl;
            return;
        }

        // unmark terminal
        curr->isTerminal = false;

        // cleanup unnecessary nodes (bottom-up)
        while (!st.empty())
        {
            TrieNode* par = st.top().first;
            int idx = st.top().second;
            st.pop();

            TrieNode* child = par->children[idx];
            if (child->isEmpty() && !child->isTerminal)
            {
                delete child;
                par->children[idx] = nullptr;
            }
            else
                break;
        }
    }
};

int main()
{
    Trie* newTrie = new Trie();

    newTrie->insert("parthib");
    newTrie->insert("ghosh");
    newTrie->insert("shreya");

    string to_delete = "ghosh";
    newTrie->deleteWord(to_delete);

    string w = "ghosh";

    if (newTrie->search(w))
        cout << w << " is present" << endl;
    else
        cout << w << " is not present" << endl;

    w = "gho";
    if (newTrie->search(w))
        cout << w << " is present" << endl;
    else
        cout << w << " is not present" << endl;
    
    return 0;
}