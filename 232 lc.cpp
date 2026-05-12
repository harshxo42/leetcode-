#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;
    
    void transferIfNeeded() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
    
public:
    MyQueue() {
        // nothing to initialize
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        transferIfNeeded();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
