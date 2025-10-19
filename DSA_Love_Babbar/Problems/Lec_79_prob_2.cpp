/*
    Implement a phone directory

    You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on 
    a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix 
    as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then 
    suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.

    Note :
    If no suggestions are found, return an empty 2D array.

    Constraints :
    1 <= N <= 100
    1 <= len <= 10

    ARR[i] contains lowercase English alphabets.
    All the given strings contain lowercase English alphabets.
    Time Limit: 1 sec.

    Sample Input 1 :
    2
    5
    cod coding codding code coly
    coding
    2
    ninjas coding
    ninja

    Sample Output 1 :
    cod coding codding code coly
    cod coding codding code coly
    cod coding codding code coly
    coding
    coding
    coding
    ninjas
    ninjas
    ninjas
    ninjas
    ninjas
    Explanation to Sample Input 1 :
    In the first test case, 
    The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
    The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
    The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
    The suggestion for “codi” is {“coding”}.
    The suggestion for “codin” is {“coding”}.
    The suggestion for “coding” is {“coding”}.

    In the second test case, 
    The suggestion for “n” is {“ninjas”}.
    The suggestion for “ni” is {“ninjas”}.
    The suggestion for “nin” is {“ninjas”}.
    The suggestion for “ninj” is {“ninjas”}.
    The suggestion for “ninja” is {“ninjas”}.
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};

class Trie
{
private:
    TrieNode* root;

    void insertUtil(TrieNode* root, int i, const string& word)
    {
        // base case
        if (i >= word.length())
        {
            root->isTerminal = true;
            return;
        }

        // next child
        TrieNode* child;

        // get the index (assuming all characters are in small)
        int idx = word[i] - 'a';

        // if present, go ahead
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else    // absent
        {
            child = new TrieNode(word[i]);
            root->childCount ++;
            root->children[idx] = child;
        }
        
        insertUtil(child, i + 1, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string pre)
    {
        if (curr->isTerminal)
        {
            temp.push_back(pre);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                pre.push_back(ch);
                printSuggestions(next, temp, pre);
                pre.pop_back();
            }
        }
    }

public:
    Trie(char ch)
    {
        this->root = new TrieNode(ch);
    }

    void insertWord(string word)        // T.C. : O(Length of word)
    {
        insertUtil(this->root, 0, word);
    }

    vector<vector<string>> getSuggestions(string &queryStr)
    {
        vector<vector<string>> ans;
        TrieNode* prev = this->root;
        string pre = "";

        for (int i = 0; i < queryStr.length(); i++)
        {
            char lastCh = queryStr[i];
            pre.push_back(lastCh);

            // check for last character
            TrieNode* curr = prev->children[lastCh - 'a'];
            if (curr == NULL)       // not found
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, pre);

            ans.push_back(temp);
            temp.clear(); 
            prev = curr;
        }
        return ans;
    }
};

// S.C. O(m*n), T.C. O(n*m^2)
// n : no. of words, m : length of words
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    int n = contactList.size();
    Trie* t = new Trie('#');

    for (int i = 0; i < n; i++)
    {
        t->insertWord(contactList[i]);
    }
    return t->getSuggestions(queryStr);
}

int main()
{
    
    return 0;
}