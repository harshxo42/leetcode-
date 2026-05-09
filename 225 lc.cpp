#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2;
public:
    MyStack() {}
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }
    
    int pop() {
        int topVal = q1.front();
        q1.pop();
        return topVal;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
