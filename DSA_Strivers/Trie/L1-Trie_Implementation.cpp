/*
    Implement Trie Data Structure to support these operations:

    insert(word) - To insert a string "word" in Trie
    search(word) - To check if string "word" is present in Trie or not.
    startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".


    Three type of queries denote these operations:

    Type 1: To insert a string "word" in Trie.
    1 word

    Type 2: To check if the string "word" is present in Trie or not.
    2 word

    Type 3: To check if there is any string in the Trie that starts with the given prefix string "word".
    3 word

    Constraints :
    1 <= Q <= 5*10^4
    1 <= W <= 10

    Where 'Q' is the number of queries, and 'W' is the length of the "word".
    All input of "word" will consist of only lowercase letters a-z.
    
    Sample Input 1 :
    5
    1 hello
    1 help
    2 help
    3 hel
    2 hel 
    
    Sample Output 1 :
    true
    true
    false
    Explanation to Sample Input 1 :
    Query 1: "hello" is inserted
    Query 2: "help" is inserted
    Query 3: "true" is printed as "help" is present
    Query 4: "true" is printed as "hello" and "help" is present having the prefix "hel"
    Query 5: "false" is printed as "hel" is not present
    
    Sample Input 2 :
    10
    1 aaaa
    1 aaaaaa
    1 bcd
    2 aaaaa
    3 aaaaa
    3 bc
    2 bc
    1 bc
    3 bcda
    2 bc
    
    Sample Output 2 :
    false
    true
    true
    false
    false
    true
    Explanation to Sample Input 2 :
    Query 1: "aaaa" is inserted
    Query 2: "aaaaaa" is inserted
    Query 3: "bcd" is inserted
    Query 4: "false" is printed as "aaaaa" is not present
    Query 5: "true" is printed as "aaaaaa" is present having the prefix "aaaaa"
    Query 6: "true" is printed as "bcd" is present having the prefix "bc"
    Query 7: "false" is printed as "bc" is not present
    Query 8: "bc" is inserted
    Query 9: "false" is printed as no word is present having the prefix "bcda"
    Query 10: "true" is printed as "bc" is present

*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
private:
    TrieNode* children[26];
    bool isTerminal;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }

    bool containsKey(char ch)
    {
        return (this->children[ch - 'a'] != NULL);
    }

    void markChild(char ch, TrieNode* child)
    {
        this->children[ch - 'a'] = child;
    }

    TrieNode* getChild(char ch)
    {
        return this->children[ch - 'a'];
    }

    void setTerminal()
    {
        this->isTerminal = true;
    }

    bool isEnd()
    {
        return this->isTerminal;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        this->root = new TrieNode();
    }

    void insertUtil(string word)
    {
        TrieNode* curr = this->root;
        for (auto ch : word)
        {
            if (!curr->containsKey(ch))     // if not present
            {
                curr->markChild(ch, new TrieNode());
            }
            curr = curr->getChild(ch);
        }

        // at the end set isTerminal to be true
        curr->setTerminal();
    }

    bool search(string word)
    {
        TrieNode* curr = this->root;
        for (auto ch : word)
        {
            if (!curr->containsKey(ch))
            {
                return false;
            }
            curr = curr->getChild(ch);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* curr = this->root;
        for (auto ch : prefix)
        {
            if (!curr->containsKey(ch))
            {
                return false;
            }
            curr = curr->getChild(ch);
        }
        return true;
    }
};

int main()
{
    
    return 0;
}