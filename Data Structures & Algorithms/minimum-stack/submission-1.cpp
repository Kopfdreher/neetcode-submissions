class MinStack {
public:
    stack<int> minInt = {};
    stack<int> container = {}; 

    MinStack() {
    }
    
    void push(int val) {
        container.push(val);
        if (minInt.empty()) minInt.push(val);
        else minInt.push(min(val, minInt.top()));
    }
    
    void pop() {
        minInt.pop();
        container.pop();
    }
    
    int top() {
        return container.top();
    }
    
    int getMin() {
        return minInt.top();
    }
};