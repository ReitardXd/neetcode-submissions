class MinStack {
private:
std::stack<int> s;
std::stack<int> ms;
public:

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        val = std::min(val, ms.empty() ? val: ms.top());
        ms.push(val);
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
         return ms.top();    
    }
};
