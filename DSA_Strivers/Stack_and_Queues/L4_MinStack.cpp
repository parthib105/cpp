/*
    Min Stack

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

    

    Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    

    Constraints:

    -2^31 <= val <= 2^31 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

#include<bits/stdc++.h>
using namespace std;

//T.C. : O(1), S.C. : O(2N)
class MinStackBrute 
{
private:
    // {element, min_till_now}
    stack<pair<int, int>> st;
public:
    MinStackBrute() {
        
    }
    
    void push(int val) {
        if (this->st.empty())
            this->st.push({val, val});
        else
        {
            int currMin = min(val, this->st.top().second);
            this->st.push({val, currMin});
        }
        cout << "The element " << val << " is pushed into the stack" << endl;
    }
    
    void pop() {
        if (this->st.empty())
            return;
        else
        {
            cout << "The element " << this->st.top().first << " is popped" << endl;
            this->st.pop();
        }
    }
    
    int top() {
        cout << "The top element is " << this->st.top().first << endl;
        return this->st.top().first;
    }
    
    int getMin() {
        cout << "The min element is " << this->st.top().second << endl;
        return this->st.top().second;
    }
};

int main()
{
    // Using Brute force
    MinStackBrute minStack = MinStackBrute();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    
    return 0;
}