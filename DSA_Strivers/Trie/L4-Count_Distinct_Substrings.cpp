/*
    Count Distinct Substrings

    Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given 
    string. You should implement the program using a trie.

    Note :
    
    A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) 
    from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

    Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at 
    index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
    
    Constraints :
    1 <= T <= 5
    1 <= |S| <= 10^3

    ‘S’ contains only lowercase English letters.

    Time Limit: 1 sec
    
    Sample Input 1 :
    2
    sds
    abc
    
    Sample Output 1 :
    6
    7
    
    Explanation of Sample Input 1 :
    In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

    In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
    
    Sample Input 2 :
    2
    aa
    abab
    
    Sample Output 2 :
    3
    8
    
    Explanation of Sample Input 2 :
    In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

    In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }


    Hints:
    1. Can you think about a data structure that can be used to store the distinct substrings?
    2. Can you think about using the fact that every substring of ‘S’ is a prefix of some suffix string of ‘S’?
    3. Try to insert every suffix of the string in Trie.
*/

#include<bits/stdc++.h>
using namespace std;

int brute(string &s)
{
    unordered_set<string> st;
    st.insert("");
    for (int i = 0; i < s.length(); i++)
    {
        string str = "";
        for (int j = i; j < s.length(); j++)
        {
            str.push_back(s[j]);
            st.insert(str); 
        }
    }
    return st.size();
}

class TrieNode
{
private:
    TrieNode* children[26];
public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }

    bool containsKey(char ch)
    {
        return this->children[ch - 'a'] != NULL;
    }

    TrieNode* next(char ch)
    {
        return this->children[ch - 'a'];
    }

    void put(char ch, TrieNode* child)
    {
        this->children[ch - 'a'] = child;
    }
};

int optimal(string &s)
{
    int count = 1;
    TrieNode* root = new TrieNode();

    for (int i = 0; i < s.length(); i++)
    {
        TrieNode* curr = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!curr->containsKey(s[j]))
            {
                count ++;
                curr->put(s[j], new TrieNode());
            }
            curr = curr->next(s[j]);
        }
    }
    return count;
}

int countDistinctSubstrings(string &s)
{
    // Brute Force
    // return brute(s);

    // Optimal
    return optimal(s);
}

int main()
{
    string s = "abab";
    cout << countDistinctSubstrings(s) << endl;
    return 0;
}