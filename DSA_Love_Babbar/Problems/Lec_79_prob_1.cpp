/*
    Longest common prefix

    You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these 
    strings. If there is no common prefix, you have to return an empty string.

    A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

    For Example:
    Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
    The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer 
    is “cod”.

    Constraints:
    1 <= N <= 3000
    1 <= |ARR[i]| <=1000

    Sample Input 1:
    4
    coding codezen codingninja coder
    3
    night ninja nil 

    Sample Output 1:
    cod
    ni

    Explanation of sample input 1:
    For the first test case, 
    The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.

    For the second test case,
    The longest common prefix among all the given strings is “ni” as it is present as a prefix in all strings. Hence, the answer is “ni”.
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

public:
    Trie(char ch)
    {
        this->root = new TrieNode(ch);
    }

    void insertWord(string word)        // T.C. : O(Length of word)
    {
        insertUtil(this->root, 0, word);
    }

    void lcp(const string& str, string& ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (this->root->childCount == 1)
            {
                ans += ch;
                // move ahead
                this->root = root->children[ch - 'a'];
            }
            else
            {
                break;
            }

            if (this->root->isTerminal)
            {
                break;
            }
        }
    }
};

// Approach 1 : T.C. O(M*N), S.C. O(M)
// M -> length of arr[0]
// N -> length of arr
string longestCommonPrefix1(vector<string> &arr, int n)
{
    string ans = "";
    
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j].size() < i || arr[j][i] != ch)
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            ans.push_back(ch);
        }
        else
        {
            break;
        }
    }
    return ans;
}

// Approach 2 : using trie
string longestCommonPrefix2(vector<string>& arr, int n)
{
    // make a trie
    Trie* t = new Trie('\0');

    // insert all the words
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }
    
    string ans = "";
    string firstStr = arr[0];

    t->lcp(firstStr, ans);
    return ans;

}

int main()
{
    int n = 4;
    vector<string> arr = {"coding", "codezen", "codingninja", "coders"};
    cout << longestCommonPrefix2(arr, n) << endl;
    return 0;
}