class MinStack {
public:
    stack<int> minInt = {};
    stack<int> container = {}; 

    MinStack() {
    }
    
    void push(int val) {
        container.push(val);
        if (minInt.empty() || val <= minInt.top()) minInt.push(val);
    }
    
    void pop() {
        if (!minInt.empty() && container.top() == minInt.top()) minInt.pop();
        container.pop();
    }
    
    int top() {
        return container.top();
    }
    
    int getMin() {
        if (!minInt.empty()) return minInt.top();
        return INT_MAX;
    }
};
