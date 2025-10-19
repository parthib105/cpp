/*
    Find median in a stream

    Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the 
    stream formed by each insertion of X to the new stream.
*/

#include<bits/stdc++.h>
using namespace std;

class medianInStream
{
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (this->maxHeap.empty() || x <= this->maxHeap.top())
        {
            this->maxHeap.push(x);
        }
        else
        {
            this->minHeap.push(x);
        }
        
        this->balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if (this->maxHeap.size() > this->minHeap.size() + 1)
        {
            this->minHeap.push(this->maxHeap.top());
            this->maxHeap.pop();
        }
        else if (this->minHeap.size() > this->maxHeap.size())
        {
            this->maxHeap.push(this->minHeap.top());
            this->minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (this->minHeap.size() > this->maxHeap.size())
        {
            return static_cast<double>(this->minHeap.top());
        }
        else if (this->maxHeap.size() > this->minHeap.size())
        {
            return static_cast<double>(this->maxHeap.top());
        }
        return static_cast<double>(this->minHeap.top() + this->maxHeap.top())/2;
    }
};

int main()
{
    vector<int> stream = {4, 2, 0, 6, 7, 3, 10};
    medianInStream median;

    for (int i = 0; i < stream.size(); i++)
    {
        median.insertHeap(stream[i]);
        cout << median.getMedian() << " ";
    }
    cout << endl;
    return 0;
}