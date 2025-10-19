#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Stack {
private:
    T* arr;           // Dynamic array to store stack elements
    int topElm;     // Index of the top element
    int capacity;     // Maximum capacity of the stack
    
public:
    // Constructor
    Stack(int size = 100) {
        this->capacity = size;
        this->arr = new T[size];
        this->topElm = -1;  // Stack is initially empty
    }
    
    // Destructor
    ~Stack() {
        delete[] arr;
    }
    
    // Copy constructor
    Stack(const Stack& other) {
        this->capacity = other.capacity;
        this->topElm = other.topElm;
        this->arr = new T[this->capacity];
        for (int i = 0; i <= this->topElm; i++) {
            this->arr[i] = other.arr[i];
        }
    }
    
    // Assignment operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] this->arr;
            this->capacity = other.capacity;
            this->topElm = other.topElm;
            this->arr = new T[this->capacity];
            for (int i = 0; i <= this->topElm; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    
    // Push operation - O(1)
    void push(const T& element) {
        if (isFull()) {
            throw overflow_error("Stack overflow: Cannot push to full stack");
        }
        arr[++this->topElm] = element;
    }
    
    // Pop operation - O(1)
    T pop() {
        if (this->isEmpty()) {
            throw underflow_error("Stack underflow: Cannot pop from empty stack");
        }
        return arr[this->topElm--];
    }
    
    // Top/Peek operation - O(1)
    T top() const {
        if (this->isEmpty()) {
            throw underflow_error("Stack is empty: No top element");
        }
        return arr[this->topElm];
    }
    
    // Check if stack is empty - O(1)
    bool isEmpty() const {
        return this->topElm == -1;
    }
    
    // Check if stack is full - O(1)
    bool isFull() const {
        return this->topElm == this->capacity - 1;
    }
    
    // Get current size - O(1)
    int size() const {
        return this->topElm + 1;
    }
    
    // Get capacity - O(1)
    int getCapacity() const {
        return this->capacity;
    }
    
    // Display stack contents
    void display() const {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        cout << "Stack contents (top to bottom): ";
        for (int i = this->topElm; i >= 0; i--) {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
    
    // Clear the stack
    void clear() {
        this->topElm = -1;
    }
};

// Usage example
int main() 
{
    try {
        Stack<int> stack(5);
        
        // Push elements
        stack.push(10);
        stack.push(20);
        stack.push(30);
        
        stack.display();  // Output: 30 20 10
        
        cout << "Top: " << stack.top() << endl;     // Output: 30
        cout << "Size: " << stack.size() << endl;   // Output: 3
        
        cout << "Popped: " << stack.pop() << endl;  // Output: 30
        stack.display();  // Output: 20 10
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
