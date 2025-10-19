#include<bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int key, val;
    DLLNode *next, *prev;

    DLLNode(int k, int v, DLLNode* p, DLLNode* n)
    {
        this->key = k;
        this->val = v;
        this->prev = p;
        this->next = n;
    }

    ~DLLNode(){
        // No need to add anything.
    }
};

class DLL
{
public:
    DLLNode *head, *tail;

    DLL()
    {
        this->head = new DLLNode(-1, -1, nullptr, nullptr);
        this->tail = new DLLNode(-1, -1, this->head, nullptr);
        this->head->next = this->tail;
    } 

    DLLNode* getLRU()
    {
        return this->tail->prev;
    }

    void insertAfterHead(DLLNode* node)
    {
        DLLNode* nextNode = this->head->next;
        this->head->next = node;
        node->prev = this->head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void deleteNode(DLLNode* node)
    {
        DLLNode* currPrev = node->prev;
        DLLNode* currNext = node->next;
        currPrev->next = currNext;
        currNext->prev = currPrev;
    }
};

class LRUCache 
{
private:
    unordered_map<int, DLLNode*> mp;
    DLL* dll;
    int size;
public:
    LRUCache(int capacity) {
        this->size = capacity;
        this->dll = new DLL();
        this->mp.clear();
    }
    
    int get(int key) {
        if (this->mp.find(key) == this->mp.end())
            return -1;

        DLLNode* currNode = mp[key];
        this->dll->deleteNode(currNode);
        this->dll->insertAfterHead(currNode);

        return currNode->val;
    }
    
    void put(int key, int value) {
        if (this->mp.find(key) != this->mp.end())
        {
            DLLNode* currNode = this->mp[key];
            currNode->val = value;
            this->dll->deleteNode(currNode);
            this->dll->insertAfterHead(currNode);
        }
        else
        {
            if (this->mp.size() == this->size)
            {
                DLLNode* lru = this->dll->getLRU();
                this->mp.erase(lru->key);
                this->dll->deleteNode(lru);
                delete lru;
            }

            DLLNode* newNode = new DLLNode(key, value, nullptr, nullptr);
            this->mp[key] = newNode;
            this->dll->insertAfterHead(newNode);
        }
    }
};

int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // return -1 (not found)
    cout << lRUCache->get(3) << endl;    // return 3
    cout << lRUCache->get(4) << endl;    // return 4
    return 0;
}